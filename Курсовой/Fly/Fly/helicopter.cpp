#include "stdafx.h"
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "helicopter.h"
#include "fly.h"
#include "windows.h"
#include "lang.h"
#include "getvalues.h"

using namespace std;

//������������
helicopter::helicopter() {
	cl = 2;
	name = "helicopter";
	Fuel = capacity;
}

helicopter::helicopter(int S, int Dis, int num, int H, int numS, int Cap) {
	speed = S;
	distance = Dis;
	numOfPass = num;
	height = H;
	numOfScrew = numS;
	capacity = Cap;

	cl = 2;
	name = "helicopter";
	Fuel = capacity;
}

//Get ������ ������
int helicopter::GetNumOfScrew() {
	return numOfScrew;
}

int helicopter::GetCapacity() {
	return capacity;
}

//����� ��������� ������ ���������� ����
int helicopter::SetCapacity() {
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, true };
	SetConsoleCursorInfo(hCons, &cursor);

	int cap = getInt();
	do {
		if (cap < 200 || cap > 11600)	//���������� � ������������/����������� ������� ���������� ���� ���������
		{
			cerr << Lang::lang[31];
			cap = getInt();
		}
		else
		{
			capacity = cap;
			return 1;
		}
	} while (true);

}

//����� ��������� ���������� ������
int helicopter::SetNumOfScrew() {
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, true };
	SetConsoleCursorInfo(hCons, &cursor);

	int ns = getInt();
	do {
		if (ns < 1 || ns > 4)		//�������� ����� �� 1 �� 4 ������
		{
			cerr << Lang::lang[31];
			ns = getInt();
		}
		else
		{
			numOfScrew = ns;
			return 1;
		}
	} while (true);

}

//����� �������� ���������� ����
int helicopter::AddFuel(int F)
{
	if (Fuel == capacity){		//���� ��� ����� ��������� �� ����
		return 1;
	}
	else {
		if (Fuel + F <= capacity) {
			Fuel = Fuel + F;				//����� ��������� � �������� ������� ��������� ����������
			return 0;
		}
		else {
			cout << Lang::lang[156] << endl;
			return 1;
		}
	}
}

// ������������� �������� ~ ����� �������� - ����� �������
int helicopter::operator~()
{
	if (Fuel != 0) {	//���� ��� �� ����, ����������
		Fuel = 0;
		cout << Lang::lang[154] << endl;
	}
	else {
		cout << Lang::lang[155] << endl;	//����� ��������� � ���, ��� ��� ��� ����
	}
	return 0;
}
//����� ��������� ��������� ������	
int helicopter::SetDistance() {
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
int helicopter::SetSpeed() {
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
int helicopter::SetNumOfPass() {
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, true };
	SetConsoleCursorInfo(hCons, &cursor);

	int num = getInt();
	do {
		if (num < 0 || num>maxpass)		//���������� � ������������ ����������� ���������� ��� ������� ������
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
//����� ��������� ������ ������
int helicopter::SetHeight() {
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
//����������
helicopter::~helicopter() {

}

//����� ������ ������ ��������
void helicopter::print() {
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
	cout << Lang::lang[90];
	cout << setw(20);
	cout << Lang::lang[91];

	cout.width(30);
	cout << GetSpeed();
	cout << setw(20);
	cout << GetDistance();
	cout << setw(30);
	cout << GetNumOfPass();
	cout << setw(20);
	cout << GetHeight();
	cout << setw(20);
	cout << GetNumOfScrew();
	cout << setw(20);
	cout << GetCapacity();
}

//����� �������������� ������
void helicopter::Edit() {
	system("cls");
	bool fl = false;
	cout << Lang::lang[62] << endl;
	cout << Lang::lang[63] << endl;
	cout << Lang::lang[64] << endl;
	cout << Lang::lang[65] << endl;
	cout << Lang::lang[69] << endl;
	cout << Lang::lang[70] << endl;
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
		break;
	case 5:
		system("cls");
		cout << Lang::lang[151] << endl;
		if (AddFuel(getInt()) == 1) {
			cout << Lang::lang[153] << endl;
		}
		else {
			cout << Lang::lang[152] << endl;
		}
		system("pause");
		break;
	case 6:
		system("cls");
		this->operator~();
		system("pause");
	}
}