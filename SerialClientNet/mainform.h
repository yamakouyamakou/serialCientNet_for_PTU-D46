#pragma once
#include <iostream>
#include<typeinfo.h>
#include<string>
#include<fstream>
#include<sstream>
#include<windows.h>

namespace SerialClientNET {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MainForm の概要
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	private:
		/**************************/
		Serial::SerialConnector^ connector;
		void ReceiveMessageFunc(Object^ s, Serial::SerialReceiveMessage^ e);
		/**************************/

	public:
		MainForm(void)
		{
			InitializeComponent();

			/**************************/
			connector = Serial::SerialConnector::GetInstance();
			connector->ReceiveMessage += gcnew Serial::SerialReceiveMessageEventHandler(this, &MainForm::ReceiveMessageFunc);
			/**************************/
		}

	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:

		private: System::Windows::Forms::TextBox^ comNo;
		private: System::Windows::Forms::Button^  openBtn;
		private: System::Windows::Forms::TextBox^ msgTxt;
		private: System::Windows::Forms::Button^  sendBtn;
		private: System::Windows::Forms::Button^  closeBtn;
	private: System::Windows::Forms::Button^  pp0Btn;
	private: System::Windows::Forms::Button^  tp0Btn;



	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  tiltPosTxt;
	private: System::Windows::Forms::Button^  tiltPosBtn;
	private: System::Windows::Forms::Button^  panPosBtn;



	private: System::Windows::Forms::TextBox^  panPosTxt;
	private: System::Windows::Forms::Button^  panVelBtn;


	private: System::Windows::Forms::TextBox^  panVelTxt;
	private: System::Windows::Forms::Button^  tiltVelBtn;


	private: System::Windows::Forms::TextBox^  tiltVelTxt;
	private: System::Windows::Forms::Button^  stopBtn;
	private: System::Windows::Forms::Button^  button1;





	private:
		/// <summary>
		/// 必要なデザイナー変数です。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// デザイナー サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディターで変更しないでください。
		/// </summary>
		void InitializeComponent(void)
		{
			this->comNo = (gcnew System::Windows::Forms::TextBox());
			this->openBtn = (gcnew System::Windows::Forms::Button());
			this->msgTxt = (gcnew System::Windows::Forms::TextBox());
			this->sendBtn = (gcnew System::Windows::Forms::Button());
			this->closeBtn = (gcnew System::Windows::Forms::Button());
			this->pp0Btn = (gcnew System::Windows::Forms::Button());
			this->tp0Btn = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tiltPosTxt = (gcnew System::Windows::Forms::TextBox());
			this->tiltPosBtn = (gcnew System::Windows::Forms::Button());
			this->panPosBtn = (gcnew System::Windows::Forms::Button());
			this->panPosTxt = (gcnew System::Windows::Forms::TextBox());
			this->panVelBtn = (gcnew System::Windows::Forms::Button());
			this->panVelTxt = (gcnew System::Windows::Forms::TextBox());
			this->tiltVelBtn = (gcnew System::Windows::Forms::Button());
			this->tiltVelTxt = (gcnew System::Windows::Forms::TextBox());
			this->stopBtn = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// comNo
			// 
			this->comNo->Location = System::Drawing::Point(62, 17);
			this->comNo->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->comNo->Name = L"comNo";
			this->comNo->Size = System::Drawing::Size(96, 22);
			this->comNo->TabIndex = 0;
			// 
			// openBtn
			// 
			this->openBtn->Location = System::Drawing::Point(174, 12);
			this->openBtn->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->openBtn->Name = L"openBtn";
			this->openBtn->Size = System::Drawing::Size(140, 28);
			this->openBtn->TabIndex = 1;
			this->openBtn->Text = L"Open";
			this->openBtn->UseVisualStyleBackColor = true;
			this->openBtn->Click += gcnew System::EventHandler(this, &MainForm::openBtn_Click);
			// 
			// msgTxt
			// 
			this->msgTxt->Enabled = false;
			this->msgTxt->Location = System::Drawing::Point(18, 324);
			this->msgTxt->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->msgTxt->Name = L"msgTxt";
			this->msgTxt->Size = System::Drawing::Size(139, 22);
			this->msgTxt->TabIndex = 2;
			// 
			// sendBtn
			// 
			this->sendBtn->Enabled = false;
			this->sendBtn->Location = System::Drawing::Point(174, 321);
			this->sendBtn->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->sendBtn->Name = L"sendBtn";
			this->sendBtn->Size = System::Drawing::Size(140, 28);
			this->sendBtn->TabIndex = 3;
			this->sendBtn->Text = L"Send Text";
			this->sendBtn->UseVisualStyleBackColor = true;
			this->sendBtn->Click += gcnew System::EventHandler(this, &MainForm::sendBtn_Click);
			// 
			// closeBtn
			// 
			this->closeBtn->Location = System::Drawing::Point(174, 49);
			this->closeBtn->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->closeBtn->Name = L"closeBtn";
			this->closeBtn->Size = System::Drawing::Size(140, 28);
			this->closeBtn->TabIndex = 4;
			this->closeBtn->Text = L"Close";
			this->closeBtn->UseVisualStyleBackColor = true;
			this->closeBtn->Click += gcnew System::EventHandler(this, &MainForm::closeBtn_Click);
			// 
			// pp0Btn
			// 
			this->pp0Btn->Location = System::Drawing::Point(174, 101);
			this->pp0Btn->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->pp0Btn->Name = L"pp0Btn";
			this->pp0Btn->Size = System::Drawing::Size(140, 28);
			this->pp0Btn->TabIndex = 3;
			this->pp0Btn->Text = L"Set Pan 0";
			this->pp0Btn->UseVisualStyleBackColor = true;
			this->pp0Btn->Click += gcnew System::EventHandler(this, &MainForm::pp0Btn_Click);
			// 
			// tp0Btn
			// 
			this->tp0Btn->Location = System::Drawing::Point(174, 136);
			this->tp0Btn->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->tp0Btn->Name = L"tp0Btn";
			this->tp0Btn->Size = System::Drawing::Size(140, 28);
			this->tp0Btn->TabIndex = 5;
			this->tp0Btn->Text = L"Set Tilt 0";
			this->tp0Btn->UseVisualStyleBackColor = true;
			this->tp0Btn->Click += gcnew System::EventHandler(this, &MainForm::tp0Btn_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(19, 19);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(39, 15);
			this->label1->TabIndex = 6;
			this->label1->Text = L"COM";
			// 
			// tiltPosTxt
			// 
			this->tiltPosTxt->Location = System::Drawing::Point(18, 214);
			this->tiltPosTxt->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->tiltPosTxt->Name = L"tiltPosTxt";
			this->tiltPosTxt->Size = System::Drawing::Size(141, 22);
			this->tiltPosTxt->TabIndex = 7;
			// 
			// tiltPosBtn
			// 
			this->tiltPosBtn->Location = System::Drawing::Point(174, 208);
			this->tiltPosBtn->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->tiltPosBtn->Name = L"tiltPosBtn";
			this->tiltPosBtn->Size = System::Drawing::Size(140, 28);
			this->tiltPosBtn->TabIndex = 8;
			this->tiltPosBtn->Text = L"Set Tilt Pos";
			this->tiltPosBtn->UseVisualStyleBackColor = true;
			this->tiltPosBtn->Click += gcnew System::EventHandler(this, &MainForm::tiltPosBtn_Click);
			// 
			// panPosBtn
			// 
			this->panPosBtn->Location = System::Drawing::Point(174, 171);
			this->panPosBtn->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->panPosBtn->Name = L"panPosBtn";
			this->panPosBtn->Size = System::Drawing::Size(140, 28);
			this->panPosBtn->TabIndex = 10;
			this->panPosBtn->Text = L"Set Pan Pos";
			this->panPosBtn->UseVisualStyleBackColor = true;
			this->panPosBtn->Click += gcnew System::EventHandler(this, &MainForm::panPosBtn_Click);
			// 
			// panPosTxt
			// 
			this->panPosTxt->Location = System::Drawing::Point(18, 177);
			this->panPosTxt->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->panPosTxt->Name = L"panPosTxt";
			this->panPosTxt->Size = System::Drawing::Size(141, 22);
			this->panPosTxt->TabIndex = 9;
			// 
			// panVelBtn
			// 
			this->panVelBtn->Location = System::Drawing::Point(174, 246);
			this->panVelBtn->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->panVelBtn->Name = L"panVelBtn";
			this->panVelBtn->Size = System::Drawing::Size(140, 28);
			this->panVelBtn->TabIndex = 14;
			this->panVelBtn->Text = L"Set Pan Vel";
			this->panVelBtn->UseVisualStyleBackColor = true;
			this->panVelBtn->Click += gcnew System::EventHandler(this, &MainForm::panVelBtn_Click);
			// 
			// panVelTxt
			// 
			this->panVelTxt->Location = System::Drawing::Point(18, 251);
			this->panVelTxt->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->panVelTxt->Name = L"panVelTxt";
			this->panVelTxt->Size = System::Drawing::Size(141, 22);
			this->panVelTxt->TabIndex = 13;
			// 
			// tiltVelBtn
			// 
			this->tiltVelBtn->Location = System::Drawing::Point(174, 283);
			this->tiltVelBtn->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->tiltVelBtn->Name = L"tiltVelBtn";
			this->tiltVelBtn->Size = System::Drawing::Size(140, 28);
			this->tiltVelBtn->TabIndex = 12;
			this->tiltVelBtn->Text = L"Set Tilt Vel";
			this->tiltVelBtn->UseVisualStyleBackColor = true;
			this->tiltVelBtn->Click += gcnew System::EventHandler(this, &MainForm::tiltVelBtn_Click);
			// 
			// tiltVelTxt
			// 
			this->tiltVelTxt->Location = System::Drawing::Point(18, 287);
			this->tiltVelTxt->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->tiltVelTxt->Name = L"tiltVelTxt";
			this->tiltVelTxt->Size = System::Drawing::Size(141, 22);
			this->tiltVelTxt->TabIndex = 11;
			// 
			// stopBtn
			// 
			this->stopBtn->Location = System::Drawing::Point(18, 101);
			this->stopBtn->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->stopBtn->Name = L"stopBtn";
			this->stopBtn->Size = System::Drawing::Size(140, 63);
			this->stopBtn->TabIndex = 3;
			this->stopBtn->Text = L"Stop";
			this->stopBtn->UseVisualStyleBackColor = true;
			this->stopBtn->Click += gcnew System::EventHandler(this, &MainForm::stopBtn_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(174, 358);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(140, 27);
			this->button1->TabIndex = 15;
			this->button1->Text = L" start sweep";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(339, 406);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->panVelBtn);
			this->Controls->Add(this->panVelTxt);
			this->Controls->Add(this->tiltVelBtn);
			this->Controls->Add(this->tiltVelTxt);
			this->Controls->Add(this->panPosBtn);
			this->Controls->Add(this->panPosTxt);
			this->Controls->Add(this->tiltPosBtn);
			this->Controls->Add(this->tiltPosTxt);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->tp0Btn);
			this->Controls->Add(this->closeBtn);
			this->Controls->Add(this->stopBtn);
			this->Controls->Add(this->pp0Btn);
			this->Controls->Add(this->sendBtn);
			this->Controls->Add(this->msgTxt);
			this->Controls->Add(this->openBtn);
			this->Controls->Add(this->comNo);
			this->KeyPreview = true;
			this->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainForm::MainForm_FormClosing);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::MainForm_KeyDown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: 
		System::Void openBtn_Click(System::Object^  sender, System::EventArgs^  e)
		{
			String^ comNoStr = this->comNo->Text->ToString();
			Int32 comNo;
			if (Int32::TryParse(comNoStr, comNo)){
				connector->Open(comNo);
			}
		}

		System::Void closeBtn_Click(System::Object^  sender, System::EventArgs^  e)
		{
			connector->Close();
		}

		System::Void sendBtn_Click(System::Object^  sender, System::EventArgs^  e)
		{
			if (connector->IsOpen) {
				String^ msgStr = String::Format("{0}\n", this->msgTxt->Text->ToString());
//				String^ msgStr = String::Format("PP0\nTP0\nA\nDR\nS\nPP2000\nTP2000\nPP\nTP\nA\nPP0\nTP0\nPP\nTP\nA\n", this->msgTxt->Text->ToString());
				connector->Send(msgStr);
			}
		}

		System::Void stopBtn_Click(System::Object^  sender, System::EventArgs^  e)
		{
			if (connector->IsOpen) {
				String^ msgStr = String::Format("H\nA\n");
				connector->Send(msgStr);
			}
		}

		System::Void pp0Btn_Click(System::Object^  sender, System::EventArgs^  e)
		{
			if (connector->IsOpen) {
				String^ msgStr = String::Format("PP0\nA\n");
				connector->Send(msgStr);
			}
		}

		System::Void tp0Btn_Click(System::Object^  sender, System::EventArgs^  e)
		{
			if (connector->IsOpen) {
				String^ msgStr = String::Format("TP0\nA\n");
				connector->Send(msgStr);
			}
		}

		System::Void panPosBtn_Click(System::Object^  sender, System::EventArgs^  e)
		{
			if (connector->IsOpen) {
				short val;
				System::String^ txt = this->panPosTxt->Text->ToString(); // panPosTxt:GUIのテキストボックス内
				if (Int16::TryParse(txt, val)){//TryParse:数値の文字列形式を、それと等価な 32 ビット符号付き整数に変換します。
					String^ msgStr = String::Format("PP{0}\nA\n", val);
					connector->Send(msgStr);
				}
			}
		}

		System::Void tiltPosBtn_Click(System::Object^  sender, System::EventArgs^  e)
		{
			if (connector->IsOpen) {
				short val;
				System::String^ txt = this->tiltPosTxt->Text->ToString();
				if (Int16::TryParse(txt, val)){
					String^ msgStr = String::Format("TP{0}\nA\n", val);
					connector->Send(msgStr);
				}
			}
		}
			 
		System::Void panSpeedBtn_Click(System::Object^  sender, System::EventArgs^  e)
		{
			if (connector->IsOpen) {
				short val;
				System::String^ txt = this->panVelTxt->Text->ToString();
				if (Int16::TryParse(txt, val)){
					String^ msgStr = String::Format("PS{0}\n", val);
					connector->Send(msgStr);
				}
			}
		}

		System::Void tiltSpeedBtn_Click(System::Object^  sender, System::EventArgs^  e)
		{
			if (connector->IsOpen) {
				short val;
				System::String^ txt = this->tiltVelTxt->Text->ToString();
				if (Int16::TryParse(txt, val)){
					String^ msgStr = String::Format("TS{0}\n", val);
					connector->Send(msgStr);
				}
			}
		}

		System::Void MainForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e)
		{
			if (connector->IsOpen) {
				connector->Close();
			}
		}

		System::Void MainForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
		{
			/* fujii */
			if (connector->IsOpen) {
				if (e->Shift) {

					// Shift を押しながらのキー入力はここで消費して下のコンロールに渡さない
					e->Handled = true;

					if (e->Control) {
						switch (e->KeyCode) {
							case Keys::Up:
								connector->Send("C:MOVEFORWARD\n");
								break;
							case Keys::Down:
								connector->Send("C:MOVEBACK\n");
								break;
						}
					}
					else {
						switch (e->KeyCode) {
							case Keys::Escape:
								connector->Send("Q\n");
								break;
							case Keys::S:
								connector->Send("C:STOP\n");
								break;
							case Keys::Up:
								//							System::Console::WriteLine("KeyUp");
								connector->Send("C:MOVEUP\n");
								break;
							case Keys::Down:
								//							System::Console::WriteLine("KeyDown");
								connector->Send("C:MOVEDOWN\n");
								break;
							case Keys::Left:
								//							System::Console::WriteLine("KeyLeft");
								connector->Send("C:MOVELEFT\n");
								break;
							case Keys::Right:
								//							System::Console::WriteLine("KeyRight");
								connector->Send("C:MOVERIGHT\n");
								break;
						}
					}
				}
			}
		}

	private: System::Void panVelBtn_Click(System::Object^  sender, System::EventArgs^  e) {
	}

private: System::Void tiltVelBtn_Click(System::Object^  sender, System::EventArgs^  e) {
}


private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	// pan limit is +-159(=12366.67)
	// tilt +limit is +31(=2411)
	// tilt -limit is -47(=3653)

	//tilt 20 =1944

	//std::string targetSolution = "jedi2";
	//std::string targetSolution = "nirAndRs";
	std::string targetSolution = "takeOverResearch\\takeOverResearch";

	std::cout << "start sweep\n";
	
	std::ofstream initSwPT("C:\\Users\\yamak\\source\\repos\\"+ targetSolution +"\\shared_folder_ubuntu\\swPT.txt");
	initSwPT << "1";
	initSwPT.close();


	std::ofstream initPan("C:\\Users\\yamak\\source\\repos\\" + targetSolution + "\\shared_folder_ubuntu\\panDeg.txt");
	initPan << "35";
	initPan.close();

	std::ofstream initTilt("C:\\Users\\yamak\\source\\repos\\" + targetSolution + "\\shared_folder_ubuntu\\tiltDeg.txt");
	initTilt << "20";
	initTilt.close();
	
	int initTilt2 = 2 * (20) / (92.5714 / 3600);
	std::to_string(initTilt2);
	String^ msgStrTilt = String::Format("TP{0}\nA\n", initTilt2);
	connector->Send(msgStrTilt);

	int initPan2 = 2 * (35) / (92.5714 / 3600);
	std::to_string(initPan2);
	String^ msgStrPan = String::Format("PP{0}\nA\n", initPan2);
	connector->Send(msgStrPan);

	//tomarunomatu




	//sw=0
	Sleep(10*1000);
	std::ofstream initSw("C:\\Users\\yamak\\source\\repos\\" + targetSolution + "\\shared_folder_ubuntu\\switch.txt");
	initSw << "0";
	initSw.close();


	int n = 1;
	int addPan = -7;
	int addTilt = -7;
	
//	while (n < 9) {
	while (true) {
		
		std::ifstream ifs("C:\\Users\\yamak\\source\\repos\\" + targetSolution + "\\shared_folder_ubuntu\\switch.txt");
		std::string sw;
		ifs >> sw;
		ifs.close();

		std::ifstream ifsSwPT("C:\\Users\\yamak\\source\\repos\\" + targetSolution + "\\shared_folder_ubuntu\\swPT.txt");
		std::string swPT;
		ifsSwPT >> swPT;
		ifsSwPT.close();

		std::ifstream ifsPan("C:\\Users\\yamak\\source\\repos\\" + targetSolution + "\\shared_folder_ubuntu\\panDeg.txt");
		std::string panDegStr;
		ifsPan >> panDegStr;
		ifsPan.close();

		std::ifstream ifsTilt("C:\\Users\\yamak\\source\\repos\\" + targetSolution + "\\shared_folder_ubuntu\\TiltDeg.txt");
		std::string tiltDegStr;
		ifsTilt >> tiltDegStr;
		ifsTilt.close();

		
		//std::ofstream initSw("C:\\Users\\yamak\\source\\repos\\jedi2\\shared_folder_ubuntu\\switch.txt");
		//initSw << "0";
		//initSw.close();

		//std::cout << "sw=" << sw  <<  ",  swPT=" << swPT << "  panDegStr=" << panDegStr <<"  tiltDegStr="<< tiltDegStr << std::endl;;
		//std::cout << "n = " << n << std::endl;
		//std::cout << "panDegStr = " << panDegStr << std::endl;
		//std::cout << "tiltDegStr = " << tiltDegStr << std::endl;

		int panDeg;
		panDeg = stoi(panDegStr);
		int tiltDeg;
		tiltDeg = stoi(tiltDegStr);

		
		if (tiltDeg <= -28) {
		String^ msgStrFin = String::Format("TP{0}\nA\n", "0");
		connector->Send(msgStrFin);

		String^ msgStrFin2 = String::Format("PP{0}\nA\n", "0");
		connector->Send(msgStrFin2);

		break;
		}
		

		extern int st;

		if (sw=="1") {

			if (swPT == "1" ) {
				// ********   pan   **************
				panDeg += addPan;
				int b = 2 * (panDeg) / (92.5714 / 3600);
				std::to_string(b);
				std::cout << "b=" << b << std::endl;
				String^ msgStr = String::Format("PP{0}\nA\n", b);
				connector->Send(msgStr);
				Sleep(4.0 * 1000);
				//Sleep(st);



				std::ofstream ifs2("C:\\Users\\yamak\\source\\repos\\" + targetSolution + "\\shared_folder_ubuntu\\switch.txt");
				ifs2 << "0";
				ifs2.close();
				n++;

				if (panDeg <= -35 || panDeg >= 35) {
					addPan = addPan * (-1);
					
					std::ofstream outSwPT("C:\\Users\\yamak\\source\\repos\\" + targetSolution + "\\shared_folder_ubuntu\\swPT.txt");
					outSwPT << "0";
					outSwPT.close();
				}

				std::to_string(panDeg);
				std::ofstream outPan("C:\\Users\\yamak\\source\\repos\\" + targetSolution + "\\shared_folder_ubuntu\\panDeg.txt");
				outPan << panDeg;
				outPan.close();
				
			}


			if (swPT == "0" ) {
				//*********  tilt   ********************
				tiltDeg += addTilt; 
				int c = 2 * (tiltDeg) / (92.5714 / 3600);
				std::to_string(c);
				std::cout << "c=" << c << std::endl;
				String^ msgStr = String::Format("TP{0}\nA\n", c);
				connector->Send(msgStr);
				Sleep(2 * 1000);

				std::ofstream outSw("C:\\Users\\yamak\\source\\repos\\" + targetSolution + "\\shared_folder_ubuntu\\switch.txt");
				outSw << "0";
				outSw.close();
				n++;

				std::ofstream panSwPT("C:\\Users\\yamak\\source\\repos\\" + targetSolution + "\\shared_folder_ubuntu\\swPT.txt");
				panSwPT << "1";
				panSwPT.close();

				std::to_string(tiltDeg);
				std::ofstream outTilt("C:\\Users\\yamak\\source\\repos\\" + targetSolution + "\\shared_folder_ubuntu\\TiltDeg.txt");
				outTilt << tiltDeg;
				outTilt.close();
				
			}

		}

		else if (sw == "1"&& panDeg>=35 && panDeg<=-35 && tiltDeg<=-22) {
			String^ msgStrFin = String::Format("TP{0}\nA\n", "0");
			connector->Send(msgStrFin);

			String^ msgStrFin2 = String::Format("PP{0}\nA\n", "0");
			connector->Send(msgStrFin2);

			break;
		}


	}


}


};
}
