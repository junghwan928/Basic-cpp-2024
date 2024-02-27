#include <iostream>
#include <cstring>
using namespace std;

class Person {
private:
    char* name;  // 문자열을 저장하기 위한 포인터 멤버 변수
    int age;     // 나이를 저장하는 멤버 변수

public:
    // 생성자: 이름과 나이를 받아 멤버 변수를 초기화함
    Person(const char* myname, int myage) { // 입력 2개를 갖는 생성자
        // 문자열의 길이를 계산하여 동적으로 메모리를 할당하고 이름을 복사함
        int len = strlen(myname) + 1;  // strlen()은 문자열의 길이를 구하는 함수
        name = new char[len];
        cout << "char Size: " << sizeof(char) << endl;
        cout << endl;
        strcpy_s(name, len, myname);

        age = myage;  // 나이를 초기화함
    }

    // 객체의 정보를 출력하는 함수
    void ShowPersonInfo() const {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << endl;
    }

    // 소멸자: 동적으로 할당된 메모리를 해제함
    ~Person() {
        delete[] name;  // 동적으로 할당된 메모리를 해제함
        cout << "Call Destructor" << endl;
    }
};

int main(void) {
    // Person 클래스를 이용하여 두 명의 객체를 생성함
    Person man1("Lee", 29);
    Person man2("Jang", 41);

    // 객체의 정보를 출력함
    man1.ShowPersonInfo();
    man2.ShowPersonInfo();

    return 0;
}
/*
1. Person 클래스를 정의하고, 
-> 해당 클래스의 객체를 생성하여 사람의 이름과 나이를 저장하고 출력하는 예제

2.Person 클래스는 문자열을 저장하기 위한 name 멤버 변수와 나이를 저장하기 위한 age 멤버 변수를 가지고 있음
-> 생성자는 객체를 생성할 때 이름과 나이를 받아서 멤버 변수를 초기화
--> name 멤버 변수에 대해서는 동적으로 메모리를 할당하여 문자열을 복사
---> 소멸자는 객체가 소멸될 때 동적으로 할당된 메모리를 해제

3. main 함수에서는 Person 클래스의 두 개의 객체를 생성하고 각 객체의 정보를 출력
*/