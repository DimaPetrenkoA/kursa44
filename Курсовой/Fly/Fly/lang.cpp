#include "stdafx.h"
#include "lang.h"
#include <fstream>
#include <iostream>
#include <sstream> 
using namespace std;

map <int, string> Lang::lang;	//������ ���� map ����������� � �������� ���������� ����� ������ � �����
								//� ���� ������ �� ������� ������
string Lang::langName;
string Lang::ln2;
string Lang::ln1;

//����� ��������� �����
void Lang::setLang(string name) {
	Lang::langName = name;
	name = name + ".txt";		//������� ���� ��������������� �� ������ �������� ����� �����������
	char * filename = new char[name.length() + 1];
	strcpy(filename, name.c_str());
}

//����� ��������� �������� �����
string Lang::getLangName() {
	return Lang::langName;
}

//����� ��� �������� ����� �����������
string Lang::setLangFile(string filename) {

	ifstream fin(filename);
	if (!fin.is_open()) {
		system("cls");
		cout << "ERROR: Language file can't open/���������� ������� ���� �����������. \n";
		system("pause");
		_exit(0);
	}
	else {
		string temp;
		Lang::lang.clear();
		for (int i = 1; getline(fin, temp, '\n'); i++) {
			Lang::lang[i] = temp;
		}
		fin.close();
	}
	return filename;
}

//����� ��������� ����� ����� �����������
void Lang::setLangFilename() {
	//system("cls");

	string newname;
	cout << Lang::lang[141] << endl;
	cin >> newname;
	setLangFile(newname);
	ifstream newlocal(newname, ios_base::in);
	newlocal.open(newname);
	if (newlocal.is_open()) {
		cout << Lang::lang[142] << endl;
		system("pause");
	}
}

//����� �������� ����������� ����� �����������
void Lang::check() {
	int a = 0;
	system("mode con cols=80 lines=20");
	if (Lang::lang.size()<0) {				//���� ������ ����� <0 - ���� ���������
		cout << "���� ����������� ���������/Localization file is damaged" << endl;
		system("pause");
		_exit(0);
	}
	for (int i = 1;i<165;i++) {
		a++;
		if (Lang::lang[i] == " ") {
			cout << "���� ����������� ���������/Localization file is damaged" << endl;
			system("pause");
			_exit(0);
		}
	}
	if (a < 164) {
		cout << "���� ����������� ���������/Localization file is damaged" << endl;
		system("pause");
		_exit(0);
	}
}