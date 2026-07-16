// CPP08_Function.cpp
#include <iostream>
#include <vector>
using namespace std;
// =============================================================
//                   <  이                 론  >
// 0. 대전제 : 무조건 메인엔 최소한의 코드만 !!
//            2번이상 사용할 거면, 함수로 구현
// 1. 함수란 : 코드 묶어놓고, 부르면 실행되는 놈
//            컴퓨터와 나와의 약속?
// 2. 구성요소 : 리턴형 함수이름(매개변수들){실행}
//    리턴형 : 이 함수 끝나면, 부른놈한테 돌려줄것
//    함수이름 : 맘대로 지으시되, 오른쪽 갈수록
//              자세해지게 이름 작성 필요
//    예: 벡터를 2번출력하는 함수 -> PrintVector2
//    매개변수 : 이 함수가 실행하기위해 필요한 거 
//             이거를 작성한 개수가 실행시 안맞으면 에러남.
//    실행     : 이함수불리면 이거 실행함.
//    매개변수는 생략가능. 리턴은 없어도됨(void)
// ==============================================================
// 1. 매개변수 없고, 리턴 없고(void)
void Type1() {
    cout << "No mege , No return" << endl;
    cout << "If I do this " << endl;
    cout << "Print this things " << endl;
}
void Introduce(){
    cout << "Hello My name is Chan Hee" << endl;
    cout << "Nice to meet you" << endl;
    cout << "Thank you" << endl;
}
void Enter() {
    cout << "------------" << endl;
}
// ================================================================
// 2. 매개변수 있고, 리턴 없고
// ==================================================================
void Type2(int x){
    // Type2쓸려면, int형 하나 넣어야함 > x
    cout << "Entered Number1 : " << x << endl;


}
// ⭐ 오버로드(OverLoad)
// 매개변수의 개수,형태 다르면 같은 함수명 ㄱㅊ
// 1~4 모두 사용 가능, 1,3번 의미가...X
void Type2(int x, int y){
    // Type2쓸려면, int형 하나 넣어야함 > x
    cout << "Entered Number1 : " << x << endl;
    cout << "Entered Number2 : " << y << endl;


}
void Type2(double x, int y){
    // Type2쓸려면, int형 하나 넣어야함 > x
    cout << "Entered Number1 : " << x << endl;
    cout << "Entered Number2 : " << y << endl;


}
// 숫자를 1개,2개,3개,4개 받아서 합계 출력
// SumNumber 함수를 제작하세요.
void SumNumber(int a){
    cout << "Sum :" << a << endl;
}
void SumNumber(int b,int c){
    cout << "Sum :" << b + c << endl;
    
}
void SumNumber(int d,int e, int f){
    cout << "Sum :" << d + e + f << endl;
    
}
void SumNumber(int q,int w, int s, int f){
    cout << "Sum :" << q+w+s+f << endl;
    
}
// Initvector 구현
void Initvector(vector<int>& v){
    // <생각> 원본이 바뀔까...?
    for(int i=0; i<10; i++){
        v.push_back(i+1);
    }
}
// PrintVector
void PrintVector(vector<int> v){
    // v 개수 알 수 없음.
    for(int i:v){
        cout << i << " ";
        cout << endl;
    }
}
// 참고용....
#include <stdlib.h>
void CAryPrint(int *ary, int size){
    // 배열은 사실 포인터 변수
    for(int i=0;i<size; i++){
        *(ary+i) = i+1;
    }
    ary = (int*)malloc(40); // 원본 변경.

    // 포인터변수는 다른놈으로 변경가능
    // 레퍼런스 설정 했으면 절 대 안 바 뀜.
}

// Initvector 오버로드 이용해서 아래와 같이 튜닝
// 1. 벡터1개, 숫자 1개 -> 숫자 만큼 1~숫자 세팅
// Initvector(v,5) -> 1,2,3,4,5
// 2. 숫자 2개 -> 숫자1~숫자2 세팅
// Initvector(v,5,8) -> 5,6,7,8
// 3. 숫자 3개 -> 숫자1~숫자2 숫자 3만큼 점프
// Initvector(v,1,10,2) -> 1,3,5,7,9
// 각각 1~3번을 만들고 메인에서 실행 + PrintVector

void Initvector(vector<int>& v){
    for(int i=0; i<10; i++){
        v.push_back(i+1);
    }
}

void Initvector(vector<int>& v, int x){
    for(int i=0; i<x; i++){
        v.push_back(i+1);
    }
}

void Initvector(vector<int>& v, int x, int y){
    // <생각> 원본이 바뀔까...?
    for(int i=x;i<=y; i++){
        v.push_back(i);
    }
}

void Initvector(vector<int>& v, int x, int y, int z){

    for(int i=x; i<=y; i=i+z){
        v.push_back(i);
    }
}











// 3. 매개변수 없고, 리턴 있고 
// ==============================================
int Get10(){
    return 10;
}
string GetName(){
    string name = "Chanhee";
    return name;
    // return "Chanhee";
}
vector<int> GetVector(){
    // 함수안에서 함수를 사용 가능
    // 단, 그 함수가 "위에" 있어야 함.
    vector<int> v;
    Initvector(v, 10, 20);
    return v;
}
// 뭔가 리턴이 있다 -> Get

string menu(){
    // 메뉴 쫙 보여주고, 숫자로 고르라고 한후
    // 선택한 메뉴 리턴
    // 수육국밥, 순대국밥, 정식, 뼈해장국
    cout << "-----------------------"<< endl;
    cout << " 1. Su gukbab " << endl;
    cout << " 2. Dae gukbab " << endl;
    cout << " 3. Jungsik " << endl;
    cout << " 4. Bone " << endl;
    cout << "-----------------------"<< endl;
    cout << " Choose the Menu : ";
    string menu;
    int choice;
    cin >> choice;
    if(choice==1){
        menu = "Su gukbab";
        return menu;
    }else if(choice == 2){
        menu = "Dae gukbab";
        return menu;
    }else if(choice == 3){
        menu = "Jungsik";
        return menu;
    }else if(choice == 4){
        menu = "Bone";
        return menu;
    }else{
        menu = "Strange";
        return menu;
    }




}

// ===============================================================
// 4. 매개변수 있고, 리턴 있고
// ==============================================================
// 뭔가 받아서 처리해서 돌려주는 놈.

int GetNumber(int x){
    x += 10;
    x *= 2;
    return x;

}
vector<int> GetVector(int start, int end){
    vector<int> v;
    for(int i=start; i<=end; i++){
        v.push_back(i);
    }
    PrintVector(v);
    return v;
}
// 벡터 한개와 숫자 한개를 넘겨받아서
// 벡터의 모든 요소에 숫자 하나를 모두 더한 후
// 그 벡터를 다시 돌려주는 Getvector 구현
vector<int> Getvector(vector<int> v, int k){
    for(int& i:v){
        i += k;
    }
    return v;

}

// 메뉴이름 받아서, 기본, 맵게 물어보고 둘이
// 둘이 붙여서, 리턴해주는 GetMenuDetail

// =====================================================
int main() { // 메인 코드가 들어가는 곳
    // 함수를 사용하는 방법 -> 함수이름(필요한거)
    Type1();
    // for(int i=0;i<10;i++){
    //     Type1();
    // }
    // Ctrl + Space :자동완성 사용 
    Introduce();
    Enter();
    // -------------------------------------------------
    Type2(3);
    Type2(10,20);
    Type2(1.1,2);
    Enter();
    // -------------------------------------------------
    SumNumber(1);
    SumNumber(1,2);
    SumNumber(1,2,3);
    SumNumber(1,2,3,4);
    Enter();
    // ----------------------------------
    // 벡터를 이용한 함수활용
    vector<int> v1;
    // 1. 벡터를 걍 넘기면 1부터 10까지 InitVector
    Initvector(v1);
    PrintVector(v1); // 레퍼런스 안스면 원본변경X
    // vector<int> v2 = {1,2,3,4,5};
    // PrintVector(v2); // 원본이 바뀌지 않았다.
    // -------------------------------------------
    vector<int> v5;
    vector<int> v6;
    vector<int> v7;
    Initvector(v5, 5);
    PrintVector(v5); // 1 2 3 4 5
    Initvector(v6, 5, 8);
    PrintVector(v6); // 5 6 7 8
    Initvector(v7, 1, 10, 2);
    PrintVector(v7); // 1 3 5 7 9
    Enter(); 
    // ----------------------------------
    // 리턴은 있는데 매개변수는 없는 놈
    int num = Get10();
    string str = GetName();
    vector<int> v8 = GetVector();
    cout << "GetNum : "<< num << endl;
    cout << "GetString : "<< str << endl;
    cout << "GetVector : "<< endl;
    PrintVector(v8);
    Enter();
    string menu = ();
    cout << "Menu : " << menu << endl;
    // -------------------------------------
    Enter();
    vector<int> v9 = GetVector(10,20);
    PrintVector(v9);
    Enter();
    v9 = GetVector(v9, 999);
    PrintVector(v9);


    // < 과제 >
    // 프로그래머스 0단계 C++ 정답률 높은 순 100문제
    // > 푼 문제는 노션에 정리

    // > 지금까지 배운거 노션에 전부 정리.




    


}// ===============================================================
// 절대로 내려가지 마!!