#include <iostream>
#include <vector>
#include <queue>
using namespace std;


vector<pair<int, int>> relation[51];  // index 노드와 인접한 노드 정보들 (노드번호, 사이시간) 저장
vector<int> minTime;                  // '노드1 ~ 해당 index 노드' 최소 소요 시간 저장


void dijkstra(int start) { 
    priority_queue<pair<int, int>> pq;
    
    minTime[start] = 0;
    pq.push(make_pair(start, 0));
    
    while(!pq.empty()) {
        int v = pq.top().first;  // 현재 노드 v
        int t = pq.top().second; // '직전 노드 -> 현재 노드 v' 이동시간 
        pq.pop();
        
        for(int i=0 ; i<relation[v].size() ; i++) {  // 현재 노드 v와 인접한(relation) 모든 노드들 탐색
            
            int vr = relation[v][i].first;           // 인접 노드 vr 
            int tr = relation[v][i].second;          // '현재 노드 v -> 인접 노드 vr' 이동시간
            
            
            //  이동시간 :  (노드1 -> 현재노드v -> 인접노드vr)  <  (노드1 -> 인접노드vr) 인 경우
            if(minTime[v] + tr < minTime[vr]) {  
                minTime[vr] = minTime[v] + tr;   // 최솟값으로 이동시간 갱신
                pq.push(make_pair(vr, tr));
            }
        }
    }
}


int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    
    minTime.resize(N + 1, 2e9);
    
    for(int i=0 ; i<road.size() ; i++) {
        int v1 = road[i][0];  // village 1
        int v2 = road[i][1];  // village 2
        int t = road[i][2];   // time (v1 ~ v2)
        
        relation[v1].push_back(make_pair(v2, t));
        relation[v2].push_back(make_pair(v1, t));
    }

    dijkstra(1);
    
    for(auto i : minTime) {
        if(i <= K) answer++;
    }
    
    return answer;
}