#include <iostream>
#include <cstring>
using namespace std;

// 직원을 나타내는 추상 클래스 Employee 정의
class Employee {
private:
    char name[100]; // 직원의 이름
public:
    // 생성자: 이름을 받아 초기화
    Employee(const char* name) {
        strcpy_s(this->name, name);
    }

    // 직원의 이름을 출력하는 가상 함수
    virtual void ShowYourName() const {
        cout << "name: " << name << endl;
    }

    // 직원의 급여를 반환하는 순수 가상 함수
    virtual int GetPay() const = 0;

    // 직원의 급여 정보를 출력하는 순수 가상 함수
    virtual void ShowSalaryInfo() const = 0;

    // 가상 소멸자
    virtual ~Employee() {}
};

// 정규직 직원을 나타내는 PermanentWorker 클래스 정의
class PermanentWorker : public Employee {
private:
    int salary; // 직원의 기본 급여
public:
    // 생성자: 이름과 기본 급여를 받아 초기화
    PermanentWorker(const char* name, int money)
        : Employee(name), salary(money) {}

    // 직원의 기본 급여를 반환하는 함수
    int GetPay() const override {
        return salary;
    }

    // 직원의 급여 정보를 출력하는 함수
    void ShowSalaryInfo() const override {
        ShowYourName();
        cout << "salary: " << GetPay() << endl << endl;
    }
};

// 임시직 직원을 나타내는 TemporaryWorker 클래스 정의
class TemporaryWorker : public Employee {
private:
    int workTime; // 일한 시간
    int payPerHour; // 시간당 급여
public:
    // 생성자: 이름과 시간당 급여를 받아 초기화
    TemporaryWorker(const char* name, int pay)
        : Employee(name), workTime(0), payPerHour(pay) {}

    // 일한 시간을 추가하는 함수
    void AddWorkTime(int time) {
        workTime += time;
    }

    // 직원의 급여를 반환하는 함수
    int GetPay() const override {
        return workTime * payPerHour;
    }

    // 직원의 급여 정보를 출력하는 함수
    void ShowSalaryInfo() const override {
        ShowYourName();
        cout << "salary: " << GetPay() << endl << endl;
    }
};

// 영업직 직원을 나타내는 SalesWorker 클래스 정의
class SalesWorker : public Employee {
private:
    int salesResult; // 판매 실적
    double bonusRatio; // 판매 보너스 비율
public:
    // 생성자: 이름, 기본 급여, 판매 보너스 비율을 받아 초기화
    SalesWorker(const char* name, int money, double ratio)
        : Employee(name), salesResult(0), bonusRatio(ratio) {}

    // 판매 실적을 추가하는 함수
    void AddSalesResult(int value) {
        salesResult += value;
    }

    // 직원의 급여를 반환하는 함수
    int GetPay() const override {
        return static_cast<int>(GetBasePay() + (salesResult * bonusRatio));
    }

    // 직원의 급여 정보를 출력하는 함수
    void ShowSalaryInfo() const override {
        ShowYourName();
        cout << "salary: " << GetPay() << endl << endl;
    }

    // 기본 급여를 반환하는 함수
    int GetBasePay() const {
        return 0; // 영업 직원의 기본 급여는 0
    }
};

// 직원들을 관리하는 클래스 EmployeeHandler 정의
class EmployeeHandler {
private:
    Employee* empList[50]; // 직원 객체 배열
    int empNum; // 등록된 직원 수
public:
    // 생성자: 등록된 직원 수 초기화
    EmployeeHandler() : empNum(0) {}

    // 직원을 추가하는 함수
    void AddEmployee(Employee* emp) {
        empList[empNum++] = emp;
    }

    // 등록된 모든 직원의 급여 정보를 출력하는 함수
    void ShowAllSalaryInfo() const {
        for (int i = 0; i < empNum; i++)
            empList[i]->ShowSalaryInfo();
    }

    // 등록된 모든 직원의 총 급여를 출력하는 함수
    void ShowTotalSalary() const {
        int sum = 0;
        for (int i = 0; i < empNum; i++)
            sum += empList[i]->GetPay();
        cout << "salary sum: " << sum << endl;
    }

    // 소멸자: 등록된 모든 직원 객체를 삭제
    ~EmployeeHandler() {
        for (int i = 0; i < empNum; i++)
            delete empList[i];
    }
};

// main 함수
int main(void) {
    EmployeeHandler handler; // EmployeeHandler 객체 생성

    // 다양한 종류의 직원 객체를 생성하여 등록
    handler.AddEmployee(new PermanentWorker("KIM", 1000));
    handler.AddEmployee(new PermanentWorker("LEE", 1500));
    TemporaryWorker* alba = new TemporaryWorker("Jung", 700);
    alba->AddWorkTime(5); // 알바 직원의 일한 시간 추가
    handler.AddEmployee(alba);
    SalesWorker* seller = new SalesWorker("Hong", 1000, 0.1);
    seller->AddSalesResult(7000); // 영업 직원의 판매 실적 추가
    handler.AddEmployee(seller);

    // 등록된 모든 직원의 급여 정보 출력
    handler.ShowAllSalaryInfo();

    // 등록된 모든 직원의 총 급여 출력
    handler.ShowTotalSalary(); // 총 급여 출력

    return 0;
}
