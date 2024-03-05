#include <iostream>
#include <cstring>
using namespace std;

class Person
{
    char* name; // 이름을 저장하기 위한 문자열 포인터
    int age; // 나이를 저장하기 위한 정수형 변수

public:
    // 생성자: 이름과 나이를 받아 멤버 변수를 초기화하는 역할 수행
    Person(char* myname, int myage)
    {
        int len = strlen(myname) + 1; // 입력된 이름의 길이 계산
        name = new char[len]; // 동적 메모리 할당
        strcpy(name, myname); // 입력된 이름을 복사하여 멤버 변수 name에 저장
        age = myage; // 입력된 나이를 멤버 변수 age에 저장
    }

    /*
    // 주석 처리된 대입 연산자 오버로딩 함수
    Person& operator=(const Person& ref)
    {
        delete []name; // 이전에 할당된 메모리를 해제

        int len=strlen(ref.name)+1; // 대입할 객체의 이름 길이 계산
        name= new char[len]; // 새로운 메모리 할당
        strcpy(name, ref.name); // 대입할 객체의 이름을 복사하여 멤버 변수 name에 저장
        age=ref.age; // 대입할 객체의 나이를 멤버 변수 age에 저장
        return *this; // 대입이 완료된 현재 객체 반환
    }
    */

    // 객체의 이름과 나이를 출력하는 함수 (const 멤버 함수로 선언하여 객체의 데이터를 변경하지 않음을 명시)
    void ShowPersonInfo() const
    {
        cout << "이름: " << name << endl; // 객체의 이름 출력
        cout << "나이: " << age << endl; // 객체의 나이 출력
    }

    // 소멸자: 동적으로 할당된 메모리를 해제
    ~Person()
    {
        delete[]name; // 동적으로 할당된 메모리를 해제
        cout << "called destructor!" << endl; // 객체가 소멸될 때 메시지 출력
    }
};

int main(void)
{
    // Person 클래스의 객체 생성 및 초기화
    Person man1("Lee dong woo", 29);
    Person man2("Yoon ji yul", 22);

    man2 = man1; // man1의 데이터를 man2에 대입 (얕은 복사 수행)

    man1.ShowPersonInfo(); // man1의 정보 출력
    man2.ShowPersonInfo(); // man2의 정보 출력

    return 0; // 프로그램 종료
}

/*
1.  Person 클래스를 정의하고, 두 개의 Person 객체를 생성하여 대입 연산을 수행하는 예제

2. Person 클래스는 이름과 나이를 저장하는 멤버 변수를 가지며, 생성자를 통해 초기화

3. ShowPersonInfo() 함수를 통해 객체의 이름과 나이를 출력

4. 객체의 소멸자는 동적으로 할당된 메모리를 해제하고 이를 통해 메모리 누수를 방지
*/