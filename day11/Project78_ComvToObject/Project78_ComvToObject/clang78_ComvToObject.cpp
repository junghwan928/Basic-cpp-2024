#include <iostream>
using namespace std;

// 'Number' Ŭ���� ����
class Number
{
private:
    int num; // -> private ���� ������ �Ʒ��� ������ ��� ���� 'num' ����

public:
    // -> ������ ����: �Ű����� �⺻���� 0���� ����
    Number(int n = 0) : num(n) // -> �ʱ�ȭ ����� ����Ͽ� 'num'�� �Ű����� 'n'�� ������ �ʱ�ȭ
    {
        cout << "Number(int n=0)" << endl; // -> �����ڰ� ȣ��� �� �޽��� ���
    }

    // ���� ������ �����ε�
    Number& operator=(const Number& ref) // -> 'ref'�� ���Ե� 'Number' ��ü�� ����
    {
        cout << "operator=()" << endl; // -> ���� ������ ȣ�� �� �޽��� ���
        num = ref.num; // -> ���Ե� ��ü�� 'num' ���� ���� ��ü�� 'num'�� ����
        return *this; // -> ���� ��ü�� ������ ��ȯ
    }

    // -> ��� �Լ� 'ShowNumber' ����: 'num' ���� ���
    void ShowNumber() { cout << num << endl; }
};

int main(void)
{
    Number num; // -> 'Number' Ŭ������ ��ü 'num'�� �⺻ �����ڷ� ����
                // -> �⺻�� 0���� �ʱ�ȭ�Ǹ�, �����ڿ��� ������ �޽��� ���

    num = 30; // -> ���� 30�� 'Number' ��ü 'num'�� ����
              // -> �̴� �����Ϸ��� ���� 'Number(30)' ���·� �ӽ� ��ü�� �����ϰ�
              // -> ���� �����ڸ� ȣ���Ͽ� ���� ��ü 'num'�� �����ϴ� ������ ��ħ
              // -> ���⼭ ���� ������ �����ε� �Լ� ȣ�� �޽��� ���

    num.ShowNumber(); // -> 'num' ��ü�� 'ShowNumber' ��� �Լ� ȣ���Ͽ� 'num' �� ���
    return 0;
}
/*
int a = 10;
int b = a;
double d = 3.14;
a = d;
d = a;
*/