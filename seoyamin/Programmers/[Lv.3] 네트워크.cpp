#include <string>
#include <vector>

using namespace std;

bool visited[200];  // 방문 여부 체크

void dfs(int current, int n, vector<vector<int>> &computers) {
    visited[current] = true;   // current 컴퓨터는 방문했다고 표시
    
    for(int i=0 ; i<n ; i++) {               
        if(!visited[i] && computers[current][i]) { // [방문한 적 X]  &&  [연결 O] 이면 다음 컴퓨터 방문
            dfs(i, n, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i=0 ; i<n ; i++) {
        if(!visited[i]) {
            dfs(i, n, computers);
            answer++;
        }
    }
    
    return answer;
}