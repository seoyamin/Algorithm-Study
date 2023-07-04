#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int w, h;

bool isInMap(int x, int y) {
    return x >= 0 && x < w && y >= 0 && y < h;
}

pair<int, int> getPoint(char pointChar, vector<string> &maps) {
    for(int i=0 ; i<h ; i++) {
        for(int j=0 ; j<w ; j++) {
            if(maps[i][j] == pointChar)
                return make_pair(j, i);
        }
    }
}


int bfs(char start, char dest, vector<string> &maps) {    
    vector<vector<int>> count(h, vector<int>(w, -1));    // 각 지점까지 가는데 소요된 이동 수 (=시간)
    queue<pair<int, int>> q;    // 지나온 지점 저장
    
    q.push(getPoint(start, maps));
    count[q.front().second][q.front().first] = 0;
    
    while(!q.empty()) {
        int currentX = q.front().first;
        int currentY = q.front().second;
        q.pop();
        
        if(maps[currentY][currentX] == dest) 
            return count[currentY][currentX];
        
        // 상하좌우 다음 지점 탐색
        for(int i=0 ; i<4 ; i++) {
            int nextX = currentX + dx[i];
            int nextY = currentY + dy[i];
            
            if(!isInMap(nextX, nextY)) continue;    // maps 범위 벗어난 지점인 경우
            if(count[nextY][nextX] > -1) continue;  // 방문한 적 있는 지점인 경우
            if(maps[nextY][nextX] == 'X') continue; // 벽인 경우
            
            q.push(make_pair(nextX, nextY));                        // (nextX, nextY) 방문
            count[nextY][nextX] = count[currentY][currentX] + 1;    // (nextX, nextY)까지 걸린 이동 수 기록
        }
    }
    
    return -1;
}


int solution(vector<string> maps) {
    int answer = -1;
    w = maps[0].size();
    h = maps.size();
    
    int t1 = bfs('S', 'L', maps);   // S ~ L
    int t2 = bfs('L', 'E', maps);   // L ~ E
    
    cout << t1 << " " << t2;
    
    if(t1==(-1) || t2==(-1)) return -1;
    
    answer =  t1 + t2;    
    return answer;
}