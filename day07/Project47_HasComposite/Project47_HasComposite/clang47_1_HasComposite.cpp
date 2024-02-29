#include <iostream>
#include <cstring>
using namespace std;

class Gun
{
private:
    int bullet;     // 장전된 총알의 수

public:
    // 생성자: 초기 총알 수를 설정
    Gun(int bnum) : bullet(bnum)
    { }

    // 총을 쏘는 함수
    void Shut()
    {
        cout << "BBANG!" << endl;
        bullet--;
    }

    // 총알 수를 반환하는 함수
    int getBulletCount() const
    {
        return bullet;
    }
};

class Police
{
private:
    int handcuffs;    // 소유한 수갑의 수
    Gun* pistol;     // 소유하고 있는 권총

public:
    // 생성자: 총알 수와 수갑 수를 받아 초기화
    Police(int bnum, int bcuff) : handcuffs(bcuff)
    {
        // 총알 수가 0보다 크면 총 객체 생성, 아니면 NULL로 설정
        if (bnum > 0)
            pistol = new Gun(bnum);
        else
            pistol = nullptr;
    }

    // 수갑을 채우는 함수
    void PutHandcuff()
    {
        cout << "SNAP!" << endl;
        handcuffs--;
    }

    // 총을 쏘는 함수
    void Shut()
    {
        // 총을 소유하고 있는지 확인 후 쏨
        if (pistol == nullptr)
            cout << "Hut BBANG!" << endl;
        else
            pistol->Shut();
    }

    // 소멸자: 동적으로 할당된 메모리 해제
    ~Police()
    {
        if (pistol != nullptr)
            delete pistol;
    }

    // 권총 총알 수를 반환하는 함수
    int getPistolBulletCount() const
    {
        if (pistol != nullptr)
            return pistol->getBulletCount();
        else
            return 0; // 권총이 없으면 0 반환
    }
};

int main(void)
{
    Police pman1(5, 3); // 총알 5발, 수갑 3개를 가진 경찰
    pman1.PutHandcuff(); // 수갑 사용
    pman1.Shut();       // 총 쏨
    cout << "현재 권총 총알 수: " << pman1.getPistolBulletCount() << ", 현재 수갑 수: " << pman1.getPistolBulletCount() << endl;

    Police pman2(0, 3); // 총알을 가지고 있지 않은 경찰
    pman2.PutHandcuff(); // 수갑 사용
    pman2.Shut();       // 총을 쏠 수 없음
    cout << "현재 권총 총알 수: " << pman2.getPistolBulletCount() << " , " << pman2.getPistolBulletCount() << endl;

    return 0;
}
