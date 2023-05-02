#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool visited[101][101];
int dr[] = {0, 0, -1, 1};
int dc[] = {-1, 1, 0, 0};

int dfs(int row, int col, vector<string> &maps) {   
    visited[row][col] = true;
    
    int days = 0;  
    days += (maps[row][col] - '0');
    
    
    // 상,하,좌,우 연결된 칸들 탐색
    for(int i=0 ; i<4 ; i++) {
        
        int row_next = row + dr[i];
        int col_next = col + dc[i];
        
        // (비정상 1) 지도 벗어난 경우
        if(row_next < 0 || row_next >= maps.size() || col_next < 0 || col_next >= maps[0].size()) {
            continue;
        }
        
        // (비정상 2) 이미 방문했거나 'X'인 경우
        if(visited[row_next][col_next] == true || maps[row_next][col_next] == 'X') {
            continue;
        }
        
        // (정상) 방문한 적 없고 'X' 아닌 경우 
        visited[row_next][col_next] = true;
        days += dfs(row_next, col_next, maps);
    }
    
    return days;
}


vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    for(int i=0 ; i<maps.size() ; i++) {
        for(int j=0 ; j<maps[i].size() ; j++) {
            if(maps[i][j] != 'X' && visited[i][j] == false) {
                int result = dfs(i, j, maps);
                answer.push_back(result);
            }
        }
    }

    
    if (answer.size() == 0) return {-1};
    
    sort(answer.begin(), answer.end());
    return answer;
}