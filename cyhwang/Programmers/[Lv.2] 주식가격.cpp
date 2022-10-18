#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer (prices.size(), 0);
    
    for (int i = 0; i < prices.size(); i++) {
        for (int j = i + 1; j < prices.size(); j++) {
            if (prices[i] > prices[j]) {
                answer[i] = j - i;
                break;
            }
            else
                answer[i]++;
        }
    }
/*    vector<int> answer (prices.size(), 0);
    stack<int> st;
    int i = 1;
    
    st.push(0);
    while (i != prices.size() - 1) {
        //cout << prices[i] << " " << stack.back() << endl;
        if (prices[i] < prices[st.top()] && !st.empty()) {
            answer[st.top()] = i - st.top();
            st.pop();
        }
        else {
            st.push(i);
            i++;
        }
    }
    
    
    while (!st.empty()) {
        answer[st.top()] = prices.size() - 1 - st.top();
        st.pop();
    }
    */
    
    return answer;
}
