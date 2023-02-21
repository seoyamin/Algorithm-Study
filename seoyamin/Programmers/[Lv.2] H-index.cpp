#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end(), greater<>());  //  6, 5, 3, 1, 0
    
    // 모두 0짜리인 경우 
    if(citations[0] == 0) return 0;
    
    // i+1 >= citation[i] (인용횟수) 이면 h++
    for(int i=0 ; i < citations.size() ; i++) {
        if(citations[i] < i+1) break;
        
        answer++;
    }
    
    return answer;
}