#include <iostream>
#include <cstring>
using namespace std;

class Person {
private:
    char* name; // 이름을 저장하는 문자열 포인터
    int age;    // 나이를 저장하는 정수

public:
    // 생성자
    Person(const char* myname, int myage) : age(myage) {
        // 입력된 이름의 길이를 계산하여 필요한 메모리를 동적으로 할당하고, 이름을 복사함.
        int len = strlen(myname) + 1;
        name = new char[len];
        strcpy_s(name, len, myname);
    }

    // 복사 생성자
    Person(const Person& copy) {
        // 복사될 객체의 나이를 복사합니다.
        this->age = copy.age;
        // 복사될 객체의 이름을 복사하기 위해 필요한 메모리를 동적으로 할당하고, 이름을 복사함.
        int len = strlen(copy.name) + 1;
        this->name = new char[len];
        strcpy_s(this->name, len, copy.name);
    }

    // 소멸자
    ~Person() {
        // 동적으로 할당된 메모리를 해제함.
        delete[] name;
        // 소멸자 호출 메시지를 출력함.
        cout << "소멸자 호출됨!!" << endl;
    }

    // 개인 정보 출력
    void ShowPersonInfo() const {
        // 객체의 이름과 나이를 출력합니다.
        cout << "이름: " << name << endl;
        cout << "나이: " << age << endl;
        cout << endl;
    }
};

int main() {
    // Person 클래스의 객체를 생성하고 초기화함.
    Person man1("Hong", 29);
    // 복사 생성자를 호출하여 새로운 객체를 초기화함.
    Person man2 = man1; // 복사 생성자 호출
    // 생성된 두 객체의 정보를 출력함.
    man1.ShowPersonInfo();
    man2.ShowPersonInfo();
    return 0;
}
