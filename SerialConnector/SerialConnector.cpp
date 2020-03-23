// これは メイン DLL ファイルです。

#include "stdafx.h"

#include "SerialConnector.h"

namespace Serial {

	SerialConnector^ SerialConnector::GetInstance()
	{
		if (connector == nullptr) {
			connector = gcnew SerialConnector();
		}
		return connector;
	}

	void SerialConnector::Open(int comNo)
	{
		if (this->isOpen) {	
			System::Console::WriteLine("Already Opened");
			return;
		}

		DCB dcb;
		COMMTIMEOUTS cto;

		/* ----------------------------------------------
		ファイルのクリエイト／オープン
		---------------------------------------------- */
		// クリエイトしたファイルのファイルハンドラを返す
		String^ comNoStr = String::Format("COM{0}", comNo);
		IntPtr wstr = System::Runtime::InteropServices::Marshal::StringToHGlobalUni(comNoStr);
		LPWSTR comNoWchar = static_cast<LPWSTR>(wstr.ToPointer());

		//System::Console::WriteLine("{0}", comNoStr);

		h = CreateFile(comNoWchar,
			GENERIC_READ | GENERIC_WRITE,
			0,
			NULL,
			OPEN_EXISTING,
			FILE_FLAG_OVERLAPPED,
			NULL);

		if (h != INVALID_HANDLE_VALUE) {

			/* ----------------------------------------------
			シリアルポートの状態操作
			---------------------------------------------- */
			GetCommState(h, &dcb); // シリアルポートの状態を取得
			dcb.BaudRate = BAUDRATE;
			dcb.ByteSize = 8; // データ長
			dcb.Parity = NOPARITY; // パリティ
			dcb.StopBits = ONESTOPBIT; // ストップビット長
			dcb.fOutxCtsFlow = FALSE;  // 送信時CTSフロー
			dcb.fRtsControl = RTS_CONTROL_ENABLE; // RTSフロー
			SetCommState(h, &dcb); // シリアルポートの状態を設定

			/* ----------------------------------------------
			シリアルポートのタイムアウト状態操作
			---------------------------------------------- */
			GetCommTimeouts(h, &cto); // タイムアウトの設定状態を取得
			cto.ReadIntervalTimeout = 1000;
			cto.ReadTotalTimeoutMultiplier = 0;
			cto.ReadTotalTimeoutConstant = 1000;
			cto.WriteTotalTimeoutMultiplier = 0;
			cto.WriteTotalTimeoutConstant = 0;
			SetCommTimeouts(h, &cto); // タイムアウトの状態を設定

			StartReceive();

			System::Console::WriteLine("{0} Open", comNoStr);
		}
		else {
			System::Console::WriteLine("{0} Open Handle Error!", comNoStr);
		}
	}

	void SerialConnector::Close()
	{
		if (isOpen) {
			StopReceive();
		}
	}

	void SerialConnector::StartReceive()
	{
		task = gcnew Task(gcnew Action(this, &SerialConnector::ReceiveInner));
		task->Start();
	}

	void SerialConnector::StopReceive()
	{
		this->task = nullptr;
		CancelIo(h);
	}

	void SerialConnector::ReceiveInner()
	{
		char str[BUFFERSIZE];
		unsigned long nn;
		int i = 0;
		char sBuf[1];

		HANDLE hEvent = CreateEvent(NULL, FALSE, FALSE, L"olp2");
		OVERLAPPED ol;
		memset(&ol, 0, sizeof(OVERLAPPED));
		ol.hEvent = hEvent;

		isOpen = true;

		while (this->task != nullptr) {
			
			/****************/
			//BOOL ret = ReadFile(h, sBuf, 1, &nn, 0); // シリアルポートに対する読み込み
			BOOL ret = ReadFile(h, sBuf, 1, &nn, &ol); // シリアルポートに対する読み込み
			DWORD error = GetLastError();
			if (!ret && error == ERROR_IO_PENDING) {
				BOOL ret2 = GetOverlappedResult(h, &ol, &nn, TRUE);
				if (!ret2) {
					printf("Error start reading.");
				}
			}
			/****************/

			if (nn == 1) {
				if (sBuf[0] == 10 || sBuf[0] == 13) { // '\r'や'\n'や'*'を受信すると文字列を閉じる
					if (i != 0) {
						str[i] = '\0';
						i = 0;
						
						System::Console::WriteLine("Received: {0}", gcnew String(str));
						
						//if (ReceiveMessage) {
							//String^ msg = gcnew String(str);
							//array<String^>^ msgArray = msg->Split(':');

							//String^ type = msgArray[0];
							//array<String^>^ data = msgArray[1]->Split(',');

							//if (type->Equals("E")) {
							//	ReceiveMessage(this, gcnew SerialReceiveMessage(SerialMessageType::TYPE_ERROR, data));
							//}
							//else if (type->Equals("D")) {
							//	ReceiveMessage(this, gcnew SerialReceiveMessage(SerialMessageType::TYPE_DATA, data));
							//}
						//}
					}
				}
				else {
					str[i] = sBuf[0];
					i++;
				}
			}
		}

		CloseHandle(hEvent);
		CloseHandle(h);
		isOpen = false;
		
		printf("Receive End\n");
	}

	void SerialConnector::Send(String^ msg)
	{
		IntPtr wstr = System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(msg);
		char* msgChar = static_cast<char*>(wstr.ToPointer());
		unsigned long nn;

		//System::Console::WriteLine("Start Sending ...");
		//bool ret = WriteFile(h, msgChar, strlen(msgChar), &nn, 0); // シリアルポートに対する書き込み
		
		/****************************/
		HANDLE hEvent = CreateEvent(NULL, FALSE, FALSE, L"olp");
		OVERLAPPED ol;
		memset(&ol, 0, sizeof(OVERLAPPED));
		ol.hEvent = hEvent;
		bool ret = WriteFile(h, msgChar, strlen(msgChar), &nn, &ol); // シリアルポートに対する書き込み
		//bool ret = WriteFile(h, msgChar, strlen(msgChar), &nn, NULL); // シリアルポートに対する書き込み
		FlushFileBuffers(h);
		/****************************/

		if (!ret) {
			DWORD error = GetLastError();
			if (error == ERROR_IO_PENDING) {
				GetOverlappedResult(h, &ol, &nn, TRUE);
			}
			else {
				printf("OVERLAP WRITTING ERROR");
				return;
			}
			//printf("ERROR %s", msgChar);
		}
		else {
			System::Console::Write("Sent ({1}byte): {0}", msg, nn);
		}
	}
}