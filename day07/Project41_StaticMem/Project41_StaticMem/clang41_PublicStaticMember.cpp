#include <iostream>
using namespace std;

class SoSimple
{
public: // ���������� public
    static int simObjCnt; // ���� ��� ������ ��ü�� ������ �����ϱ� ���� ���� -> static ������� ����(Ŭ�������)

public:
    // ������: ��ü�� ������ ������ ���� ��� ������ ������Ű�� ������ ��
    SoSimple()
    {
        simObjCnt++; // SoSimple ��ü�� ������ ������Ŵ
    }
};

// ���� ��� ������ �ʱ�ȭ
int SoSimple::simObjCnt = 0;

int main(void)
{
    // ������� ������ SoSimple ��ü�� ���� ���
    cout << SoSimple::simObjCnt << "��° SoSimple ��ü" << endl;

    SoSimple sim1; // SoSimple ��ü ����
    SoSimple sim2; // SoSimple ��ü ����

    // ������ SoSimple ��ü�� ���� ���
    cout << SoSimple::simObjCnt << "��° SoSimple ��ü" << endl;

    // ��ü�� ���� ��� ������ �����Ͽ� ��ü ���� ���
    cout << sim1.simObjCnt << "��° SoSimple ��ü" << endl;
    cout << sim2.simObjCnt << "��° SoSimple ��ü" << endl;

    return 0;
}

/* �߰� ����
1. SoSimple Ŭ�������� ���� ��� ���� simObjCnt�� ����. �� ������ ��ü�� ������ �����ϱ� ���� ����.

2. main �Լ������� ���� ������� ������ SoSimple ��ü�� ������ ���.

3. SoSimple Ŭ������ ��ü�� sim1�� sim2�� �����ϸ鼭 �����ڰ� ȣ��Ǿ� simObjCnt�� �����մϴ�.

4. ������ ��ü�� ������ ����� �� SoSimple::simObjCnt�� sim1.simObjCnt, sim2.simObjCnt ��� ����� �� ����. 
    -> ��� ��ü�� ���� ��� ������ �����ϱ� ������ ������ ���� ���.

5. �̷��� ����� ���� ���� ��� ������ Ȱ���Ͽ� Ŭ������ ��� ��ü�� �����ϴ� ������ ����

*/