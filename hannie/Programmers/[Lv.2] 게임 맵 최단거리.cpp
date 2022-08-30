#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>

using namespace std;

int dir[4][2] = {{0,1}, {1,0}, {-1,0},{0,-1}};
int dist[101][101]; // 방문 거리

/*
 * 최단 거리 => BFS
 * 마지막 좌표에 도달 못하면 -1
 *
 * */

int solution(vector<vector<int> > maps){

    int n=maps.size();
    int m=maps[0].size();
    queue<pair<int, int>> q;
    memset(dist,-1,sizeof(dist));

    q.push({0,0});
    dist[0][0]=1;

    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        if(y==n-1 && x==m-1)
            return dist[y][x];

        for(int i=0; i<4; i++){
            int ny = y+dir[i][0];
            int nx = x+dir[i][1];
            if(ny >= 0 && ny < n && nx>=0 && nx<m){
                if(maps[ny][nx]==1 && dist[ny][nx]==-1){
                    dist[ny][nx] = dist[y][x]+1;
                    q.push({ny,nx});
                }
            }
        }
    }
    // 도착 못할 경우
    return -1;
}
