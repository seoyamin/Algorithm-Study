#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> days;
    queue<int> q;
    vector<int> answer;
    
    
    // 개발 완료까지 소요 일수 days vector에 원소 삽입
    for(int i=0 ; i<progresses.size() ; i++) {
        int day = 100 - progresses[i];
        
        if(day%speeds[i] == 0) day = day/speeds[i];
        else day = day/speeds[i] + 1;
        
        days.push_back(day);
    }
    
    
    // days의 첫번째 원소 q에 넣고 시작
    q.push(days[0]);
    
    
    // q 이용하여 answer 완성하기
    for(int j=1 ; j<days.size() ; j++) {
        
        // [case 1] 들어오려는 days[j]가 q.front()보다 큼
        if(days[j] > q.front()) {
            answer.push_back(q.size());
            
            while(!q.empty()) {
                q.pop();
            }
            
            q.push(days[j]);
        } 
        
        // [case 2] 들어오려는 days[j]가 q.front()보다 작음
        else {
            q.push(days[j]);
        }
    }
    
    
    // q에 남아 있는 원소 처리
    answer.push_back(q.size());
    
    return answer;
}