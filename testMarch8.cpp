#include <iostream>
#include <string>
using namespace std;

// 부모 클래스 Product 정의
class Product {
private:
    int id;
    double price;
    string producer;
public:
    
    // 생성자
    Product(int _id, double _price, string _producer) : id(_id), price(_price), producer(_producer) {}
    
    // 가격 반환
    double getPrice() const {
        return price;
    }
    
    // 가격 설정
    void setPrice(double _price) {
        price = _price;
    }
    
    // 가격 출력
    virtual void print() const = 0; // 순수 가상 함수
    
    // 가상 소멸자 추가
    virtual ~Product() {}
    
    // ID 반환
    int getId() const {
        return id;
    }
    // 제조사 반환
    string getProducer() const {
        return producer;
    }
};

// 자식 클래스 Book 정의
class Book : public Product {
private:
    string ISBN;
    string title;

public:
    // 생성자
    Book(int _id, double _price, string _producer, string _ISBN, string _title)
        : Product(_id, _price, _producer), ISBN(_ISBN), title(_title) {}
    // 상품 정보 출력
    virtual void print() const override {
        cout << "Book ID : " << getId() << ", ISBN : " << ISBN << ", Title : " << title << ", Price :" << getPrice() << ", Producer : " << getProducer() << endl;
    }
};

// 자식 클래스 Handphone 정의
class Handphone : public Product {
private:
    string model;
    int RAM;
public:
    // 생성자
    Handphone(int _id, double _price, string _producer, string _model, int _RAM)
        : Product(_id, _price, _producer), model(_model), RAM(_RAM) {}
    // 상품 정보 출력
    virtual void print() const override {
        cout << "Handphone ID: " << getId() << ", Model : " << model << ", RAM : " << RAM << "GB, Price :" << getPrice() << ", Producer : " << getProducer() << endl;
    }
};

// 자식 클래스 Computer 정의
class Computer : public Product {
private:
    string model;
    string cpu;
    int RAM;
public:
    // 생성자
    Computer(int _id, double _price, string _producer, string _model, string _cpu, int _RAM)
        : Product(_id, _price, _producer), model(_model), cpu(_cpu), RAM(_RAM) {}
    // 상품 정보 출력
    virtual void print() const override {
        cout << "Computer ID :x " << getId() << ", Model : " << model << ", CPU : " << cpu << ", RAM : " << RAM << "GB, Price : " << getPrice() << ", Producer : " << getProducer() << endl;
    }
};

// 상품을 검색하는 함수
void searchProduct(Product *products[], int count, int targetId) {
    for (int i = 0; i < count; ++i) {
        if (products[i]->getId() == targetId) {
            products[i]->print();
            return;
        }
    }
    cout << "해당 ID의 상품을 찾을 수 없습니다." << endl;
}

int main() {
    Product *products[100]; // 객체 포인터 배열

    int choice;
    int count = 0; // 현재 추가된 상품 수

    // 메인 메뉴 출력
    while (true) {
        cout << "상품관리 프로그램" << endl;
        cout << "1. 상품추가  2. 상품출력  3. 상품검색  0. 종료" << endl;
        cout << "선택: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int subChoice;
                cout << "1. 책  2. 핸드폰  3. 컴퓨터" << endl;
                cout << "선택: ";
                cin >> subChoice;

                switch (subChoice) {
                    case 1: {
                        int id;
                        double price;
                        string producer, ISBN, title;
                        cout << "책 정보 입력" << endl;
                        cout << "ID: ";
                        cin >> id;
                        cout << "가격: ";
                        cin >> price;
                        cout << "제조사: ";
                        cin >> producer;
                        cout << "ISBN: ";
                        cin >> ISBN;
                        cout << "제목: ";
                        cin >> title;
                        products[count++] = new Book(id, price, producer, ISBN, title);
                        cout << "책이 추가되었습니다." << endl;
                        break;
                    }
                    case 2: {
                        int id, RAM;
                        double price;
                        string producer, model;
                        cout << "핸드폰 정보 입력" << endl;
                        cout << "ID: ";
                        cin >> id;
                        cout << "가격: ";
                        cin >> price;
                        cout << "제조사: ";
                        cin >> producer;
                        cout << "모델: ";
                        cin >> model;
                        cout << "RAM (GB): ";
                        cin >> RAM;
                        products[count++] = new Handphone(id, price, producer, model, RAM);
                        cout << "핸드폰이 추가되었습니다." << endl;
                        break;
                    }
                    case 3: {
                        int id, RAM;
                        double price;
                        string producer, model, cpu;
                        cout << "컴퓨터 정보 입력" << endl;
                        cout << "ID: ";
                        cin >> id;
                        cout << "가격: ";
                        cin >> price;
                        cout << "제조사: ";
                        cin >> producer;
                        cout << "모델: ";
                        cin >> model;
                        cout << "CPU: ";
                        cin >> cpu;
                        cout << "RAM (GB): ";
                        cin >> RAM;
                        products[count++] = new Computer(id, price, producer, model, cpu, RAM);
                        cout << "컴퓨터가 추가되었습니다." << endl;
                        break;
                    }
                    default:
                        cout << "잘못된 선택입니다." << endl;
                }
                break;
            }
            case 2: {
                cout << "추가된 상품 목록:" << endl;
                for (int i = 0; i < count; ++i) {
                    products[i]->print();
                }
                break;
            }
            case 3: {
                int targetId;
                cout << "검색할 상품의 ID를 입력하세요: ";
                cin >> targetId;
                searchProduct(products, count, targetId);
                break;
            }
            case 0: {
                // 메모리 해제
                for (int i = 0; i < count; ++i) {
                    delete products[i];
                }
                return 0;
            }
            default:
                cout << "잘못된 선택입니다." << endl;
        }
    }

    return 0;
}
