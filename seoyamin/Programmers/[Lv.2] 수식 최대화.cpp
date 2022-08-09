#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;


// string expression -> vector<string> ["100", "+", "200", "-", .....] 바꿔주는 함수
vector<string> getVector(string ex) {
    vector<string> v;
    
    string num = "";
    for(int i=0 ; i<ex.size() ; i++) {
        
        // [case 1] operator인 경우
        if(ex[i] == '+' || ex[i] == '-' || ex[i] == '*') {
            v.push_back(num);
            num = "";
            
            string op = "";
            op += ex[i];
            v.push_back(op);
        }
            
        // [case 2] 숫자인 경우
        else num += ex[i];
    }
    
    v.push_back(num);
    return v;
}


// op 계산 결과를 string으로 리턴하는 함수
string getCal(long long a, long long b, char op) {
    long long result = 0;
    
    if(op == '+') result = a + b;
    else if(op == '-') result = a - b;
    else result = a * b;
    
    return to_string(result);
}


long long solution(string expression) {
    long long answer = 0;
    vector<vector<char>> op_list = {{'+', '-', '*'}, {'+', '*', '-'}, 
                                    {'-', '+', '*'}, {'-', '*', '+'}, 
                                    {'*', '+', '-'}, {'*', '-', '+'}};
    
    
    for(int i=0 ; i<op_list.size() ; i++) {
        vector<string> v = getVector(expression);
        
        for(int j=0 ; j<op_list[i].size() ; j++) {  //  {'+', '-', '*'}
            for(int k=1 ; k<v.size() ; k++) {
                
                // char  ->  string  (그래야 string인 v의 원소와 비교 가능)
                string op = "";
                op += op_list[i][j];
                
                if(v[k] == op) {
                    long long left = stoll(v[k-1]);   // [주의]  stoi (X), stoll (O)
                    long long right = stoll(v[k+1]);
                    string s = getCal(left, right, op_list[i][j]);
                    
                    v.erase(v.begin() + k-1, v.begin() + k+2);
                    v.insert(v.begin() + k-1, s);
                    k--;
                }
            }
        }
        
        long long temp = abs(stoll(v[0]));        
        if(temp > answer) answer = temp;
    }
    
    return answer;
}