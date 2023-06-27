#include <string>
#include <cmath>
#include <stack>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    stack<int> st;
    int temp;
    
    for(int i=0 ; i<dartResult.size() ; i++) {
        // 점수
        if(dartResult[i] >= '0' && dartResult[i] <= '9') {
            if(dartResult[i] == '1' && dartResult[i+1] == '0') {
                temp = 10;
                i++;
            } 
            
            else {
                temp = dartResult[i] - '0';
            }
        }
        
        // 보너스
        else if(dartResult[i] == 'S' || dartResult[i] == 'D' | dartResult[i] == 'T') {            
            if(dartResult[i] == 'S') temp = pow(temp, 1);
            else if(dartResult[i] == 'D') temp = pow(temp, 2);
            else if(dartResult[i] == 'T') temp = pow(temp, 3);
            
            st.push(temp);
        }
        
        // 옵션
        else {
            int currScore = st.top();
            st.pop();
            
            // *
            if(dartResult[i] == '*') {
                if(!st.empty()) {
                    int prevScore = st.top();
                    st.pop();
                    st.push(prevScore * 2);
                }        
                st.push(currScore * 2);
            }
            
            // #
            else if(dartResult[i] == '#') {
                st.push(currScore * (-1));
            }
        }
    }
    
    
    while(!st.empty()) {
        int score = st.top();
        st.pop();
        answer += score;
    }
    
    
    return answer;
}