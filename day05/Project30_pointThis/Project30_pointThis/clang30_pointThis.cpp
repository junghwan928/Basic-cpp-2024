#include <iostream>
#include <cstring>
using namespace std;

class SoSimple
{
private:
    int num; // 정수형 멤버 변수 num 선언
public:
    SoSimple(int num) 
    {   
        this->num = num;
        cout << "num = " << num << ", " << endl; // 생성자에서 멤버 변수 num의 값을 출력
        cout << "address = " << this << endl; // 객체의 주소를 출력
    }

    void ShowSimpleData() {
        cout << num << endl; // 멤버 변수 num의 값을 출력
        cout << endl;
    }

    SoSimple* GetThisPointer()
    {
        return this; // 객체의 주소를 반환
    }
};

int main(void) 
{
    SoSimple sim1(100); // SoSimple 객체 생성 및 초기화
    SoSimple* ptr1 = sim1.GetThisPointer(); // sim1 객체의 주소를 저장
    cout << ptr1 << ", " << endl; // 포인터 값 출력
    ptr1->ShowSimpleData(); // 포인터를 통해 객체의 데이터 출력

    SoSimple sim2(200); // SoSimple 객체 생성 및 초기화
    SoSimple* ptr2 = sim2.GetThisPointer(); // sim2 객체의 주소를 저장
    cout << ptr2 << ", " << endl; // 포인터 값 출력
    ptr2->ShowSimpleData(); // 포인터를 통해 객체의 데이터 출력

    return 0;
}
/* 추가 설명
1. SoSimple 클래스는 정수형 멤버 변수 num 하나를 가지고 있음

2. SoSimple 클래스의 생성자에서는 전달받은 인자 num을 멤버 변수 num에 할당하고, 그 값을 출력

3. 생성자에서 this 포인터를 통해 객체의 주소를 출력

4. ShowSimpleData() 함수는 객체의 num 멤버 변수를 출력

5. GetThisPointer() 함수는 객체의 주소를 반환

-- 코드 main() 함수-- :

1. sim1 객체를 생성하고 초기화. 
-> 이때 생성자에서 num 멤버 변수의 값을 출력하고, 객체의 주소를 출력.

2. GetThisPointer() 함수 통해 
=> sim1 객체의 주소를 포인터 ptr1에 저장하고, 이를 출력.

3. ptr1을 사용하여 sim1 객체의 데이터를 출력.
-> 위 과정을 sim2 객체에 대해서도 반복
*/
