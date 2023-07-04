#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    vector<char> alpha;
    
    for(char c = 'a' ; c <= 'z' ; c++) {
        alpha.push_back(c);
    }
    
    for(char c = 'a' ; c <= 'z' ; c++) {
        alpha.push_back(c);
    }
    
    
    for(int i=0 ; i<s.size() ; i++) {
        if(s[i] == ' ') {
            answer += ' ';
            continue;
        }
        
        else if(s[i] >= 'a' && s[i] <= 'z') {
            int idx = s[i] - 'a';
            answer += alpha[idx + n];
        }
        
        else {
            int idx = s[i] - 'A';
            answer += toupper(alpha[idx + n]);
        }
    }
    
    return answer;
}