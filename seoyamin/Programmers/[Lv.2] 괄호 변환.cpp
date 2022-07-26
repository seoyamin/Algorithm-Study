#include <string>
#include <vector>
#include <stack>

using namespace std;


// string s가 올바른 괄호 문자열인지 T/F return 
bool checkCorrect(string s) {
    bool result;
    stack<char> st;
    
    for(int i=0 ; i<s.size() ; i++) {
        if(st.empty()) {
            if(s[i] == ')') return false;      //  짝이 없는 )으로 시작 : 무조건 false
            else st.push(s[i]);               //  (은 일단 st에 넣고 짝을 기다림
        } 
        
        else {
            if(s[i] != st.top()) st.pop();    //   (  ) 짝이 이루어짐
            
            else st.push(s[i]);               //   (  ( 짝이 이루어지지 않음
        }
    }
    
    if(st.empty()) result = true;
    return result;
}


// string balanced를 올바른 괄호 문자열로 변환해서 return  
string toCorrect(string balanced) {
    string correct = "";
    
    if(balanced == "") {
        correct = "";
    }
    
    // [case 1] balanced가 이미 correct
    else if(checkCorrect(balanced)) {
        correct = balanced;
    }
    
    // [case 2] balanced가 아직 correct 아님
    else {
        
        // u의 맨 끝 인덱스 i 꺼내기
        int left = 0, right = 0;
        int i = 0;

        while(i<balanced.size()) {
            if(balanced[i] == '(') left++;
            else right++;
            
            if(left == right && left + right != 0) break;
            else i++;
        }
        
        // i 기준으로 balanced에서 u, v 나누기
        string u = balanced.substr(0, i+1);
        string v = balanced.substr(i+1);
        
        
        // [case 1] u가 올바른 괄호 문자열인 경우
        if(checkCorrect(u)) {
            correct += u;
            correct += toCorrect(v);
        }
        
        // [case 2] u가 올바른 괄호 문자열이 아닌 경우
        else {
            correct += "(";
            correct += toCorrect(v);
            correct += ")";
            
            
            // u 양끝 제거 후 괄호 뒤집기
            u = u.substr(1, u.size()-2);
            
            for(int j=0 ; j<u.size() ; j++) {
                if(u[j] == '(')  u[j] = ')';
                else u[j] = '(';
            }
            
            correct += u;
        }
    }

    
    return correct;
}




string solution(string p) {
    string answer = "";
    
    answer = toCorrect(p);
    
    return answer;
}