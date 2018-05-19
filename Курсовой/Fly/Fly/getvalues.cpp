#include "stdafx.h"
#include "getvalues.h"
#include "lang.h"
#include "string.h"

//����� ��� ����� ������������� �������� ��������
int getInt()
{
	const char enter = 13;
	const char backspace = 8;
	bool input = false;
	char c = '\0';
	string str;
	int i = 0;
	while (c != enter)
	{
		c = _getch();

		if (c >= '0' && c <= '9')		//����� �������� �����
		{
			str += c;
			input = true;
			cout << c;
			i++;
		}
		else if (c == '-' && !input)
		{
			str += c;
			input = true;
			cout << c;
			i++;
		}
		else if (c == backspace && input)	//� ����� �������� ������� ����������
		{
			str.resize(str.size() - 1);
			cout << "\b \b";
			if (str.size() == 0)
				input = false;
			i--;
		}
	}
	cout << endl;
	if (str.length() > 0) {
		if (str.length() != 1) {
			return stoi(str);

		}
		else if (str[0] != '-') {
			return stoi(str);
		}
		else {
			return 0;
		}
	}
	else {
		return 0;
	}
}

//����� ��� ����� ��������� ��������
char* getChar() {

	const char enter = 13;
	const char pr = 32;
	const char backspace = 8;
	bool input = false;
	char c = '\0';
	string str;
	int i = 0;
	bool fl = false;
	char* s;
	while (c != enter)
	{
		c = _getch();

		if ((strcmp((Lang::getLangName()).c_str(), "eng")) == 0) {	//��� ���������� ����������� 
			fl = true;												//��������������� ���� ������ ���������� ����
			
		}
		else {
			fl = false;
		}

		if (fl == true) {
			if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
			{
				str += c;
				input = true;
				cout << c;
				i++;
			}
			else if (c == pr && input) {
				str += c;
				input = true;
				cout << " ";
				i++;
			}

			else if (c == '-' && !input)
			{
				str += c;
				input = true;
				cout << c;
				i++;
			}
			else if (c == backspace && input)
			{
				str.resize(str.size() - 1);
				cout << "\b \b";
				if (str.size() == 0)
					input = false;
				i--;
			}
		}

		else {
			if ((c >= '�' && c <= '�') || (c >= '�' && c <= '�'))	//��� ������� ����������� - ������� �����
			{
				str += c;
				input = true;
				cout << c;
				i++;
			}
			else if (c == pr && input) {
				str += c;
				input = true;
				cout << " ";
				i++;
			}

			else if (c == '-' && !input)
			{
				str += c;
				input = true;
				cout << c;
				i++;
			}
			else if (c == backspace && input)		//��������������� ����������� �������� �����������
			{
				str.resize(str.size() - 1);
				cout << "\b \b";
				if (str.size() == 0)
					input = false;
				i--;
			}
		}
	}
	cout << endl;
	s = new char[i];
	strcpy(s, str.c_str());
	return s;
}

//����� ��� ����� ��������� ��������
string getstr() {

	const char enter = 13;
	const char pr = 32;
	const char backspace = 8;
	bool input = false;
	char c = '\0';
	string str;
	int i = 0;
	bool fl = false;
	char* s;
	while (c != enter)
	{
		c = _getch();

		if ((strcmp((Lang::getLangName()).c_str(), "eng")) == 0) {
			fl = true;
		}
		else {
			fl = false;
		}

		if (fl == true) {
			if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))	//������ ���������� ��� ����. �����������
			{
				str += c;
				input = true;
				cout << c;
				i++;
			}
			else if (c == pr && input) {
				str += c;
				input = true;
				cout << " ";
				i++;
			}

			else if (c == '-' && !input)
			{
				str += c;
				input = true;
				cout << c;
				i++;
			}
			else if (c == backspace && input)
			{
				str.resize(str.size() - 1);
				cout << "\b \b";
				if (str.size() == 0)
					input = false;
				i--;
			}
		}

		else {
			if ((c >= '�' && c <= '�') || (c >= '�' && c <= '�'))		//������ ������� ��� ���. �����������
			{
				str += c;
				input = true;
				cout << c;
				i++;
			}
			else if (c == pr && input) {
				str += c;
				input = true;
				cout << " ";
				i++;
			}

			else if (c == '-' && !input)
			{
				str += c;
				input = true;
				cout << c;
				i++;
			}
			else if (c == backspace && input)
			{
				str.resize(str.size() - 1);
				cout << "\b \b";
				if (str.size() == 0)
					input = false;
				i--;
			}
		}
	}
	cout << endl;
	return str;
}
