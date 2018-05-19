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
#include "jetfighter.h"
#include "lang.h"
#include "getvalues.h"
#include "screen.h"

using namespace std;

//������������
jetfighter::jetfighter() {
	numOfPass = 0;
	cl = 3;
	name = "Jetfighter";
}

jetfighter::jetfighter(int S, int Dis, int Num, int H, string cou, int g, string tp) {
	speed = S;
	height = H;
	distance = Dis;
	numOfPass = Num;
	country = cou;
	type = tp;
	guns = g;

	cl = 3;
	name = "Jetfighter";
	numOfPass = 0;
}

//����������
jetfighter::~jetfighter() {

}

//Get ������ ������
int jetfighter::getGuns() {
	return guns;
}


string jetfighter::getCountry() {
	return country;
}

string jetfighter::getType() {
	return type;
}

//����� ��������� ���������� ������
int jetfighter::setGuns() {
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, true };
	SetConsoleCursorInfo(hCons, &cursor);

	int gn = getInt();
	do {
		if (gn < 1 || gn > 8)
		{
			cerr << Lang::lang[31];
			gn = getInt();
		}
		else
		{
			guns = gn;
			return 1;
		}
	} while (true);

}

//����� ��������� ���� ����������� (������/�������/�������)
int jetfighter::setType() {
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, true };
	SetConsoleCursorInfo(hCons, &cursor);
	do {
		string tp = getstr();
		int lena = tp.length();
		if ((lena <= 0) || (lena >20) || ((strcmp(tp.c_str(), Lang::lang[54].c_str())) != 0) && ((strcmp(tp.c_str(), Lang::lang[55].c_str())) != 0) && ((strcmp(tp.c_str(), Lang::lang[56].c_str())) != 0))
		{
			cerr << Lang::lang[31];
		}
		else
		{
			type = tp;
			return 1;
		}
	} while (true);
}

//����� ��������� ������ ������������� (������, ���, �������, ��������)
int jetfighter ::setCountry() {
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, true };
	SetConsoleCursorInfo(hCons, &cursor);
	do {
		string coun = getstr();
		int lena = coun.length();
		if ((lena <= 0) || (lena >20) || ((strcmp(coun.c_str(), Lang::lang[80].c_str())) != 0) && ((strcmp(coun.c_str(), Lang::lang[81].c_str())) != 0) && ((strcmp(coun.c_str(), Lang::lang[82].c_str())) != 0) && ((strcmp(coun.c_str(), Lang::lang[83].c_str())) != 0))
		{
			cerr << Lang::lang[31];
		}
		else
		{
			country = coun;
			return 1;
		}
	} while (true);
}

//����� ��������� ��������� ������	
int jetfighter::SetDistance() {
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, true };
	SetConsoleCursorInfo(hCons, &cursor);

	int dist = getInt();
	do {
		if (dist < 1 || dist>maxdist)  //���������� � ������������ ���������� ������ ��� ������� ������
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
//����� ��������� ��������
int jetfighter::SetSpeed() {
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, true };
	SetConsoleCursorInfo(hCons, &cursor);

	int spd = getInt();
	do {
		if (spd < 40 || spd>maxspeed)	//���������� � ������������ ��������� ������ ��� ������� ������
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
//����� ��������� ��������� ����������
int jetfighter::SetNumOfPass() {
	cout << Lang::lang[164] << endl;
	return 0;
}
//����� ��������� ������ ������
int jetfighter::SetHeight() {
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, true };
	SetConsoleCursorInfo(hCons, &cursor);

	int hei = getInt();
	do {
		if (hei < 1000 || hei>maxheight)		//���������� � ������������ ������� ������ ��� ������� ������
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

//������������� �������� -- ����� �������� ��������� ���� �����������
void operator--(jetfighter& r) {
	if (strcmp(r.type.c_str(), Lang::lang[54].c_str()) == 0) {
		cout << Lang::lang[79] << endl;
	}
	if (strcmp(r.type.c_str(), Lang::lang[55].c_str()) == 0) {
		r.type = Lang::lang[54];
		cout << Lang::lang[72] << "\n" << endl;
	}
	if (strcmp(r.type.c_str(), Lang::lang[56].c_str()) == 0) {
		r.type = Lang::lang[55];
		cout << Lang::lang[72] << "\n" << endl;
	}
}

//����� ������ ������ �� �������
void jetfighter::print() {
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
	cout << Lang::lang[92];
	cout << setw(20);
	cout << Lang::lang[93];
	cout << setw(20);
	cout << Lang::lang[94];

	cout.width(30);
	cout << GetSpeed();
	cout << setw(20);
	cout << GetDistance();
	cout << setw(30);
	cout << GetNumOfPass();
	cout << setw(20);
	cout << GetHeight();
	cout << setw(20);
	cout << getType();
	cout << setw(20);
	cout << getCountry();
	cout << setw(20);
	cout << getGuns();
}

//����� �������������� ������
void jetfighter::Edit() {
	system("cls");
	bool fl = false;
	cout << Lang::lang[62] << endl;
	cout << Lang::lang[63] << endl;
	cout << Lang::lang[64] << endl;
	cout << Lang::lang[65] << endl;
	cout << Lang::lang[76] << endl;
	cout << Lang::lang[77] << endl;
	cout << Lang::lang[78] << endl;
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
		//� ����������� �� ������ ������������ �������� ����������� Set �����
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
		setType();
		break;
	case 6:
		setCountry();
		break;
	case 7:
		setGuns();
		break;
	case 8:
		operator--(*this);
		break;
	}

}

