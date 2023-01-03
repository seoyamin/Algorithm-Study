#include <string>
#include <vector>

using namespace std;

int myFunc(string s, int current) {    
    for(int i=1 ; i<=current ; i++) {
        if(s[current] == s[current - i]) return i;
    }
    
    return -1;
}

vector<int> solution(string s) {
    vector<int> answer = {-1};
    
    for(int i=1 ; i<s.size() ; i++) {
        answer.push_back(myFunc(s, i));
    }
    
    return answer;
}