#include <iostream>
using namespace std;

// 템플릿 함수 정의
template <typename T>
T Add(T num1, T num2)
{
    cout << "T Add(T num1, T num2)" << endl; // 템플릿 함수 호출 시 출력되는 메시지
    return num1 + num2; // 두 인자의 합을 반환
}

// 정수형 두 개를 받아 덧셈을 수행하는 함수 정의
int Add(int num1, int num2)
{
    cout << "Add(int num1, int num2)" << endl; // 정수형 함수 호출 시 출력되는 메시지
    return num1 + num2; // 두 정수의 합을 반환
}

// 실수형 두 개를 받아 덧셈을 수행하는 함수 정의
double Add(double num1, double num2)
{
    cout << "Add(double num1, double num2)" << endl; // 실수형 함수 호출 시 출력되는 메시지
    return num1 + num2; // 두 실수의 합을 반환
}

int main(void)
{
    cout << Add(5, 7) << endl; // 정수형 함수 호출
    cout << Add(3.7, 7.5) << endl; // 실수형 함수 호출
    cout << Add<int>(5, 7) << endl; // 템플릿 함수 호출 (정수형)
    cout << Add<double>(3.7, 7.5) << endl; // 템플릿 함수 호출 (실수형)
    return 0;
}

/*
1. template <typename T> T Add(T num1, T num2): 
    -> 템플릿 함수 Add의 정의임. 
        -> 동일한 타입의 두 매개변수를 받아서 덧셈을 수행하며, 호출되었을 때 출력되는 메시지가 포함.

2. int Add(int num1, int num2): 
    -> 정수형 두 개를 받아서 덧셈을 수행하는 함수의 정의임. 
        -> 호출되었을 때 출력되는 메시지가 포함.

3. double Add(double num1, double num2): 
    -> 실수형 두 개를 받아서 덧셈을 수행하는 함수의 정의임. 
        -> 호출되었을 때 출력되는 메시지가 포함.

4. cout << Add(5, 7) << endl;: 
    -> 정수형 함수를 호출하고, 반환된 결과를 출력함.

5. cout << Add(3.7, 7.5) << endl;: 
    -> 실수형 함수를 호출하고, 반환된 결과를 출력함.

6. cout << Add<int>(5, 7) << endl;: 
    -> 템플릿 함수를 정수형으로 호출하고, 반환된 결과를 출력함.
*/