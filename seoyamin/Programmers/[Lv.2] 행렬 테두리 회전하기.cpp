#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<vector<int>> v(rows, vector<int>(columns, 0));
    vector<int> answer;
    
    
    // 전체 행렬 v 값 초기화
    int value = 1;
    for(int i=0 ; i<rows ; i++) {
        for(int j=0 ; j<columns ; j++) {
            v[i][j] = value;
            value++;
        }
    }
    
    
    // 회전 & 최솟값 찾기
    for(int k=0 ; k<queries.size() ; k++) {
        vector<int> maxV;
        
        int x1 = queries[k][0] - 1; int y1 = queries[k][1] - 1;
        int x2 = queries[k][2] - 1; int y2 = queries[k][3] - 1;
        
        
        // 양 모퉁이 4개 값 꺼내놓기 (a11 ~ a22)
        int a11 = v[x1][y1]; maxV.push_back(a11);
        int a12 = v[x1][y2]; maxV.push_back(a12);
        int a21 = v[x2][y1]; maxV.push_back(a21);
        int a22 = v[x2][y2]; maxV.push_back(a22);
        
        
        // 가로 라인 회전
        for(int m = y1 + 1 ; m < y2 ; m++) {
            v[x1][y2-m+y1+1] = v[x1][y2-m+y1];
            v[x2][m-1] = v[x2][m];
            
            maxV.push_back(v[x1][y2-m+y1]);
            maxV.push_back(v[x2][m]);
        }
        
        // 세로 라인 회전
        for(int n = x1 + 1 ; n < x2 ; n++) {
            v[n-1][y1] = v[n][y1];
            v[x2-n+x1+1][y2] = v[x2-n+x1][y2];
            
            maxV.push_back(v[n][y1]);
            maxV.push_back(v[x2-n+x1][y2]);
        }
        
        // 꺼낸 모퉁이 다시 넣기
        v[x1][y1+1] = a11;
        v[x1+1][y2] = a12;
        v[x2-1][y1] = a21;
        v[x2][y2-1] = a22;
        
        
        // 최솟값 answer에 넣기
        sort(maxV.begin(), maxV.end());
        answer.push_back(maxV[0]);
    }
    
    return answer;
}