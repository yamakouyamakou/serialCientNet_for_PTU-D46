#include "MainForm.h"

using namespace SerialClientNET;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// コントロールが作成される前に、Windows XP ビジュアル効果を有効にします
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	// メイン ウィンドウを作成して、実行します
	Application::Run(gcnew MainForm());

	return 0;
}
