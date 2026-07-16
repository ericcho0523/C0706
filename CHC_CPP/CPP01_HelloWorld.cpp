// CPP01_HelloWorld.cpp
// 파일이름 규칙. 숫자시작X공백X특수기호X _은 괜찮, 한글X
#include <iostream>

int main() {
    // 출력
    std::string name = "hello World";
    // C -> 포인터 char *str, char str[30]; malloc
    char str[100] = "Hello World";

    // C++ 출력. std : standard, cout : console out
    std::cout << name << std::endl; // end line 
    // << : 리다이렉션 : 오른쪽에 있는놈 왼쪽으로 보냄.
    // 출력하는놈 << Hello World << endl;
    // C 출력
    printf("%s\n", str);
    // Ctrl + Alt + N 실행

    //\n안썼는데 왜 개행됨?/ -> 응 자동이야 (endl) ~ endl:개행
    //----------------------------------------------
    //C입력 -> scanf
    //char str2[99];
    //scanf("%s", &str2);
    
    //C++입력 -> cin : console in
    std::string str2;
    std::cin >> str2;
    int k;
    std::cin >> k;
    std::cout << str2 << ", " << k << std::endl;

    




    
}
