#include <vector>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer = {0,0};
    set<string> s;    // 지금까지 나온 단어 목록
    string before;    // 직전 사람이 말한 단어
    
    s.insert(words[0]);
    before = words[0];
    
    for(int i=1 ; i<words.size() ; i++) {
        
        // 탈락 조건 :  (1) 끝말 안이어짐  or  (2) 이미 나온 단어
        if(words[i].front() != before.back() || s.find(words[i]) != s.end()) {
            answer[0] = (i+1) % n == 0 ? n : (i+1) % n;
            answer[1] =  i/n + 1;
            return answer;
        } 
        
        before = words[i];
        s.insert(words[i]);
    }

    return answer;
}