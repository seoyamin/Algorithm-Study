#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    vector<vector<int>> graph(n+1);     // 두 노드 간의 관계
    vector<int> counts(n+1, 0);         // 두 노드 간의 edge 수
    vector<bool> visited(n+1, false);   // 탐색 여부
    queue<int> queue;                   // 한 from과 연결된 to들 
    int answer = 0;
    
    // graph 채우기
    for (int i = 0; i < edge.size(); i++) {
        int from = edge[i][0];
        int to = edge[i][1];
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    // 일단 start node 넣고 시작
    queue.push(1);
    visited[1] = true;

    while(!queue.empty()) {
        int from = queue.front();  // from
        queue.pop();

        // from과 연결된 모든 to 탐색
        for (int i = 0; i < graph[from].size(); i++) {
            int to = graph[from][i];
            if (!visited[to]) {
                int currentCount = counts[from] + 1;
                visited[to] = true;
                counts[to] = currentCount;
                queue.push(to);
            }
        }
    }

    sort(counts.begin(), counts.end(), greater<int>());
    
    for (auto cnt : counts) {
        if (counts[0] != cnt) break;
        answer++;
    }
    
    return answer;
}