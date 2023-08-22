#include <string>
#include <vector>

using namespace std;

/* 플로이드 와샬 - 모든 정점 사이의 최단 경로를 구하는 알고리즘

for (int 중간점 = 1; 중간점 <= N; 중간점++) {
	for (int 시작점 = 1; 시작점 <= N; 시작점++) {
		for (int 도착점 = 1; 도착점 <= N; 도착점++) {
			if : Dist[시작점][중간점] + Dist[중간점][도착점] < Dist[시작점][도착점]
				 => Dist[시작점][도착점] = Dist[시작점][중간점] + Dist[중간점][도착점] (최소 경로로 업데이트)
		}
	}
}
*/

int dist[201][201];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 1e8;     // max n : 200, max f = 1e5
    
    // 경로 초기화
    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=n ; j++) {
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = 1e8;          // max n : 200, max f = 1e5
        }
    }
    
    // 두 지점 간 요금 반영
    for(auto f : fares) {
        dist[f[0]][f[1]] = f[2];
        dist[f[1]][f[0]] = f[2];
    }
    
    // 플로이드 와샬
    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=n ; j++) {
            for(int k=1 ; k<=n ; k++) {
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
    }
    
    // 경로 = (s -> i) + (i -> a) + (i -> b)
    for(int i=1 ; i<=n ; i++) {
        answer = min(answer, dist[s][i] + dist[i][a] + dist[i][b]);
    }
    
    
    return answer;
}