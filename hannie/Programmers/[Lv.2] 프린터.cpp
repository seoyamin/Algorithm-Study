#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
  
    int answer = 0;
    queue <pair<int,int>> q; // 큐(priority, location)
    priority_queue <int> pq; // 우선순위 큐(priority)
  
    for(int i=0; i<priorities.size();i++){
        pq.push(priorities[i]);
        q.push({priorities[i],i});
    }

  
// 정답이 나올 
    while(!q.empty()&&!pq.empty()){
      // 현재가 가장 높은 우선순위라면 => 큐에서 pop
        if(q.front().first==pq.top()){ // priority
               answer++;
          // 현재 위치가 입력 위치와 맞으면 리턴
            if(q.front().second == location){ // location
                return answer;
            }
            q.pop();
            pq.pop();

        }
      // 현재가 가장 높은 우선순위가 아니라면
        else{
            pair<int,int> temp = {q.front().first,q.front().second};
            // 꺼내서(pop) 맨 뒤로 보냄(push)
            q.pop();
            q.push(temp);
        }
    }
    return answer;
}
