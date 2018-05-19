#pragma once
#include <map>
#include <string>
using namespace std;

class Screens {
	void renderMenu(map <int, string>, int);
public:
	void LanguageScreen(int);
	void MainScreen(int);
	void DemonstrationScreen(int);
	void WorkScreen(int);
	void ListScreen(int);
	void EditScreen(int, int);

	void FlyScreen(int);
	void HelicopterScreen(int);
	void JetfighterScreen(int);
	void BomberScreen(int);
	void transportAircraftScreen(int);
	void PlainScreen(int);
	void ManagerScreen(int);

	void BackScreen(int);
	void HelpScreen(int);

	void LanguageScreen1(int);
	void LanguageScreen2(int);
	void LanguageScreen3(int);
	void LanguageScreen4(int);
	void LanguageScreen5(int);

};
