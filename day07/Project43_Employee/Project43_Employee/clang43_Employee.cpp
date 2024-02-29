#include <iostream>
#include <cstring> // strcpy �Լ� ����� ���� ��� ���� �߰�
using namespace std;

// PermanentWorker Ŭ���� ����
class PermanentWorker
{
private:
    char name[100]; // �̸��� �����ϴ� ���ڿ� �迭
    int salary;     // �޿��� �����ϴ� ����

public:
    // ������: �̸��� �޿��� �޾� �ʱ�ȭ
    PermanentWorker(const char* name, int money) : salary(money)
    {
        strcpy(this->name, name); // name �迭�� �̸� ����
    }

    // �޿��� ��ȯ�ϴ� �Լ�
    int GetPay() const
    {
        return salary;
    }

    // �̸��� �޿� ������ ����ϴ� �Լ�
    void ShowSalaryInfo() const
    {
        cout << "name: " << name << endl;
        cout << "salary: " << GetPay() << endl << endl;
    }
};

// EmployeeHandler Ŭ���� ����
class EmployeeHandler
{
private:
    PermanentWorker* empList[50]; // PermanentWorker ��ü ������ �迭
    int empNum; // ��ϵ� ���� ��

public:
    // ������: ��ϵ� ���� �� �ʱ�ȭ
    EmployeeHandler() : empNum(0)
    { }

    // ������ �迭�� �߰��ϴ� �Լ�
    void AddEmployee(PermanentWorker* emp) // ������ ��ü�� �����ͷ� �޾Ƽ� -> EMPLIST�迭�� ���� �ֱ�
    {
        empList[empNum++] = emp;
    }

    // ��ϵ� ��� ������ �޿� ������ ����ϴ� �Լ�
    void ShowAllSalaryInfo() const
    {
        for (int i = 0; i < empNum; i++)
            empList[i]->ShowSalaryInfo(); // �� ������ ��ü�� SHOWSALARYINFO �Լ� ȣ���Ͽ� ���� ���
    }

    // ��� ������ �޿� ������ ����ϴ� �Լ�
    void ShowTotalSalary() const
    {
        int sum = 0;
        for (int i = 0; i < empNum; i++)
            sum += empList[i]->GetPay();
        cout << "salary sum: " << sum << endl;
    }

    // �Ҹ���: ���� �Ҵ�� PermanentWorker ��ü���� �޸𸮿��� ����
    ~EmployeeHandler()
    {
        for (int i = 0; i < empNum; i++)
            delete empList[i];
    }
};

int main()
{
    // EmployeeHandler ��ü ����
    EmployeeHandler handler;

    // PermanentWorker ��ü ���� �� ���
    handler.AddEmployee(new PermanentWorker("LEE", 3000));
    handler.AddEmployee(new PermanentWorker("KIM", 4000));
    handler.AddEmployee(new PermanentWorker("CHOI", 3500));

    // ��ϵ� ��� ������ �޿� ���� ���
    handler.ShowAllSalaryInfo();

    // ��� ������ �޿� ���� ���
    handler.ShowTotalSalary();

    return 0;
}

/* �߰� ����
1. PermanentWorker Ŭ�������� �����ڿ� ��� �Լ��鿡 const Ű���带 �߰��Ͽ� ��� �������� ������� ������ ������.

2. EmployeeHandler Ŭ���������� ��ϵ� ���� ���� �����ϱ� ���� empNum ��� ������ �����.

3. EmployeeHandler Ŭ������ AddEmployee �Լ��� ��ϵ� ���� ���� ������Ű��, �ش� �ε����� ���� ��ü�� ����.

4. ShowAllSalaryInfo �Լ��� ��ϵ� ��� ������ �޿� ������ ���.

5. ShowTotalSalary �Լ��� ��� ������ �޿� ������ ����Ͽ� ���.

6. �Ҹ��ڸ� ���� ���� �Ҵ�� PermanentWorker ��ü���� �޸𸮿��� ����.

7. main �Լ������� EmployeeHandler ��ü�� �����ϰ�, �� ���� PermanentWorker ��ü�� �����Ͽ� ���. 
    -> �׷� ���� ��ϵ� ��� ������ �޿� ������ ����ϰ�, ��� ������ �޿� ������ ���
*/