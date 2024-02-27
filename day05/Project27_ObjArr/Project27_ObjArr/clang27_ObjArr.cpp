#include <iostream>
#include <cstring>
using namespace std;

class Person {
private:
    char* name;  // 문자열 포인터 멤버 변수
    int age;     // 나이를 저장하는 멤버 변수

public:
    // 생성자: 이름과 나이를 받아 멤버 변수를 초기화
    Person(const char* myname, int myage) {
        int len = static_cast<int>(strlen(myname)) + 1;
        name = new char[len];  // 동적으로 메모리 할당하여 이름을 저장
        strcpy_s(name, len, myname);  // 받은 이름을 할당된 메모리에 복사
        age = myage;           // 나이를 초기화
    }

    // 기본 생성자: 이름과 나이를 초기화하지 않은 경우
    Person() {
        name = nullptr;
        age = 0;
        cout << "Called Person() " << endl;
        cout << endl;
    }

    // 소멸자: 동적으로 할당된 메모리를 해제함
    ~Person() {
        delete[] name;  // 동적으로 할당된 메모리를 해제
        cout << "Called Destructor!" << endl;
        cout << endl;
    }

    // 이름과 나이를 설정하는 함수
    void SetPersonInfo(const char* myname, int myage) {
        int len = static_cast<int>(strlen(myname)) + 1;
        name = new char[len];  // 동적으로 메모리 할당하여 이름을 저장
        strcpy_s(name, len, myname);  // 받은 이름을 할당된 메모리에 복사
        age = myage;
    }

    // 객체의 정보를 출력하는 함수
    void ShowPersonInfo() const {
        cout << "Name: " << name << ", " ;
        cout << "Age: " << age << endl;
        cout << endl;
    }
};

int main(void) {
    Person parr[3];  // Person 객체 배열 선언
    char namestr[100];
    int age;

    // 사용자로부터 이름과 나이를 입력받아 객체 정보 설정
    for (int i = 0; i < 3; i++) {
        cout << "Name: " << endl;
        cin >> namestr;
        cout << "Age: " << endl;
        cin >> age;
        cout << endl;
        parr[i].SetPersonInfo(namestr, age);  // 객체 정보 설정
    }

    // 생성된 객체들의 정보 출력
    for (int i = 0; i < 3; i++) {
        parr[i].ShowPersonInfo();
    }

    return 0;
}
/* 추가 설명 
1. Person 클래스를 사용하여 세 명의 사람에 대한 정보를 입력받고 출력하는 프로그램.

2. 클래스 Person은 이름(name)과 나이(age)를 저장하는 멤버 변수를 가지고 있음. 
-> 생성자를 통해 이름과 나이를 받아 멤버 변수를 초기화, 
--> 소멸자를 통해 동적으로 할당된 메모리를 해제. 
---> 또한 SetPersonInfo 함수를 통해 이름과 나이를 설정하고, ShowPersonInfo 함수를 통해 객체의 정보를 출력.

3. main 함수 => Person 클래스의 객체 배열을 선언한 후 
-> 사용자로부터 이름과 나이를 입력받아 객체 정보를 설정하고 출력.

*/