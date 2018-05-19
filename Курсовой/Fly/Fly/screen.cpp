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

//метод рендеринга меню
void Screens::renderMenu(map <int, string> menu, int action) {

	cout << "\n\n\n\n";
	for (int i = 0; i<menu.size(); i++) {
		if (i != 0) cout << "\n\n";
		cout << "                           ";
		(i + 1 == action) ? cout << "--" : cout << "  ";		//перемещаем т.н. указатель между пунктами 
		cout << "  " << menu[i] << "";
	}
	cout << "\n\n\n\n";
}

//меню изменения языка
void Screens::LanguageScreen1(int menu) {
	system("title Курсовая работа. Вариант 13. Сменить язык./Course work. Variant 13. Change language.");
	system("cls");
	system("mode con lines=10");

	map <int, string> nav;
	nav[0] = "русский";
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

//меню изменения языка
void Screens::LanguageScreen2(int menu) {
	system("title Курсовая работа. Вариант 13. Сменить язык./Course work. Variant 13. Change language.");
	system("cls");
	system("mode con lines=10");

	map <int, string> nav;
	nav[0] = "русский";
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

//меню изменения языка
void Screens::LanguageScreen3(int menu) {
	system("title Курсовая работа. Вариант 13. Сменить язык./Course work. Variant 13. Change language.");
	system("cls");
	system("mode con lines=10");

	map <int, string> nav;
	nav[0] = "русский";
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

//меню изменения языка
void Screens::LanguageScreen4(int menu) {
	system("title Курсовая работа. Вариант 13. Сменить язык./Course work. Variant 13. Change language.");
	system("cls");
	system("mode con lines=10");

	map <int, string> nav;
	nav[0] = "русский";
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

//меню изменения языка
void Screens::LanguageScreen5(int menu) {
	system("title Курсовая работа. Вариант 13. Сменить язык./Course work. Variant 13. Change language.");
	system("cls");
	system("mode con lines=10");

	map <int, string> nav;
	nav[0] = "русский";
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

//главный экран
void Screens::MainScreen(int menu) {
	system("title Курсовая работа. Вариант 13.Глaвное меню/Course work. Variant 13. Main menu.");
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
	nav[2] = Lang::lang[2];				//формирование меню из файла локализации
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
		case 1: DemonstrationScreen(1); break;		//переход к работе
		case 2: HelpScreen(1); break;				//меню помощи
		case 3: LanguageScreen1(1); break;			//сменить язык
		case 4: _exit(0); break;					//выход
		}
	}
	else {
		MainScreen(1);								//нажатие любых клавиш приводит к перезагрузке текущего экрана 
	}
}

//рабочий экран
void Screens::DemonstrationScreen(int menu) {
	system("title Курсовая работа. Вариант 13. Меню добавления./Course work. Variant 13. Add menu.");
	system("CLS");
	system("mode con lines=30");

	map <int, string> nav;
	nav[0] = Lang::lang[17];			
	nav[1] = Lang::lang[18];
	nav[2] = Lang::lang[45];						//формирование меню из файла локализации
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
			ListScreen(1);				//просмотр списка лет. аппаратов
		}
		if (menu == 2) {
			WorkScreen(1);				//меню добавления
		}
		if (menu == 3) {
			ManagerScreen(1);			//меню управления
		}
		if (menu == 4) {
			LanguageScreen2(1);			//сменить язык
		}
		if (menu == 5) {
			MainScreen(1);				//вернуться к главному экрану
		}
		if (menu == 6) {
			_exit(0);					//выход
		}
	}
	else {
		DemonstrationScreen(1);
	}
}

//просмотр списка ле. аппаратов
void Screens::ListScreen(int menu) {
	system("title Курсовая работа. Вариант 13. Список летательных аппаратов./Course work. Variant 13. List.");
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, false };
	SetConsoleCursorInfo(hCons, &cursor);

	system("CLS");
	system("mode con lines=30 cols=100");
	cout << "----------------------"
		<< Lang::lang[134]
		<< "-----------------------" << endl;
	for (int i = 0; i < Flies::devices.size(); i++) {

		cout << "\n" << "[" << i << "] - " << Flies::devices[i]->GetName();		//отображаем списко аппаратов в порядке их добавления
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
		cout << endl << endl << "Выберите летательный аппарат:/Choose the device" << " ";
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

//меню добавления
void Screens::WorkScreen(int menu) {
	system("CLS");
	system("mode con lines=30");

	map <int, string> nav;
	nav[0] = Lang::lang[20];
	nav[1] = Lang::lang[21];
	nav[2] = Lang::lang[23];
	nav[3] = Lang::lang[24];
	nav[4] = Lang::lang[25];				//формирование меню из файла локализации
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
			FlyScreen(1);				//добавить объект Fly
		}
		if (menu == 2) {
			HelicopterScreen(1);		//добавить объект Helicopter
		}
		if (menu == 3) {
			BomberScreen(1);			//добавить объект Bomber
		}
		if (menu == 4) {
			PlainScreen(1);				//добавить объект Plain
		}
		if (menu == 5) {
			transportAircraftScreen(1);	//добавить объект TransportAircraft
		}
		if (menu == 6) {
			
			JetfighterScreen(1);		//добавить объект Jetfighter
		}
		if (menu == 7) {
			LanguageScreen3(1);			//сменить язык
			
		}
		if (menu == 8) {
			DemonstrationScreen(1);		//вернуться в пред. меню
		}
		if (menu == 9) {
			_exit(0);					//выход
		}
	}
	else {
		WorkScreen(1);
	}
}

//добавления объекта Fly
void Screens::FlyScreen(int menu) {
	system("title Курсовая работа. Вариант 13. Добавить объект Полёт/Course work. Variant 13. Add Fly.");
	system("cls");
	system("mode con cols=100 lines=30");
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, true };
	SetConsoleCursorInfo(hCons, &cursor);

	//создаем объект при помощи конструктора без параметров
	Fly *e = new Fly();
	//вызываем set методы для всех полей
	cout << Lang::lang[34] << endl;
	e->SetSpeed();
	cout << Lang::lang[35] << endl;
	e->SetHeight();
	cout << Lang::lang[36] << endl;
	e->SetDistance();
	cout << Lang::lang[37] << endl;
	e->SetNumOfPass();

	e->id = Flies::AddFly(e);		//добавляем объект в вектор
	e->print();						//выводим информацию
	BackScreen(1);
}

//добавления объекта helicopter
void Screens::HelicopterScreen(int menu) {
	system("title Курсовая работа. Вариант 13. Добавить объект Вертолёт/Course work. Variant 13. Add helicopter.");
	system("cls");
	system("mode con cols=100 lines=30");
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, true };
	SetConsoleCursorInfo(hCons, &cursor);
	//создаем объект при помощи конструктора без параметров
	helicopter *h = new helicopter();
	//вызываем set методы для всех полей
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

	h->id = Flies::AddFly(h);			//добавляем объект в вектор
	h->print();							//выводим информацию
	BackScreen(1);
}

//добавления объекта jetfighter
void Screens::JetfighterScreen(int menu) {
	system("title Курсовая работа. Вариант 13. Добавить объект Истребитель/Course work. Variant 13. Add jetfighter.");
	system("cls");
	system("mode con cols=100 lines=30");
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, true };
	SetConsoleCursorInfo(hCons, &cursor);
	//создаем объект при помощи конструктора без параметров
	jetfighter *j = new jetfighter();
	//вызываем set методы для всех полей
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

	j->id = Flies::AddFly(j);		//добавляем объект в вектор
	j->print();						//выводим информацию
	BackScreen(1);
	
}
//добавление объекта bomber
void Screens::BomberScreen(int menu) {
	system("title Курсовая работа. Вариант 13. Добавить объект Бомбардировщик/Course work. Variant 13. Add bomber.");
	system("cls");
	system("mode con cols=100 lines=30");
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, true };
	SetConsoleCursorInfo(hCons, &cursor);
	//создаем объект при помощи конструктора без параметров
	bomber *b = new bomber();
	//вызываем set методы для всех полей
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

	b->id = Flies::AddFly(b);			//добавляем объект в вектор
	b->print();							//выводим информацию
	BackScreen(1);
	
}

//добавление объекта transportAircraft
void Screens::transportAircraftScreen(int menu) {
	system("title Курсовая работа. Вариант 13. Добавить объект Транспортный самолёт/Course work. Variant 13. Add transport aircraft.");
	system("cls");
	system("mode con cols=100 lines=30");
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, true };
	SetConsoleCursorInfo(hCons, &cursor);
	//создаем объект при помощи конструктора без параметров
	transportAircraft *t = new transportAircraft();
	//вызываем set методы для всех полей
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
	
	t->id = Flies::AddFly(t);				//добавляем объект в вектор
	t->print();								//выводим информацию
	BackScreen(1);
	
}

//Добавление объекта plain
void Screens::PlainScreen(int menu) {
	system("title Курсовая работа. Вариант 13. Добавить объект Пассажирский самолёт/Course work. Variant 13. Add plain.");
	system("cls");
	system("mode con cols=100 lines=30");
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, true };
	SetConsoleCursorInfo(hCons, &cursor);
	//создаем объект при помощи конструктора без параметров
	plain *p = new plain();
	//вызываем set методы для всех полей
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

	p->id = Flies::AddFly(p);				//добавляем объект в вектор
	p->print();								//выводим информацию
	BackScreen(1);
}

//возврат к предыдущему меню
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
		WorkScreen(1);							//меняем размеры экрана и переключаемся на рабочий экран
	}
	else {
		system("mode con cols=70 lines=30");
		WorkScreen(1);
	}
}

//экран управления объектами
void Screens::ManagerScreen(int menu) {
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, false };
	SetConsoleCursorInfo(hCons, &cursor);
	system("title Курсовая работа. Вариант 13.Режим управления/Course work. Variant 13. Manage menu.");
	system("CLS");
	system("mode con lines=30 cols=80");

	map <int, string> nav;
	nav[0] = Lang::lang[46];
	nav[1] = Lang::lang[47];
	nav[2] = Lang::lang[2];
	nav[3] = Lang::lang[102];			//формирование меню из файла локализации
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
			cout << Lang::lang[30] << a << endl;					//выводим общее колчиество объектов и колчиство
			cout << "---" << Lang::lang[48] << "---" << "\n";		//объектов каждого класса отдельно
			cout << Lang::lang[49] << Flies::counts[1] << endl;
			cout << Lang::lang[50] << Flies::counts[2] << endl;
			cout << Lang::lang[51] << Flies::counts[3] << endl;
			cout << Lang::lang[52] << Flies::counts[4] << endl;
			cout << Lang::lang[143] << Flies::counts[5] << endl;
			cout << Lang::lang[53] << Flies::counts[6] << endl;
			system("pause");
			ManagerScreen(1);
		}
		if (menu == 2) {				//очистить список объектов
			system("cls");
			Flies::DeleteAllFlies();
			cout << Lang::lang[26] << endl;
			system("pause");
			ManagerScreen(1);
		}
		if (menu == 3) {				//сменить язык
			LanguageScreen4(1);
		}
		if (menu == 6) {				//вернуться в предыдущее меню
			DemonstrationScreen(1);
		}
		if (menu == 7) {				//выход
			_exit(0);
		}
		if (menu == 4) {				//сохранить состояние системы
			system("cls");
			FCache::saveCache();
			cout << Lang::lang[72] << endl;
			system("pause");
			ManagerScreen(1);
		}
		if (menu == 5) {				//загрузить объекты из файла
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

//экран просмотра и редактирования
void Screens::EditScreen(int menu, int device) {
	system("title Курсовая работа. Вариант 13. Редактировать/Course work. Variant 13. Edit menu.");
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
			Flies::devices[device]->Edit();			//вызываем метод редактирования относительно текущего объекта
			Flies::devices[device]->print();		//выводим новые данные
			system("pause");
			EditScreen(1, device);
		}

		if (menu == 3) {							//удалить текущий объект
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

		if (menu == 1) {						//вывести данные об объекте
			system("cls");
			system("mode con cols=166");
			Flies::devices[device]->print();
			system("pause");
			EditScreen(1, device);
		}

		if (menu == 4) {						//вернуться в пред. меню
			DemonstrationScreen(1);
		}

		else {
			EditScreen(1, device);
		}
	}
	
}

//меню помощи
void Screens::HelpScreen(int menu) {
	system("title Курсовая работа. Вариант 13.Помощь/Course work. Variant 13. Help.");
	system("CLS");
	system("mode con lines=20 ");

	map <int, string> nav;
	nav[0] = Lang::lang[105];
	nav[1] = Lang::lang[106];
	nav[2] = Lang::lang[107];			//формирование меню на основе файла локализации
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
		if (menu == 1) {							//выводим текст файла "О программе"
			system("cls");
			for (int i = 108;i<115;i++) {
				cout << Lang::lang[i] << endl;
			}
			system("pause");
			HelpScreen(1);
		}
		if (menu == 2) {
			system("cls");
			for (int k = 116;k<120;k++) {			//вывод текста файла "Об авторе"
				cout << Lang::lang[k] << endl;
			}
			system("pause");
			HelpScreen(1);
		}
		if (menu == 3) {
			system("cls");
			for (int l = 121;l<132;l++) {			//вывод текста файла "Руководство оператора"
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
