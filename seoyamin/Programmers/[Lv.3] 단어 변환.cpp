#include <string>
#include <vector>
#include <iostream>

using namespace std;

int answer = 50;

void dfs(string begin, string target, vector<string> words, vector<int> &isUsed, int cnt = 0) {
    for(int i=0 ; i<words.size() ; i++) {
        // 현재 탐색중인 단어 : words[i]
        
        int count = 0;  // begin과 words[i]의 다른 문자의 개수
        
        for(int j=0 ; j<words[i].size() ; j++) {
            if(isUsed[i] == 0 && begin[j] != words[i][j]) count++;  // count 세기
        }
        
        // 다른 문자 개수가 1개 -> 변환 가능한 상태
        if(count == 1) {
            
            // 현재까지의 answer보다 작은 answer 등장 시 업데이트
            if(target == words[i] && answer > cnt+1) {
                answer = cnt + 1;
                return;
            }
            
            isUsed[i] = 1;  // isUsed 업데이트
            dfs(words[i], target, words, isUsed, cnt+1);
            
            isUsed[i] = 0;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    vector<int> isUsed(words.size(), 0);
    
    dfs(begin, target, words, isUsed);
    
    if(answer == 50) return 0;    
    return answer;
}