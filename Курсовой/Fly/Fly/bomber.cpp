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
#include "bomber.h"
#include "lang.h"
#include "getvalues.h"
#include "screen.h"

using namespace std;

//Конструкторы
bomber::bomber() {
	cl = 4;
	name = "Bomber";
	numOfPass = 0;
}

bomber::bomber(int S, int Dis, int Num, int H, int fr, int fm, int pt) {
	speed = S;
	height = H;
	distance = Dis;
	numOfPass = 0;
	fradius = fr;
	fmass = fm;
	ptime = pt;

	cl = 4;
	name = "Bomber";
}

//Деструктор
bomber::~bomber(){

}

//Get методы класса
int bomber::getFradius() {
	return fradius;
}

int bomber::getFmass() {
	return fmass;
}

int bomber::getPtime() {
	return ptime;
}

//метод установки боевого радиуса
int bomber::setFradius() {
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, true };
	SetConsoleCursorInfo(hCons, &cursor);

	int frad = getInt();
	do {
		if (frad < 2000 || frad > 8000)			//сравниваем с макс./мин. боевым радиусов для бомбардировщиков
		{
			cerr << Lang::lang[31];
			frad = getInt();
		}
		else
		{
			fradius = frad;
			return 1;
		}
	} while (true);

}

//метод установки боевой нагрузки
int bomber::setFmass() {
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, true };
	SetConsoleCursorInfo(hCons, &cursor);

	int fms = getInt();
	do {
		if (fms < 10000 || fms > 45000)		//сравниваем с макс./мин. боевой нагрузкой для бомбардировщиков
		{
			cerr << Lang::lang[31];
			fms = getInt();
		}
		else
		{
			fmass = fms;
			return 1;
		}
	} while (true);

}
//метод установки дальности полета	
int bomber::SetDistance() {
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
int bomber::SetSpeed() {
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
int bomber::SetNumOfPass() {
	cout << Lang::lang[164] << endl;
	return 0;
}
//метод установки высоты полета
int bomber::SetHeight() {
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
//метод установки времени патрулирования
int bomber::setPtime() {
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, true };
	SetConsoleCursorInfo(hCons, &cursor);

	int ptm = getInt();
	do {
		if (ptm <5  || ptm>15)			//сравниваем с макс.\мин. временем патрулирования для бомбардировщиков
		{
			cerr << Lang::lang[31];
			ptm = getInt();
		}
		else
		{
			ptime = ptm;
			return 1;
		}
	} while (true);

}

//метод вывода данных об объекте
void bomber::print() {
	system("mode con cols=160");
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
	cout << Lang::lang[95];
	cout << setw(20);
	cout << Lang::lang[96];
	cout << setw(20);
	cout << Lang::lang[97];

	cout.width(30);
	cout << GetSpeed();
	cout << setw(20);
	cout << GetDistance();
	cout << setw(30);
	cout << GetNumOfPass();
	cout << setw(20);
	cout << GetHeight();
	cout << setw(20);
	cout << getFmass();
	cout << setw(20);
	cout << getFradius();
	cout << setw(20);
	cout << getPtime();
}

//метод редактирования данных
void bomber::Edit() {
	system("cls");
	bool fl = false;
	cout << Lang::lang[62] << endl;
	cout << Lang::lang[63] << endl;
	cout << Lang::lang[64] << endl;
	cout << Lang::lang[65] << endl;
	cout << Lang::lang[73] << endl;
	cout << Lang::lang[74] << endl;
	cout << Lang::lang[75] << endl;
	cout << Lang::lang[68] << endl;
	int k = getInt();
	do {
		if (k < 1 || k>7)
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
		system("pause");
		break;
	case 5:
		setFradius();
		break;
	case 6:
		setFmass();
		break;
	case 7:
		setPtime();
		break;
	}

}
