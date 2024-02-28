#include <iostream>
using namespace std;

class SoSimple
{
private:
    int num;

public:
    // 생성자: 객체가 생성될 때 호출되며, num을 인자로 초기화홤.
    SoSimple(int n) : num(n)
    {
        // 객체 생성 시 메시지 출력
        cout << "Copy obj: " << this << endl;
    }

    // 복사 생성자: 다른 객체를 받아와서 num을 복사함.
    SoSimple(const SoSimple& copy) : num(copy.num)
    {
        // 새로운 객체가 생성될 때 메시지 출력
        cout << "New Copy Obj: " << this << endl;
    }

    // 소멸자: 객체가 소멸될 때 호출되며, 메시지를 출력함.
    ~SoSimple()
    {
        // 객체가 소멸될 때 메시지 출력
        cout << "Destroy obj: " << this << endl;
    }
};

// SoSimple 객체를 매개변수로 받고, 동일한 객체를 반환하는 함수
SoSimple SimpleFuncObj(SoSimple ob)
{
    // 매개변수로 받은 객체의 주소 출력
    cout << "Parm ADR: " << &ob << endl;
    return ob; // SoSimple 객체를 반환
}

int main(void)
{
    // SoSimple 객체 생성 및 생성 메시지 출력
    SoSimple obj(7);

    // SimpleFuncObj 함수 호출
    SimpleFuncObj(obj);

    // 줄바꿈
    cout << endl;

    // 반환된 객체를 저장할 객체 생성
    SoSimple tempRef = SimpleFuncObj(obj);
    // 반환된 객체의 주소 출력
    cout << "Return Obj: " << &tempRef << endl;

    return 0;
}


/* 추가 설명
1. SimpleFuncObj 함수가 SoSimple 객체를 반환하도록 수정. 
    -> 이제 함수는 SoSimple 객체를 매개변수로 받고, 동일한 객체를 반환.

2. main 함수에서 SimpleFuncObj의 반환값을 적절히 활용하여 객체를 생성하고, 
    -> 이를 tempRef라는 객체에 저장하도록 변경됨.

 3. 이제 SimpleFuncObj 함수는 매개변수로 전달된 객체를 복사하여 반환하고, 
    -> main 함수에서 이를 활용하여 객체를 생성
*/

/* 출력 된 값
Copy obj: 0x7ffeefbff540
Parm ADR: 0x7ffeefbff520
New Copy Obj: 0x7ffeefbff510
Destroy obj: 0x7ffeefbff510
Return Obj: 0x7ffeefbff4f0
Destroy obj: 0x7ffeefbff540
Destroy obj: 0x7ffeefbff520
Destroy obj: 0x7ffeefbff4f0

-------------설명Zone-------------
1. Copy obj: 0x7ffeefbff540      // main 함수에서 SoSimple 객체 obj가 생성될 때의 주소
2. Parm ADR: 0x7ffeefbff520      // SimpleFuncObj 함수 내에서 SoSimple 객체 ob가 생성될 때의 주소 (매개변수로 받은 객체의 주소)
3. New Copy Obj: 0x7ffeefbff510  // SimpleFuncObj 함수 내에서 SoSimple 객체 ob를 복사하여 새로운 객체가 생성될 때의 주소 (복사 생성자 호출)
4. Destroy obj: 0x7ffeefbff510   // SimpleFuncObj 함수 내에서 생성된 SoSimple 객체 ob가 소멸될 때의 주소
5. Return Obj: 0x7ffeefbff4f0    // main 함수에서 반환된 SoSimple 객체 tempRef가 생성될 때의 주소
6. Destroy obj: 0x7ffeefbff540   // main 함수에서 생성된 SoSimple 객체 obj가 소멸될 때의 주소
7. Destroy obj: 0x7ffeefbff520   // SimpleFuncObj 함수 내에서 생성된 SoSimple 객체 ob가 소멸될 때의 주소
8. Destroy obj: 0x7ffeefbff4f0   // main 함수에서 생성된 SoSimple 객체 tempRef가 소멸될 때의 주소

*/

/*

*/