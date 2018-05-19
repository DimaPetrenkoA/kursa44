#include <sstream>
#include "fly.h"

using namespace std;
class bomber : public Fly {
protected:
	int fradius;	//������ ������ (�)
	int fmass;		//������ �������� (��)
	int ptime;		//����� ��������������(�)

	const int maxdist = 14000; //����. ��������� ������ ���������������
	const int maxheight = 20000; //����. ������ ������ ���������������
	const int maxspeed = 2200; //����. �������� ������ ���������������
public:
	bomber();
	bomber(int S, int Dis, int Num, int H, int fr, int fm, int pt);
	~bomber();
	int setFradius();
	int getFradius();
	int setFmass();
	int getFmass();
	int setPtime();
	int getPtime();
	int SetDistance();
	int SetHeight();
	int SetNumOfPass();
	int SetSpeed();

	void print();
	void Edit();

};