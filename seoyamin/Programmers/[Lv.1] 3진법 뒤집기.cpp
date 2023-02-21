#include <string>
#include <vector>
#include <cmath>

using namespace std;

// 10진수 -> 3진수(String) 변환 함수
string toTernary(int n) {
    string result = "";
    
    while(n >= 3) {
        int temp = n % 3;  
        result = to_string(temp) + result;
        n /= 3;
    }
    
    return to_string(n) + result;
}

int solution(int n) {
    int answer = 0;
    
    string n_ternary = toTernary(n);
    
    for(int i=0 ; i<n_ternary.size() ; i++) {
        answer += (n_ternary[i] - '0') * pow(3, i);
    }
    
    return answer;
}