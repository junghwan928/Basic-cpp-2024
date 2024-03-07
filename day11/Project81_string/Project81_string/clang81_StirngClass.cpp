#include <iostream>
#include <cstring>
using namespace std;

class String
{
private:
    int len;    // ���ڿ� ���̸� �����ϴ� ��� ����
    char* str;  // ���ڿ��� �����ϴ� ������

public:
    // ������
    String();
    String(const char* s);
    String(const String& s);
    // �Ҹ���
    ~String();
    // ���� ������ �����ε�
    String& operator= (const String& s);
    // ���� ���� ������ �����ε�
    String& operator+= (const String& s);
    // ���� �� ������ �����ε�
    bool operator== (const String& s);
    // ���ڿ� ���� ������ �����ε�
    String operator+ (const String& s);

    // ��� ������ �����ε�
    friend ostream& operator<< (ostream& os, const String& s);
    // �Է� ������ �����ε�
    friend istream& operator>> (istream& is, String& s);
};

// �⺻ ������ ����
String::String()
{
    len = 0;
    str = nullptr; // �����͸� �ʱ�ȭ
}

// ���ڿ��� �޾Ƽ� �ʱ�ȭ�ϴ� ������ ����
String::String(const char* s)
{
    len = strlen(s) + 1; // �� ���� ���ڱ��� ����Ͽ� ���ڿ� ���� ���
    str = new char[len]; // �������� �޸� �Ҵ�
    strcpy_s(str, len, s); // ���ڿ� ����
}

// ���� ������ ����
String::String(const String& s)
{
    len = s.len;
    str = new char[len];
    strcpy_s(str, len, s.str); // ���ڿ� ����
}

// �Ҹ��� ����
String::~String()
{
    if (str != nullptr)
        delete[] str; // �������� �Ҵ�� �޸� ����
}

// ���� ������ �����ε�
String& String::operator= (const String& s)
{
    if (str != nullptr)
        delete[] str; // ���� �޸� ����

    len = s.len;
    str = new char[len];
    strcpy_s(str, len, s.str); // ���ڿ� ����

    return *this;
}

// ���� ���� ������ �����ε�
String& String::operator+= (const String& s)
{
    len += (s.len - 1); // ���� ���ڿ� ���̿� �߰��� ���ڿ� ���̸�ŭ ����
    char* tempstr = new char[len];
    strcpy_s(tempstr, len, str); // ���� ���ڿ� ����
    strcat_s(tempstr, len, s.str); // ���� ���ڿ� �߰�

    if (str != nullptr)
        delete[] str; // ���� �޸� ����

    str = tempstr; // ������ ����
    return *this;
}

// ���� �� ������ �����ε�
bool String::operator== (const String& s)
{
    return strcmp(str, s.str) == 0; // strcmp �Լ� ����� ���� true �Ǵ� false ��ȯ
}

// ���ڿ� ���� ������ �����ε�
String String::operator+ (const String& s)
{
    char* tempstr = new char[len + s.len - 1];
    strcpy_s(tempstr, len + s.len - 1, str); // ù ��° ���ڿ� ����
    strcat_s(tempstr, len + s.len - 1, s.str); // �� ��° ���ڿ� �߰�

    String temp(tempstr); // ���ο� String ��ü ����
    delete[] tempstr; // �������� �Ҵ�� �޸� ����
    return temp; // ���ο� ��ü ��ȯ
}

// ��� ������ �����ε�
ostream& operator<< (ostream& os, const String& s)
{
    os << s.str; // ���ڿ� ���
    return os; // ��Ʈ�� ��ȯ
}

// �Է� ������ �����ε�
istream& operator>> (istream& is, String& s)
{
    char str[100];
    is >> str; // ���ڿ� �Է� �ޱ�
    s = String(str); // �Է� ���� ���ڿ��� String ��ü �ʱ�ȭ
    return is; // ��Ʈ�� ��ȯ
}

int main(void)
{
    String str1 = "I like "; // String ��ü ���� �� �ʱ�ȭ
    String str2 = "string class"; // String ��ü ���� �� �ʱ�ȭ
    String str3 = str1 + str2; // �� ���ڿ��� �����Ͽ� ���ο� String ��ü ����

    cout << str1 << endl; // ���ڿ� ���
    cout << str2 << endl; // ���ڿ� ���
    cout << str3 << endl; // ���ڿ� ���

    str1 += str2; // ���ڿ� �����Ͽ� ���� ��ü�� ����
    if (str1 == str3) // ���ڿ� ���� ��
        cout << "���� ���ڿ�!" << endl;
    else
        cout << "�������� ���� ���ڿ�!" << endl;

    String str4; // �� ���ڿ� ��ü ����
    cout << "���ڿ� �Է�: ";
    cin >> str4; // ���ڿ� �Է� �ޱ�
    cout << "�Է��� ���ڿ�: " << str4 << endl; // �Է��� ���ڿ� ���
    return 0;
}
