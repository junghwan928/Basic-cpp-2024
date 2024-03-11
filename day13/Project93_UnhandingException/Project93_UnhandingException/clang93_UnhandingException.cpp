#include <iostream>
using namespace std;

// 함수 선언
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);

int main() {
    double num1, num2;
    char operation;

    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;

    cout << "Enter operation (+, -, *, /): ";
    cin >> operation;

    switch (operation) {
    case '+':
        cout << "Result: " << add(num1, num2) << endl;
        break;
    case '-':
        cout << "Result: " << subtract(num1, num2) << endl;
        break;
    case '*':
        cout << "Result: " << multiply(num1, num2) << endl;
        break;
    case '/':
        if (num2 != 0.0) {
            cout << "Result: " << divide(num1, num2) << endl;
        }
        else {
            cout << "Error: Division by zero!" << endl;
        }
        break;
    default:
        cout << "Invalid operation!" << endl;
    }

    return 0;
}

// 함수 정의
double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b != 0.0) {
        return a / b;
    }
    else {
        return 0.0; // 여기서는 분모가 0인 경우를 처리하지만, 실제 사용 시에는 호출 전에 검사합니다.
    }
}
