#include <iostream>
using namespace std;

// Ŭ���� AAA ����
class AAA {
private:
    int num;  // ������ ��� ����
public:
    // AAA Ŭ������ ������. ��ü�� ������ �� ȣ���. �̴ϼȶ�����
    AAA() : num(0) {}

    // ���ο� AAA ��ü�� �����ϰ� �ʱ�ȭ�� �Ŀ� �ش� ��ü�� ���� �����ڸ� ��ȯ�ϴ� �Լ�
    AAA& CreateInitObj(int n) const {
        AAA* ptr = new AAA(n);  // ���ο� AAA ��ü�� �������� �Ҵ��ϰ� �ʱ�ȭ��
        return *ptr;             // �ش� ��ü�� ���� �����ڸ� ��ȯ��
    }

    // ��� ���� num�� ���� ����ϴ� �Լ�
    void ShowNum() const { cout << num << endl; }

private:
    // AAA Ŭ������ ������. ������ �Ű������� �޾� ��� ���� num�� �ʱ�ȭ��.
    AAA(int n) : num(n) {}
};

int main(void) {
    AAA base;  // �⺻ AAA ��ü ����
    base.ShowNum();  // �⺻ ��ü�� num ���� ���

    // CreateInitObj �Լ��� ���� ���ο� AAA ��ü�� �����ϰ� �ش� ��ü�� num ���� ���
    AAA& obj1 = base.CreateInitObj(3);
    obj1.ShowNum();

    // CreateInitObj �Լ��� ���� �� �ٸ� ���ο� AAA ��ü�� �����ϰ� �ش� ��ü�� num ���� ���
    AAA& obj2 = base.CreateInitObj(12);
    obj2.ShowNum();

    // �������� �Ҵ�� ��ü���� �޸𸮿��� ������
    delete& obj1;
    delete& obj2;

    return 0;
}

/*
1. AAA Ŭ������ ����
-> �ش� Ŭ���� ���� �⺻ �����ڿ� �Ű������� �޴� �����ڸ� ����

2. CreateInitObj �Լ��� ���� 
-> ���ο� AAA ��ü�� �������� �Ҵ��ϰ� �ʱ�ȭ�� �� 
-> �ش� ��ü�� ���� �����ڸ� ��ȯ

3. main �Լ������� �⺻ AAA ��ü�� ������ �� 
-> CreateInitObj �Լ��� ���� ���ο� ��ü�� �����ϰ� 
-> �� ���� ���

4. �������� �Ҵ�� ��ü���� �޸𸮿��� ����
*/