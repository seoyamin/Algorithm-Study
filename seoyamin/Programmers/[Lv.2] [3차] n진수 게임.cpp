#include <string>
#include <vector>

using namespace std;

// n진수 숫자로 바꾸는 방법
string to_n(int n, int decimal) {
    string c[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", 
                "A", "B", "C", "D", "E", "F"};
    
    if(decimal < n) return c[decimal];
    else return to_n(n, decimal/n) + c[decimal % n];
}


string solution(int n, int t, int m, int p) {
    string n_num = "";   // 0 ~ t * m 숫자를 n진수로 바꿔서 쭉 연결한 문자열
    string answer = "";
    
    for(int d=0 ; d < t * m ; d++) {
        n_num += to_n(n, d);
    }
    
    // 튜브의 순서인 문자만 골라서 answer에 더하기
    for(int i=0 ; i<n_num.size() ; i++) {
        if(answer.size() == t) break;              // 미리 구할 숫자 개수 만족하면 break
        if(i % m == p - 1) answer += n_num[i];
    }
    
    return answer;
}