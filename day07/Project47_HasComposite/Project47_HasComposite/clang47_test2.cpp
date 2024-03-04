#include <iostream>
#include <cstring>
using namespace std;

class Myclass {
private:
    char name[30];
    int age;

public:
    // 이름과 나이를 설정하는 멤버 함수
    void setNameAge(const char* _name, int _age) {
        strncpy_s(name, _name, sizeof(name)); // 문자열 복사 (_name의 길이를 초과하면 자동으로 NULL 문자 추가)
        age = _age;
    }

    // 이름을 반환하는 멤버 함수
    const char* getName() const {
        return name;
    }

    // 나이를 반환하는 멤버 함수
    int getAge() const {
        return age;
    }
};

class MyInfo : public Myclass {
private:
    char pNumber[20]; // 전화번호를 저장하는 멤버 변수

public:
    // 전화번호를 설정하는 멤버 함수
    void setPhoneNumber(const char* _pNumber) {
        strncpy_s(pNumber, _pNumber, sizeof(pNumber)); // 문자열 복사 (_pNumber의 길이를 초과하면 자동으로 NULL 문자 추가)
    }

    // 나의 정보를 출력하는 멤버 함수
    void printMyInfo() {
        cout << "나의 이름은 " << getName() << "이고 나이는 " << getAge() << "살이며 전화번호는 " << pNumber << "입니다." << endl;
    }
};

int main() {
    MyInfo myInfoObj; // MyInfo 객체 생성

    myInfoObj.setNameAge("LEE", 28); // 이름과 나이 설정
    myInfoObj.setPhoneNumber("010-5888-9280"); // 전화번호 설정
    myInfoObj.printMyInfo(); // 정보 출력

    return 0;
}

/* 추가 설명
1. Myclass: 이름과 나이를 저장하는 클래스. 
    -> setNameAge 함수로 이름과 나이를 설정하고, getName과 getAge 함수로 이름과 나이를 반환.

2. MyInfo: Myclass를 상속받은 클래스로, 전화번호를 추가로 저장하는 클래스. 
    -> setPhoneNumber 함수로 전화번호를 설정하고, printMyInfo 함수로 이름, 나이, 전화번호를 출력.

*/