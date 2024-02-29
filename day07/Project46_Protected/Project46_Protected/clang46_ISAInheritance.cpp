#include <iostream>
#include <cstring>
using namespace std;

class Computer
{
private:
    char owner[50]; // 소유자 이름을 저장하는 변수

public:
    // 생성자: 소유자 이름을 초기화함
    Computer(const char* name)
    {
        strcpy_s(owner, name); // strcpy를 strcpy_s로 변경하여 문자열을 복사함
    }

    // 계산기 기능을 수행하는 함수
    void calculator()
    {
        cout << "요청된 내용을 계산합니다." << endl;
    }
};

class NoteBookCamp : public Computer
{
private:
    int battery; // 배터리 충전량을 나타내는 변수

public:
    // 생성자: 소유자 이름과 초기 배터리 충전량을 초기화함
    NoteBookCamp(const char* name, int initCharge) : Computer(name), battery(initCharge)
    { }

    // 배터리를 충전하는 함수
    void charging() { battery += 5; }

    // 배터리를 사용하는 함수
    void useBattery() { battery -= 1; }

    // 배터리 충전량을 반환하는 함수
    int getBatteryInfo() const { return battery; }

    // 이동하면서 계산하는 함수
    void movingCal()
    {
        if (getBatteryInfo() < 1)
        {
            cout << "배터리가 부족합니다. 노트북을 충전해주세요." << endl;
            return;
        }
        cout << "이동하면서 ";
        calculator(); // 계산기 기능 호출
        useBattery(); // 배터리 사용
    }
};

class TableNotebook : public NoteBookCamp
{
private:
    char regstPenmodel[50]; // 등록된 펜 모델을 저장하는 변수

public:
    // 생성자: 소유자 이름, 초기 배터리 충전량, 초기 펜 모델을 초기화함
    TableNotebook(const char* name, int initCharge, int initDesk, const char* pen) : NoteBookCamp(name, initCharge)
    {
        strcpy_s(regstPenmodel, pen); // strcpy를 strcpy_s로 변경하여 등록된 펜 모델을 복사함
    }

    // 등록된 펜으로 쓰기를 수행하는 함수
    void Write(const char* penInfo)
    {
        if (getBatteryInfo() < 1)
        {
            cout << "배터리가 부족합니다. 노트북을 충전해주세요." << endl;
            return;
        }
        if (strcmp(regstPenmodel, penInfo) != 0)
        {
            cout << "등록되지 않은 펜입니다." << endl;
            return;
        }
        cout << "필기 내용을 처리합니다." << endl;
        useBattery(); // 배터리 사용
    }
};

int main()
{
    NoteBookCamp nc("Roy", 5); // 노트북 캠프 객체 생성
    TableNotebook tnb("Alice", 50, 1, "ISE-241-123"); // 테이블 노트북 객체 생성
    tnb.movingCal(); // 이동 중에 계산 수행
    tnb.Write("ISE-241-123"); // 등록된 펜으로 쓰기 수행

    return 0;
}

/* 추가 설명
1. Computer 클래스:
    - owner 멤버 변수는 컴퓨터의 소유자 이름을 저장함.
    - 생성자 Computer(const char* name)은 소유자 이름을 인자로 받아 초기화함.
    - calculator() 함수는 컴퓨터의 계산기 기능을 수행함.

    
2. NoteBookCamp 클래스:
    - battery 멤버 변수는 노트북의 배터리 충전량을 저장함.
    - 생성자 NoteBookCamp(const char* name, int initCharge)는 소유자 이름과 초기 배터리 충전량을 인자로 받아 초기화함.
    - charging() 함수는 배터리를 충전함.
    - useBattery() 함수는 배터리를 사용함.
    - getBatteryInfo() 함수는 현재 배터리 충전량을 반환함.
    - movingCal() 함수는 배터리 충전량이 충분한 경우 이동하면서 계산을 수행함.


3. TableNotebook 클래스:
    - regstPenmodel 멤버 변수는 등록된 펜 모델을 저장함.
    - 생성자 TableNotebook(const char* name, int initCharge, int initDesk, const char* pen)
    => 소유자 이름, 초기 배터리 충전량, 초기 펜 모델을 인자로 받아 초기화함.
    - Write() 함수는 등록된 펜으로 필기를 수행합니다. 이때 배터리 충전량이 충분하지 않거나 등록된 펜이 아닌 경우 쓰기를 수행하지 않음

*/