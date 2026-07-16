// CPP06_If.cpp
#include <iostream>
using namespace std;
// =====================================
int main() {
    // 조건문 -> true, false 다른 결과
    // if, if-else, if-elseif-else
    // bool : true, false를 저장할 수 있는 자료형
    // C는 true,false 없어서 1,0으로 사용함
    bool b = 10>=20
    // cout << boolalpha;
    cout << b << endl;
    // -------------------------
    if(b) {
        cout << "True" << endl;
    }else{
        cout << "False"<< endl;
    }
    // -------------------------
    if(b){
        cout << "True" << endl;
    }
    else if(10<20){
        cout << "Else False" << endl;
    }
    else{
        cout << "False" << endl;
    }
    // else는 필수가 아님.
    // 하나만 실행할 거라면, {} 생략 가능


} // =======================================