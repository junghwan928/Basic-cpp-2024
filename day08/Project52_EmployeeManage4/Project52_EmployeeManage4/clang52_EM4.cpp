#include <iostream>
#include <cstring> // strcpy_s 함수를 사용하기 위해 필요한 헤더 파일을 포함.
using namespace std;

// 직원을 나타내는 기본 클래스 Employee 정의
class Employee
{
private:
    char name[100]; // 직원의 이름을 저장하는 문자열 배열.
public:
    // 생성자: 직원의 이름을 받아 초기화합니다.
    Employee(const char* name)
    {
        // strcpy_s 함수를 사용하여 직원의 이름을 복사합니다. 보안상 안전한 문자열 복사를 보장합니다.
        strcpy_s(this->name, sizeof(this->name), name);
    }

    // 직원의 이름을 출력하는 함수.
    void ShowYourName() const
    {
        cout << "name: " << name << endl;
    }

    // 가상 함수로 선언되어 있으며, 각각의 파생 클래스에서 구현.
    virtual int GetPay() const
    {
        return 0;
    }

    // 가상 함수로 선언되어 있으며, 각각의 파생 클래스에서 구현.
    virtual void ShowSalaryInfo() const
    {
        // 아무 동작도 수행하지 않음. 기본 구현은 파생 클래스에서 재정의.
    }
};

// 정규직 직원을 나타내는 클래스 PermanentWorker 정의
class PermanentWorker : public Employee
{
private:
    int salary; // 직원의 기본 급여를 저장하는 변수.
public:
    // 생성자: 직원의 이름과 기본 급여를 받아 초기화.
    PermanentWorker(const char* name, int money)
        : Employee(name), salary(money)
    { }

    // 직원의 기본 급여를 반환하는 함수.
    int GetPay() const override
    {
        return salary;
    }

    // 직원의 급여 정보를 출력하는 함수.
    void ShowSalaryInfo() const override
    {
        ShowYourName();
        cout << "salary: " << GetPay() << endl << endl;
    }
};

// 임시직 직원을 나타내는 클래스 TemporaryWorker 정의
class TemporaryWorker : public Employee
{
private:
    int workTime; // 일한 시간을 저장하는 변수.
    int payPerHour; // 시간당 급여를 저장하는 변수.
public:
    // 생성자: 직원의 이름과 시간당 급여를 받아 초기화합니다.
    TemporaryWorker(const char* name, int pay)
        : Employee(name), workTime(0), payPerHour(pay)
    { }

    // 일한 시간을 추가하는 함수.
    void AddWorkTime(int time)
    {
        workTime += time;
    }

    // 직원의 급여를 반환하는 함수.
    int GetPay() const override
    {
        return workTime * payPerHour;
    }

    // 직원의 급여 정보를 출력하는 함수.
    void ShowSalaryInfo() const override
    {
        ShowYourName();
        cout << "salary: " << GetPay() << endl << endl;
    }
};

// 영업직 직원을 나타내는 클래스 SalesWorker 정의
class SalesWorker : public PermanentWorker
{
private:
    int salesResult; // 판매 실적을 저장하는 변수.
    double bonusRatio; // 판매 보너스 비율을 저장하는 변수.
public:
    // 생성자: 직원의 이름, 기본 급여, 판매 보너스 비율을 받아 초기화.
    SalesWorker(const char* name, int money, double ratio)
        : PermanentWorker(name, money), salesResult(0), bonusRatio(ratio)
    { }

    // 판매 실적을 추가하는 함수.
    void AddSalesResult(int value)
    {
        salesResult += value;
    }

    // 직원의 급여를 반환하는 함수.
    int GetPay() const override
    {
        return PermanentWorker::GetPay() + static_cast<int>(salesResult * bonusRatio);
    }

    // 직원의 급여 정보를 출력하는 함수.
    void ShowSalaryInfo() const override
    {
        ShowYourName();
        cout << "salary: " << GetPay() << endl << endl;
    }
};

// 직원들을 관리하는 클래스 EmployeeHandler 정의
class EmployeeHandler
{
private:
    Employee* empList[50]; // 직원 객체의 포인터를 저장하는 배열.
    int empNum; // 등록된 직원 수를 저장하는 변수.
public:
    // 생성자: 등록된 직원 수를 초기화합니다.
    EmployeeHandler() : empNum(0)
    { }

    // 직원을 추가하는 함수.
    void AddEmployee(Employee* emp)
    {
        empList[empNum++] = emp;
    }

    // 등록된 모든 직원의 급여 정보를 출력하는 함수.
    void ShowAllSalaryInfo() const
    {
        for (int i = 0; i < empNum; i++)
            empList[i]->ShowSalaryInfo();
    }

    // 등록된 모든 직원의 총 급여를 출력하는 함수.
    void ShowTotalSalary() const
    {
        int sum = 0;
        for (int i = 0; i < empNum; i++)
            sum += empList[i]->GetPay();
        cout << "salary sum: " << sum << endl;
    }

    // 소멸자: 등록된 모든 직원 객체를 메모리에서 해제.
    ~EmployeeHandler()
    {
        for (int i = 0; i < empNum; i++)
            delete empList[i];
    }
};

int main(void)
{
    // 직원을 관리하는 EmployeeHandler 객체 생성
    EmployeeHandler handler;

    // 정규직 직원 추가
    handler.AddEmployee(new PermanentWorker("KIM", 1000));
    handler.AddEmployee(new PermanentWorker("LEE", 1500));

    // 임시직 직원 추가
    TemporaryWorker* alba = new TemporaryWorker("Jung", 700);
    alba->AddWorkTime(5);    // 5시간 근무 추가
    handler.AddEmployee(alba);

    // 영업직 직원 추가
    SalesWorker* seller = new SalesWorker("Hong", 1000, 0.1);
    seller->AddSalesResult(7000);    // 판매 실적 추가
    handler.AddEmployee(seller);

    // 등록된 모든 직원의 급여 정보 출력
    handler.ShowAllSalaryInfo();

    // 등록된 모든 직원의 총 급여 출력
    handler.ShowTotalSalary();

    return 0;
}
