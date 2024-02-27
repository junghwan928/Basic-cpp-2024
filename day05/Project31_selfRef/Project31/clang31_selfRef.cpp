#include <iostream>
using namespace std;

class SelfRef
{
private:
    int num; // ������ ��� ���� num ����

public:
    // ������: ������ �޾� ��� ������ �ʱ�ȭ
    SelfRef(int n) : num(n)
    {
        cout << "��ü ����" << endl; // ��ü�� ������ �� �޽��� ���
    }

    // ������ ���Ͽ� �ڱ� �ڽ��� ��ȯ�ϴ� �Լ�
    SelfRef& Adder(int n)
    {
        num += n; // ��� ������ ������ ����
        return *this; // �ڱ� �ڽ��� �����ϴ� ������ ��ȯ
    }

    // ��ü�� ������ ����ϰ� �ڱ� �ڽ��� ��ȯ�ϴ� �Լ�
    SelfRef& ShowTwoNumber()
    {
        cout << num << endl; // ��� ������ �� ���
        return *this; // �ڱ� �ڽ��� �����ϴ� ������ ��ȯ
    }
};

int main(void)
{
    SelfRef obj(3); // SelfRef ��ü ���� �� �ʱ�ȭ
    SelfRef& ref = obj.Adder(2); // obj ��ü�� ������ ���ϰ�, ��ȯ�� ��ü�� ������ ref�� ����

    obj.ShowTwoNumber(); // obj ��ü�� ���� ���
    ref.ShowTwoNumber(); // ref�� �����ϴ� ��ü�� ���� ���

    // �޼��� ü�̴��� ���� ���ӵ� �Լ� ȣ��
    ref.Adder(1).ShowTwoNumber().Adder(2).ShowTwoNumber();

    return 0;
}


/* �߰� ����

1. SelfRef Ŭ������ num�̶�� ������ ��� ������ ������ ����.

2. �����ڴ� ���ڷ� ���� ������ ����Ͽ� num�� �ʱ�ȭ.

3. Adder �Լ��� ���ڷ� ���� ������ num�� ���� ��, �ڱ� �ڽ��� ��ȯ.

4. ShowTwoNumber �Լ��� ��ü�� num�� ����� ��, �ڱ� �ڽ��� ��ȯ.

5. main �Լ������� SelfRef ��ü�� �����ϰ�, Adder �Լ��� ShowTwoNumber �Լ��� �޼��� ü�̴��Ͽ� ȣ��

*/