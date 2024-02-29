#include <iostream>
using namespace std;

class SoSimple
{
private:
    static int simObjcnt; // ���� ��� ������ ��ü�� ������ �����ϱ� ���� ����

public:
    // ������: ��ü�� ������ ������ ���� ��� ������ ������Ű�� ��ȣ�� �Բ� ��ü ���� �޽����� �����
    SoSimple()
    {
        simObjcnt++; // SoSimple ��ü�� ���� ����
        cout << simObjcnt << " ��° SoSimple ��ü" << endl;
    }
};

// ���� ��� ������ �ʱ�ȭ
int SoSimple::simObjcnt = 0;

class SoComplex
{
private:
    static int cmxObjCnt; // ���� ��� ������ ��ü�� ������ �����ϱ� ���� ����

public:
    // ������: ��ü�� ������ ������ ���� ��� ������ ������Ű�� ��ȣ�� �Բ� ��ü ���� �޽����� �����
    SoComplex()
    {
        cmxObjCnt++; // SoComplex ��ü�� ���� ����
        cout << cmxObjCnt << " ��° SoComplex ��ü" << endl;
    }
};

// ���� ��� ������ �ʱ�ȭ
int SoComplex::cmxObjCnt = 0;

int main(void)
{
    SoSimple sim1;       // SoSimple ��ü ����
    SoSimple sim2;       // SoSimple ��ü ����

    SoComplex cmx1;      // SoComplex ��ü ����
    SoComplex cmx2 = cmx1; // SoComplex ��ü ���� ����
    SoComplex();         // SoComplex ��ü ���� (�ӽ� ��ü)

    return 0;
}

/* �߰� ����

1. SoSimple�� SoComplex Ŭ���������� 
    ->���� ��� ���� simObjcnt�� cmxObjCnt�� ����Ͽ� �� Ŭ������ ��ü ������ ������.

2. main �Լ������� �� Ŭ������ ��ü�� �����ϰ�, 
    ->������ ��ü�� ��ȣ�� �Բ� ���� �޽����� �����.

3. ���� ��� ������ Ŭ���� ������ �ϳ��� �����Ǹ�, 
    -> ��� ��ü�� �� ������ �����մϴ�. ���� ��ü�� ������ ������ ���� ��� ������ �����Ͽ� ��ü�� ������ ������ �� ����.

4. ���� �����ڴ� 
    -> SoComplex Ŭ������ ���ǵǾ� ���� �����Ƿ� ����Ʈ ���� �����ڰ� ����.

5. SoComplex();���� 
    -> ������ ��ü�� �̸��� ���� �ӽ� ��ü�̹Ƿ� ������ ��ü�� ��ȣ�� ��µ��� ����
*/