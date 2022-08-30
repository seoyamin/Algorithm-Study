#include <iostream>
#include <vector>
using namespace std;

# define INF 500000
vector<int> dijkstra (int N, vector<vector<int>> road);

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    
    vector<int> dist = dijkstra(N, road);
    
    for (auto &i : dist) {
        if (i <= K)
            answer++;
    }

    return answer;
}

int NextNode (int N, vector<int> dist, vector<int> visited) {
    int min_dist = INF;
    int min_node;
    
    for (int i = 1; i <= N; i++) {
        if ((dist[i] < min_dist) && !visited[i]) {
            min_dist = dist[i];
            min_node = i;
        }
    }
    return min_node;
}

vector<int> dijkstra (int N, vector<vector<int>> road) {
    vector<int> dist(N + 1, INF);
    vector<int> visited(N + 1, false);
    vector<vector<int>> map(N + 1, vector<int>(N + 1,INF));
    
    for (auto &i : road) {
        map[i[0]][i[1]] = min (map[i[0]][i[1]], i[2]);
        map[i[1]][i[0]] = min (map[i[1]][i[0]], i[2]);
    }
    
    for (int i = 1; i <= N; i++) {
        dist[i] = map[1][i];
    }
    dist[1] = 0;
    visited[1] = true;
    
    for (int i = 0; i < N - 1; i++) {
        int next_node = NextNode(N, dist, visited);
        visited[next_node] = true;
        
        for (int j = 1; j <= N; j++) {
            if ((!visited[j]) && (dist[j] > (dist[next_node] + map[next_node][j]))) {
                dist[j] = dist[next_node] + map[next_node][j];
            }
        }
    }
    return dist;
}





