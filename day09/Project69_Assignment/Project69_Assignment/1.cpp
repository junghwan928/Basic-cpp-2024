#include <iostream>
using namespace std;

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

int main()
{
    Point a(10, 20);
    a.viewPoint();

    Point b(30, 40);
    b.viewPoint();

    Point c = a + b;
    c.viewPoint();

    Point d = a + 100;
    Point e = 100 + a;

    d.viewPoint();
    e.viewPoint();

    return 0;
}