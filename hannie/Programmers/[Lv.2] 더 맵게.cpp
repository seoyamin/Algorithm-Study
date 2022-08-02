
// 더 맵게
#include <string>
#include <vector>
#include <queue> // 큐

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue <int,vector<int>,greater<int>> p_q(scoville.begin(),scoville.end());
    
    while(p_q.size()>1 && p_q.top()<K) {
        int one = p_q.top();
        p_q.pop();
        int two = p_q.top();
        p_q.pop();
        int three = one+two*2;
        p_q.push(three);
        answer++;
    }
    if(p_q.top()<K) return -1;
    else return answer;
}
