/*
char ary[] = {'a','b', 'c', 'd', 'e', 'f'}

����: while���� if �������� �迭 ���� �ٲپ ������ ���
*/

#include <iostream>
using namespace std;

int main() {
    char ary[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int size = sizeof(ary) / sizeof(ary[0]);
    int start = 0;
    int end = size - 1;

    while (start < end) {
        // if ���� ����� Ư�� ���� �Ͽ����� ��Ҹ� ��ȯ
        // ���⼭�� �ܼ��� ���ø� �����ֱ� ���� ��� ��쿡 true�� ������ ���
        if (start < end) {
            char temp = ary[start];
            ary[start] = ary[end];
            ary[end] = temp;
        }

        start++;
        end--;

        // ���⼭ if ���� ����� �� �ִ� �ٸ� ����,
        // Ư�� ����(��: �ε����� ¦���� ��) �Ͽ����� �ε����� ������Ű�ų� ���ҽ�Ű�� ���Դϴ�.
        // �̴� �迭�� ������ �⺻ �������� ������ �����Ƿ� �����ؾ� �մϴ�.
    }

    // ������ �迭 ���
    for (int i = 0; i < size; i++) {
        cout << ary[i] << ' ';
    }
    cout << endl;

    return 0;
}


