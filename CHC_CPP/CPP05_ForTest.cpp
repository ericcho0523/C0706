// CPP05_ForTest.cpp
// < 반복문 벡터 레퍼런스 문제 >
#include <iostream>
#include <vector>
using namespace std;
int main() {
// 1. 벡터에 10 20 30 40 50 을 순서대로 넣고, 일반반복 이용해서 모두 출력
vector<int > v1; // = {10,20,30,40,50};
for(int i=0; i<5; i++){
    v1.push_back( (i+1) * 10); // 0 1 2 3 4 -> 1 2 3 4 5 -> 10 20 30 40 50
}
for(int i=0; i<5; i++){
    // cout << *(v1.begin()+i) << " ";
    cout << v1[i] << " ";
}
cout << endl;

// 2. 벡터에 1 2 3 4 5 넣고, 향상된 for문으로 모두 출력.
vector<int > v2;
for(int i=0; i<5; i++){
    v2.push_back( (i+1) ); 
}

} 

// 3. 벡터에 1~20까지 넣고, 향상된 for문으로 합계를 구해서 출력.
// 4. 벡터에 1~200까지 넣고, 짝수 몇개인지 향상된 for문으로 구하세요.
//    이때 짝수를 찾은 경우, 그 값을 0으로 만들어 버리세요. (If문 필요)
// 5. 벡터에 1~1972까지 넣고, 이를 향상된 for문을 이용해서 거꾸로 출력하세요.
// 향상된 for문으로 거꾸로 출력할 수 없음. > 거꾸로 저장
vector<int> v5;
// 1972 ~ 1
//for(int i=1972 ; i>=0; i--)
for(int i=0; i<1972; i++){
    v5.push_back(1972-i);
}
for(int i:v5){
    cout << i << " "
}   cout << endl;

// 6. 벡터에 -3 -5 -7 3 5 7 을 넣은 후, 향상된 for문을 이용해서
//    음수는 0으로 만들어 버린 후 출력하세요 ( IF문 필요함 )
vector<int> v6;
v6.push_back(-3);
v6.push_back(-5);
v6.push_back(-7);
v6.push_back(3);
v6.push_back(5);
v6.push_back(7);
for(int& i:v6){
    if(i<0){
        i-0;
    }
    cout << i << " "
}   cout << endl;
//    if( 조건식 ){조건식 예시 -> a>=10, a==2, a<=3, a!=2
//        맞으면 얘 
// }else{
//     틀리면 얘.
// }








