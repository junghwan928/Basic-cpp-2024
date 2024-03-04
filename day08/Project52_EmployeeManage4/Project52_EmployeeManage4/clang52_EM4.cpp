#include <iostream>
#include <cstring> // strcpy_s �Լ��� ����ϱ� ���� �ʿ��� ��� ������ ����.
using namespace std;

// ������ ��Ÿ���� �⺻ Ŭ���� Employee ����
class Employee
{
private:
    char name[100]; // ������ �̸��� �����ϴ� ���ڿ� �迭.
public:
    // ������: ������ �̸��� �޾� �ʱ�ȭ�մϴ�.
    Employee(const char* name)
    {
        // strcpy_s �Լ��� ����Ͽ� ������ �̸��� �����մϴ�. ���Ȼ� ������ ���ڿ� ���縦 �����մϴ�.
        strcpy_s(this->name, sizeof(this->name), name);
    }

    // ������ �̸��� ����ϴ� �Լ�.
    void ShowYourName() const
    {
        cout << "name: " << name << endl;
    }

    // ���� �Լ��� ����Ǿ� ������, ������ �Ļ� Ŭ�������� ����.
    virtual int GetPay() const
    {
        return 0;
    }

    // ���� �Լ��� ����Ǿ� ������, ������ �Ļ� Ŭ�������� ����.
    virtual void ShowSalaryInfo() const
    {
        // �ƹ� ���۵� �������� ����. �⺻ ������ �Ļ� Ŭ�������� ������.
    }
};

// ������ ������ ��Ÿ���� Ŭ���� PermanentWorker ����
class PermanentWorker : public Employee
{
private:
    int salary; // ������ �⺻ �޿��� �����ϴ� ����.
public:
    // ������: ������ �̸��� �⺻ �޿��� �޾� �ʱ�ȭ.
    PermanentWorker(const char* name, int money)
        : Employee(name), salary(money)
    { }

    // ������ �⺻ �޿��� ��ȯ�ϴ� �Լ�.
    int GetPay() const override
    {
        return salary;
    }

    // ������ �޿� ������ ����ϴ� �Լ�.
    void ShowSalaryInfo() const override
    {
        ShowYourName();
        cout << "salary: " << GetPay() << endl << endl;
    }
};

// �ӽ��� ������ ��Ÿ���� Ŭ���� TemporaryWorker ����
class TemporaryWorker : public Employee
{
private:
    int workTime; // ���� �ð��� �����ϴ� ����.
    int payPerHour; // �ð��� �޿��� �����ϴ� ����.
public:
    // ������: ������ �̸��� �ð��� �޿��� �޾� �ʱ�ȭ�մϴ�.
    TemporaryWorker(const char* name, int pay)
        : Employee(name), workTime(0), payPerHour(pay)
    { }

    // ���� �ð��� �߰��ϴ� �Լ�.
    void AddWorkTime(int time)
    {
        workTime += time;
    }

    // ������ �޿��� ��ȯ�ϴ� �Լ�.
    int GetPay() const override
    {
        return workTime * payPerHour;
    }

    // ������ �޿� ������ ����ϴ� �Լ�.
    void ShowSalaryInfo() const override
    {
        ShowYourName();
        cout << "salary: " << GetPay() << endl << endl;
    }
};

// ������ ������ ��Ÿ���� Ŭ���� SalesWorker ����
class SalesWorker : public PermanentWorker
{
private:
    int salesResult; // �Ǹ� ������ �����ϴ� ����.
    double bonusRatio; // �Ǹ� ���ʽ� ������ �����ϴ� ����.
public:
    // ������: ������ �̸�, �⺻ �޿�, �Ǹ� ���ʽ� ������ �޾� �ʱ�ȭ.
    SalesWorker(const char* name, int money, double ratio)
        : PermanentWorker(name, money), salesResult(0), bonusRatio(ratio)
    { }

    // �Ǹ� ������ �߰��ϴ� �Լ�.
    void AddSalesResult(int value)
    {
        salesResult += value;
    }

    // ������ �޿��� ��ȯ�ϴ� �Լ�.
    int GetPay() const override
    {
        return PermanentWorker::GetPay() + static_cast<int>(salesResult * bonusRatio);
    }

    // ������ �޿� ������ ����ϴ� �Լ�.
    void ShowSalaryInfo() const override
    {
        ShowYourName();
        cout << "salary: " << GetPay() << endl << endl;
    }
};

// �������� �����ϴ� Ŭ���� EmployeeHandler ����
class EmployeeHandler
{
private:
    Employee* empList[50]; // ���� ��ü�� �����͸� �����ϴ� �迭.
    int empNum; // ��ϵ� ���� ���� �����ϴ� ����.
public:
    // ������: ��ϵ� ���� ���� �ʱ�ȭ�մϴ�.
    EmployeeHandler() : empNum(0)
    { }

    // ������ �߰��ϴ� �Լ�.
    void AddEmployee(Employee* emp)
    {
        empList[empNum++] = emp;
    }

    // ��ϵ� ��� ������ �޿� ������ ����ϴ� �Լ�.
    void ShowAllSalaryInfo() const
    {
        for (int i = 0; i < empNum; i++)
            empList[i]->ShowSalaryInfo();
    }

    // ��ϵ� ��� ������ �� �޿��� ����ϴ� �Լ�.
    void ShowTotalSalary() const
    {
        int sum = 0;
        for (int i = 0; i < empNum; i++)
            sum += empList[i]->GetPay();
        cout << "salary sum: " << sum << endl;
    }

    // �Ҹ���: ��ϵ� ��� ���� ��ü�� �޸𸮿��� ����.
    ~EmployeeHandler()
    {
        for (int i = 0; i < empNum; i++)
            delete empList[i];
    }
};

int main(void)
{
    // ������ �����ϴ� EmployeeHandler ��ü ����
    EmployeeHandler handler;

    // ������ ���� �߰�
    handler.AddEmployee(new PermanentWorker("KIM", 1000));
    handler.AddEmployee(new PermanentWorker("LEE", 1500));

    // �ӽ��� ���� �߰�
    TemporaryWorker* alba = new TemporaryWorker("Jung", 700);
    alba->AddWorkTime(5);    // 5�ð� �ٹ� �߰�
    handler.AddEmployee(alba);

    // ������ ���� �߰�
    SalesWorker* seller = new SalesWorker("Hong", 1000, 0.1);
    seller->AddSalesResult(7000);    // �Ǹ� ���� �߰�
    handler.AddEmployee(seller);

    // ��ϵ� ��� ������ �޿� ���� ���
    handler.ShowAllSalaryInfo();

    // ��ϵ� ��� ������ �� �޿� ���
    handler.ShowTotalSalary();

    return 0;
}
