#include <iostream>
#include <cstring>
#include "Car.h"
using namespace std;

void Car::InitMembers(const char* ID, int fuel)
{
	strcpy(gamerID, ID);
	fuelGauge = fuel;
	curSpeed = 0;
}

void Car::ShowCarState()
{
	cout << "소유자ID: " << gamerID << endl;
	cout << "연료량: " << fuelGauge << "%" << endl;
	cout << "현재속도: " << curSpeed << "km/s" << endl << endl;
}

void Car::Accel()
{
	if (fuelGauge <= 0)
		return;
	else
		fuelGauge -= CAR_CONST::FUEL_STEP;

	if ((curSpeed + CAR_CONST::ACC_STEP) >= CAR_CONST::MAX_SPD)
	{
		curSpeed = CAR_CONST::MAX_SPD;
		return;
	}
		curSpeed += CAR_CONST::ACC_STEP;
	
}

void Car::Break()
{
	if (curSpeed < CAR_CONST::BRK_STEP)
	{
		curSpeed = 0;
		return;
	}
	curSpeed -= CAR_CONST::BRK_STEP;
}

/*
1. strcpy():
	- strcpy() 함수는 C 언어 표준 라이브러리에서 제공.
	- 이 함수는 원본 문자열의 끝을 확인하지 않고, 대상 버퍼의 크기를 고려하지 않고 문자열을 복사.
	- 만약 대상 버퍼의 크기가 충분하지 않다면, 버퍼 오버플로우가 발생할 수 있어 보안 취약점을 유발할 수 있습니다.

	
2. strcpy_s():
	- strcpy_s() 함수는 C11 표준에서 추가된 보안 강화 버전의 문자열 복사 함수.
	- 이 함수는 대상 버퍼의 크기를 검사하여 버퍼 오버플로우를 방지.
	- strcpy_s() 함수의 세 번째 매개변수로는 대상 버퍼의 크기를 전달. 
		=> 이렇게 하면 목적지 버퍼가 충분한 공간을 가지고 있는지 런타임에 확인.
	- strcpy_s()는 버퍼 오버플로우를 방지하기 위해 많은 구현에서 권장되는 함수. 
		=> 그러나 C11 표준 이전의 버전에서는 지원되지 않을 수 있음.
*/