#include "MainForm.h"

namespace SerialClientNET
{
	void MainForm::ReceiveMessageFunc(Object^ s, Serial::SerialReceiveMessage^ e)
	{
		Serial::SerialMessageType type = e->Type;
		array<String^>^ data = e->Data;

		switch (type) {
			case Serial::SerialMessageType::TYPE_ERROR:
				break;
			case Serial::SerialMessageType::TYPE_DATA:
				for (int i = 0; i < data->Length; i++) {
					System::Console::WriteLine("{0}", data[i]);
				}
				break;
		}
	}
}
