#include <string>
#include <vector>
#include <stack>

using namespace std;

// 올바른 괄호 문자열인지 확인하는 함수
bool checkRight(string s) {
    stack<char> st;
    
    for(auto i : s) {
        if(i == '[' || i == '{' || i == '(') st.push(i);
        
        else if(st.empty()) return false;
        
        else if(st.top() == '[' && i == ']') st.pop();
        else if(st.top() == '{' && i == '}') st.pop();
        else if(st.top() == '(' && i == ')') st.pop();
    }
    
    if(!st.empty()) return false; 
    
    return true;
}


int solution(string s) {
    int answer = 0;
    string rotated;
    
    for(int i=0 ; i<s.size() ; i++) {
        rotated = s.substr(i, s.size()-i) + s.substr(0, i);  // i칸만큼 회전한 문자열 rotated
        if(checkRight(rotated)) answer++;
    }
    
    return answer;
}