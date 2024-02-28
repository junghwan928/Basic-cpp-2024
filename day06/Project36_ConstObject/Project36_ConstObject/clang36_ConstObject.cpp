#include <iostream>
using namespace std;

class SoSimple
{
private:
    int num; // 정수를 저장하는 멤버 변수

public:
    // 생성자: 객체가 생성될 때 호출되며, 멤버 변수 num을 인자로 초기화함.
    SoSimple(int n) : num(n)
    { }

    // 멤버 함수 AddNum: 정수를 매개변수로 받아 멤버 변수 num에 더한 뒤 자신의 객체를 반환함.
    SoSimple AddNum(int n) {
        num += n; // 멤버 변수 num에 매개변수 n을 더함.
        return *this; // 자신의 객체를 반환함.
    }

    // 멤버 함수 ShowData: 객체의 멤버 변수 num을 출력함.
    void ShowData() const
    {
        cout << "num: " << num << endl; // 멤버 변수 num을 출력함.
    }
};

int main(void)
{
    const SoSimple obj(7); // SoSimple 클래스의 상수 객체 obj를 생성하고, 멤버 변수 num에 7을 저장함.

    // obj.AddNum(20);  // 상수 객체 obj의 멤버 함수를 호출하여 멤버 변수 num에 20을 더하려 하지만, 상수 객체이므로 오류가 발생함.

    obj.ShowData(); // 상수 객체 obj의 멤버 함수를 호출하여 객체의 멤버 변수 num을 출력함.

    return 0;
}

/* 추가 설명 
1. SoSimple 클래스는 하나의 정수형 멤버 변수 num을 가지고 있음.

2. 생성자 SoSimple(int n)은 객체가 생성될 때 호출되며, 
-> 멤버 변수 num을 인자 n으로 초기화함.

3. AddNum(int n) 함수는 매개변수로 받은 정수 n을 현재 객체의 num에 더한 후, 
-> 자신의 객체를 반환함. 이 함수는 객체의 내부 상태를 변경하는 역할.

4. ShowData() 함수는 현재 객체의 num 값을 출력함. 
-> 이 함수는 객체의 내부 상태를 읽어오는 역할.

5. main() 함수에서는 상수 객체 obj를 생성하고, 이 객체의 num 값을 출력함. 
-> 상수 객체는 한 번 생성되면 수정할 수 없기 때문에 AddNum() 함수를 호출하려고 하면 컴파일 오류가 발생함.
*/