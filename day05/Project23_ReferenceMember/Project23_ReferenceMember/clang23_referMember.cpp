#include <iostream>
using namespace std;

// 클래스 AAA 정의
class AAA {
public:
    // AAA 클래스의 생성자. 객체가 생성될 때 호출됨.
    AAA() {
        cout << "empty object" << endl;
    }

    // AAA 클래스의 멤버 함수. 객체의 이름을 출력함.
    void ShowYourName() {
        cout << "I am class AAA" << endl;
    }
};

// 클래스 BBB 정의
class BBB {
private:
    AAA& ref;      // AAA 클래스 객체에 대한 참조자
    const int& num;  // 정수형 변수에 대한 상수 참조자

public:
    // BBB 클래스의 생성자. AAA 객체와 정수형 변수에 대한 참조자를 매개변수로 받음.
    BBB(AAA& r, const int& n) : ref(r), num(n) {
        // 생성자의 초기화 목록을 사용하여 ref와 num을 초기화함.
        // 생성자의 몸체는 비어 있음.
    }

    // BBB 클래스의 멤버 함수. AAA 객체의 이름과 정수형 변수의 값을 출력함.
    void ShowYourName() {
        ref.ShowYourName();     // AAA 객체의 이름 출력
        cout << "and" << endl;
        cout << "I ref num " << num << endl;   // 정수형 변수의 값을 출력
    }
};

int main(void) {
    AAA obj1;          // AAA 클래스의 객체 생성
    BBB obj2(obj1, 20);   // BBB 클래스의 객체 생성, AAA 객체 obj1과 정수형 변수 20에 대한 참조자를 인수로 전달
    obj2.ShowYourName();   // BBB 객체의 ShowYourName() 함수 호출하여 AAA 객체의 이름과 정수형 변수의 값을 출력
    return 0;
}

/*
1. AAA 클래스와 BBB 클래스를 정의하고 
-> BBB 클래스가 AAA 클래스 객체에 대한 참조자와 정수형 변수에 대한 상수 참조자를 멤버로 갖음.

2. AAA 클래스 객체를 생성한 후에 BBB 클래스 객체를 생성할 때 
-> AAA 객체와 정수형 변수에 대한 참조자를 전달

3. BBB 객체의 멤버 함수를 호출하여 
-> AAA 객체의 이름과 정수형 변수의 값을 출력
 */