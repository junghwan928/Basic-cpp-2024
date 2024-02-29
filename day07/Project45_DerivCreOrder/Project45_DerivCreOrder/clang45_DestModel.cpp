#include <iostream>
#include <cstring> // strcpy_s를 사용하기 위한 헤더 파일 포함
using namespace std;

// Person 클래스 정의
class Person
{
private:
    char* name; // 이름을 저장하기 위한 포인터 멤버 변수

public:
    // 생성자: 이름을 인자로 받아 동적 할당 후 복사
    Person(const char* myname)
    {
        size_t len = strlen(myname) + 1; // 문자열 길이 계산
        name = new char[len]; // 동적 할당
        strcpy_s(name, len, myname); // 문자열 복사
    }

    // 소멸자: 동적으로 할당된 메모리 해제
    ~Person()
    {
        delete[] name; // 메모리 해제
    }

    // 이름을 출력하는 멤버 함수
    void WhatYourName() const
    {
        cout << "My name is " << name << endl;
    }
};

// UnivStudent 클래스 정의 (Person 클래스를 상속받음)
class UnivStudent : public Person
{
private:
    char* major; // 전공을 저장하기 위한 포인터 멤버 변수

public:
    // 생성자: 이름과 전공을 인자로 받아 초기화
    UnivStudent(const char* myname, const char* mymajor) : Person(myname)
    {
        size_t len = strlen(mymajor) + 1; // 문자열 길이 계산
        major = new char[len]; // 동적 할당
        strcpy_s(major, len, mymajor); // 문자열 복사
    }

    // 소멸자: 동적으로 할당된 메모리 해제
    ~UnivStudent()
    {
        delete[] major; // 메모리 해제
    }

    // 개인 정보와 전공을 출력하는 멤버 함수
    void whoAreYou() const
    {
        WhatYourName(); // 이름 출력
        cout << "My Major is " << major << endl << endl; // 전공 출력
    }
};

// main 함수
int main(void)
{
    // UnivStudent 객체 생성 및 초기화
    UnivStudent st1("Lee", "Computer");
    st1.whoAreYou(); // 개인 정보 출력

    UnivStudent st2("Hong", "Software");
    st2.whoAreYou(); // 개인 정보 출력

    return 0;
}

/* 상세 설명
1. Person 클래스는 이름을 저장하고 출력하는 기능을 제공. 
    -> 이름은 동적으로 할당된 메모리에 저장.

2. UnivStudent 클래스는 Person 클래스를 상속받아 이름과 함께 전공도 저장하고 출력하는 기능을 추가로 제공. 
    -> 이름은 Person 클래스의 생성자를 통해 초기화되며, 전공은 UnivStudent 클래스의 생성자를 통해 초기화
*/