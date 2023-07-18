#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    int route[101][101] = {0, };    // 초기화 = 0
    
    route[1][1] = 1;                // start = 1    
    
    for(auto p : puddles) {         // 웅덩이 = -1
        route[p[1]][p[0]] = -1;
    }
    
    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=m ; j++) {
            
            // start
            if(i==1 && j==1) {
                continue;
            }
            
            // 현재 지점이 웅덩이
            else if(route[i][j] == -1) {
                continue;
            }
            
            else {
                int up = (route[i-1][j] == -1) ? 0 : route[i-1][j];
                int left = (route[i][j-1] == -1) ? 0 : route[i][j-1];
                
                route[i][j] = (up + left) % 1000000007;
            }
        }
    }
    
    answer = route[n][m];
    return answer;
}