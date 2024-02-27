#include <iostream>
using namespace std;

class AA {
    int a;
    int b;

public:
    // 생성자: 두 정수를 받아 초기화
    AA(int a, int b) {
        this->a = a;
        this->b = b;
    }

    // 복사 생성자: 다른 AA 객체를 받아 초기화
    AA(const AA& other) {
        this->a = other.a;
        this->b = other.b;
    }

    // 객체의 정보를 출력하는 함수
    void AAInfo() {
        cout << a << " " << b << endl;
    }
};

int main()
{
    // 객체 생성 및 초기화
    AA obj1(10, 20);
    obj1.AAInfo(); // obj1의 정보 출력

    // 복사 생성자를 호출
    // -> obj1의 내용으로 obj2 초기화
    AA obj2(obj1);
    obj2.AAInfo(); // obj2의 정보 출력

    return 0;
}
