#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// a가 낮은 점수를 더 많이 맞힌 경우이면 TRUE
bool compare(vector<int>& a, vector<int>& b) {
    for(int i=11 ; i>= 0 ; i--) {
        if(a[i] != b[i]) return a[i] > b[i];
    }
    
    return false;
}


vector<int> solution(int n, vector<int> info) {
    vector<int> answer(12, -1);
    vector<int> v(n+10);    // 중복조합 벡터
    
    fill(v.begin() + n, v.end(), 1);  // 칸막이 10개
    
    do {
        vector<int> temp;
        int idx = -1;
        for(int i=0 ; i<v.size() ; i++) {
            if(v[i]==1) {  // 칸막이이면
                temp.push_back(i-idx-1);
                idx = i;
            }
        }
        temp.push_back(n+10-idx-1);
        
        // 라이언의 점수 계산
        int score = 0;
        for(int i=0 ; i<=10 ; i++) {
            if(temp[i] > info[i]) score += (10-i);
            else if(info[i] != 0) score -= (10-i);
        }
        
        if(score <= 0) continue;
        temp.push_back(score);   
        
        if(compare(temp, answer)) answer = temp;
    }while(next_permutation(v.begin(), v.end()));
    
    if(answer[0] == -1) return vector<int>({-1});
    answer.pop_back();
    
    return answer;
}