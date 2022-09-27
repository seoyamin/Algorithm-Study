#include <vector>
#include <iostream>

using namespace std;


char alphabet[5] = {'A', 'E', 'I', 'O', 'U'};
vector<string> all;  // 모든 가능 단어 저장


void dfs(string s) {
    if(s.size() == 5) return;
    
    for(auto i : alphabet) {
        string s_next = s + i;
        all.push_back(s_next);
        dfs(s_next);
    }
}


int solution(string word) {
    int answer = 0;
    
    dfs("");
    
    for(int i=0 ; i<all.size() ; i++) {
        if(all[i] == word) {
            answer = i + 1;
            break;
        }
    }
    
    return answer;
}