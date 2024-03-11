#include <iostream>
using namespace std;

int main() {
    double num1, num2;

    cout << "정수 2개 입력 : "; // 사용자에게 두 개의 숫자를 입력할 것을 요청하는 메시지 출력
    cin >> num1 >> num2; // 두 개의 숫자를 한 번에 입력 받음

    try {
        if (num1 == 0 && num2 == 0) { // 두 숫자가 모두 0이면 예외 발생
            throw string("두 숫자 다 0으로 나눌 수 없다."); // 예외 던지기
        }
        else if (num2 == 0) { // 두 번째 숫자가 0이면 예외 발생
            throw string("숫자를 0으로 나눌 수 없다."); // 예외 던지기
        }
        else { // 예외가 발생하지 않을 경우에만 사칙연산 수행
            cout << "더하기: " << num1 + num2 << endl;
            cout << "빼기: " << num1 - num2 << endl;
            cout << "곱하기: " << num1 * num2 << endl;
            cout << "나누기: " << num1 / num2 << endl;
        }
    }
    catch (string& errorMessage) { // 예외 처리
        cout << "ERROR : " << errorMessage << endl;
    }

    return 0;
}
