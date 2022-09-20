#include <string.h>
#include <vector>
#include <queue>

using namespace std;

int moves[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool visited[100][100];


int bfs(int col_current, int row_current, int m, int n, const vector<vector<int>> &picture) {
    int size = 1;             // 영역에 속한 좌표 개수 (영역 크기)
    queue<pair<int, int>> q;  // 영역에 속하는 좌표 저장하는 큐
    
    q.push(make_pair(col_current, row_current));
    visited[col_current][row_current] = true;
    
    
    while(!q.empty()) {
        int col_current = q.front().first;
        int row_current = q.front().second;
        
        q.pop();
        
        for(int i=0 ; i<4 ; i++) {
            int col_next = col_current + moves[i][0];
            int row_next = row_current + moves[i][1];
            
            if(col_next >=0 && row_next >= 0 && col_next < m && row_next < n    // 조건 1. 그림 내부
               && picture[col_current][row_current] == picture[col_next][row_next]  // 조건 2. 동일한 영역
                && visited[col_next][row_next] == false) {   // 조건 3. 방문한 적 없는 공간
                
                q.push(make_pair(col_next, row_next));
                visited[col_next][row_next] = true;
                size++;
            }
        }
    }

    return size;
}


// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    
    memset(visited, false, sizeof(visited));    // visited 초기화
    
    for(int i=0 ; i<m ; i++) {
        for(int j=0 ; j<n ; j++) {
            if(visited[i][j] == false && picture[i][j] != 0) {  // 방문한 적 없는 색칠칸인 경우
                number_of_area++;
                
                int size = bfs(i, j, m, n, picture);  // 영역의 크기 (칸 수) 리턴하는 bfs 함수
                max_size_of_one_area = max(max_size_of_one_area, size);
            }
        }
    }
    
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}