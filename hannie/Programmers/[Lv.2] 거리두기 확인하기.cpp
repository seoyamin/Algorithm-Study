#include <vector>
#include <iostream>

using namespace std;

bool isCheck(vector<string> board) {
    vector<vector<bool>> visited(5,vector<bool>(5,false)); // 5*5 bool 타일

    int dy[4] = {0,0,1,-1};
    int dx[4] = {1,-1,0,0};

    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            if(board[i][j] == 'P') { // P일 때
                for(int d = 0; d<4; d++) {
                    int ny=i+dy[d];
                    int nx=j+dx[d];
                    // 경계밖
                    if(ny >= 5 || nx >= 5 || nx < 0 || ny < 0) continue;

                    switch(board[ny][nx]) {
                        case 'P' : return false; // 거리두기 지키지 않음
                        case 'O' :
                            if(visited[ny][nx]) return false; 
                            else {
                                visited[ny][nx] = true;
                                break;
                            }
                    }
                }
            }
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(vector<string> p : places)
        answer.push_back(isCheck(p));
    return answer;
}
