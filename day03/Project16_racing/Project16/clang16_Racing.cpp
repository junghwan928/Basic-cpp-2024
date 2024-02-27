#include <iostream>
using namespace std;
/*
1. Car_CONST ���ӽ����̽�: 
-> �� ���ӽ����̽����� �ڵ����� ���� ������� ������(enum)���� ����
--> �̷��� ������� �ڵ����� �Ӽ� �� ���ۿ� ���� ������ ����. 
---> ���� ���, �ڵ����� ID ����, �ִ� �ӵ�, ���� �Ҹ�, ���� �� ���� �ӵ� �������� ����
*/
namespace Car_CONST {
	enum {
		ID_LEN =20,
		MAX_SPD = 200,
		FUEL_STEP = 2, 
		ACC_STEP = 2,
		BRK_STEP = 2,
	};
}


/*
2. Car ����ü
-> �� ����ü���� �ڵ����� �Ӽ� �� ������ ǥ���ϴ� ��� ������ ��� �Լ��� ����
--> gamerID: �ڵ����� ������ ID�� ����.
--> fuelGauge: �ڵ����� ���ᷮ�� ����.
--> curSpeed: �ڵ����� ���� �ӵ��� ����.
--> ShowCarState(): �ڵ����� ���¸� ����ϴ� �Լ���, ������ ID, ���ᷮ �� ���� �ӵ��� ���.
--> Accel(): �ڵ����� ���ӽ�Ű�� �Լ���, ���� �Ҹ𷮰� �ӵ��� ����.
--> Break(): �ڵ����� ���ӽ�Ű�� �Լ���, �ӵ��� ����.
*/
struct Car
{
	char gamerID[Car_CONST::ID_LEN]; // char gameID[20];
	int fuelGauge;
	int curSpeed;

	void ShowCarState() {
		cout << "������ ID" << gamerID << endl;
		cout << "���ᷮ" << fuelGauge << "%" << endl;
		cout << "����ӵ�" << curSpeed <<"km/s" << endl;

	}

	void Accel()
	{
		if (fuelGauge <= 0)
			return;
		else
		
			fuelGauge -= Car_CONST::FUEL_STEP;
		if ((curSpeed + Car_CONST::ACC_STEP) >= Car_CONST::MAX_SPD)
		{
			curSpeed = Car_CONST::MAX_SPD;
			return;

		}
		curSpeed += Car_CONST::ACC_STEP;

		
	}

	void Break()
	{
		if (curSpeed < Car_CONST::BRK_STEP)
		{
			curSpeed = 0;
			return;
		}
		curSpeed -= Car_CONST::BRK_STEP;
	}
};


/*
3. main �Լ�: 
-> �� �Լ������� �� ���� �ڵ��� ��ü(run99�� sped77)�� �����ϰ�, 
--> ������ ��ü�� ���� ���� �� ���� ������ ������ �Ŀ� �ڵ����� ���¸� ���
*/
int main(void) {
	Car run99 = { "run99", 100, 0 };
	run99.Accel(); // 98,10
	run99.Accel(); // 96,20
	run99.ShowCarState();
	run99.Break();
	run99.ShowCarState();

	Car sped77 = { "sped77", 100, 0 };
	sped77.Accel();
	sped77.Break();
	sped77.ShowCarState();
	return 0;
}