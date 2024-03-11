#include <iostream>
#include <string>
using namespace std;
class Product {
    int id;
    string price, description, producer;
public:
    Product() {}
    Product(int id, string price, string des, string pro) {
        this->id = id; this->price = price;
        description = des; producer = pro;
    }
    virtual void show() = 0; // 부모 클래스에서 자식 클래스의 함수를 접근하기위해
    // 순수 가상 함수 사용
    int getId() { return id; }
    string getPrice() { return price; }
    string getDes() { return description; }
    string getPro() { return producer; }
};
class Book : public Product {
    string isbn, author, bookName;
public:
    Book(int id, string des, string pro, string price, string bookName, string author, string isbn) :Product(id, price, des, pro) {
        this->isbn = isbn; this->author = author; this->bookName = bookName;
    }
    void show();
    string getName() { return bookName; }
    string getAut() { return author; }
    string getISBN() { return isbn; }
};
void Book::show() {
    cout << "--- 상품ID : " << getId() << endl;
    cout << "상품설명 : " << getDes() << endl;
    cout << "생산자 : " << getPro() << endl;
    cout << "가격 : " << getPrice() << endl;
    cout << "책제목 : " << bookName << endl;
    cout << "저자 : " << author << endl;
    cout << "ISBN : " << isbn << endl;
}
class CompactDisc : public Product {
    string title, singer;
public:
    CompactDisc(int id, string des, string pro, string price, string title, string singer) : Product(id, price, des, pro) {
        this->title = title; this->singer = singer;
    }
    void show();
};
void CompactDisc::show() {
    cout << "--- 상품ID : " << getId() << endl;
    cout << "상품설명 : " << getDes() << endl;
    cout << "생산자 : " << getPro() << endl;
    cout << "가격 : " << getPrice() << endl;
    cout << "앨범제목 : " << title << endl;
    cout << "가수 : " << singer << endl;
}
class ConversationBook : public Book {
    string language;
public:
    ConversationBook(int id, string des, string pro, string price, string bookName, string author, string lan, string isbn)
        :Book(id, des, pro, price, bookName, author, isbn) {
        this->language = lan;
    }
    void show();
};
void ConversationBook::show() {
    cout << "--- 상품ID : " << getId() << endl;
    cout << "상품설명 : " << getDes() << endl;
    cout << "생산자 : " << getPro() << endl;
    cout << "가격 : " << getPrice() << endl;
    cout << "책제목 : " << getName() << endl;
    cout << "저자 : " << getAut() << endl;
    cout << "언어 : " << language << endl;
    cout << "ISBN : " << getISBN() << endl;
}
int main() {
    Product* p[100];
    int id = 0;
    string des, pro, price, isbn, aut, name, title, singer, lan;
    //설명,생산자,가격,isbn번호,작가,책이름,앨범제목,가수,언어
    cout << "***** 상품 관리 프로그램을 작동합니다 *****" << endl;
    for (;;) {
        cout << "상품 추가(1), 모든 상품 조회(2), 끝내기(3) ? ";
        int n;
        cin >> n;
        if (n == 1) {
            if (id >= 100) break;
            cout << "상품 종류 책(1), 음악CD(2), 회화책(3) ? ";
            cin >> n;
            cin.ignore(); // 해주지 않으면 버퍼 문제때문에 입력오류
            if (n == 1) {
                cout << "상품설명>>"; getline(cin, des);
                cout << "생산자>>"; getline(cin, pro);
                cout << "가격>>"; getline(cin, price);
                cout << "책제목>>"; getline(cin, name);
                cout << "저자>>"; getline(cin, aut);
                cout << "ISBN>>"; getline(cin, isbn);
                Book* b = new Book(id, des, pro, price, name, aut, isbn);
                p[id] = b;
                ++id;
            }
            else if (n == 2) {
                cout << "상품설명>>"; getline(cin, des);
                cout << "생산자>>"; getline(cin, pro);
                cout << "가격>>"; getline(cin, price);
                cout << "앨범제목>>"; getline(cin, title);
                cout << "가수>>"; getline(cin, singer);
                CompactDisc* c = new CompactDisc(id, des, pro, price, title, singer);
                p[id] = c;
                ++id;
            }
            else if (n == 3) {
                cout << "상품설명>>"; getline(cin, des);
                cout << "생산자>>"; getline(cin, pro);
                cout << "가격>>"; getline(cin, price);
                cout << "책제목>>"; getline(cin, name);
                cout << "저자>>"; getline(cin, aut);
                cout << "언어>>"; getline(cin, lan);
                cout << "ISBN>>"; getline(cin, isbn);
                ConversationBook* cb = new ConversationBook(id, des, pro, price, name, aut, lan, isbn);
                p[id] = cb;
                ++id;
            }
            else
                cout << "숫자 입력 오류" << endl;
        }
        else if (n == 2) {
            for (int i = 0; i < id; ++i)
                p[i]->show();
        }
        else if (n == 3) {
            break;
        }
        else
            cout << "숫자 입력 오류" << endl;
        cout << endl;
    }
}