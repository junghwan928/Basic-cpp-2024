#include <iostream>
using namespace std;

class AA {
    int a;
    int b;

public:
    // ������: a�� b�� �ʱ�ȭ�ϴ� ������
    AA(int a, int b) {
        this->a = a;
        this->b = b;
    }

    // ��ü�� ������ ����ϴ� �Լ�
    void AAInfo() {
        cout << a << " " << b << endl;
    }
};

int main()
{
    // AA ��ü obj1 ���� �� �ʱ�ȭ
    AA obj1(10, 20);
    obj1.AAInfo(); // obj1�� ���� ���

    // obj1�� �����Ͽ� obj2 ����
    AA obj2(obj1);
    obj2.AAInfo(); // obj2�� ���� ���

    return 0;
}

/* �߰� ����

1. AA(int a, int b): �� ������ �Ű������� �޾� ��� ���� a�� b�� �ʱ�ȭ.
2. void AAInfo(): ��ü�� ������ ����ϴ� �Լ�.
3. main �Լ������� ������ ���� �۾��� ����
4. AA Ŭ������ ��ü obj1�� �����ϰ�, 10�� 20���� �ʱ�ȭ.
5. obj1�� ������ ���.
6. obj1�� �����Ͽ� obj2�� ����.
7. obj2�� ������ ���.

*/