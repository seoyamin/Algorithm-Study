#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) { 
    int remain = n;   // 현재 남은 콜라 수
    int give, take;   // 가져다 준 콜라 수, 가져다 주고 받은 콜라수 
    int answer = 0;   // 받은 콜라 수 총합
    
    while(remain >= a) {
        give = (remain / a) * a;
        take = (give / a) * b;
        remain = remain - give + take;
        
        answer += take;
    }
    
    return answer;
}