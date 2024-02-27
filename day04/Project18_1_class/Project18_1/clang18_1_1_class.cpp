#include <iostream>
using namespace std;

class FruitSeller {
private:
	int Apple_Price;
	int numOfApples;
	int myMoney;

public:
	void InitMember(int price, int num, int money) { // => 생성자(기능:객체를 생성하고, 초기화)
		Apple_Price = price;
		numOfApples = num; // 올바른 변수로 수정
		myMoney = money;
	}

	int SaleApples(int money)
	{
		int num = money / Apple_Price; //판매 갯수
		numOfApples -= num; // 팔고 난 뒤 남은 사과 갯수 => 
		myMoney += money; // 사과를 팔고 번 돈 => myMoney = myMoney + money;
		return num;

	}

	void ShowSalesResult()
	{
		cout << "남은 사과 개수 : " << numOfApples << endl;
		cout << "판매 수익 : " << myMoney << endl;
	}

};

class FruitBuyer {

	int numOfApples; //private
	int myMoney; //private

public:
	void InitMember(int money) {
		numOfApples = 0;
		myMoney = money;


	}
	void BuyApples(FruitSeller& seller, int money) {
		numOfApples += seller.SaleApples(money); // seller에게 지불한 금액으로 수정
		myMoney -= money; // 구매자의 잔액을 감소시킴
	}

	void ShowBuyResult()
	{
		cout << "현재 잔액 : " << myMoney << endl;
		cout << "판매 수익 : " << numOfApples << endl;
	}

};

int main(void) {
	FruitSeller seller;
	seller.InitMember(1000, 20, 0);
	FruitBuyer buyer;
	buyer.InitMember(5000);
	buyer.BuyApples(seller, 2000); // 과일 구매

	cout << "과일 판매자의 현황 : " << endl;
	seller.ShowSalesResult();
	cout << "과일 구매자의 현황 : " << endl;
	buyer.ShowBuyResult();
	return 0;
}

/*
1. FruitSeller 클래스:

	-> Apple_Price, numOfApples, myMoney라는 세 가지 멤버 변수를 가지고 있음.
		=> 각각은 사과의 가격, 남은 사과의 개수, 판매자의 보유 금액을 나타냄.

	->	InitMember 함수는 멤버 변수들을 초기화.
		=> 이 함수는 가격, 사과 개수, 보유 금액을 매개변수로 받아와서 멤버 변수에 할당.

		-> SaleApples 함수는 사과를 판매하는 메서드.
			=> 구매자로부터 받은 돈을 기반으로 판매하고, 판매된 사과의 개수와 판매 수익을 반환.

		-> ShowSalesResult 함수 = 남은 사과의 개수와 판매 수익을 출력.

2. FruitBuyer 클래스:

	-> numOfApples, myMoney라는 두 가지 멤버 변수를 가지고 있음.
		=> 각각은 구매한 사과의 개수, 구매자의 보유 금액을 나타냄.

	-> InitMember 함수는 멤버 변수들을 초기화.
		=> 초기에는 사과를 하나도 구매하지 않았으므로 numOfApples은 0.

	-> BuyApples 함수는 과일 판매자로부터 사과를 구매하는 메서드.
		=>판매자에게 돈을 주고, 판매된 사과의 개수를 증가시키고, 구매자의 잔액을 감소시킴.

	->ShowBuyResult 함수는 현재 보유 금액과 구매한 사과의 개수를 출력.


3. 메인 함수:
	-> main 함수에서는 먼저 과일 판매자와 과일 구매자 객체를 생성 후 -> 초기화.
	-> 구매자가 판매자로부터 사과를 구매하고, 거래 과정의 결과를 출력.

*/