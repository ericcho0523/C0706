// CPP07_Scope.cpp
#include <iostream>
#include <vector>
using namespace std; 
// =============================================================
int main() {
    // 스코프(Scope) : 범위
    // ⭐지역변수⭐
    // {안에} 선언된 변수
    int x = 10;
    vector<int> v;
    {
        int y = 20;
        vector<int> v2;
        cout << x + y << endl;
    } // y소멸
    cout << x + y << endl;
    v.push_back(1);
    v2.push_back(2);

    for(int i=0; i<10; i++){
        cout << i;
    } // i를 잠깐 쓰고 버릴 목적으로 안에 생성.
    cout << i << endl;
    // 개발자는, 항상 메모리를 소중히 해야 함.
    // 가능하다면, 다 쓴것은 버릴 수 있게 해야 함.

    if(true){
        int f = 999999;
    }
    cout << f << endl;
// void Function1() 
    {
        int fun = 100;
        cout << m << endl;   

    }
 // int main()
    {
        int m = 200;
        cout << fun << endl;

    }

} // ===========================================================
// 여러 프로그래밍 언어 공부할 때 헷갈린다면??
// 헷갈리는 이유 : 레벨이 다 비슷해서.
// 특정 분기점을 넘겨야함. -> PCCE Top
// C   : 이거 먼저!!
// C++ : 요거 위주 -> C헷갈림..