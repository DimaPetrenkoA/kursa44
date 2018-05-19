#include <sstream>
#include "fly.h"

using namespace std;
class jetfighter : public Fly {
protected:
	string type;
	int guns;
	string country;

	const int maxdist = 4500; //����. ��������� ������ �����������
	const int maxheight = 18000; //����. ������ ������ �����������
	const int maxspeed = 2570; //����. �������� ������ �����������
public:
	jetfighter();
	jetfighter(int S, int Dis, int Num, int H, string cou, int g, string tp);
	~jetfighter();
	int setType();
	string getType();
	int setGuns();
	int getGuns();
	int setCountry();
	string getCountry();
	void print();
	void Edit();
	int SetDistance();
	int SetHeight();
	int SetSpeed();
	int SetNumOfPass();

	friend void operator--(jetfighter&); //���������� ��������� -- (�� ���� ������)
};
