#include <iostream>
#include <vector>
#include <queue>
#define MAX 101

using namespace std;

typedef struct{
    int x,y,cnt;
} Me;

int solution(vector<vector<int> > maps) {
    int row = maps.size(); //행
    int col = maps[0].size(); //열

    int youX = col-1, youY = row-1;
    //상대 진영 x,y 좌표

    int dirX[4] = {-1,1,0,0};
    int dirY[4] = {0,0,-1,1};
    //상하좌우 움직임

    queue<Me> q;
    bool visited[MAX][MAX] = {false,};
    //내가 움직이는 좌표값과 카운트를 넣을 큐와 왔다간 자리를 체크할 배열 선언

    q.push({0,0,0});
    visited[0][0]=true;
    //처음 내가 있는 곳 초기화

    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int cnt = q.front().cnt;
        q.pop();
        //큐 맨 앞에 있는 값 받고 pop

        if(y==youY && x==youX){
            return cnt+1;
        }
        //만약 상대진영에 다다르면 옮긴 cnt 더해주고 리턴

        //상하좌우 뻗어나감
        for(int i=0; i<4; i++){
            int nextX = x+dirX[i];
            int nextY = y+dirY[i];

            //좌표값이 바둑판에서 빠져나가거나, 맵에서 벽인 경우, 이미 지나간 경우 제외
            if(nextY <0 || nextY>= row || nextX<0 || nextX >= col
            || maps[nextY][nextX]==0 || visited[nextY][nextX]){
                continue;
            }

            //다 해당안되면 방문한 뒤 경로 탐색할 큐에 넣어줌(방문했으니 cnt 더해줌)
            visited[nextY][nextX] = true;
            q.push({nextX,nextY,cnt+1});
        }
    }
    //큐가 빌 때까지 리턴되지 못하면 -1리턴
    return -1;
}

