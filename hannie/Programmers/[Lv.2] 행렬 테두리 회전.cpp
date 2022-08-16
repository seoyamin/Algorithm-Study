#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

int map[101][101];
int cnt;

//회전 함수
void rotation(int x1, int y1, int x2, int y2) {

    int start = map[x1][y1];
    
    // right 
    for (int i = x1; i < x2; i++) {
        map[i][y1] = map[i + 1][y1];
        cnt = min(cnt, map[i][y1]);
    }
    // down
    for (int i = y1; i < y2; i++) {
        map[x2][i] = map[x2][i + 1];
        cnt = min(cnt, map[x2][i]);
    }
    // left
    for (int i = x2; i > x1; i--) {
        map[i][y2] = map[i - 1][y2];
        cnt = min(cnt, map[i][y2]);
    }
    // up
    for (int i = y2; i > y1 + 1; i--) {
        map[x1][i] = map[x1][i - 1];
        cnt = min(cnt, map[x1][i]);
    }

    map[x1][y1 + 1] = start;
    cnt = min(cnt, map[x1][y1 + 1]);
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    //초기화
    memset(map, 0, sizeof(map));

    //맵 그리기
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= columns; j++) {
            map[i][j] = (i - 1) * columns + j;
        }
    }
    //좌표 가져오기
    for (int i = 0; i < queries.size(); i++) {
        cnt = 10001;
        int x1 = queries[i][0];
        int y1 = queries[i][1];
        int x2 = queries[i][2];
        int y2 = queries[i][3];

        //회전
        rotation(x1,y1,x2,y2);

        //결과 저장
        answer.push_back(cnt);
    }

    //결과 반환
    return answer;
}
