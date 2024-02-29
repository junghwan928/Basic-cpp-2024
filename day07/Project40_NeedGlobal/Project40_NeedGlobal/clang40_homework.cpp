#include <iostream>
#include <cstring> // strcpy 사용을 위한 헤더 추가
using namespace std;

class Person
{
private:
    char* name; // 이름을 저장하는 동적 할당된 문자열 포인터
    int age;    // 나이를 저장하는 정수

public:
    // 생성자: 이름과 나이를 입력받아 멤버 변수에 할당
    Person(const char* pname, int page) : age(page)
    {
        // 이름을 복사하기 위해 동적 할당
        name = new char[strlen(pname) + 1]; // 문자열을 저장할 메모리 동적 할당
        strncpy_s(name, strlen(pname) + 1, pname, _TRUNCATE); // 문자열 복사 
    }

    // 복사 생성자: 다른 Person 객체를 복사하여 새로운 객체 생성
    Person(const Person& other) : age(other.age)
    {
        // 이름을 복사하기 위해 동적 할당
        name = new char[strlen(other.name) + 1]; // 문자열을 저장할 메모리 동적 할당
        strncpy_s(name, strlen(other.name) + 1, other.name, _TRUNCATE); // 문자열 복사
    }

    // 소멸자: 동적 할당된 메모리 해제
    ~Person()
    {
        delete[] name; // 동적 할당된 메모리 해제
    }

    // 개인 정보 출력 함수
    void personInfo() const
    {
        cout << "이름: " << name << ", 나이: " << age << endl;
    }
};

int main()
{
    Person p("LEE", 28); // "Lee" 문자열을 가지고 2이라는 나이로 Person 객체 생성
    p.personInfo(); // Person 객체의 정보 출력

    Person copyp(p); // p 객체를 복사하여 새로운 객체 copyp 생성
    copyp.personInfo(); // 복사된 객체 copyp의 정보 출력

    return 0;
}


/*
1. Person 클래스: 이름과 나이를 저장하는 멤버 변수 name과 age를 가지고 있음. 
    -> 동적으로 할당된 메모리를 사용하여 이름을 저장하며, 
        -> 복사 생성자를 통해 객체를 복사할 때 메모리를 복사함. 소멸자를 통해 동적으로 할당된 메모리를 해제함.

2. Person::Person(const char* pname, int page): 생성자는 이름과 나이를 인자로 받아서 멤버 변수를 초기화함. 
    -> name 멤버 변수에 대해 동적 할당을 수행하고, strncpy_s 함수를 사용하여 이름을 복사함.

3. Person::Person(const Person& other): 복사 생성자는 다른 Person 객체를 인자로 받아서 멤버 변수를 복사함. 
    -> 이때도 동적 할당된 메모리를 사용하고, strncpy_s 함수를 사용하여 이름을 복사함.

4. Person::~Person(): 소멸자는 동적으로 할당된 메모리를 해제함.

5. main() 함수: Person 객체를 생성하고 정보를 출력하는 예시 코드. 
    -> 먼저 초기화된 Person 객체를 출력하고, 그 객체를 복사하여 새로운 객체를 만들고 이를 출력함.

6. _TRUNCATE : Visual Studio에서 제공되는 문자열 함수들(예: strncpy_s, strcpy_s, strcat_s)에서 사용되는 매크로 상수.
    -> _TRUNCATE를 사용하면, 문자열을 복사할 때 목표 버퍼의 크기를 초과하는 경우에 문자열을 자르고 널 종단 문자를 추가하여 버퍼 오버플로우를 방지함. 
    -> 따라서 _TRUNCATE를 사용하면 안전하게 문자열을 복사

*/