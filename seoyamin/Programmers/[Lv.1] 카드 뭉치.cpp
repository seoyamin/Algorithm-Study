#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "Yes";
    stack<string> st1, st2;
    
    // st1 채우기
    for(int i=cards1.size()-1 ; i>=0 ; i--) {
        st1.push(cards1[i]);
    }
    
    // st2 채우기
    for(int i=cards2.size()-1 ; i>=0 ; i--) {
        st2.push(cards2[i]);
    }
    
    for(int i=0 ; i<goal.size() ; i++) {
        if(!st1.empty() && st1.top() == goal[i]) {
            st1.pop(); 
            continue;
        }
        
        else if(!st2.empty() && st2.top() == goal[i]) {
            st2.pop();
            continue;
        }
        
        else return "No";
    }
    
    return answer;
}