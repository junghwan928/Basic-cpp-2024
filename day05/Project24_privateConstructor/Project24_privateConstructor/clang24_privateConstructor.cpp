#include <iostream>
using namespace std;

// 클래스 AAA 정의
class AAA {
private:
    int num;  // 정수형 멤버 변수
public:
    // AAA 클래스의 생성자. 객체가 생성될 때 호출됨. 이니셜라이즈
    AAA() : num(0) {}

    // 새로운 AAA 객체를 생성하고 초기화한 후에 해당 객체에 대한 참조자를 반환하는 함수
    AAA& CreateInitObj(int n) const {
        AAA* ptr = new AAA(n);  // 새로운 AAA 객체를 동적으로 할당하고 초기화함
        return *ptr;             // 해당 객체에 대한 참조자를 반환함
    }

    // 멤버 변수 num의 값을 출력하는 함수
    void ShowNum() const { cout << num << endl; }

private:
    // AAA 클래스의 생성자. 정수형 매개변수를 받아 멤버 변수 num을 초기화함.
    AAA(int n) : num(n) {}
};

int main(void) {
    AAA base;  // 기본 AAA 객체 생성
    base.ShowNum();  // 기본 객체의 num 값을 출력

    // CreateInitObj 함수를 통해 새로운 AAA 객체를 생성하고 해당 객체의 num 값을 출력
    AAA& obj1 = base.CreateInitObj(3);
    obj1.ShowNum();

    // CreateInitObj 함수를 통해 또 다른 새로운 AAA 객체를 생성하고 해당 객체의 num 값을 출력
    AAA& obj2 = base.CreateInitObj(12);
    obj2.ShowNum();

    // 동적으로 할당된 객체들을 메모리에서 해제함
    delete& obj1;
    delete& obj2;

    return 0;
}

/*
1. AAA 클래스를 정의
-> 해당 클래스 내에 기본 생성자와 매개변수를 받는 생성자를 정의

2. CreateInitObj 함수를 정의 
-> 새로운 AAA 객체를 동적으로 할당하고 초기화한 후 
-> 해당 객체에 대한 참조자를 반환

3. main 함수에서는 기본 AAA 객체를 생성한 후 
-> CreateInitObj 함수를 통해 새로운 객체를 생성하고 
-> 그 값을 출력

4. 동적으로 할당된 객체들을 메모리에서 해제
*/