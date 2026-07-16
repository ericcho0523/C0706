// CPP04_InputTest.cpp
// 1. 기본세팅 진행
// 2. 자기소개를 위해서 아래 변수 생성
//    이름(name), 나이(age), 주소(address)
// 3. 키보드로 입력받아 이름, 나이, 주소 세팅
//    이때, 뭐 입력하라고 UI 잘 만드세요
// 4. 모두 입력이 끝나면 자기소개를 진행하세요.
// 예시.
// 안녕하세요 강대성입니다.
// 서울시 마포구에 살고요, 나이는 33 입니다.
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string name;
    int age;
    string address;

    cout << "Enter name :" << endl;
    cin >> name;
    cout << "Enter age :" << endl;
    cin >> age; // 엔터 후 종료됨.
    cout << "Enter address :" << endl;
    cin.ignore();
    getline(cin, address);
    cout << "Hello " << "my name is "<< name << endl;
    cout << "I live at " << address << endl;
    cout << "My age is " << age << endl;
    



    
}
