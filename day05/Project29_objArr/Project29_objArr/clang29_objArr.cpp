#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Human {
private:
    char name[30];
    int age;

public:
    // 생성자: 이름과 나이를 받아 멤버 변수를 초기화
    Human(const char* myname, int myage) {
        strcpy(name, myname);
        age = myage;
    }

    // 소멸자: 객체가 소멸될 때 호출되는 함수
    ~Human() {
        std::cout << "Object " << name << " destroyed." << std::endl;
    }

    // 객체의 정보를 출력하는 함수
    void HumanInfo() const {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << endl;
    }
};

int main() {
    // Human 객체 배열 생성과 초기화
    Human h[3] = { Human("Hong",50), Human("KIM",28),Human("CHOI",40) };

    // 객체 배열의 정보 출력
    for (int i = 0; i < 3; i++) {
        h[i].HumanInfo(); // 객체의 정보 출력
    }
    
    Human *h1 = new Human("가나다", 50); // 동적으로 Human 객체를 생성하고, 생성자를 호출하여 초기화
    h1->HumanInfo(); // 동적으로 생성된 객체의 정보를 출력
    //h1.HumanInfo(); 위에 h1->HumanInfo();

    delete h1; // 동적으로 생성된 객체를 메모리에서 해제하여 누수를 방지.


    return 0;
}
