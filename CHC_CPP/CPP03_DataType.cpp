// CPP03_DataType.cpp
// 출력 입력 자료형 형변환 연산자 조건문 반복문 배열 함수 
// 앞으로 새로운 파일 만들면 무 족 건 기 본 셋 팅!!!
#include <iostream>
#include <iomanip> // 소수점 결정
#include <vector>
// ===========================================================
using namespace std;
void PrintVector(vector<int> ddd){
    for(int i=0 ; i<ddd.size() ; i++){
        cout << ddd[i] << " ";
    }   cout << endl;
}
// ========================================================================
int main(){
    // 자료형(Data Type) C자료형 + C++ 자료형
    cout << "------------- Primitive Type ----" << endl;
    // 기본 자료형 -> 객체 X -> 자료형이 함수를 가지고 있지 X
    int jungSuuuuu = 123;
    printf("Int : %d\n", jungSuuuuu);
    cout << "Int : " << jungSuuuuu << endl;
    double twotimes = 1.232322322231; // C++은 변수에 한글을 허용함.
    cout << twotimes << endl; // 절대로 쓰지 마세요!!
    printf("%.2lf\n", twotimes);

    // (한숨) 소수점 결정하기 > #include <iomanip>
    cout << fixed << setprecision(2) << twotimes << endl;;
    // ------------------------------------------------------
    // 문자열 문자
    char ch = 'A'; // 1개, ' ' 작은 따옴표
    char str[99] = "sdffsdadsdadsd"; //C는 개수 반드시 지정
    // C의 가변길이 문자열 -> 동적 할당법
    // C++ 가변길이 문자열 -> 연결리스트 형식
    string str2 = "Tk";
    str2 = "Tkk";

    printf("C String : %s\n", str); // 기본 문법
    printf("C String : %s\n", str2.c_str()); // 객체. 일 시키기(매소드)
    cout << str2 <<", " << str << endl;

    // ------------------------------------------------------------
    // bool. 타입.
    // 기존의 C는 true, false 자료형이 없어서 1과 0으로 사용했음
    // 하지만 C++에서는 이를 true, false 라는 자료형을 만들었음.
    bool b1 = true; // Python True / Java true
    bool b2 = false; // true : 1취급, false :  0취급
    printf("b1 : %d\n", b1); // 1
    printf("b2 : %d\n", b2); // 0
    cout << boolalpha;
    cout << "C ++ b1 : " << b1 << endl; // ??????? 1 나오는데요???????
    cout << "C ++ b2 : " << b2 << endl; // boolalpha 설정하세요.
    // 저 타자가 넘 느려요 ㅠㅠㅠ -> speed coder 가서 연습
    cout << noboolalpha; // 싫어요 돌려줘요
    // =================================================
    cout << "-------------------------" << endl;
    // < 배열 >
    // C : int ary[??], Java : ArrayList, Python : [] List
    // C++ : vector -> ⭐⭐⭐
    // Vector의 특징
    // 1. 용량 한계가 없음
    // 2. 일반 배열처럼 인덱스도 쓸 수 있고 추가 기능도 많음
    // 3. int double float, string등 다양한 자료형으로 사용 가능
    // 4. 일반 배열보다 삽입 삭제 성능 좋고 심지어 정렬까지 가능....!!!!
    // 5. 대신, 얘 잘 다루려면 Iterator(이터레이터)를 다뤄야함.  (쫌 어렵.)
    // ---------------------------------------
    // 벡터 만들기 -> import vector 
    // #include <vector>
    // vector<뭐로만들래> 백터이름;
    // vector<뭐로만들래> 백터이름 = {1,2,3,123,23}; 초기값 설정
    vector<int> qwer; // 아무것도 없는 벡터 -> 알바생.
    // 벡터에 데이터 넣기 -> back 알바한테 시켜야함. 알바이름.시킬꺼
    qwer.push_back(10); // 맨 뒤에 10 넣음.
    cout << qwer[0] << endl;
    cout << qwer[1] << endl; // 쓰레기값.

    // 반복문으로 20부터 30까지 넣읍시다.
    for(int i=20; i<=30;i++){
        qwer.push_back(i);
    }
    // 벡터의 모든 내용 출력하기.
    // C에서는 배열의 크기를 알아내려면 쌩 쑈를 해야 하는데, 얘는 size 있음.
    qwer.size(); // java -> length, python -> len()
    for(int i=0; i<qwer.size(); i++){
        cout << qwer[i] << " ";
    } cout << endl;

    PrintVector(qwer); // C 포인터




    





















} // =============================================================

