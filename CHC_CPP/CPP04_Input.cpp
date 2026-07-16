// CPP04_Input.cpp
#include <iostream>
#include <string> // string.h
using namespace std;
//=======================================
//=======================================
int main() {
    // 입력 : cin
    // 여러개 입력 > cin >> a >> b >> c...
    int i1, i2;
    cout << "Enter two integar : ";
    cin >> i1 >> i2;
    printf(" i1 : %d, i2 : %d\n", i1, i2);

    double d1, d2;
    cout << "Enter two number : ";
    cin >> d1 >> d2;
    printf("d1 : %lf, d2 : %lf\n", d1, d2);
    cout<<"d1 :"<<d1<<", d2 : "<<d2<<endl;

    string s1, s2;
    cout << "Enter favorite 2 singers : "<< endl;
    cin >> s1 >> s2; // 공백 기준 구분.
    cout << s1 << ", " << s2 << endl;
    
    // 한줄 단위로 입력받기
    // C gets, fgets , C++ getline -> Enter 끝
    string s3;
    cout << "Enter 3 ingredients for maratang : ";
    cin.ignore(); // 버퍼에 남아있는 내용 제거.
    // scanf(" %s"~~)
    getline(cin, s3); // string import 필요 
    cout << s3 << endl; // 뭔가 이상함....
    // 1 2 1.1 1.2 2.2 () A B Hello World

















} // ====================================