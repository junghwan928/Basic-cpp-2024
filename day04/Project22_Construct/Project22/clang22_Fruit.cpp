#include <iostream>
using namespace std;

// 과일 판매자 클래스
class FruitSeller {
private:
    int Apple_Price;    // 사과 가격
    int numOfApples;    // 보유한 사과 개수
    int myMoney;        // 보유한 돈

public:
    // 생성자: 초기 가격, 사과 개수, 보유한 돈을 매개변수로 받아 초기화.
    FruitSeller(int price, int num, int money)
    {
        Apple_Price = price;
        numOfApples = num;
        myMoney = money;
    }

    // 사과를 판매하는 함수
    int SaleApples(int money)
    {
        int num = money / Apple_Price;  // 사과의 개수 계산
        numOfApples -= num;             // 보유한 사과 개수 감소
        myMoney += money;               // 판매 수익 증가
        return num;                     // 판매한 사과 개수 반환
    }

    // 현재 상태를 출력하는 함수
    void ShowSalesResult() const
    {
        cout << "남은 사과: " << numOfApples << endl;
        cout << "판매 수익: " << myMoney << endl;
    }
};

// 과일 구매자 클래스
class FruitBuyer {
public:
    // 생성자: 초기 돈을 매개변수로 받아 초기화.
    FruitBuyer(int money)
    {
        myMoney = money;
        numOfApples = 0;
    }

private:
    int myMoney;        // 보유한 돈
    int numOfApples;    // 보유한 사과 개수

    // 사과를 구매하는 함수
    void BuyApples(FruitSeller& seller, int money)
    {
        numOfApples += seller.SaleApples(money); // 판매자로부터 사과를 구매.
        myMoney -= money;                         // 보유한 돈을 감소.
    }

    // 현재 상태를 출력하는 함수
    void ShowBuyResult() const
    {
        cout << "현재 잔액: " << myMoney << endl;
        cout << "사과 개수: " << numOfApples << endl;
    }

    friend int main(); // main 함수에서 private 멤버에 접근할 수 있도록 friend 선언
};

int main(void) {
    FruitSeller seller(1000, 20, 0);   // 과일 판매자 객체 생성
    FruitBuyer buyer(5000);             // 과일 구매자 객체 생성
    buyer.BuyApples(seller, 2000);      // 사과를 구매.

    cout << "과일 판매자의 현황:" << endl;
    seller.ShowSalesResult();           // 판매자의 현황 출력
    cout << "과일 구매자의 현황:" << endl;
    buyer.ShowBuyResult();              // 구매자의 현황 출력
    return 0;
}
