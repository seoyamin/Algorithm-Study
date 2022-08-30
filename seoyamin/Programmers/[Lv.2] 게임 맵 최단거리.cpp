#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int dx[4] = {-1, 1, 0, 0};      // 캐릭터 이동 단위 dx, dy
int dy[4] = {0, 0, -1, 1};
int check[101][101] = {0,};    // '시작점 노드 ~ 해당 좌표 노드'까지 지나간 칸 수 저장 (방문 전이면 0)


// bfs 함수
int bfs(vector<vector<int>> maps) {
    queue<pair<int, int>> q;
    int row = maps.size(), col = maps[0].size();
    
    
    q.push(make_pair(0, 0));
    check[0][0] = 1;
    
    
    // q가 텅 빌 때까지 1,2 반복 (텅 빔 == 모든 노드 탐색함)
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        if(x == row-1 && y == col-1) return check[x][y]; // 상대팀 진영 노드 (row-1, col-1) 도착한 경우
        
        
        // 1. queue의 첫번째 노드 A를 pop한 후, A와 인접한 상하좌우 4개 노드 탐색
        for(int i=0 ; i<4 ; i++) {
            int x_nearby = x + dx[i];
            int y_nearby = y + dy[i];
            
            
            // 2. 4개의 노드 중 유효한 노드만 queue에 push 
            // 2-1. 무효노드 : 게임맵 외부 or 벽 or 이미 방문
            if(x_nearby >= row || y_nearby >= col || x_nearby < 0 || y_nearby < 0) continue; // 외부
            if(maps[x_nearby][y_nearby] == 0) continue;  // 벽
            if(check[x_nearby][y_nearby] > 0) continue; // 이미 방문
            
            
            // 2-2. 유효노드
            q.push(make_pair(x_nearby, y_nearby));
            check[x_nearby][y_nearby] = check[x][y] + 1;
        }
    }
    
    return -1;    
}


int solution(vector<vector<int>> maps) {
    int answer = 0;
    
    answer = bfs(maps);
    return answer;
}