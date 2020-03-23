// SerialConnector.h

#pragma once

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>

using namespace System;
using namespace System::Threading::Tasks;

namespace Serial {

	public enum class SerialMessageType
	{
		TYPE_ERROR = 0x00,
		TYPE_DATA = 0x01
	};

	public ref class SerialReceiveMessage : System::EventArgs
	{
	public:
		const SerialMessageType Type;
		array<String^>^ Data;

		SerialReceiveMessage(SerialMessageType type, ... array<String^>^ data) : Type(type)
		{
			Data = gcnew array<String^>(data->Length);
			data->CopyTo(Data, 0);
		}
	};
	public delegate void SerialReceiveMessageEventHandler(Object^ s, SerialReceiveMessage^ e);

	public ref class SerialConnector
	{
	private:
		static SerialConnector^ connector;

		static const int BAUDRATE = 9200;// 115200;
		static const int BUFFERSIZE = 1024;

		HANDLE h;

		Task^ task;
		bool isOpen = false;

		void ReceiveInner();
	
	public:
		static SerialConnector^ GetInstance();

		event SerialReceiveMessageEventHandler^ ReceiveMessage;

		property bool IsOpen{
			bool get(){ return this->isOpen; }
			private: 
				void set(bool value){ this->isOpen = value;  }
		};

		void Open(int comNo);
		void Close();
		void StartReceive();
		void StopReceive();
		void Send(String^ msg);
	};
}
