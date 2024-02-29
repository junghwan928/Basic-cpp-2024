#include <iostream>
#include <cstring> // strcpy 함수 사용을 위한 헤더 파일 추가
using namespace std;

// PermanentWorker 클래스 정의
class PermanentWorker
{
private:
    char name[100]; // 이름을 저장하는 문자열 배열
    int salary;     // 급여를 저장하는 변수

public:
    // 생성자: 이름과 급여를 받아 초기화
    PermanentWorker(const char* name, int money) : salary(money)
    {
        strcpy(this->name, name); // name 배열에 이름 복사
    }

    // 급여를 반환하는 함수
    int GetPay() const
    {
        return salary;
    }

    // 이름과 급여 정보를 출력하는 함수
    void ShowSalaryInfo() const
    {
        cout << "name: " << name << endl;
        cout << "salary: " << GetPay() << endl << endl;
    }
};

// EmployeeHandler 클래스 정의
class EmployeeHandler
{
private:
    PermanentWorker* empList[50]; // PermanentWorker 객체 포인터 배열
    int empNum; // 등록된 직원 수

public:
    // 생성자: 등록된 직원 수 초기화
    EmployeeHandler() : empNum(0)
    { }

    // 직원을 배열에 추가하는 함수
    void AddEmployee(PermanentWorker* emp) // 정규직 객체를 포인터로 받아서 -> EMPLIST배열에 집어 넣기
    {
        empList[empNum++] = emp;
    }

    // 등록된 모든 직원의 급여 정보를 출력하는 함수
    void ShowAllSalaryInfo() const
    {
        for (int i = 0; i < empNum; i++)
            empList[i]->ShowSalaryInfo(); // 각 직원의 객체의 SHOWSALARYINFO 함수 호출하여 정보 출력
    }

    // 모든 직원의 급여 총합을 출력하는 함수
    void ShowTotalSalary() const
    {
        int sum = 0;
        for (int i = 0; i < empNum; i++)
            sum += empList[i]->GetPay();
        cout << "salary sum: " << sum << endl;
    }

    // 소멸자: 동적 할당된 PermanentWorker 객체들을 메모리에서 해제
    ~EmployeeHandler()
    {
        for (int i = 0; i < empNum; i++)
            delete empList[i];
    }
};

int main()
{
    // EmployeeHandler 객체 생성
    EmployeeHandler handler;

    // PermanentWorker 객체 생성 및 등록
    handler.AddEmployee(new PermanentWorker("LEE", 3000));
    handler.AddEmployee(new PermanentWorker("KIM", 4000));
    handler.AddEmployee(new PermanentWorker("CHOI", 3500));

    // 등록된 모든 직원의 급여 정보 출력
    handler.ShowAllSalaryInfo();

    // 모든 직원의 급여 총합 출력
    handler.ShowTotalSalary();

    return 0;
}

/* 추가 설명
1. PermanentWorker 클래스에서 생성자와 멤버 함수들에 const 키워드를 추가하여 멤버 변수들이 변경되지 않음을 보장함.

2. EmployeeHandler 클래스에서는 등록된 직원 수를 추적하기 위해 empNum 멤버 변수를 사용함.

3. EmployeeHandler 클래스의 AddEmployee 함수는 등록된 직원 수를 증가시키고, 해당 인덱스에 직원 객체를 저장.

4. ShowAllSalaryInfo 함수는 등록된 모든 직원의 급여 정보를 출력.

5. ShowTotalSalary 함수는 모든 직원의 급여 총합을 계산하여 출력.

6. 소멸자를 통해 동적 할당된 PermanentWorker 객체들을 메모리에서 해제.

7. main 함수에서는 EmployeeHandler 객체를 생성하고, 세 명의 PermanentWorker 객체를 생성하여 등록. 
    -> 그런 다음 등록된 모든 직원의 급여 정보를 출력하고, 모든 직원의 급여 총합을 출력
*/