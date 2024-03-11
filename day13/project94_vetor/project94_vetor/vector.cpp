/*Vector ��ü �����ϰ� ������ �Է� ������ ���� ���Ϳ� �����ϰ� ����� ����Ͻÿ�*/
#include <iostream>
#include <vector>
#include <numeric> // accumulate �Լ��� ����ϱ� ���� �ʿ�
using namespace std;

int main() {
    vector<int> numbers; // ������ ������ ���� ����
    int input;

    cout << "������ �Է��ϼ��� (�Է��� ��ġ���� 0�� �Է��ϼ���):" << endl;

    // ����ڷκ��� ������ �Է� �޾Ƽ� ���Ϳ� ����
    while (true) {
        cin >> input;
        if (input == 0) // �Է��� 0�̸� �Է� ����
            break;
        numbers.push_back(input);
    }

    if (numbers.empty()) { // ���Ͱ� ��������� ����� ����� �ʿ� ����
        cout << "�Էµ� ���ڰ� �����ϴ�." << endl;
    }
    else {
        // accumulate �Լ��� ����Ͽ� ������ ���ҵ��� ���� ���
        int sum = accumulate(numbers.begin(), numbers.end(), 0);
        double average = static_cast<double>(sum) / numbers.size(); // ��� ���
        cout << "�Էµ� ������ ����� " << average << "�Դϴ�." << endl;
    }

    return 0;
}
