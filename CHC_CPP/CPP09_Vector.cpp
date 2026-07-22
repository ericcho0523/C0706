// CPP09_Vector.cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <time.h> // 랜덤 -> main첫줄에 srand 넣어야 함.
using namespace std;
// 함수===============================================
// InitV 랜덤값 1~10의 값을 랜덤하게 넣어줌
void InitV(vector<int> v,int size){
    for(int i=0; i<size;i++){
        v.push_back(rand()%10+1);
    }
}

// PrintV -> 모든 요소 출력
void PrintV(vector<int> v){
    for(int i=0;i<v.size();i++){
        cout << v[i] << " ";
    }   cout << endl;
}

// InsertV 실행하면, 입력 하나 받고, 어디에 넣을지도 입력받아서
// 해당 위치에 데이터 입력 후, 입력전, 후 출력 함수 구현
void InsertV(vector<int>& v){

    int data, location;
    cout << "Input Data : ";
    cin >> data;
    cout << "Input Location : ";
    cin >> location;
    cout << "<Before> : " ;     PrintV(v);
    // ------------------------
    v.insert(v.begin() + location, data);
    // ------------------------
    cout << "<After> : " ;      PrintV(v);




}

// 특정 배열에서 특정 값의 위치(이터레이터)를 리턴

vector<int>::iterator FindV(vector<int> v, int target){
        
        vector<int>::iterator iter;
        iter = find(v.begin(), v.end(), target);
        return iter;
}
// 특정 값이 들어올 경우, 해당 값이 총 몇개 있는지
// 돌려주는 GetFindRepeat 함수 제작
int GetFindRepeat(vector<int>&v,int target){
    int cnt = 0;
    vector<int>::iterator iter = v.begin();
    for(;true;){ // while(true)
        auto temp = find(iter, v.end(), target);
        if(temp==v.end()){
            // iter가 마지막 target 위치
            return cnt;
        }else{
            iter = temp+1;
            cnt++;
        }
        

    }
    // 해당 값을 먼저 찾으면 cnt++
    // 만약 해당 값이 없다면 end()가 나옴.
    // end()를 만나면 바로 return
    // 만약 찾으면 그 다음 위치부터 다시 find를 반복
    // for(int i=0;i<v.size();i++){
    //     if(v[i]==target) cnt++;
    // }
    // return cnt;;


    
}
// 타겟을 연속 삭제 (최적화된 코드 아님)
void DeleteVALL(vector<int>&v, int target){
    int size = GetFindRepeat(v,target);
    for(int i=0;i<size;i++){
        vector<int>::iterator iter = FindV(v,target);
        v.erase(iter);
    }
}





// ===============================================
int main(){
    srand(time(NULL)); // 매번마다 다르게 섞어라 
    // ---------------------------------------
    vector<int> v1;
    InitV(v1, 10); // 10개 만들어짐

    // 맨 앞, 맨 뒤, 가운데 777
    // begin  end  begin+ v.size()/2
    v1.insert(v1.begin(), 777);
    v1.insert(v1.end(), 777);
    v1.insert(v1.begin() + v1.size()/2 , 777);
    // 맨 앞 기준으로, 인덱스 3 자리에 777을 넣으세용
    // 777 2 3 777 10 72 777 10 4 3 2 9 777
    v1.insert(v1.begin()+3, 777);
    PrintV(v1);

    // Iterator는 값일까? 주소일까?
    // cout << v1.begin() << endl;
    // printf("%p\n", v1.begin()); // 0000019673821ac0 
    // printf("%p\n", &v1[0]);
    // printf("%p\n", *v1.begin()); // 주소의 데이터공간 사용
    // printf("%p\n", *(v1.begin()+3)  );  

    // int ary[999] = {0};
    // printf("%p\n", ary);
    // printf("%p\n", &ary[0]);    
    // ----------------------------------------
    // InsertV(v1);
    // ------------------------------------------
    // 현존하는 모든 777 제거 + 출력
    v1.erase(v1.begin());
    v1.erase(v1.begin()+2);
    v1.erase(v1.end());
    v1.erase(v1.begin()+5);

    PrintV(v1);
    // 실습. 남은 777 제거, begin, end 활용
    // 777 2 4 777 2 8 6 777 2 2 1 1 5 777
    // 2 4 777 2 8 6 777 2 2 1 1 5 777

    // pop_back 활용 -> 5번 삭제
    for(int i=0;i<100;i++)
        v1.pop_back(); // 100번 삭제해도 에러안남
        // no except

    // -------------------------------------------
    // v2 -> 2 4 6 8 .. 20 저장
    vector<int> v2;
    for(int i=0; i<10; i++){
        v2.push_back( (i+1)*2);
    }    
    PrintV(v2);
    // --------------------------------------------
    // find
    cout << *find(v2.begin(), v2.end(), 16) << endl;
    v2.erase( find(v2.begin(), v2.end(), 16));
    PrintV(v2);
    // 여러개를 찾고 싶다면??
    // A = find(처음,끝,x) != end(); // 1번째꺼
    // B = find (A+1, 끝, x) != end(); // 2번째꺼


    // iter + auto > 14
    vector<int>::iterator iter = find(v2.begin(), v2.end(), 14);
    // auto iter2 = find(v2.begin(), v2.end(), 14);

    // erase + find
    v2.erase(iter);

    PrintV(v2);

    // iter와 erase를 이용해서, 8, 12, 20을 삭제
    // iter = find(v2.begin(), v2.end(), 8);
    // v2.erase(iter);
    // iter = find(v2.begin(), v2.end(), 12);
    // v2.erase(iter);
    // iter = find(v2.begin(), v2.end(), 20);
    // v2.erase(iter);

    vector<int>::iterator iter2;
    iter2 = find(v2.begin(),v2.end(),8);
    vector<int>::iterator iter3;
    iter3 = find(v2.begin(),v2.end(),12);
    vector<int>::iterator iter4;
    iter4 = find(v2.begin(),v2.end(),20);
    v2.erase(iter4);
    v2.erase(iter3);
    v2.erase(iter2);
    // 이것을, 함수 FindV로 구현해서, iter를 리턴 
    v2.erase(FindV(v2, 10));

    PrintV(v2);

    // 연속 검색 구현 - 함수
    vector<int> v3 = {10,20,10,30,10,40,10,50};
    int cnt = GetFindRepeat(v3,10);
    cout << "Find Cnt : " << cnt << endl; // 4

    // 연속 삭제 -> 몇번삭제 할 지 알면? > 무한반복 X
    DeleteVALL(v3,10);
    PrintV(v3);

    // 정렬하기
    vector<int> v4;
    InitV(v4, 50);
    PrintV(v4);
    sort(v4.begin(), v4.end()); // 오름차순
    cout << "---------------" << endl;
    PrintV(v4);
    cout << "---------------" << endl;
    sort(v4.begin(), v4.end(), greater<int>()  ); 
    PrintV(v4);
    // 내림차순 상태에서, 절반부터만 오름차순 정렬
    cout << "--------------" << endl;
    sort(v4.begin()+v4.size()/2 , v4.end());
    PrintV(v4);
    // 숫자 6을 찾아서, 3부터 내림차순 정렬
    cout << "--------------" << endl;
    iter = FindV(v4, 3);
    sort(iter, v4.end(), greater<int>());
    PrintV(v4);
    
    // ----------------------------------------
    // 유틸리티 사용
    cout << v4.size() << endl;
    cout << boolalpha << v4.empty() << endl;
    v4.clear();
    PrintV(v4);
    

}// ==============================================
/*------------------------------------------------
< Vector > 심층 이론
1. 벡터 만들기
#include -> vector
vector<자료형> 벡터이름;
vector<자료형> 벡터이름 = {12,1,231,231};

2. 데이터 넣기
벡터이름.push_back(뒤에넣을놈)
벡터이름.insert(iterator, 넣을놈);

3. Iterator
반복 가능한 객체(벡터, 큐, 스택 등등)의 위치를 알고 있는
특별한 (⭐)포인터 -> 주소 알고 있는 놈
begin() -> 맨 앞 주소   
end() -> 맨 뒤 주소 + 한칸 뒤
   ㅁ    ㅁ    ㅁ    ㅁ   ㅁ   ㅁ
   begin                          end()
begin, end 자체에는 데이터가 없고 주소만 가지고 있음
*앞에 붙여주면? 해당 공간 안에 있는 데이터 값 사용

4. 삭제하기
벡터이름.erase(삭제할놈 위치)
벡터이름.pop_back() 맨 오른쪽 놈 삭제함

5. 검색하기
find(StartIterator, EndIterator, 찾을값)
만약에 못 찾으면 end()가 나옴. -> 이거 안나오면 있다!




함수의 결과 : Iterator -> 자료형이 좀 골때림
이터레이트 자료형원형 : vector<int>::iterator iter =
⭐ 당분간 이 치트키는 이터레이터에만 사용할 것 ⭐
auto asdf = 아무거나 -> auto가 알아서 자료형 결정함.




6. 정렬하기 -> #include <algorithm>
6.1 오름차순
sort -> 반복가능한 객체에는 "거의 다" 적용 가능
sort(어디부터이터레이터, 여기까지이터레이터)
1 3 5 2 4 -> 1 2 3 4 5

6.2 내림차순
sort(어디부터이터레이터, 여기까지이터레이터, greater<int>() )
<제네릭> -> 제네릭 자리에 int넣으면, int 기준, double...



7. 유틸리티
크기,비었니,사이즈,비긴,엔드
벡터.size()
벡터.empty() > 비었으면 true, 안비었으면 false
벡터.begin() 첫 위치
벡터.end() 끝 위치



8. 전체 삭제하기
벡터.clear() 모든 요소 삭제됨








*/
