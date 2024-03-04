#include <iostream>
using namespace std;

// Ŭ���� Data�� �䳻�� ����
typedef struct Data
{
    int data; // ������ ��� ����
    void (*ShowData)(Data*); // �����͸� ����ϴ� �Լ� ������
    void (*Add)(Data*, int); // �����͸� ���ϴ� �Լ� ������
} Data;

// ������ ��� �Լ�
void ShowData(Data* THIS)
{
    cout << "Data: " << THIS->data << endl;
}

// ������ ���ϴ� �Լ�
void Add(Data* THIS, int num)
{
    THIS->data += num;
}

// ������ ����� main �Լ�
int main(void)
{
    // Data ����ü�� �̿��Ͽ� ��ü ���� �� �ʱ�ȭ
    Data obj1 = { 15, ShowData, Add };
    Data obj2 = { 7, ShowData, Add };

    // ��ü�� ������ ���� �� ���
    obj1.Add(&obj1, 17);
    obj2.Add(&obj2, 9);
    obj1.ShowData(&obj1);
    obj2.ShowData(&obj2);

    return 0;
};

/*
1. typedef struct Data�� �̿��Ͽ� ����ü�� �����ϰ�, �ش� ����ü�� Data��� �̸����� typedef�Ͽ� ���.

2. Data ����ü ���ο��� ������ ��� ���� data�� �Լ� ������ �� ��(ShowData, Add)�� ����.

3. ShowData �Լ��� ��ü�� �����͸� ����ϴ� �Լ���, ��ü�� �ּҸ� ���ڷ� ����.

4. Add �Լ��� ��ü�� �����͸� ���ϴ� �Լ���, ��ü�� �ּҿ� ���� ���� ���ڷ� ����.

5. main �Լ������� Data ����ü�� �̿��Ͽ� �� ���� ��ü(obj1, obj2)�� �����ϰ� �ʱ�ȭ. ���Ŀ��� �ش� ��ü���� �����͸� �����ϰ� ���
*/