#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int validIdx = 0;       // 한 단어 안에서의 인덱스
    
    for(auto c : s) {
        if(c == ' ') {
            answer += c;
            validIdx = 0;
            continue;
        }
        
        if(validIdx % 2 == 0) 
            answer += toupper(c);
        
        else 
            answer += tolower(c);
        
        validIdx++;
    }
    
    return answer;
}