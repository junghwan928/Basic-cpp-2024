/*Vector 객체 생성하고 정수를 입력 받을때 마다 백터에 삽입하고 평균을 출력하시오*/
#include <iostream>
#include <vector>
#include <numeric> // accumulate 함수를 사용하기 위해 필요
using namespace std;

int main() {
    vector<int> numbers; // 정수를 저장할 벡터 생성
    int input;

    cout << "정수를 입력하세요 (입력을 마치려면 0을 입력하세요):" << endl;

    // 사용자로부터 정수를 입력 받아서 벡터에 삽입
    while (true) {
        cin >> input;
        if (input == 0) // 입력이 0이면 입력 종료
            break;
        numbers.push_back(input);
    }

    if (numbers.empty()) { // 벡터가 비어있으면 평균을 계산할 필요 없음
        cout << "입력된 숫자가 없습니다." << endl;
    }
    else {
        // accumulate 함수를 사용하여 벡터의 원소들의 합을 계산
        int sum = accumulate(numbers.begin(), numbers.end(), 0);
        double average = static_cast<double>(sum) / numbers.size(); // 평균 계산
        cout << "입력된 숫자의 평균은 " << average << "입니다." << endl;
    }

    return 0;
}
