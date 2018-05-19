#pragma once
#include <sstream>

using namespace std;
class Fly {
protected:
	int speed;
	int height;
	int distance;
	int numOfPass;
	const int maxdist = 41467; //����. ��������� ������ ������������ ��������
	const int maxheight = 37650; //����. ������ ������ ������������ ��������
	const int maxpass = 850; //����. ���������� ���������� ������������ ��������
	const int maxspeed = 2570; //����. �������� ������ ������������ ��������
	const char *name;
	int cl;
public:
	int id;
	Fly();
	Fly(int S, int Dis, int Num, int H);
	~Fly();
	int GetSpeed();
	virtual int SetSpeed();
	int GetDistance();
	virtual int SetDistance();
	int GetHeight();
	virtual int SetHeight();
	int GetNumOfPass();
	virtual int SetNumOfPass();
	int IsFlying(int h, Fly f);
	int makeFlight(int d, Fly f);

	const char *GetName();
	int GetCl();
	virtual void print();
	virtual void Edit();
};
