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
#include "transportAircraft.h"
#include "lang.h"
#include "getvalues.h"
#include "screen.h"

using namespace std;
//Конструкторы
transportAircraft::transportAircraft() {
	cl = 6;
	name = "TransportAircraft";
	numOfPass = 0;
}

transportAircraft::transportAircraft(int S, int Dis, int Num, int H, int car, string pre){
	speed = S;
	height = H;
	distance = Dis;
	carrying = car;
	prefix = pre;
	numOfPass = 0;
	cl = 6;
	name = "TransportAircraft";
}

//Деструктор
transportAircraft::~transportAircraft() {

}

//Get методы класса
int transportAircraft::getCarrying() {
	return carrying;
}

string transportAircraft::getPrefix() {
	return prefix;
}

//метод установки грузоподъемности
int transportAircraft::setCarrying() {
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, true };
	SetConsoleCursorInfo(hCons, &cursor);

	int c = getInt();
	do {
		if (c < 5 || c > 450)
		{
			cerr << Lang::lang[31];
			c = getInt();
		}
		else
		{
			carrying = c;
			return 1;
		}
	} while (true);

}

//метод установки дальности полета	
int transportAircraft::SetDistance() {
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
int transportAircraft::SetSpeed() {
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
int transportAircraft::SetNumOfPass() {
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
int transportAircraft::SetHeight() {
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

//метод установки префикса названия
int transportAircraft::setPrefix() {
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, true };
	SetConsoleCursorInfo(hCons, &cursor);
	do {
		string pre = getstr();
		int lena = pre.length();
		if ((lena <= 0) || (lena >2))
		{
			cerr << Lang::lang[31];
		}
		else
		{
			prefix = pre;
			return 1;
		}
	} while (true);
}

//метод вывода данных об объекте
void transportAircraft::print() {
	system("mode con cols=140");
	cout << setiosflags(ios::left);
	cout << setw(30);
	cout << Lang::lang[86];
	cout << setw(20);
	cout << Lang::lang[87];
	cout << setw(30);
	cout << Lang::lang[88];
	cout << setw(20);
	cout << Lang::lang[89];
	cout << setw(20);
	cout << Lang::lang[100];
	cout << setw(20);
	cout << Lang::lang[99];

	cout.width(30);
	cout << GetSpeed();
	cout << setw(20);
	cout << GetDistance();
	cout << setw(30);
	cout << GetNumOfPass();
	cout << setw(20);
	cout << GetHeight();
	cout << setw(20);
	cout << getPrefix();
	cout << setw(20);
	cout << getCarrying();
}

//метод редактирования данных
void transportAircraft::Edit() {
	system("cls");
	bool fl = false;
	cout << Lang::lang[62] << endl;
	cout << Lang::lang[63] << endl;
	cout << Lang::lang[64] << endl;
	cout << Lang::lang[65] << endl;
	cout << Lang::lang[162] << endl;
	cout << Lang::lang[135] << endl;
	cout << Lang::lang[68] << endl;
	int k = getInt();
	do {
		if (k < 1 || k>6)
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
		setCarrying();
		break;
	case 6:
		setPrefix();
		break;
	}


}