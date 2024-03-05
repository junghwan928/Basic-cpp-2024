#include <iostream>
using namespace std;

class Myclass {
private:
    int num; // Myclass의 멤버 변수로 정수형 num 선언

public:
    // 생성자: 인자로 받은 정수 값을 멤버 변수 num에 초기화
    Myclass(int v) : num(v) {}

    // 복사 생성자: 다른 Myclass 객체를 받아와서 그 객체의 num를 복사하여 초기화
    Myclass(const Myclass& other) : num(other.num) {}

    // print 함수: 객체의 value를 출력
    void print() {
        cout << "Value: " << num << endl;
    }

    // 덧셈 연산자 오버로딩: 두 Myclass 객체의 num를 더한 결과를 가지는 새로운 Myclass 객체를 반환
    Myclass operator+(const Myclass& other) const {
        return Myclass(num + other.num);
    }
};

int main() {
    Myclass a(10); // Myclass 객체 a를 생성하고 num를 10으로 초기화
    a.print(); // a의 num 출력 (Value: 10)

    Myclass b(a); // Myclass 객체 b를 생성하고 a의 num로 초기화
    b.print(); // b의 num 출력 (Value: 10)

    Myclass c = b; // Myclass 객체 c를 생성하고 b의 num로 초기화
    c.print(); // c의 num 출력 (Value: 10)

    Myclass d = a + b + c; // a, b, c의 value를 더한 결과로 Myclass 객체 d를 생성
    d.print(); // d의 num 출력 (Value: 30)

    return 0;
}