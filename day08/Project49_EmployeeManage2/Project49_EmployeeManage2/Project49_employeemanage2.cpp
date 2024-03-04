#include <iostream>
#include <cstring>
using namespace std;

class Employee {
private:
    char name[100]; // 직원의 이름을 저장할 배열
public:
    // 생성자: 이름을 매개변수로 받아 name 배열에 복사합니다.
    Employee(const char* name) {
        strcpy_s(this->name, name);
    }

    // 직원의 이름을 출력하는 멤버 함수
    virtual void ShowYourName() const {
        cout << "name: " << name << endl;
    }

    // 급여를 반환하는 순수 가상 함수. 이 함수는 파생 클래스에서 구현되어야 합니다.
    virtual int GetPay() const = 0;

    // 급여 정보를 출력하는 순수 가상 함수. 이 함수도 파생 클래스에서 구현되어야 합니다.
    virtual void ShowSalaryInfo() const = 0;

    // 가상 소멸자: 파생 클래스에서의 객체 삭제 시 정상적인 소멸자 호출을 보장합니다.
    virtual ~Employee() {}
};

class PermanentWorker : public Employee {
private:
    int salary; // 직원의 급여를 저장하는 변수
public:
    // 생성자: 이름과 급여 정보를 받아 초기화합니다. Employee의 생성자를 호출합니다.
    PermanentWorker(const char* name, int money) : Employee(name), salary(money) { }

    // GetPay 오버라이딩: 이 직원의 급여를 반환합니다.
    int GetPay() const override {
        return salary;
    }

    // ShowSalaryInfo 오버라이딩: 직원의 이름과 급여 정보를 출력합니다.
    void ShowSalaryInfo() const override {
        ShowYourName();
        cout << "salary: " << GetPay() << endl << endl;
    }
};


class EmployeeHandler {
private:
    Employee* empList[50]; // 직원 객체 포인터를 저장할 배열
    int empNum; // 현재 저장된 직원의 수
public:
    // 생성자: empNum을 0으로 초기화합니다.
    EmployeeHandler() : empNum(0) { }

    // 직원 객체를 배열에 추가합니다.
    void AddEmployee(Employee* emp) {
        empList[empNum++] = emp;
    }

    // 저장된 모든 직원의 급여 정보를 출력합니다.
    void ShowAllSalaryInfo() const {
        for (int i = 0; i < empNum; i++)
            empList[i]->ShowSalaryInfo();
    }

    // 저장된 모든 직원의 급여의 합을 계산하고 출력합니다.
    void ShowTotalSalary() const {
        int sum = 0;
        for (int i = 0; i < empNum; i++)
            sum += empList[i]->GetPay();
        cout << "salary sum: " << sum << endl;
    }

    // 소멸자: 동적으로 할당된 모든 직원 객체를 삭제합니다.
    ~EmployeeHandler() {
        for (int i = 0; i < empNum; i++)
            delete empList[i];
    }
};


int main(void) {
    EmployeeHandler handler; // 직원 관리자 객체 생성

    // 새로운 PermanentWorker 객체를 생성하고 직원 관리자에 추가합니다.
    handler.AddEmployee(new PermanentWorker("KIM", 1000));
    handler.AddEmployee(new PermanentWorker("LEE", 1500));
    handler.AddEmployee(new PermanentWorker("JUN", 2000));

    // 저장된 모든 직원의 급여 정보를 출력합니다.
    handler.ShowAllSalaryInfo();

    // 저장된 모든 직원의 급여 합을 출력합니다.
    handler.ShowTotalSalary();

    return 0; // 프로그램 종료
}

