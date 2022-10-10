#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// *소수 판별!
bool isPrime(long long num) {
    if(num < 2) return false; // 0,1 => 소수x
    for(int i=2; i<=sqrt(num); ++i) {
        if(num % i == 0) return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    vector<pair<string, int>> v;

    string s = ""; // s는 k진수
    while(n > 0) {
        s += to_string(n % k); 
        n /= k;
    }
    reverse(s.begin(), s.end());
    // 110101020112 -> 211020101011
    // *역순 뒤집기 idea!
    
    string tmp = "";
    for (char c : s) {
        if (c == '0') {
            if (!tmp.empty() && isPrime(stoll(tmp))) // string -> long long
                answer++;
            tmp = "";
        }
        else tmp += c;
    }
    // 마지막 남은 tmp 처리
    if (!tmp.empty() && isPrime(stoll(tmp))) 
        answer++;

    return answer;
}
