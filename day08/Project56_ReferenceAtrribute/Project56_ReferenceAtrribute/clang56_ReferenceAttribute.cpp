#include <iostream>
using namespace std;

// �θ� Ŭ������ First ����
class First
{
public:
    // FirstFunc() ��� �Լ� ����
    void FirstFunc()
    {
        cout << "FirstFunc()" << endl;
    }

    // ���� �Լ� SimpleFunc() ����
    virtual void SimpleFunc()
    {
        cout << "First's SimpleFunc()" << endl;
    }
};

// First Ŭ������ ��ӹ޴� Second Ŭ���� ����
class Second : public First
{
public:
    // SecondFunc() ��� �Լ� ����
    void SecondFunc()
    {
        cout << "SecondFunc()" << endl;
    }

    // �θ� Ŭ������ ���� �Լ��� �������� SimpleFunc() ����
    virtual void SimpleFunc()
    {
        cout << "Second's SimpleFunc()" << endl;
    }
};

// Second Ŭ������ ��ӹ޴� Third Ŭ���� ����
class Third : public Second
{
public:
    // ThirdFunc() ��� �Լ� ����
    void ThirdFunc()
    {
        cout << "ThirdFunc()" << endl;
    }

    // Second Ŭ������ ���� �Լ��� �������� SimpleFunc() ����
    virtual void SimpleFunc()
    {
        cout << "Third's SimpleFunc()" << endl;
    }
};

int main(void)
{
    // Third Ŭ������ ��ü obj ����
    Third obj;
    obj.FirstFunc();    // First Ŭ������ ��� �Լ� ȣ��
    obj.SecondFunc();   // Second Ŭ������ ��� �Լ� ȣ��
    obj.ThirdFunc();    // Third Ŭ������ ��� �Լ� ȣ��
    obj.SimpleFunc();   // Third Ŭ������ SimpleFunc() ȣ��
    cout << endl;

    // Second Ŭ������ ������ ���� sref�� �̿��Ͽ� obj�� ��� �Լ� ȣ��
    Second& sref = obj;
    sref.FirstFunc();   // First Ŭ������ ��� �Լ� ȣ��
    sref.SecondFunc();  // Second Ŭ������ ��� �Լ� ȣ��
    sref.SimpleFunc();  // Third Ŭ������ SimpleFunc() ȣ��
    cout << endl;

    // First Ŭ������ ������ ���� fref�� �̿��Ͽ� obj�� ��� �Լ� ȣ��
    First& fref = obj;
    fref.FirstFunc();   // First Ŭ������ ��� �Լ� ȣ��
    fref.SimpleFunc();  // Third Ŭ������ SimpleFunc() ȣ�� (������)

    return 0;
}
