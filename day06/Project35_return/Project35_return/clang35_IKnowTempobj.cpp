#include <iostream>
using namespace std;

class Temporary
{
private:
    int num;

public:
    // 생성자: 객체가 생성될 때 호출되며, num을 인자로 초기화합니다.
    Temporary(int n) : num(n)
    {
        // 객체 생성 시 메시지 출력
        cout << "create obj: " << num << endl;
    }

    // 소멸자: 객체가 소멸될 때 호출되며, 메시지를 출력합니다.
    ~Temporary()
    {
        cout << "destroy obj: " << num << endl;
    }

    // 객체 정보를 출력하는 멤버 함수
    void ShowTempInfo()
    {
        cout << "My num is: " << num << endl;
    }
};

int main(void)
{
    // 임시 객체 생성 및 생성 메시지 출력
    Temporary temp1(100);
    cout << "********* after make!" << endl << endl;

    // 임시 객체 생성 및 생성 메시지 출력
    Temporary temp2(200);
    cout << "********* after make!" << endl << endl;

    // 객체 생성 후에 참조를 생성하여 임시 객체의 수명을 연장합니다.
    const Temporary& ref = Temporary(300);
    cout << "********* after make!" << endl << endl;

    return 0;
}

/* 추가 설명
1. Temporary 클래스는 정수형 멤버 변수 num을 가지고 있음.
2. 생성자에서는 객체가 생성될 때 num을 인자로 초기화하고, 
    -> 소멸자에서는 객체가 소멸될 때 num 값을 출력.
3. ShowTempInfo 함수는 객체의 num 값을 출력함.
*/