#include <vector>
#include <queue>
#include <algorithm>
#define INF 1e8
using namespace std;

int solution(int N, vector<vector<int> > road, int K) {

    int ans = 0;
    //최소 값을 저장해둘 그래프
    vector<vector<int>> g(N+1, vector<int>(N+1,INF));

    //두 마을을 잇는 양방향 도로가 여러개일 수 있으므로, 가장 작은 값만 저장
    for(int i=0; i<road.size(); i++){
        g[road[i][0]][road[i][1]] = min(g[road[i][0]][road[i][1]],road[i][2]);
        g[road[i][1]][road[i][0]] = min(g[road[i][1]][road[i][0]],road[i][2]);
    }

    //다익스트라(특정 정점에서 최단경로 탐색)
    priority_queue <pair<int,int>> pq;
    vector<int> distance(N+1,INF);

    //1의 경우 거리 0임을 우선순위 큐와 distance 벡터에 넣어줌.
    pq.push({0,1});
    distance[1] = 0;

    while(!pq.empty()){
        int d = -pq.top().first; //우선순위 큐는 내림차순이므로 - 붙여줌
        int n = pq.top().second;
        pq.pop(); //뻗어나갈 정점을 빼서 탐색 시작

        for(int i=1; i<=N; i++){
            //대각선(자기 자신)이거나 i쪽으로 향하는 도로가 없으면 넘어감
            if(i==n || g[n][i]==INF) continue;

            //거리값을 더했을 때 기존 거리값보다 작으면 갱신하고 넣어줌
            if(distance[i] > d+g[n][i]){
                distance[i] = d+g[n][i];
                pq.push({-distance[i],i});
            }
        }
    }

    for(int i=1;i<=N; i++){
        if(distance[i]<=K)
           ans++;
    }

    return ans;

}