// CPP02_namespace.cpp
#include <iostream>
namespace Ever{
    int age = 28;
    void Introduce() {
        std::cout<< "What can you do" << std::endl;
    }

}
namespace Haeyon{
    int age = 30;
    void Introduce() {
        std::cout << "Babo" << std::endl;
    }
}

using namespace Ever;
using namespace std; // 기본설정 필요
int main() 
{
    // std :: 네임스페이스
    // C 클래스, 데이터는 묶는게 있는데, 함수 못 묶음
    // 강제로 파일기준으로 코드를 구분.
    // + 다른 사람과 협업시, 변수명 자꾸 충돌!!
    // 변수명들을 묶는 단위 -> 네임스페이스 
    // ------------------------------------------
    // 에버랑 해이연 나이 출력
    std::cout << "Ever Age : " << age << std::endl;
    std::cout << "Hae Age : "  << Haeyon::age << std::endl;
    Introduce(); // 터미널 chcp 65001
}
