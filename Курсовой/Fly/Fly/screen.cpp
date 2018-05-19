#include "stdafx.h"
#include "conio.h"
#include "windows.h"
#include <iostream>
#include <iomanip>
#include "screen.h"
#include "lang.h"
#include "fly.h"
#include "helicopter.h"
#include "jetfighter.h"
#include "bomber.h"
#include "plain.h"
#include "transportAircraft.h"
#include <ctime>
#include "manager.h"
#include "getvalues.h"
#include <string.h>
#include <fstream>
#include "Cache.h"


#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

//����� ���������� ����
void Screens::renderMenu(map <int, string> menu, int action) {

	cout << "\n\n\n\n";
	for (int i = 0; i<menu.size(); i++) {
		if (i != 0) cout << "\n\n";
		cout << "                           ";
		(i + 1 == action) ? cout << "--" : cout << "  ";		//���������� �.�. ��������� ����� �������� 
		cout << "  " << menu[i] << "";
	}
	cout << "\n\n\n\n";
}

//���� ��������� �����
void Screens::LanguageScreen1(int menu) {
	system("title �������� ������. ������� 13. ������� ����./Course work. Variant 13. Change language.");
	system("cls");
	system("mode con lines=10");

	map <int, string> nav;
	nav[0] = "�������";
	nav[1] = "english";
	renderMenu(nav, menu);


	int choice = _getch();
	if (choice == 224)
		choice = _getch();
	if (choice == 72)
		if (menu != 1)
			LanguageScreen1(menu - 1);
		else
			LanguageScreen1(nav.size());
	if (choice == 80)
		if (menu != nav.size())
			LanguageScreen1(menu + 1);
		else
			LanguageScreen1(1);
	if (choice == 13 || choice == 32) {
		if (menu == 1) {
			Lang::setLangFile(Lang::ln1);

			MainScreen(1);
		}
		if (menu == 2) {
			Lang::setLangFile(Lang::ln2);
			
			MainScreen(1);
		}
	}
	else {
		LanguageScreen1(1);
	}
}

//���� ��������� �����
void Screens::LanguageScreen2(int menu) {
	system("title �������� ������. ������� 13. ������� ����./Course work. Variant 13. Change language.");
	system("cls");
	system("mode con lines=10");

	map <int, string> nav;
	nav[0] = "�������";
	nav[1] = "english";
	renderMenu(nav, menu);

	int choice = _getch();
	if (choice == 224)
		choice = _getch();
	if (choice == 72)
		if (menu != 1)
			LanguageScreen2(menu - 1);
		else
			LanguageScreen2(nav.size());
	if (choice == 80)
		if (menu != nav.size())
			LanguageScreen2(menu + 1);
		else
			LanguageScreen2(1);
	if (choice == 13 || choice == 32) {
		if (menu == 1) {
			Lang::setLangFile(Lang::ln1);

			DemonstrationScreen(1);
		}
		if (menu == 2) {
			Lang::setLangFile(Lang::ln2);

			DemonstrationScreen(1);
		}
	}
	else {
		LanguageScreen2(1);
	}
}

//���� ��������� �����
void Screens::LanguageScreen3(int menu) {
	system("title �������� ������. ������� 13. ������� ����./Course work. Variant 13. Change language.");
	system("cls");
	system("mode con lines=10");

	map <int, string> nav;
	nav[0] = "�������";
	nav[1] = "english";
	renderMenu(nav, menu);

	int choice = _getch();
	if (choice == 224)
		choice = _getch();
	if (choice == 72)
		if (menu != 1)
			LanguageScreen3(menu - 1);
		else
			LanguageScreen3(nav.size());
	if (choice == 80)
		if (menu != nav.size())
			LanguageScreen3(menu + 1);
		else
			LanguageScreen3(1);
	if (choice == 13 || choice == 32) {
		if (menu == 1) {
			Lang::setLangFile(Lang::ln1);

			WorkScreen(1);
		}
		if (menu == 2) {
			Lang::setLangFile(Lang::ln2);

			WorkScreen(1);
		}
	}
	else {
		LanguageScreen3(1);
	}
}

//���� ��������� �����
void Screens::LanguageScreen4(int menu) {
	system("title �������� ������. ������� 13. ������� ����./Course work. Variant 13. Change language.");
	system("cls");
	system("mode con lines=10");

	map <int, string> nav;
	nav[0] = "�������";
	nav[1] = "english";
	renderMenu(nav, menu);

	int choice = _getch();
	if (choice == 224)
		choice = _getch();
	if (choice == 72)
		if (menu != 1)
			LanguageScreen4(menu - 1);
		else
			LanguageScreen4(nav.size());
	if (choice == 80)
		if (menu != nav.size())
			LanguageScreen4(menu + 1);
		else
			LanguageScreen4(1);
	if (choice == 13 || choice == 32) {
		if (menu == 1) {
			Lang::setLangFile(Lang::ln1);

			ManagerScreen(1);
		}
		if (menu == 2) {
			Lang::setLangFile(Lang::ln2);

			ManagerScreen(1);
		}
	}
	else {
		LanguageScreen4(1);
	}
}

//���� ��������� �����
void Screens::LanguageScreen5(int menu) {
	system("title �������� ������. ������� 13. ������� ����./Course work. Variant 13. Change language.");
	system("cls");
	system("mode con lines=10");

	map <int, string> nav;
	nav[0] = "�������";
	nav[1] = "english";
	renderMenu(nav, menu);

	int choice = _getch();
	if (choice == 224)
		choice = _getch();
	if (choice == 72)
		if (menu != 1)
			LanguageScreen5(menu - 1);
		else
			LanguageScreen5(nav.size());
	if (choice == 80)
		if (menu != nav.size())
			LanguageScreen5(menu + 1);
		else
			LanguageScreen5(1);
	if (choice == 13 || choice == 32) {
		if (menu == 1) {
			Lang::setLangFile(Lang::ln1);

			HelpScreen(1);
		}
		if (menu == 2) {
			Lang::setLangFile(Lang::ln2);

			HelpScreen(1);
		}
	}
	else {
		LanguageScreen5(1);
	}
}

//������� �����
void Screens::MainScreen(int menu) {
	system("title �������� ������. ������� 13.��a���� ����/Course work. Variant 13. Main menu.");
	system("CLS");
	system("mode con lines=30");


	cout << endl;
	cout << "                " << Lang::lang[4] << endl;
	cout << "                " << Lang::lang[5] << endl;
	cout << "                " << Lang::lang[6] << endl;
	cout << "                " << Lang::lang[7] << endl;
	cout << "                " << Lang::lang[8] << endl;
	cout << "                " << Lang::lang[9] << endl;
	cout << endl;
	cout << "                " << Lang::lang[10] << endl;
	cout << "                    " << Lang::lang[11] << endl;
	cout << "                    " << Lang::lang[12] << endl;
	cout << endl;
	cout << "                " << Lang::lang[13] << endl;

	map <int, string> nav;
	nav[0] = Lang::lang[104];
	nav[1] = Lang::lang[16];
	nav[2] = Lang::lang[2];				//������������ ���� �� ����� �����������
	nav[3] = Lang::lang[3];
	renderMenu(nav, menu);

	int choice = _getch();
	if (choice == 224)
		choice = _getch();
	if (choice == 72)
		if (menu != 1)
			MainScreen(menu - 1);
		else
			MainScreen(nav.size());
	if (choice == 80)
		if (menu != nav.size())
			MainScreen(menu + 1);
		else
			MainScreen(1);
	if (choice == 13 || choice == 32) {
		switch (menu) {
		case 1: DemonstrationScreen(1); break;		//������� � ������
		case 2: HelpScreen(1); break;				//���� ������
		case 3: LanguageScreen1(1); break;			//������� ����
		case 4: _exit(0); break;					//�����
		}
	}
	else {
		MainScreen(1);								//������� ����� ������ �������� � ������������ �������� ������ 
	}
}

//������� �����
void Screens::DemonstrationScreen(int menu) {
	system("title �������� ������. ������� 13. ���� ����������./Course work. Variant 13. Add menu.");
	system("CLS");
	system("mode con lines=30");

	map <int, string> nav;
	nav[0] = Lang::lang[17];			
	nav[1] = Lang::lang[18];
	nav[2] = Lang::lang[45];						//������������ ���� �� ����� �����������
	nav[3] = Lang::lang[2];
	nav[4] = Lang::lang[14];
	nav[5] = Lang::lang[3];										

	renderMenu(nav, menu);

	int choice = _getch();
	if (choice == 224)
		choice = _getch();
	if (choice == 72)
		if (menu != 1)
			DemonstrationScreen(menu - 1);
		else
			DemonstrationScreen(nav.size());
	if (choice == 80)
		if (menu != nav.size())
			DemonstrationScreen(menu + 1);
		else
			DemonstrationScreen(1);
	if (choice == 13 || choice == 32) {
		if (menu == 1) {
			ListScreen(1);				//�������� ������ ���. ���������
		}
		if (menu == 2) {
			WorkScreen(1);				//���� ����������
		}
		if (menu == 3) {
			ManagerScreen(1);			//���� ����������
		}
		if (menu == 4) {
			LanguageScreen2(1);			//������� ����
		}
		if (menu == 5) {
			MainScreen(1);				//��������� � �������� ������
		}
		if (menu == 6) {
			_exit(0);					//�����
		}
	}
	else {
		DemonstrationScreen(1);
	}
}

//�������� ������ ��. ���������
void Screens::ListScreen(int menu) {
	system("title �������� ������. ������� 13. ������ ����������� ���������./Course work. Variant 13. List.");
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, false };
	SetConsoleCursorInfo(hCons, &cursor);

	system("CLS");
	system("mode con lines=30 cols=100");
	cout << "----------------------"
		<< Lang::lang[134]
		<< "-----------------------" << endl;
	for (int i = 0; i < Flies::devices.size(); i++) {

		cout << "\n" << "[" << i << "] - " << Flies::devices[i]->GetName();		//���������� ������ ��������� � ������� �� ����������
	}

	if (Flies::devices.size() == 0) {
		cout << endl << Lang::lang[28] << "\n";
		system("pause");
		DemonstrationScreen(1);
	}
	else {

		HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO cursor = { 1, true };
		SetConsoleCursorInfo(hCons, &cursor);
		cout << endl << endl << "�������� ����������� �������:/Choose the device" << " ";
		int key = getInt();

		if (key >= (Flies::devices.size())) {
			cout << "no";
		}
		else {
			EditScreen(1, key);
		}
	}

	map <int, string> nav;
	nav[0] = Lang::lang[14];
	renderMenu(nav, menu);

	int choice = _getch();
	if (choice == 224)
		choice = _getch();
	if (choice == 13 || choice == 32) {
		if (menu != nav.size())
			DemonstrationScreen(menu + 1);
		else
			DemonstrationScreen(1);
		_exit(0);
	}
	else {
		ListScreen(1);
	}
	
}

//���� ����������
void Screens::WorkScreen(int menu) {
	system("CLS");
	system("mode con lines=30");

	map <int, string> nav;
	nav[0] = Lang::lang[20];
	nav[1] = Lang::lang[21];
	nav[2] = Lang::lang[23];
	nav[3] = Lang::lang[24];
	nav[4] = Lang::lang[25];				//������������ ���� �� ����� �����������
	nav[5] = Lang::lang[22];
	nav[6] = Lang::lang[2];
	nav[7] = Lang::lang[14];
	nav[8] = Lang::lang[3];

	renderMenu(nav, menu);

	int choice = _getch();
	if (choice == 224)
		choice = _getch();
	if (choice == 72)
		if (menu != 1)
			WorkScreen(menu - 1);
		else
			WorkScreen(nav.size());
	if (choice == 80)
		if (menu != nav.size())
			WorkScreen(menu + 1);
		else
			WorkScreen(1);
	if (choice == 13 || choice == 32) {
		if (menu == 1) {
			FlyScreen(1);				//�������� ������ Fly
		}
		if (menu == 2) {
			HelicopterScreen(1);		//�������� ������ Helicopter
		}
		if (menu == 3) {
			BomberScreen(1);			//�������� ������ Bomber
		}
		if (menu == 4) {
			PlainScreen(1);				//�������� ������ Plain
		}
		if (menu == 5) {
			transportAircraftScreen(1);	//�������� ������ TransportAircraft
		}
		if (menu == 6) {
			
			JetfighterScreen(1);		//�������� ������ Jetfighter
		}
		if (menu == 7) {
			LanguageScreen3(1);			//������� ����
			
		}
		if (menu == 8) {
			DemonstrationScreen(1);		//��������� � ����. ����
		}
		if (menu == 9) {
			_exit(0);					//�����
		}
	}
	else {
		WorkScreen(1);
	}
}

//���������� ������� Fly
void Screens::FlyScreen(int menu) {
	system("title �������� ������. ������� 13. �������� ������ ����/Course work. Variant 13. Add Fly.");
	system("cls");
	system("mode con cols=100 lines=30");
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, true };
	SetConsoleCursorInfo(hCons, &cursor);

	//������� ������ ��� ������ ������������ ��� ����������
	Fly *e = new Fly();
	//�������� set ������ ��� ���� �����
	cout << Lang::lang[34] << endl;
	e->SetSpeed();
	cout << Lang::lang[35] << endl;
	e->SetHeight();
	cout << Lang::lang[36] << endl;
	e->SetDistance();
	cout << Lang::lang[37] << endl;
	e->SetNumOfPass();

	e->id = Flies::AddFly(e);		//��������� ������ � ������
	e->print();						//������� ����������
	BackScreen(1);
}

//���������� ������� helicopter
void Screens::HelicopterScreen(int menu) {
	system("title �������� ������. ������� 13. �������� ������ �������/Course work. Variant 13. Add helicopter.");
	system("cls");
	system("mode con cols=100 lines=30");
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, true };
	SetConsoleCursorInfo(hCons, &cursor);
	//������� ������ ��� ������ ������������ ��� ����������
	helicopter *h = new helicopter();
	//�������� set ������ ��� ���� �����
	cout << Lang::lang[34] << endl;
	h->SetSpeed();
	cout << Lang::lang[35] << endl;
	h->SetHeight();
	cout << Lang::lang[36] << endl;
	h->SetDistance();
	cout << Lang::lang[37] << endl;
	h->SetNumOfPass();
	cout << Lang::lang[38] << endl;
	h->SetNumOfScrew();
	cout << Lang::lang[39] << endl;
	h->SetCapacity();

	h->id = Flies::AddFly(h);			//��������� ������ � ������
	h->print();							//������� ����������
	BackScreen(1);
}

//���������� ������� jetfighter
void Screens::JetfighterScreen(int menu) {
	system("title �������� ������. ������� 13. �������� ������ �����������/Course work. Variant 13. Add jetfighter.");
	system("cls");
	system("mode con cols=100 lines=30");
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, true };
	SetConsoleCursorInfo(hCons, &cursor);
	//������� ������ ��� ������ ������������ ��� ����������
	jetfighter *j = new jetfighter();
	//�������� set ������ ��� ���� �����
	cout << Lang::lang[34] << endl;
	j->SetSpeed();
	cout << Lang::lang[35] << endl;
	j->SetHeight();
	cout << Lang::lang[36] << endl;
	j->SetDistance();
	cout << Lang::lang[40] << endl;
	j->setType();
	cout << Lang::lang[43] << endl;
	j->setCountry();
	cout << Lang::lang[41] << endl;
	j->setGuns();

	j->id = Flies::AddFly(j);		//��������� ������ � ������
	j->print();						//������� ����������
	BackScreen(1);
	
}
//���������� ������� bomber
void Screens::BomberScreen(int menu) {
	system("title �������� ������. ������� 13. �������� ������ ��������������/Course work. Variant 13. Add bomber.");
	system("cls");
	system("mode con cols=100 lines=30");
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, true };
	SetConsoleCursorInfo(hCons, &cursor);
	//������� ������ ��� ������ ������������ ��� ����������
	bomber *b = new bomber();
	//�������� set ������ ��� ���� �����
	cout << Lang::lang[34] << endl;
	b->SetSpeed();
	cout << Lang::lang[35] << endl;
	b->SetHeight();
	cout << Lang::lang[36] << endl;
	b->SetDistance();
	cout << Lang::lang[37] << endl;
	b->SetNumOfPass();
	cout << Lang::lang[42] << endl;
	b->setFradius();
	cout << Lang::lang[44] << endl;
	b->setFmass();
	cout << Lang::lang[57] << endl;
	b->setPtime();

	b->id = Flies::AddFly(b);			//��������� ������ � ������
	b->print();							//������� ����������
	BackScreen(1);
	
}

//���������� ������� transportAircraft
void Screens::transportAircraftScreen(int menu) {
	system("title �������� ������. ������� 13. �������� ������ ������������ ������/Course work. Variant 13. Add transport aircraft.");
	system("cls");
	system("mode con cols=100 lines=30");
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, true };
	SetConsoleCursorInfo(hCons, &cursor);
	//������� ������ ��� ������ ������������ ��� ����������
	transportAircraft *t = new transportAircraft();
	//�������� set ������ ��� ���� �����
	cout << Lang::lang[34] << endl;
	t->SetSpeed();
	cout << Lang::lang[35] << endl;
	t->SetHeight();
	cout << Lang::lang[36] << endl;
	t->SetDistance();
	cout << Lang::lang[37] << endl;
	t->SetNumOfPass();
	cout << Lang::lang[137] << endl;
	t->setPrefix();
	cout << Lang::lang[138] << endl;
	t->setCarrying();
	
	t->id = Flies::AddFly(t);				//��������� ������ � ������
	t->print();								//������� ����������
	BackScreen(1);
	
}

//���������� ������� plain
void Screens::PlainScreen(int menu) {
	system("title �������� ������. ������� 13. �������� ������ ������������ ������/Course work. Variant 13. Add plain.");
	system("cls");
	system("mode con cols=100 lines=30");
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, true };
	SetConsoleCursorInfo(hCons, &cursor);
	//������� ������ ��� ������ ������������ ��� ����������
	plain *p = new plain();
	//�������� set ������ ��� ���� �����
	cout << Lang::lang[34] << endl;
	p->SetSpeed();
	cout << Lang::lang[35] << endl;
	p->SetHeight();
	cout << Lang::lang[36] << endl;
	p->SetDistance();
	cout << Lang::lang[37] << endl;
	p->SetNumOfPass();
	cout << Lang::lang[141] << endl;
	p->setAge();
	cout << Lang::lang[140] << endl;
	p->setCrew();
	cout << Lang::lang[139] << endl;
	p->setEngines();
	cout << Lang::lang[142] << endl;
	p->setModel();

	p->id = Flies::AddFly(p);				//��������� ������ � ������
	p->print();								//������� ����������
	BackScreen(1);
}

//������� � ����������� ����
void Screens::BackScreen(int menu) {
	map <int, string> nav;
	nav[0] = Lang::lang[14];
	renderMenu(nav, menu);

	int choice = _getch();
	if (choice == 224) {
		choice = _getch();
	}
	if (choice == 13 || choice == 32) {
		HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO cursor = { 1, false };
		SetConsoleCursorInfo(hCons, &cursor);
		system("mode con cols=70 lines=30");
		WorkScreen(1);							//������ ������� ������ � ������������� �� ������� �����
	}
	else {
		system("mode con cols=70 lines=30");
		WorkScreen(1);
	}
}

//����� ���������� ���������
void Screens::ManagerScreen(int menu) {
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, false };
	SetConsoleCursorInfo(hCons, &cursor);
	system("title �������� ������. ������� 13.����� ����������/Course work. Variant 13. Manage menu.");
	system("CLS");
	system("mode con lines=30 cols=80");

	map <int, string> nav;
	nav[0] = Lang::lang[46];
	nav[1] = Lang::lang[47];
	nav[2] = Lang::lang[2];
	nav[3] = Lang::lang[102];			//������������ ���� �� ����� �����������
	nav[4] = Lang::lang[136];
	nav[5] = Lang::lang[14];
	nav[6] = Lang::lang[3];

	renderMenu(nav, menu);

	int choice = _getch();
	if (choice == 224)
		choice = _getch();
	if (choice == 72)
		if (menu != 1)
			ManagerScreen(menu - 1);
		else
			ManagerScreen(nav.size());
	if (choice == 80)
		if (menu != nav.size())
			ManagerScreen(menu + 1);
		else
			ManagerScreen(1);
	if (choice == 13 || choice == 32) {
		if (menu == 1) {
			system("cls");
			int a = Flies::devices.size();
			cout << Lang::lang[30] << a << endl;					//������� ����� ���������� �������� � ���������
			cout << "---" << Lang::lang[48] << "---" << "\n";		//�������� ������� ������ ��������
			cout << Lang::lang[49] << Flies::counts[1] << endl;
			cout << Lang::lang[50] << Flies::counts[2] << endl;
			cout << Lang::lang[51] << Flies::counts[3] << endl;
			cout << Lang::lang[52] << Flies::counts[4] << endl;
			cout << Lang::lang[143] << Flies::counts[5] << endl;
			cout << Lang::lang[53] << Flies::counts[6] << endl;
			system("pause");
			ManagerScreen(1);
		}
		if (menu == 2) {				//�������� ������ ��������
			system("cls");
			Flies::DeleteAllFlies();
			cout << Lang::lang[26] << endl;
			system("pause");
			ManagerScreen(1);
		}
		if (menu == 3) {				//������� ����
			LanguageScreen4(1);
		}
		if (menu == 6) {				//��������� � ���������� ����
			DemonstrationScreen(1);
		}
		if (menu == 7) {				//�����
			_exit(0);
		}
		if (menu == 4) {				//��������� ��������� �������
			system("cls");
			FCache::saveCache();
			cout << Lang::lang[72] << endl;
			system("pause");
			ManagerScreen(1);
		}
		if (menu == 5) {				//��������� ������� �� �����
			system("cls");
			FCache::getCache();
			cout << Lang::lang[163] << endl;
			system("pause");
			ManagerScreen(1);
		}
	}
	else {
		ManagerScreen(1);
	}
		
}

//����� ��������� � ��������������
void Screens::EditScreen(int menu, int device) {
	system("title �������� ������. ������� 13. �������������/Course work. Variant 13. Edit menu.");
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, false };
	SetConsoleCursorInfo(hCons, &cursor);
	system("cls");
	map <int, string> nav;
	nav[0] = Lang::lang[58];
	nav[1] = Lang::lang[59];
	nav[2] = Lang::lang[60];
	nav[3] = Lang::lang[14];

	renderMenu(nav, menu);


	int choice = _getch();
	if (choice == 224)
		choice = _getch();
	if (choice == 72) {
		if (menu != 1) {
			EditScreen((menu - 1), device);
		}
		else {
			EditScreen(nav.size(), device);
		}
	}
	if (choice == 80) {
		if (menu != nav.size()) {
			EditScreen((menu + 1), device);
		}
		else {
			EditScreen(1, device);
		}
	}
	if (choice == 13 || choice == 32) {
		if (menu == 2) {
			Flies::devices[device]->Edit();			//�������� ����� �������������� ������������ �������� �������
			Flies::devices[device]->print();		//������� ����� ������
			system("pause");
			EditScreen(1, device);
		}

		if (menu == 3) {							//������� ������� ������
			if (Flies::devices.size() != 0) {
				delete Flies::devices[device];

				system("cls");
				cout << Lang::lang[72] << endl;
				system("pause");
				EditScreen(1, device);
			}
			else {
				system("cls");
				cout << Lang::lang[28] << endl;
				system("pause");
				EditScreen(1, device);
			}
		}

		if (menu == 1) {						//������� ������ �� �������
			system("cls");
			system("mode con cols=166");
			Flies::devices[device]->print();
			system("pause");
			EditScreen(1, device);
		}

		if (menu == 4) {						//��������� � ����. ����
			DemonstrationScreen(1);
		}

		else {
			EditScreen(1, device);
		}
	}
	
}

//���� ������
void Screens::HelpScreen(int menu) {
	system("title �������� ������. ������� 13.������/Course work. Variant 13. Help.");
	system("CLS");
	system("mode con lines=20 ");

	map <int, string> nav;
	nav[0] = Lang::lang[105];
	nav[1] = Lang::lang[106];
	nav[2] = Lang::lang[107];			//������������ ���� �� ������ ����� �����������
	nav[3] = Lang::lang[2];
	nav[4] = Lang::lang[14];

	renderMenu(nav, menu);

	int choice = _getch();
	if (choice == 224)
		choice = _getch();
	if (choice == 72)
		if (menu != 1)
			HelpScreen(menu - 1);
		else
			HelpScreen(nav.size());
	if (choice == 80)
		if (menu != nav.size())
			HelpScreen(menu + 1);
		else
			HelpScreen(1);
	if (choice == 13 || choice == 32) {
		if (menu == 1) {							//������� ����� ����� "� ���������"
			system("cls");
			for (int i = 108;i<115;i++) {
				cout << Lang::lang[i] << endl;
			}
			system("pause");
			HelpScreen(1);
		}
		if (menu == 2) {
			system("cls");
			for (int k = 116;k<120;k++) {			//����� ������ ����� "�� ������"
				cout << Lang::lang[k] << endl;
			}
			system("pause");
			HelpScreen(1);
		}
		if (menu == 3) {
			system("cls");
			for (int l = 121;l<132;l++) {			//����� ������ ����� "����������� ���������"
				cout << Lang::lang[l] << endl;
			}
			system("pause");
			HelpScreen(1);
		}
		if (menu == 4) {
			LanguageScreen5(1);
		}
		if (menu == 5) {
			MainScreen(1);
		}
	}
	else {
		HelpScreen(1);
	}
}
