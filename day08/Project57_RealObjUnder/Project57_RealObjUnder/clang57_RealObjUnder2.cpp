#include <iostream>
using namespace std;

// 클래스 Data를 흉내낸 영역
typedef struct Data
{
    int data; // 데이터 멤버 변수
    void (*ShowData)(Data*); // 데이터를 출력하는 함수 포인터 = showdata 멤버함수 선언
    void (*Add)(Data*, int); // 데이터를 더하는 함수 포인터 = add 멤버 함수 선언
} Data;

// 데이터 출력 함수
void ShowData(Data* THIS) // showdata 멤버함수 정의
{
    cout << "Data: " << THIS->data << endl;
}

// 데이터 더하는 함수 add 멤버 함수 정의
void Add(Data* THIS, int num)
{
    THIS->data += num;
}

// 적절히 변경된 main 함수
int main(void)
{
    // Data 구조체를 이용하여 객체 생성 및 초기화
    Data obj1 = { 15, ShowData, Add }; // Data  구조체 변수 obj1 선언과 초기화 
    Data obj2 = { 7, ShowData, Add };

    // 객체의 데이터 조작 및 출력
    obj1.Add(&obj1, 17);
    obj2.Add(&obj2, 9);
    obj1.ShowData(&obj1);
    obj2.ShowData(&obj2);

    return 0;
};

/*
1. typedef struct Data를 이용하여 구조체를 정의하고, 해당 구조체를 Data라는 이름으로 typedef하여 사용.

2. Data 구조체 내부에는 데이터 멤버 변수 data와 함수 포인터 두 개(ShowData, Add)가 선언.

3. ShowData 함수는 객체의 데이터를 출력하는 함수로, 객체의 주소를 인자로 받음.

4. Add 함수는 객체의 데이터를 더하는 함수로, 객체의 주소와 더할 값을 인자로 받음.

5. main 함수에서는 Data 구조체를 이용하여 두 개의 객체(obj1, obj2)를 생성하고 초기화. 이후에는 해당 객체들의 데이터를 조작하고 출력
*/