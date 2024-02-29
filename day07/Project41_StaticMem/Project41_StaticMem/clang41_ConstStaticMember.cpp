#include <iostream>
using namespace std;

// 국가 면적을 저장하는 클래스 정의
class CountryArea
{
public:
    // 정적 상수 멤버 변수로 각 국가의 면적을 저장
    const static int RUSSIA = 1707540;
    const static int CANADA = 998467;
    const static int CHINA = 9572950;
    const static int SOUTH_KR = 9922;
};

int main(void)
{
    // 각 국가의 면적 출력
    cout << "Russia Area : " << CountryArea::RUSSIA << "km" << endl;
    cout << "Canada Area : " << CountryArea::CANADA << "km" << endl;
    cout << "China Area : " << CountryArea::CHINA << "km" << endl;
    cout << "South Korea Area : " << CountryArea::SOUTH_KR << "km" << endl;

    return 0;
}

/* 추가 설명
1. CountryArea 클래스는 멤버 변수를 가지지 않고, 모든 멤버가 정적 상수.
2. RUSSIA, CANADA, CHINA, SOUTH_KR은 각각 러시아, 캐나다, 중국, 대한민국의 면적을 저장하는 상수.
3. main 함수에서는 CountryArea 클래스의 정적 멤버 변수를 사용하여 각 국가의 면적을 출력.
4. 정적 멤버 변수는 클래스의 모든 객체에 대해 공유되므로 클래스 이름과 범위 지정 연산자 ::를 사용하여 접근.
5. 이러한 방식으로 각 국가의 면적을 효율적으로 관리하고, 코드의 가독성을 높일 수 있음.
*/