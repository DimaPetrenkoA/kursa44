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
#include "lang.h"
#include "getvalues.h"
#include "screen.h"
#include "manager.h"


using namespace std;
//������������
Fly::Fly() {
	cl = 1;					//��� �������
	name = "Fly";			//��� ����
}
Fly::Fly(int S, int Dis, int Num, int H) {
	speed = S;
	distance = Dis;
	numOfPass = Num;
	height = H;

	name = "Fly";
	cl = 1;
}

//Get ������ ������
int Fly::GetCl()
{
	return Fly::cl;
}

const char *Fly::GetName() {
	return name;
}

int Fly::GetDistance() {
	return distance;
}

int Fly::GetHeight() {
	return height;
}

int Fly::GetNumOfPass() {
	return numOfPass;
}

int Fly::GetSpeed() {
	return speed;
}

//����� ��������� ��������� ������	
int Fly::SetDistance() { 			
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
int Fly::SetSpeed() { 	
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
int Fly::SetNumOfPass() {	
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
int Fly::SetHeight() { 
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

//����� �������� �� ����� �� ��������� ������
int Fly::IsFlying(int h, Fly f) {	
	if (h > f.maxheight ){
		cout << Lang::lang[148] << endl;
	}
	else {
		cout << Lang::lang[147] << endl;
	}
	return 0;
}

//����� �������� �� ����� �� ��������� ���������
int Fly::makeFlight(int d, Fly f) {
	if (d > f.maxdist){
		cout << Lang::lang[149] << endl;
	}
	else {
		cout << Lang::lang[150] << endl;
	}
	return 0;
}

//���������
Fly::~Fly() {
	Flies::DeleteOneFly(this);
}

//����� ������ ������
void Fly::print() {
	system("mode con cols=100");
	cout << setiosflags(ios::left);
	cout << setw(30);
	cout << Lang::lang[86];
	cout << setw(20);
	cout << Lang::lang[87];
	cout << setw(30);
	cout << Lang::lang[88];
	cout << setw(20);
	cout << Lang::lang[89];

	cout.width(30);
	cout << GetSpeed();
	cout << setw(20);
	cout << GetDistance();
	cout << setw(30);
	cout << GetNumOfPass();
	cout << setw(20);
	cout << GetHeight();
}

//����� �������������� ������
void Fly::Edit() {
	system("cls");
	bool fl = false;
	cout << Lang::lang[62] << endl;
	cout << Lang::lang[63] << endl;
	cout << Lang::lang[64] << endl;
	cout << Lang::lang[65] << endl;
	cout << Lang::lang[66] << endl;
	cout << Lang::lang[67] << endl;
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
		break;
	case 5:
		system("cls");
		cout << Lang::lang[35] << endl;
		IsFlying(getInt(), *this);
		system("pause");
		break;
	case 6:
		system("cls");
		cout << Lang::lang[36] << endl;
		makeFlight(getInt(), *this);
		system("pause");
	}

}

