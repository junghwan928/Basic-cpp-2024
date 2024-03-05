#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos; // x와 y 좌표를 나타내는 private 멤버 변수

public:
    Point(int x = 0, int y = 0) : xpos(x), ypos(y)
    {
        // 생성자: x와 y 좌표를 초기화합니다.
    }

    void ShowPosition() const
    {
        // 현재 좌표를 출력하는 멤버 함수임.
        cout << '[' << xpos << ", " << ypos << ']' << endl;
    }

    // 전위 증가 연산자 오버로딩
    Point& operator++() // 전위 
    {
        xpos += 1;
        ypos += 1;
        return *this;
    }

    // 후위 증가 연산자 오버로딩 => 던져주고 증가. a = i++
    // 현재의 객체를 복사하여 현재의 속성값을 유지시킴
    const Point operator++(int)
    {
        const Point retobj(xpos, ypos); // 현재 객체의 복사본을 생성함. 

        // ==> 현재 객체의 속성값을 1씩 증가 시킴
        xpos += 1;
        ypos += 1;
        return retobj; // 증가 이전의 복사한 객체를 반환하여 전달.
    }

    // 전위 감소 연산자를 friend 함수로 선언
    friend Point& operator--(Point& ref);

    // 후위 감소 연산자를 friend 함수로 선언
    friend const Point operator--(Point& ref, int);
};

// 전위 감소 연산자 구현
Point& operator--(Point& ref)
{
    ref.xpos -= 1;
    ref.ypos -= 1;
    return ref;
}

// 후위 감소 연산자 구현
const Point operator--(Point& ref, int)
{
    const Point retobj(ref); // 현재 객체의 복사본을 생성함.
    ref.xpos -= 1;
    ref.ypos -= 1;
    return retobj; // 감소 이전의 객체를 반환함.
}

int main(void)
{
    Point pos(3, 5); // 좌표 (3, 5)를 가지는 Point 객체를 생성함.
    Point cpy;       // 복사할 Point 객체를 선언함.

    // 후위 감소 연산자를 사용하여 pos의 좌표를 cpy에 할당하고 cpy의 좌표를 출력함.
    cpy = pos--;
    cpy.ShowPosition(); // 출력: [3, 5]
    pos.ShowPosition(); // 출력: [2, 4]

    // 후위 증가 연산자를 사용하여 pos의 좌표를 cpy에 할당하고 cpy의 좌표를 출력함.
    cpy = pos++;
    cpy.ShowPosition(); // 출력: [2, 4]
    pos.ShowPosition(); // 출력: [3, 5]

    return 0;
}

/* 추가 설명

1. Point 클래스는 x와 y 좌표를 가지며, 좌표를 출력하는 ShowPosition() 멤버 함수를 제공함.

2. 전위 증가 연산자(++)와 후위 증가 연산자(++)가 클래스 멤버 함수로 정의되어 있음.

3. 전위 감소 연산자(--)와 후위 감소 연산자(--)가 friend 함수로 선언되어 있음.

4. main() 함수에서는 후위 감소 연산자와 후위 증가 연산자를 사용하여 좌표를 조작하고 그 결과를 출력함

*/