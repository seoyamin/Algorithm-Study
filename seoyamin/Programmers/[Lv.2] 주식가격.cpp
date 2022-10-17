#include <string>
#include <vector>

using namespace std;

int getSeconds(int idx, vector<int>& prices) {
    int seconds = 0; // 가격 떨어지지 않은 기간
    
    for(int i=idx+1 ; i<prices.size() ; i++) {
        if(prices[idx] <= prices[i]) seconds++;  // 가격 떨어지지 않은 기간 카운트
        else return seconds + 1;
    }
    
    return seconds;
}

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    for(int i=0 ; i<prices.size() ; i++) {
        answer.push_back(getSeconds(i, prices));
    }
    
    return answer;
}