#include <iostream>
using namespace std;

// Data Ŭ���� ����
class Data
{
private:
    int data; // private ��� ������ ������ data ����
public:
    // ������: �Ű������� ���� data ��� ���� �ʱ�ȭ
    Data(int num) : data(num)
    {
    }

    // ShowData ��� �Լ�: data ���� ����ϴ� �Լ�
    void ShowData()
    {
        cout << "Data: " << data << endl;
    }

    // Add ��� �Լ�: �Ű������� ���� ���� data�� ���ϴ� �Լ�
    void Add(int num)
    {
        data += num;
    }
};

// main �Լ�
int main(void)
{
    // Data Ŭ������ ��ü obj�� �����ϰ�, �ʱⰪ���� 15�� �����Ͽ� �ʱ�ȭ
    Data obj(15);

    // obj�� Add �Լ��� ȣ���Ͽ� 17�� ����
    obj.Add(17);

    // obj�� ShowData �Լ��� ȣ���Ͽ� data ���� ���
    obj.ShowData();

    return 0;
}

/*
1. Data Ŭ������ ���ǵ˴ϴ�. �� Ŭ�������� private���� ���ǵ� ������ ��� ���� data�� ����.

2. ������ Data(int num)�� �Ű����� num�� �޾Ƽ� data ��� ������ �ʱ�ȭ.

3. ShowData() ��� �Լ��� data ���� ���.

4. Add(int num) ��� �Լ��� �Ű����� num�� �޾Ƽ� data�� ����.

5. main �Լ������� Data Ŭ������ ��ü obj�� �����ϰ�, �ʱⰪ���� 15�� �����Ͽ� �ʱ�ȭ.

6. obj�� Add �Լ��� ȣ���Ͽ� 17�� ����.

7. obj�� ShowData �Լ��� ȣ���Ͽ� data ���� ����մϴ�. ��� ����� "Data: 32"�� ��
*/