#include <iostream>
using namespace std;

class Point {
public:
	int x; //=> x좌표 범위이상 0over 100under
	int y; //=> y좌표 범위이상 0over 100under
};

class Retacgle
{
public:
	Point upLeft;
	Point lowRight;

public:
	void ShowRecInfo()
	{
		cout << "좌 상단 : " << '[' << upLeft.x << ",";
		cout << upLeft.y << ']' << endl;
		cout << "우 상단 : " << '[' << lowRight.x << ",";
		cout << lowRight.y << ']' << endl << endl;
	}
};

int main(void) {
	Point pos1 = { -2, 4 };
	Point pos2 = { 5, 9 };
	Retacgle rec = { pos2,pos1 };
	rec.ShowRecInfo();
	return 0;
}