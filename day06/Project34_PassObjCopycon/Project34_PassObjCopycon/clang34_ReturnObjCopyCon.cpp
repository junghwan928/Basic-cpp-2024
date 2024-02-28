#include <iostream>
using namespace std;

class SoSimple
{
private:
    int num; // 정수를 저장하는 멤버 변수

public:
    // 생성자
    SoSimple(int n) : num(n)
    { }

    // 복사 생성자
    SoSimple(const SoSimple& copy) : num(copy.num)
    {
        cout << "Called SoSimple(const SoSimple& copy)" << endl;
    }

    // 멤버 변수에 값을 더하는 함수
    SoSimple& AddNum(int n)
    {
        num += n; // num = num + n;
        return *this;
    }

    // 데이터를 출력하는 멤버 함수
    void ShowData()
    {
        cout << "Num: " << num << endl;
    }
};

// 객체를 매개변수로 받는 함수
SoSimple SimpleFuncObj(SoSimple ob)
{
    cout << "Return Before" << endl;
    return ob;
}

int main(void)
{
    // 객체 생성 및 초기화
    // SimpleFuncObj 함수는 객체를 매개변수로 받고, 그 객체를 반환.
    // 반환된 객체에 AddNum 함수를 호출하여 num에 3을 더하고,
    // 그 결과에 ShowData 함수를 호출하여 num을 출력
    SoSimple obj(7); 
    SimpleFuncObj(obj).AddNum(3).ShowData();

    // 원본 객체 obj의 num 값을 출력.
    obj.ShowData();
    return 0;
}
/*
1. SoSimple 클래스는 정수를 저장하는 num 멤버 변수를 가지고 있음.
2. 생성자를 통해 num 멤버 변수를 초기화.
3. 복사 생성자는 다른 객체를 받아와서 num 멤버 변수를 복사.
4. AddNum 함수는 멤버 변수 num에 값을 더하고, 객체 자신을 반한.
5. ShowData 함수는 객체의 num 값을 출력.
6. SimpleFuncObj 함수는 SoSimple 객체를 매개변수로 받고, 받은 객체를 반환.
7. main 함수에서는 객체 obj를 생성하고, SimpleFuncObj(obj)를 호출한 후 
    ->반환된 객체에 AddNum(3)과 ShowData()를 순차적으로 호출.
8. 마지막으로 obj.ShowData()를 호출하여 원본 객체의 num 값을 출력.
*/