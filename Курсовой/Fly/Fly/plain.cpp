#include "stdafx.h"
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "windows.h"
#include "fly.h"
#include "plain.h"
#include "lang.h"
#include "getvalues.h"
#include "screen.h"

using namespace std;

//Конструкторы
plain::plain() {
	cl = 5;
	name = "Plain";
}

plain::plain(int S, int Dis, int Num, int H, int cr, int eng, int a, int m) {
	speed = S;
	height = H;
	distance = Dis;
	numOfPass = Num;
	crew = cr;
	engines = eng;
	age = a;
	model = m;

	cl = 5;
	name = "Plain";
}

//Деструктор
plain::~plain() {

}

//Get методы класса
int plain::getAge() {
	return age;
}

int plain::getCrew() {
	return crew;
}

int plain::getModel() {
	return model;
}

int plain::getEngines() {
	return engines;
}

//метод установки срока эксплуатации самолета
int plain::setAge() {
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, true };
	SetConsoleCursorInfo(hCons, &cursor);

	int a = getInt();
	do {
		if (a < 0 || a > 15)
		{
			cerr << Lang::lang[31];
			a = getInt();
		}
		else
		{
			age = a;
			return 1;
		}
	} while (true);

}

//метод установки количества двигателей
int plain::setEngines() {
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, true };
	SetConsoleCursorInfo(hCons, &cursor);

	int en = getInt();
	do {
		if (en < 2 || en > 8)
		{
			cerr << Lang::lang[31];
			en = getInt();
		}
		else
		{
			engines = en;
			return 1;
		}
	} while (true);

}

//метод установки модели самолета
int plain::setModel() {
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, true };
	SetConsoleCursorInfo(hCons, &cursor);

	int mod = getInt();
	do {
		if (mod < 100 || mod>999)
		{
			cerr << Lang::lang[31];
			mod = getInt();
		}
		else
		{
			model = mod;
			return 1;
		}
	} while (true);

}

//метод установки численности экипажа
int plain::setCrew() {
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, true };
	SetConsoleCursorInfo(hCons, &cursor);

	int cr = getInt();
	do {
		if (cr < 2 || cr>15)
		{
			cerr << Lang::lang[31];
			cr = getInt();
		}
		else
		{
			crew = cr;
			return 1;
		}
	} while (true);
}

//метод установки дальности полета	
int plain::SetDistance() {
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, true };
	SetConsoleCursorInfo(hCons, &cursor);

	int dist = getInt();
	do {
		if (dist < 1 || dist>maxdist)  //сравниваем с максимальной дальностью полета для данного класса
		{
			cerr << Lang::lang[31];
			dist = getInt();
		}
		else
		{
			distance = dist;
			return 1;
		}
	} while (true);

}
//метод установки скорости
int plain::SetSpeed() {
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, true };
	SetConsoleCursorInfo(hCons, &cursor);

	int spd = getInt();
	do {
		if (spd < 40 || spd>maxspeed)	//сравниваем с максимальной скоростью полета для данного класса
		{
			cerr << Lang::lang[31];
			spd = getInt();
		}
		else
		{
			speed = spd;
			return 1;
		}
	} while (true);

}
//метод установки колчества пассажиров
int plain::SetNumOfPass() {
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, true };
	SetConsoleCursorInfo(hCons, &cursor);

	int num = getInt();
	do {
		if (num < 0 || num>maxpass)		//сравниваем с максимальным колчиеством пассажиров для данного класса
		{
			cerr << Lang::lang[31];
			num = getInt();
		}
		else
		{
			numOfPass = num;
			return 1;
		}
	} while (true);

}
//метод установки высоты полета
int plain::SetHeight() {
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, true };
	SetConsoleCursorInfo(hCons, &cursor);

	int hei = getInt();
	do {
		if (hei < 1000 || hei>maxheight)		//сравниваем с максимальной высотой полета для данного класса
		{
			cerr << Lang::lang[31];
			hei = getInt();
		}
		else
		{
			height = hei;
			return 1;
		}
	} while (true);
}


//перегруженный как дружестенный метод оператор ++ Новое действие - повышение срока эксплуатации самолета
plain& operator++(plain& t)
{
	if (t.age == 14)
	{
		cout << Lang::lang[71] << "\n" << endl;
		return t;
	}
	else
	{
		++t.age;
		cout << Lang::lang[72] << "\n" << endl;
		return t;
	}
}

//метод вывода данных об объекте
void plain::print() {
	system("mode con cols=166");
	cout << setiosflags(ios::left);
	cout << setw(15);
	cout << Lang::lang[86];
	cout << setw(20);
	cout << Lang::lang[87];
	cout << setw(30);
	cout << Lang::lang[88];
	cout << setw(15);
	cout << Lang::lang[89];
	cout << setw(25);
	cout << Lang::lang[101];
	cout << setw(25);
	cout << Lang::lang[144];
	cout << setw(18);
	cout << Lang::lang[145];
	cout << setw(18);
	cout << Lang::lang[146];

	cout.width(15);
	cout << GetSpeed();
	cout << setw(20);
	cout << GetDistance();
	cout << setw(30);
	cout << GetNumOfPass();
	cout << setw(15);
	cout << GetHeight();
	cout << setw(25);
	cout << getCrew();
	cout << setw(25);
	cout << getEngines();
	cout << setw(18);
	cout << getAge();
	cout << setw(18);
	cout << getModel();
}

//метод редактирования данных об объекте
void plain::Edit() {
	system("cls");
	bool fl = false;
	cout << Lang::lang[62] << endl;
	cout << Lang::lang[63] << endl;
	cout << Lang::lang[64] << endl;
	cout << Lang::lang[65] << endl;
	cout << Lang::lang[157] << endl;
	cout << Lang::lang[158] << endl;
	cout << Lang::lang[159] << endl;
	cout << Lang::lang[160] << endl;
	cout << Lang::lang[161] << endl;
	cout << Lang::lang[68] << endl;
	int k = getInt();
	do {
		if (k < 1 || k>9)
		{
			cerr << Lang::lang[31];
			k = getInt();
		}
		else
		{
			fl = true;
		}
	} while (fl != true);

	system("cls");
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, true };
	SetConsoleCursorInfo(hCons, &cursor);
	cout << Lang::lang[98] << endl;
	switch (k) {
		//в зависимости от выбора пользователя вызываем необходимый Set метод
	case 1:
		SetSpeed();
		break;
	case 2:
		SetDistance();
		break;
	case 3:
		SetHeight();
		break;
	case 4:
		SetNumOfPass();
		break;
	case 5:
		setAge();
		break;
	case 6:
		setCrew();
		break;
	case 7:
		setEngines();
		break;
	case 8:
		setModel();
		break;
	case 9:
		operator++(*this);
		break;
	}

}


