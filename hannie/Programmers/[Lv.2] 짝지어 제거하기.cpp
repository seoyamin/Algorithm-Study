// 짝지어 제거하기

#include<iostream>
#include<string>
#include<stack>
using namespace std;
stack<char> st; // 스택

int solution(string s)
{
    int answer = 0;
    for(int i=0; i<s.size(); i++){
        if(st.size() > 0 && st.top() == s[i]) st.pop();
        else st.push(s[i]);
    }
    answer = !st.size();
    
    return answer;
}
