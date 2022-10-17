#include <iostream>
using namespace std;

// 홀짝 판별
bool checkOdd(int n) {   
    return n%2;
}

// 짝수 중 2의 제곱수 여부 판별
bool checkEvenType(int n) {
    while(n > 1) {
        if(n%2==1) return false;  // 2로 나누어 떨어지지 않음 => 2의 제곱수 아님
        else n /= 2;              // 아직 2로 나누어떨어짐
    }
    return true;  // 2로 계속 나누어 떨어져서 n=1 됨 => 2의 제곱수 맞음
}

int getAnswer(int n) {
    
    if(checkOdd(n)) {            // 1. 홀수인 경우
        n -= 1;
        return getAnswer(n) + 1;
    }
    
    else if(checkEvenType(n)) {  // 2. 짝수이면서 2의 제곱수
        return 1;
    }    
    
    else {                       // 3. 짝수이면서 2의 제곱수 X
        while(n%2 != 1) {
            n /= 2;
        }
        return getAnswer(n);
    }
}

int solution(int n) {
    int ans = 0;
    
    if(n==1) return 1;
    else ans = getAnswer(n);
    

    return ans;
}

/*  참고

while(n > 0) {
    if(n % 2 == 0) n /= 2;
    else {
        n--;
        ans++;
    }
}

    return ans;
*/