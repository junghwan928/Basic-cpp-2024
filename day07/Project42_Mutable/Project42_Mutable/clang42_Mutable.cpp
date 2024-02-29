#include <iostream>
using namespace std;

class SoSimple
{
private:
    int num1;    // ��� ��� ����
    mutable int num2;  // ����(mutable) ��� ����

public:
    // ������: �� ���� ������ �޾� �ʱ�ȭ
    SoSimple(int n1, int n2) : num1(n1), num2(n2)
    { }

    // ��ü�� �����͸� ����ϴ� ��� �Լ�
    void ShowSimpleData() const
    {
        // const ��� �Լ��̹Ƿ� num1, num2 ��� ��� ����
        cout << "num1: " << num1 << ", num2: " << num2 << endl;
    }

    // num1�� ���� num2�� �����ϴ� ��� �Լ�
    void CopyToNum2() const
    {
        // mutable Ű����� ����� num2�� const �Լ� �������� ���� ����
        num2 = num1;
    }
};

int main(void)
{
    // SoSimple ��ü ����
    SoSimple sm(1, 2);

    // �ʱ� ������ ���
    cout << "Initial Data:" << endl;
    sm.ShowSimpleData();

    // CopyToNum2 �Լ� ȣ���Ͽ� num1 ���� num2�� ����
    sm.CopyToNum2();

    // ����� ������ ���
    cout << "After CopyToNum2:" << endl;
    sm.ShowSimpleData();

    return 0;
}

/* �߰� ����
1. SoSimple Ŭ������ num1�� num2��� �� ���� ��� ������ ����.

2. num1�� ��� ��� �����̹Ƿ� const ��� �Լ� �������� ������ �� ����.

3. num2�� mutable Ű����� ����Ǿ� �־�, const ��� �Լ� �������� ������ ����.

4. ShowSimpleData �Լ��� ��ü�� �����͸� ����ϴ� ��� �Լ�. 
    -> �� �Լ��� const ��� �Լ��� ����Ǿ����Ƿ� num1�� num2�� ��� ����� �� ����.

5. CopyToNum2 �Լ��� num1�� ���� num2�� �����ϴ� ��� �Լ�. 
    -> num2�� mutable�� ����Ǿ��� ������ const ��� �Լ� �������� num2�� ���� ������ �� ����.

6. main �Լ������� SoSimple ��ü�� �����ϰ�, 
    -> �ʱ� ������ ��� �� CopyToNum2 �Լ��� ȣ���Ͽ� num1�� ���� num2�� ������ �� ����� �����͸� ���
*/