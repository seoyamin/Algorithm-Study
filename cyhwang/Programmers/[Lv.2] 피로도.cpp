#include <string>
#include <vector>
#include <iostream>

using namespace std;
void dfs (vector<vector<int>> dungeons, int cur_k, int count);
vector<bool> visited(8, false);
int answer = -1;

int solution(int k, vector<vector<int>> dungeons) {
    dfs(dungeons, k, 0);
    
    return answer;
}

void dfs (vector<vector<int>> dungeons, int cur_k, int count) {
    if (cur_k < 0) {
        return;
    }
    
    for (int i = 0; i < dungeons.size(); i++) {
        if (!visited[i] && cur_k >= dungeons[i][0]) {
            visited[i] = true;
            dfs(dungeons, cur_k - dungeons[i][1], count + 1);
            visited[i] = false;
        }
    }
    if (count > answer)
        answer = count;
    return;
    
}
