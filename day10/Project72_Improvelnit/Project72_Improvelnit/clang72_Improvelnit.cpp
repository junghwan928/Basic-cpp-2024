#include <iostream>
using namespace std;

class AAA
{
private:
    int num;

public:
    // 매개변수가 있는 생성자
    AAA(int n = 0) : num(n) // 정수 하나를 입력을 갖는 생성자
    {
        cout << "AAA(int n=0)" << endl;
    }

    // 복사 생성자
    AAA(const AAA& ref) : num(ref.num) // 객체 하나를 입력을 갖는 생성자
    {
        cout << "AAA(const AAA & ref)" << endl;
    }

    // 대입 연산자 오버로딩
    AAA& operator=(const AAA& ref)
    {
        num = ref.num;
        cout << "operator=(const AAA &ref)" << endl;
        return *this; // 현재 객체의 참조를 반환
    }
};

class BBB
{
private:
    AAA mem;

public:
    // AAA 타입의 객체를 매개변수로 받는 생성자
    BBB(const AAA& ref)
        : mem(ref) // 초기화 리스트를 사용하여 mem을 초기화(복사 생성자 호출) -> 맴버 이니셜라이즈(콜론 초기화)를 통해서 초기화
    {  }
};

class CCC
{
private:
    AAA mem;

public:
    // AAA 타입의 객체를 매개변수로 받는 생성자
    CCC(const AAA& ref)
    {
        mem = ref; // 대입 연산자를 사용하여 mem을 초기화
    }
};

int main(void)
{
    AAA obj1(12); // AAA의 매개변수가 있는 생성자 호출
    cout << "*********************" << endl;
    BBB obj2(obj1); // obj1을 사용하여 obj2 초기화. BBB의 생성자 내부에서 AAA의 복사 생성자 호출
    cout << "*********************" << endl;
    CCC obj3(obj1); // obj1을 사용하여 obj3 초기화. CCC의 생성자 내부에서 AAA의 대입 연산자 호출
    return 0;
}

/* 상세 설명
1. AAA(int n=0): AAA 클래스의 생성자는 매개변수 n을 받아 내부 num 멤버 변수를 초기화함. 
    -> 기본값이 0으로 설정되어 있어, 매개변수 없이도 호출할 수 있음.

2. AAA(const AAA & ref): 복사 생성자는 AAA 타입의 참조를 매개변수로 받아 num을 복사함. 
    -> 객체가 다른 객체로 초기화될 때 호출됨.

3. operator=(const AAA &ref): 대입 연산자 오버로딩은 AAA 타입의 참조를 매개변수로 받아 num을 대입함. 
    -> 객체에 이미 다른 객체가 대입될 때 호출됨.

4. BBB(const AAA& ref): BBB 클래스의 생성자는 AAA 객체의 참조를 매개변수로 받아, 
    -> 멤버 mem을 초기화?. 여기서는 복사 생성자를 사용함.

5. CCC(const AAA& ref): CCC 클래스의 생성자는 AAA 객체의 참조를 매개변수로 받지만,
    -> 대입 연산자를 사용하여 mem을 초기화함

*/
/* 실행과정
1. obj1이 생성될 때 AAA의 매개변수가 있는 생성자가 호출됨.
obj2가 obj1으로 초기화될 때 BBB의 생성자가 호출되며, 이는 내부적으로 AAA의 복사 생성자를 사용해 mem을 초기화함.
obj3가 obj1으로 초기화될 때 CCC의 생성자가 호출되며, 이는 내부적으로 AAA의 대입 연산자를 사용해 mem을 초기화함.

*/