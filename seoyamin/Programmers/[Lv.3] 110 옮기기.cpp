#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<string> solution(vector<string> s) {
    vector<string> answer(s.size());
    
    for(int i=0 ; i<s.size() ; i++) {
        stack<char> st;
        int count = 0;    // 110 개수
        
        for(int j=0 ; j<s[i].size() ; j++) {
            st.push(s[i][j]);
            
            if(st.size() >= 3) {  // 일단 최상단 3개 꺼내보기
                char third = st.top();
                st.pop();
                
                char second = st.top();
                st.pop();
                
                char first = st.top();
                st.pop();
                
                // 110 나온 경우 -> count 1 증가 후, 다음 문자 i[j]로
                if(first == '1' && second == '1' && third == '0') {
                    ++count;
                    continue;
                }
                
                // 110 아닌 경우 -> 다시 넣고 다음 문자 i[j]로
                else {
                    st.push(first);
                    st.push(second);
                    st.push(third);
                }
            }
        }
        
        // 110이 하나도 없는 문자열인 경우 그대로 answer에
        if(count == 0) {
            answer[i] = s[i];
            continue;
        }
        
        int insert_idx = st.size();
        string str = "";
        
        // 뒤에서부터 꺼내서 string 만들기 (연속적으로 1이 나오는 동안) 
        while(!st.empty() && st.top() == '1') {
            --insert_idx;
            str = st.top() + str;
            st.pop();
        }
        
        // 남은 문자 꺼내서 str에 더하기
        while(!st.empty()) {
            str = st.top() + str;
            st.pop();
        }
        
        while(count-- > 0) {
            str.insert(insert_idx, "110");
        }
        
        answer[i] = str;
        
    }
    
    
    
    return answer;
}