#include <iostream>
using namespace std;

class AA {
    int a;
    int b;

public:
    // 생성자: a와 b를 초기화하는 생성자
    AA(int a, int b) {
        this->a = a;
        this->b = b;
    }

    // 객체의 정보를 출력하는 함수
    void AAInfo() {
        cout << a << " " << b << endl;
    }
};

int main()
{
    // AA 객체 obj1 생성 및 초기화
    AA obj1(10, 20);
    obj1.AAInfo(); // obj1의 정보 출력

    // obj1을 복사하여 obj2 생성
    AA obj2(obj1);
    obj2.AAInfo(); // obj2의 정보 출력

    return 0;
}

/* 추가 설명

1. AA(int a, int b): 두 정수형 매개변수를 받아 멤버 변수 a와 b를 초기화.
2. void AAInfo(): 객체의 정보를 출력하는 함수.
3. main 함수에서는 다음과 같은 작업을 수행
4. AA 클래스의 객체 obj1을 생성하고, 10과 20으로 초기화.
5. obj1의 정보를 출력.
6. obj1을 복사하여 obj2를 생성.
7. obj2의 정보를 출력.

*/