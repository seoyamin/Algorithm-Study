#include <vector>
#include <iostream>
#include <queue>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    // false bool 배열
    bool visited[101][101];
    fill(&visited[0][0],&visited[100][101],false);

    int dy[4] = {0,0,1,-1};
    int dx[4] = {1,-1,0,0};


    // (y,x) 좌표를 담을 q 선언
    queue<pair<int,int>> q;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(visited[i][j]==false&&picture[i][j]!=0){
                int area=1;
                number_of_area++;
                q.push(make_pair(i,j));
                visited[i][j]=true;

                while(!q.empty()){
                    // 시작 좌표
                    int y=q.front().first;
                    int x=q.front().second;
                    q.pop();
                    // 상하좌우 탐색 시작
                    for(int k=0;k<4;k++){
                        int ny=y+dy[k];
                        int nx=x+dx[k];
                        // 존재하는 좌표 and 방문하지 않음 and 같은 번호
                        if(ny>=0 && nx>=0 && ny<m && nx<n && visited[ny][nx]==false && picture[y][x]==picture[ny][nx]){
                            visited[ny][nx]=true; // 방문함 표시
                            q.push(make_pair(ny,nx)); // 좌표 q에 push
                            area++; // area 계산
                        }
                    }
                }
                if(area > max_size_of_one_area)
                    max_size_of_one_area = area;
            }
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;

    return answer;
}
