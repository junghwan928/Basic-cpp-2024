#include <iostream>
using namespace std;

class Point {
    int x, y; // x, y 좌표를 나타내는 private 멤버 변수

public:
    // 생성자: x, y 좌표를 초기화
    Point(int ax = 0, int ay = 0) : x(ax), y(ay) {
        cout << "Constructor" << endl; // 객체가 생성될 때 호출되는 생성자
    }

    // 다른 Point 객체의 x, y 값을 현재 객체에 더하는 멤버 함수
    Point add(const Point& other) {
        return Point(x + other.x, y + other.y); // 현재 객체와 다른 객체의 좌표를 더한 새로운 Point 객체를 반환
    }

    // 객체의 x, y 좌표를 출력하는 멤버 함수
    void showPoint() const {
        cout << "Point: [" << x << ", " << y << "]" << endl; // 객체의 현재 좌표를 출력
    }
};

int main() {
    Point p1(3, 4); // 첫 번째 Point 객체 생성, 초기 좌표 (3, 4)
    Point p2(10, 20); // 두 번째 Point 객체 생성, 초기 좌표 (10, 20)
    Point p3 = p1.add(p2); // p1과 p2의 좌표를 더한 값을 가지는 새로운 Point 객체 p3 생성

    p1.showPoint(); // p1의 초기 위치 출력
    p2.showPoint(); // p2의 위치 출력
    p3.showPoint(); // p1과 p2의 좌표를 더한 값인 p3의 좌표 출력

    return 0;
}

/*
1. Point 클래스를 정의하고, x와 y 좌표를 나타내는 private 멤버 변수를 선언.

2.클래스에 생성자를 정의하여 객체가 생성될 때 초기 좌표를 설정.

3. add 함수를 정의하여 현재 객체와 다른 객체의 좌표를 더한 결과를 변환.

4. showPoint 함수를 정의하여 객체의 현재 좌표를 출력.

5. main 함수에서 두 개의 Point 객체를 생성하고, 첫 번째 객체와 두 번째 객체의 좌표를 더한 값을 가지는 세 번째 객체를 생성함. 그런 다음, 각 객체의 좌표를 출력함

*/