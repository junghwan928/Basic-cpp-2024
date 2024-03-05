#include <iostream>
using namespace std;

// Point 클래스 정의
class Point {
private:
    int x, y; // x와 y 좌표를 저장하기 위한 멤버 변수

public:
    // 생성자: x와 y를 받아 객체를 초기화
    Point(int ax = 0, int ay = 0) : x(ax), y(ay) {}

    // 덧셈 연산자 오버로딩: 두 Point 객체를 더한 결과를 반환
    Point operator+(const Point& p) const {
        return Point(x + p.x, y + p.y);
    }

    // 덧셈 연산자 오버로딩: Point 객체와 정수를 더한 결과를 반환
    friend Point operator+(const int& num, const Point& p) {
        return Point(num + p.x, num + p.y);
    }

    // 덧셈 연산자 오버로딩: 정수와 Point 객체를 더한 결과를 반환
    friend Point operator+(const Point& p, const int& num) {
        return num + p; // 위에서 정의한 operator+ 함수 호출
    }

    // 좌표를 출력하는 함수
    void viewPoint() const {
        cout << "(" << x << ", " << y << ")"; // 현재 Point 객체의 좌표 출력
    }

    // 출력 연산자 오버로딩: Point 객체의 좌표를 출력
    friend ostream& operator<<(ostream& os, const Point& p) {
        os << "(" << p.x << ", " << p.y << ")"; // 현재 Point 객체의 좌표 출력
        return os;
    }
};

int main() {
    // Point 객체 생성과 초기화
    Point a(10, 20);
    Point b(30, 40);

    // 덧셈 연산을 통해 새로운 Point 객체 생성
    Point c = a + b; // 두 Point 객체를 더한 결과를 저장
    Point d = a + 100; // Point 객체와 정수를 더한 결과를 저장
    Point e = 100 + a; // 정수와 Point 객체를 더한 결과를 저장

    // 생성된 Point 객체들의 좌표 출력
    cout << "a: " << a << endl; // a의 좌표 출력
    cout << "b: " << b << endl; // b의 좌표 출력
    cout << "c: " << c << endl; // c의 좌표 출력
    cout << "d: " << d << endl; // d의 좌표 출력
    cout << "e: " << e << endl; // e의 좌표 출력

    return 0;
}


/*
1. Point 클래스를 정의하고, 덧셈 연산자와 출력 연산자를 오버로딩하여 주어진 요구사항을 충족!

2. 코드를 실행하면 각 객체의 좌표와 덧셈 연산 결과가 출력!
*/



/* 이걸로 만들어 보기
class point{

}

int main {
point a(10, 20);
point b(30, 40);
point c = a + b;
point d = a + 100;
point e = 100 + a;

d.viewPoint();
e.viewPoint()

cout<<c<<endl;
cout<<d<<endl;
cout<<e<<endl;
}

*/