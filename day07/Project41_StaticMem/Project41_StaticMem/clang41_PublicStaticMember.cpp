#include <iostream>
using namespace std;

class SoSimple
{
public: // 접근제한이 public
    static int simObjCnt; // 정적 멤버 변수로 객체의 개수를 저장하기 위한 변수 -> static 멤버변수 선언(클래스멤버)

public:
    // 생성자: 객체가 생성될 때마다 정적 멤버 변수를 증가시키는 역할을 함
    SoSimple()
    {
        simObjCnt++; // SoSimple 객체의 개수를 증가시킴
    }
};

// 정적 멤버 변수의 초기화
int SoSimple::simObjCnt = 0;

int main(void)
{
    // 현재까지 생성된 SoSimple 객체의 개수 출력
    cout << SoSimple::simObjCnt << "번째 SoSimple 객체" << endl;

    SoSimple sim1; // SoSimple 객체 생성
    SoSimple sim2; // SoSimple 객체 생성

    // 생성된 SoSimple 객체의 개수 출력
    cout << SoSimple::simObjCnt << "번째 SoSimple 객체" << endl;

    // 객체의 정적 멤버 변수에 접근하여 객체 개수 출력
    cout << sim1.simObjCnt << "번째 SoSimple 객체" << endl;
    cout << sim2.simObjCnt << "번째 SoSimple 객체" << endl;

    return 0;
}

/* 추가 설명
1. SoSimple 클래스에는 정적 멤버 변수 simObjCnt가 있음. 이 변수는 객체의 개수를 추적하기 위해 사용됨.

2. main 함수에서는 먼저 현재까지 생성된 SoSimple 객체의 개수를 출력.

3. SoSimple 클래스의 객체인 sim1과 sim2를 생성하면서 생성자가 호출되어 simObjCnt가 증가합니다.

4. 생성된 객체의 개수를 출력할 때 SoSimple::simObjCnt와 sim1.simObjCnt, sim2.simObjCnt 모두 사용할 수 있음. 
    -> 모든 객체가 정적 멤버 변수를 공유하기 때문에 동일한 값을 출력.

5. 이러한 방식을 통해 정적 멤버 변수를 활용하여 클래스의 모든 객체가 공유하는 정보를 추적

*/