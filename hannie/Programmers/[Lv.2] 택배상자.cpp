#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<int> order) {

    stack<int> sub; // 보조 컨테이너 벨트 = 서브
    stack<int> st1; // 기존 컨테이너 벨트 = 스택1

    // st1 = [1,2,3,4,5]
    for(int i=0; i<order.size(); i++)
        st1.push(order.size()-i); 

    int idx=0; // order의 인덱스
    // 기존 스택과 보조 스택이 모두 비워질 때까지
    while(!st1.empty() || !sub.empty()){
        if(!st1.empty() && st1.top()==order[idx]){ // 기존 벨트에서 order 꺼낼 때
            st1.pop();
            idx++;
        }
        else if(!sub.empty() && sub.top()==order[idx]){ // 보조 벨트에서 order 꺼낼 때
            sub.pop();
            idx++;
        }
        else if(!st1.empty()){ // 둘 다 꺼낼 수 없을 때=>기존 벨트에서 보조 벨트로 옮기기
            sub.push(st1.top());
            st1.pop();
        }
        else
            break; // 이도 저도 못할 때
    }

    return idx;
}
