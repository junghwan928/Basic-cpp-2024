#include <iostream>
using namespace std;

// Ŭ���� AAA ����
class AAA {
public:
    // AAA Ŭ������ ������. ��ü�� ������ �� ȣ���.
    AAA() {
        cout << "empty object" << endl;
    }

    // AAA Ŭ������ ��� �Լ�. ��ü�� �̸��� �����.
    void ShowYourName() {
        cout << "I am class AAA" << endl;
    }
};

// Ŭ���� BBB ����
class BBB {
private:
    AAA& ref;      // AAA Ŭ���� ��ü�� ���� ������
    const int& num;  // ������ ������ ���� ��� ������

public:
    // BBB Ŭ������ ������. AAA ��ü�� ������ ������ ���� �����ڸ� �Ű������� ����.
    BBB(AAA& r, const int& n) : ref(r), num(n) {
        // �������� �ʱ�ȭ ����� ����Ͽ� ref�� num�� �ʱ�ȭ��.
        // �������� ��ü�� ��� ����.
    }

    // BBB Ŭ������ ��� �Լ�. AAA ��ü�� �̸��� ������ ������ ���� �����.
    void ShowYourName() {
        ref.ShowYourName();     // AAA ��ü�� �̸� ���
        cout << "and" << endl;
        cout << "I ref num " << num << endl;   // ������ ������ ���� ���
    }
};

int main(void) {
    AAA obj1;          // AAA Ŭ������ ��ü ����
    BBB obj2(obj1, 20);   // BBB Ŭ������ ��ü ����, AAA ��ü obj1�� ������ ���� 20�� ���� �����ڸ� �μ��� ����
    obj2.ShowYourName();   // BBB ��ü�� ShowYourName() �Լ� ȣ���Ͽ� AAA ��ü�� �̸��� ������ ������ ���� ���
    return 0;
}

/*
1. AAA Ŭ������ BBB Ŭ������ �����ϰ� 
-> BBB Ŭ������ AAA Ŭ���� ��ü�� ���� �����ڿ� ������ ������ ���� ��� �����ڸ� ����� ����.

2. AAA Ŭ���� ��ü�� ������ �Ŀ� BBB Ŭ���� ��ü�� ������ �� 
-> AAA ��ü�� ������ ������ ���� �����ڸ� ����

3. BBB ��ü�� ��� �Լ��� ȣ���Ͽ� 
-> AAA ��ü�� �̸��� ������ ������ ���� ���
 */