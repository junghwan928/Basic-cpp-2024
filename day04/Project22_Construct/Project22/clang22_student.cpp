#include <iostream>
using namespace std;

// 학생 정보를 담는 클래스 정의
class StudentClass
{
private:
    int ID;             // 학번
    char name[20];      // 이름
    char major[20];     // 전공
    int age;            // 나이

public:
    // 생성자: 학생 정보를 초기화.
    // 멤버이니셜라이즈 => 객체 생성시 초기화 되지 않은 멤버들을 초기화 할때 사용.
    // 즉, 객체생성과 상관없이 미리 초기화 되는
    StudentClass(int id, const char* studentName, const char* studentMajor, int studentAge) {
        ID = id;                            // 학번 초기화
        strcpy_s(name, studentName);        // 이름 복사
        strcpy_s(major, studentMajor);      // 전공 복사
        age = studentAge;                   // 나이 초기화
    }

    // 학생 정보를 출력하는 함수
    void ShowInfo() const {
        cout << "학번 -> " << ID << endl;        // 학번 출력
        cout << "이름 -> " << name << endl;      // 이름 출력
        cout << "전공 -> " << major << "과" << endl;     // 전공 출력
        cout << "나이 -> " << age << "살" << endl;       // 나이 출력
        cout << endl; // 한줄 비우기
    }
};

int main() {
    // 학생 객체 생성 및 초기화
    StudentClass student1(12345, "홍길동", "컴퓨터공학", 20); //객체를 생성하면 생성자 호출
    StudentClass student2(67890, "김여사", "경영학", 21);
    StudentClass student3(13579, "뽀로로", "토목학", 22);
    StudentClass student4(24680, "루피", "식품영양학", 23);
    StudentClass student5(2020864003, "이정환", "소프트웨어학", 28);

    // 학생 정보 출력
    student1.ShowInfo();
    student2.ShowInfo();
    student3.ShowInfo();
    student4.ShowInfo();
    student5.ShowInfo();

    return 0;
}

    /*추가 설명 :
     strcpy => string copy의 줄임말, 함수는 어떤 변수(메모리) or 문자열 상수에 저장 되어있는 문자열을 다른 변수(메모리) 복사할 때 사용
     strcpy_s => strcpy함수의 단점을 보완하기 위해서 만들어진 함수
     -> 유사하지만, dest변수와 src변수 사이에 dest가 가리키는 메모리의 크기를 적는 매개 변수가 추가.*/

/* 
1. private: 
-> private으로 선언된 멤버는 클래스 외부에서 접근할 수 없으며, 오직 클래스 내부의 멤버 함수에서만 접근할 수 있음.
--> 즉, 해당 멤버는 클래스의 구현에만 영향을 미치며 외부에서는 숨겨져 있음.

2. public: 
-> public으로 선언된 멤버는 클래스 외부에서도 접근할 수 있음.
--> 따라서 클래스를 사용하는 코드에서 해당 멤버에 직접 접근하여 값을 읽거나 변경할 수 있음.
*/