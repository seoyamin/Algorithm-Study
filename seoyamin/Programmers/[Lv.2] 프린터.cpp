#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    priority_queue<int> pq;
    queue<pair<int, int>> q;
    
    // pq 원소 삽입
    for(int i=0 ; i<priorities.size(); i++) {
        pq.push(priorities[i]);
    }
    
    // q 원소 삽입
    for(int i=0 ; i<priorities.size() ; i++) {
        q.push(make_pair(i, priorities[i]));  // <index, p[i]> pair
        
    }
    
    
    // [조건 1] q의 index = location
    // [조건 2] pq의 top value = q의 value
    while( !( (q.front().first == location) && (q.front().second == pq.top()) ) ) {
        
        if(pq.top() == q.front().second) {
            pq.pop();
            q.pop();
            answer++;
        }
        
        else  {
            q.push(q.front());
            q.pop();
        }
    }
    
    
    // location 문서 자기 자신 인쇄되는 경우 1 추가
    return answer + 1;
}