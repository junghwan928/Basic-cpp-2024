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
        name = new char[len];
        strcpy_s(name, len, myname);
        age = myage;
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
        name = new char[len];
        strcpy_s(name, len, myname);
        age = myage;
    }

    // 객체의 정보를 출력하는 함수
    void ShowPersonInfo() const {
        cout << "Name: " << name << ", ";
        cout << "Age: " << age << endl;
        cout << endl;

        
    }
};

int main(void) {
    Person* parr[3];  // Person 객체 포인터 배열 선언
    char namestr[100];
    int age;

    // 사용자로부터 이름과 나이를 입력받아 객체 정보 설정
    for (int i = 0; i < 3; i++) {
        cout << "Name: " << endl;
        cin >> namestr;
        cout << "Age: " << endl;
        cin >> age;
        cout << endl;
        parr[i] = new Person(namestr, age);  // Person 객체를 동적으로 생성하여 포인터 배열에 저장 (힙영역에 객체를 생성)
    }

    parr[0]->ShowPersonInfo();  // 객체 정보 출력 = 객체포인터를 가지고 멤버에 접근( -> )
    parr[1]->ShowPersonInfo();  // 객체 정보 출력
    parr[2]->ShowPersonInfo();  // 객체 정보 출력

    // delete 연산자를 사용하여 메모리를 해제
    delete parr[0];
    delete parr[1];
    delete parr[2];

    return 0;
}
