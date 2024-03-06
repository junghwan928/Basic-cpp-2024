#include <iostream>
using namespace std;

// Point 클래스 정의
class Point
{
private:
    int xpos, ypos; // x와 y 좌표

public:
    // 생성자: 기본값으로 (0, 0) 좌표를 가짐
    Point(int x = 0, int y = 0) : xpos(x), ypos(y) {  }

    // friend 함수로서 operator<< 함수를 선언
    friend ostream& operator<<(ostream& os, const Point& pos);

    // operator new 함수 오버로딩
    void* operator new(size_t size)
    {
        // 새로운 객체를 위한 메모리 할당을 표시
        cout << "operator new : " << size << endl;
        // char 배열을 사용하여 메모리 할당
        void* adr = new char[size];
        return adr;
    }

    // operator delete 함수 오버로딩
    void operator delete(void* adr)
    {
        // 객체의 메모리 해제를 표시
        cout << "operator delete()" << endl;
        delete[] adr;
    }
};

// 출력 연산자 << 오버로딩
ostream& operator<<(ostream& os, const Point& pos)
{
    os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
    return os;
}

int main(void)
{
    // Point 클래스의 포인터를 동적으로 할당하고 초기화
    Point* ptr = new Point(3, 4);

    // 포인터가 가리키는 객체를 출력
    cout << *ptr;

    // 할당된 메모리를 해제
    delete ptr;

    return 0;
}

/*
1. Point 클래스를 정의합니다. 이 클래스에는 xpos와 ypos라는 두 개의 private 멤버 변수가 있음.

2. Point 클래스에는 operator<< 함수가 있음. 이 함수는 객체를 출력하기 위해 오버로딩. 
    -> friend 함수로 선언되어 클래스의 private 멤버에 접근할 수 있음.

3. Point 클래스 내에서 operator new와 operator delete가 오버로딩. 
    -> 이렇게 하면 클래스의 객체가 동적으로 할당되고 해제될 때마다 해당 함수가 호출. 
        -> 이 함수들은 메모리 할당 및 해제를 표시하기 위해 각각 "operator new : "와 "operator delete()" 메시지를 출력함.

4. main() 함수에서는 Point 클래스의 포인터를 동적으로 할당하고 초기화. 
    -> 이 포인터가 가리키는 객체를 출력한 후 메모리를 해제함.
*/