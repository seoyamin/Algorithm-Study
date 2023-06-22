#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int x, int y, int n) {
    int answer = 0;
    vector<int> visited(1000001, 0);
    queue<int> q;   // 연산의 결과들 저장
    
    q.push(x);
    
    while(!q.empty()) {
        int current = q.front();
        q.pop();
        
        // current 값을 y로 만들기 성공한 경우 - return 하면서 종료
        if(current == y) return visited[current];
        
        // 가능한 연산 3가지
        int dx[3] = {current + n, current * 2, current * 3};
        
        for(int i=0 ; i<3 ; i++) {
            int next = dx[i];
            
            // 이미 방문했거나, 계산한 결과가 y값 넘어선 경우는 넘어가기
            if(visited[next] != 0 || next > y) continue;
            
            visited[next] = visited[current] + 1;
            q.push(next);
        }
    }
    
    return -1;  // x를 y로 만들 수 없는 경우
}