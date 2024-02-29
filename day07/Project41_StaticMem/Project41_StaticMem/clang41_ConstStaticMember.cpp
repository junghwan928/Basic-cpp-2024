#include <iostream>
using namespace std;

// ���� ������ �����ϴ� Ŭ���� ����
class CountryArea
{
public:
    // ���� ��� ��� ������ �� ������ ������ ����
    const static int RUSSIA = 1707540;
    const static int CANADA = 998467;
    const static int CHINA = 9572950;
    const static int SOUTH_KR = 9922;
};

int main(void)
{
    // �� ������ ���� ���
    cout << "Russia Area : " << CountryArea::RUSSIA << "km" << endl;
    cout << "Canada Area : " << CountryArea::CANADA << "km" << endl;
    cout << "China Area : " << CountryArea::CHINA << "km" << endl;
    cout << "South Korea Area : " << CountryArea::SOUTH_KR << "km" << endl;

    return 0;
}

/* �߰� ����
1. CountryArea Ŭ������ ��� ������ ������ �ʰ�, ��� ����� ���� ���.
2. RUSSIA, CANADA, CHINA, SOUTH_KR�� ���� ���þ�, ĳ����, �߱�, ���ѹα��� ������ �����ϴ� ���.
3. main �Լ������� CountryArea Ŭ������ ���� ��� ������ ����Ͽ� �� ������ ������ ���.
4. ���� ��� ������ Ŭ������ ��� ��ü�� ���� �����ǹǷ� Ŭ���� �̸��� ���� ���� ������ ::�� ����Ͽ� ����.
5. �̷��� ������� �� ������ ������ ȿ�������� �����ϰ�, �ڵ��� �������� ���� �� ����.
*/