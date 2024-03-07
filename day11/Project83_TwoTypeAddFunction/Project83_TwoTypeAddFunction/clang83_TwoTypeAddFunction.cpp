#include <iostream>
using namespace std;

// ���ø� �Լ� ����
template <typename T>
T Add(T num1, T num2)
{
    cout << "T Add(T num1, T num2)" << endl; // ���ø� �Լ� ȣ�� �� ��µǴ� �޽���
    return num1 + num2; // �� ������ ���� ��ȯ
}

// ������ �� ���� �޾� ������ �����ϴ� �Լ� ����
int Add(int num1, int num2)
{
    cout << "Add(int num1, int num2)" << endl; // ������ �Լ� ȣ�� �� ��µǴ� �޽���
    return num1 + num2; // �� ������ ���� ��ȯ
}

// �Ǽ��� �� ���� �޾� ������ �����ϴ� �Լ� ����
double Add(double num1, double num2)
{
    cout << "Add(double num1, double num2)" << endl; // �Ǽ��� �Լ� ȣ�� �� ��µǴ� �޽���
    return num1 + num2; // �� �Ǽ��� ���� ��ȯ
}

int main(void)
{
    cout << Add(5, 7) << endl; // ������ �Լ� ȣ��
    cout << Add(3.7, 7.5) << endl; // �Ǽ��� �Լ� ȣ��
    cout << Add<int>(5, 7) << endl; // ���ø� �Լ� ȣ�� (������)
    cout << Add<double>(3.7, 7.5) << endl; // ���ø� �Լ� ȣ�� (�Ǽ���)
    return 0;
}

/*
1. template <typename T> T Add(T num1, T num2): 
    -> ���ø� �Լ� Add�� ������. 
        -> ������ Ÿ���� �� �Ű������� �޾Ƽ� ������ �����ϸ�, ȣ��Ǿ��� �� ��µǴ� �޽����� ����.

2. int Add(int num1, int num2): 
    -> ������ �� ���� �޾Ƽ� ������ �����ϴ� �Լ��� ������. 
        -> ȣ��Ǿ��� �� ��µǴ� �޽����� ����.

3. double Add(double num1, double num2): 
    -> �Ǽ��� �� ���� �޾Ƽ� ������ �����ϴ� �Լ��� ������. 
        -> ȣ��Ǿ��� �� ��µǴ� �޽����� ����.

4. cout << Add(5, 7) << endl;: 
    -> ������ �Լ��� ȣ���ϰ�, ��ȯ�� ����� �����.

5. cout << Add(3.7, 7.5) << endl;: 
    -> �Ǽ��� �Լ��� ȣ���ϰ�, ��ȯ�� ����� �����.

6. cout << Add<int>(5, 7) << endl;: 
    -> ���ø� �Լ��� ���������� ȣ���ϰ�, ��ȯ�� ����� �����.
*/