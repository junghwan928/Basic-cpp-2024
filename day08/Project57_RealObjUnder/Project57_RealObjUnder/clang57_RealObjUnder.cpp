#include <iostream>
using namespace std;

// Data 클래스 정의
class Data
{
private:
    int data; // private 멤버 변수로 정수형 data 선언
public:
    // 생성자: 매개변수를 통해 data 멤버 변수 초기화
    Data(int num) : data(num)
    {
    }

    // ShowData 멤버 함수: data 값을 출력하는 함수
    void ShowData()
    {
        cout << "Data: " << data << endl;
    }

    // Add 멤버 함수: 매개변수로 받은 값을 data에 더하는 함수
    void Add(int num)
    {
        data += num;
    }
};

// main 함수
int main(void)
{
    // Data 클래스의 객체 obj를 생성하고, 초기값으로 15를 전달하여 초기화
    Data obj(15);

    // obj의 Add 함수를 호출하여 17을 더함
    obj.Add(17);

    // obj의 ShowData 함수를 호출하여 data 값을 출력
    obj.ShowData();

    return 0;
}

/*
1. Data 클래스가 정의됩니다. 이 클래스에는 private으로 정의된 정수형 멤버 변수 data가 있음.

2. 생성자 Data(int num)은 매개변수 num을 받아서 data 멤버 변수를 초기화.

3. ShowData() 멤버 함수는 data 값을 출력.

4. Add(int num) 멤버 함수는 매개변수 num을 받아서 data에 더함.

5. main 함수에서는 Data 클래스의 객체 obj를 생성하고, 초기값으로 15를 전달하여 초기화.

6. obj의 Add 함수를 호출하여 17을 더함.

7. obj의 ShowData 함수를 호출하여 data 값을 출력합니다. 출력 결과는 "Data: 32"가 됨
*/