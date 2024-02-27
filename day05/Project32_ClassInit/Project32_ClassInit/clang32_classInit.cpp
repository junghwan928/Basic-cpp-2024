#include <iostream>
using namespace std;

class SoSimple
{
private:
    int num1; // ������ ��� ���� num1 ����
    int num2; // ������ ��� ���� num2 ����

public:
    // ������: �� ���� ������ �޾� ��� ������ �ʱ�ȭ
    SoSimple(int n1, int n2) : num1(n1), num2(n2)
    {
        // empty
        // �����ڿ����� ��� �̴ϼȶ������� ����Ͽ� ��� ������ �ʱ�ȭ.
        // ���� �� ����� ������ �����Ƿ� �����.
    }

    // ���� ������: �ٸ� SoSimple ��ü�� �޾� ��� ������ ���� �ʱ�ȭ
    SoSimple(SoSimple& copy) : num1(copy.num1), num2(copy.num2)
    {
        // ���� �����ڰ� ȣ��Ǿ��� �� �޽��� ���
        cout << "Called SoSimple(SoSimple &Copy)" << endl;
    }

    // ��� ������ ����ϴ� �Լ�
    void ShowSimpleData()
    {
        cout << num1 << endl; // num1 ���
        cout << num2 << endl; // num2 ���
    }
};

int main(void)
{
    SoSimple sim1(5, 10); // SoSimple ��ü ���� �� �ʱ�ȭ
    cout << "���� �� �ʱ�ȭ ����" << endl;
    SoSimple sim2 = sim1; // ���� ������ ȣ���� ���� ��ü ���� �� �ʱ�ȭ
    // ���� �ڵ�� SoSimple sim2(sim1)�� ������ ����.
    cout << "���� �� �ʱ�ȭ ����" << endl;
    sim2.ShowSimpleData(); // sim2 ��ü�� ������ ���
    return 0;
}

/* �߰� ����
1. SoSimple Ŭ����
    => num1�� num2��� �� ���� ������ ��� ������ ������ ����.

2. �����ڴ� �� ���� ������ �޾Ƽ� ��� ������ �ʱ�ȭ. 
    =>���� �����ڴ� �ٸ� SoSimple ��ü�� �޾Ƽ� �� ��ü�� ��� ������ �����Ͽ� �ʱ�ȭ.

3. main �Լ������� ���� sim1 ��ü�� �����ϰ� �ʱ�ȭ�� ��, ���� �����ڸ� ȣ���Ͽ� sim1 ��ü�� ������ �����Ͽ� sim2 ��ü�� ����. 
    =>�׸��� sim2 ��ü�� �����͸� ���
*/