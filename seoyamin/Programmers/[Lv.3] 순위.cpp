#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    bool status[101][101] = {false, };
    
    // p0 > p1 상태 : status[p0][p1] = true
    for(int i=0 ; i<results.size() ; i++) {
        status[results[i][0]][results[i][1]] = true;    
    }
    
    
    for(int a=1 ; a<=n ; a++) {
        for(int b=1 ; b<=n ; b++) {
            for(int c=1 ; c<=n ; c++) {
                // b > a && a > c 이면 b > c
                if(status[b][a] == true && status[a][c] == true) {
                    status[b][c] = true;
                }
            }
        }
    }
    
    
    for(int i=1 ; i<=n ; i++) {
        int count = 0;
        
        // i와 j의 순위가 결정된 상태이면 count++
        for(int j=1; j<=n ; j++) {
            if(status[i][j] != status[j][i]) count++;
        }
        
        if(count == n-1) answer++;
    }
    
    return answer;
}