#include <iostream>
#include <string> // std::string을 사용하기 위한 헤더 파일
using namespace std;

class First
{
private:
    string strOne; // char* 대신에 std::string 사용
public:
    First(const char* str) : strOne(str) // std::string으로 초기화
    {
    }
    virtual ~First()
    {
        cout << "~First()" << endl;
    }
};

class Second : public First
{
private:
    string strTwo; // char* 대신에 std::string 사용
public:
    Second(const char* str1, const char* str2) : First(str1), strTwo(str2) // std::string으로 초기화
    {
    }
    virtual ~Second()
    {
        cout << "~Second()" << endl;
    }
};

int main(void)
{
    /*
    상속 관계에 있어서 객체포인터는 조심해야함
    보모타입의 객체 포인터로 자식 객체를 가리키는 경우(다형성) 조심, 조심 또 조심
    */
    First* ptr = new Second("simple", "complex");
    delete ptr;
    return 0;
}
