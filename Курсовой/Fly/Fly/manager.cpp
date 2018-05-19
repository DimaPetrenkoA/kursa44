#include "stdafx.h"
#include "fly.h"
#include "manager.h"
#include <algorithm>
#include "Cache.h"
vector <Fly*> Flies::devices;
map <int, int> Flies::counts;

//����� ���������� ������� � ������
int Flies::AddFly(Fly* Fly) {
	Flies::counts[Fly->GetCl()]++;	//����������� ����������� �������
	Flies::devices.insert(Flies::devices.end(), Fly);	//��������� ����� ������ � �����
	return Flies::devices.size();	//���������� ������� ����������� �������
}

//����� ������� ������� (�������� ���� ��������)
void Flies::DeleteAllFlies() {
	for (int i = 0; i<Flies::devices.size(); i++)
		delete Flies::devices[i];	//������� ������ ������ ��������
	Flies::devices.clear();			//������� ������
	Flies::counts.clear();			//�������� ���������� ��� ������� ������
	FCache::saveCache();			//��������� ������� ��������� � ���
}

//����� ��� �������� ������ �������
void Flies::DeleteOneFly(Fly* e) {
	auto F = find(devices.begin(), devices.end(), e);	//���� � ������� �������� ������
	if (F != devices.end()) {
		devices.erase(F);		//�������
	}
	Flies::counts[e->GetCl()]--;	//��������� ����������� �������
	FCache::saveCache();			//��������� ���������
}



