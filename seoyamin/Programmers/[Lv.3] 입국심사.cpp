#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    sort(times.begin(), times.end(), greater<>());
    long long maxTime = (long long)times[0] * n;
    long long minTime = 1;
    
    while(minTime <= maxTime) {
        long long midTime = (minTime + maxTime) / 2;
        long long done = 0;     // midTime 동안 times의 모든 심사관들이 처리하는 사람 수
        
        for(int i=0 ; i<times.size() ; i++) {
            long long temp = midTime / times[i];      // midTime동안 i번째 심사관이 처리하는 사람 수
            done += temp;
        }
        
        if(done < n) minTime = midTime + 1;
        else {
            answer = midTime;           // 이번 midTime은 answer 될 수 있음
            maxTime = midTime - 1;      // 더 작은 answer 가능한지 다시 루프 돌아보기
        }
    }
    
    return answer;
}