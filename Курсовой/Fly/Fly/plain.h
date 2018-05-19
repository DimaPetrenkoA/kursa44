#pragma once
#include <sstream>
#include "fly.h"

using namespace std;
class plain : public Fly {
protected:
	int crew;
	int engines;
	int age;
	int model;

	const int maxdist = 21601; //����. ��������� ������������� ��������
	const int maxheight = 37650; //����. ������ ������������� ��������
	const int maxpass = 850; //����. ���������� ���������� ������������� ��������
	const int maxspeed = 2570; //����. �������� ������������� ��������

public:
	plain();
	plain(int S, int Dis, int Num, int H, int cr, int eng, int a, int m);
	~plain();
	int setEngines();
	int getEngines();
	int setCrew();
	int getCrew();
	int setAge();
	int getAge();
	int setModel();
	int getModel();

	int SetDistance();
	int SetHeight();
	int SetSpeed();
	int SetNumOfPass();

	friend plain& operator++(plain&); //���������� ��������� ++ ����� �������� �������� ���� ������������� ��������
	void print();
	void Edit();
};