#include <string>
#include <vector>

using namespace std;

int dp[500][500];

int solution(vector<vector<int>> triangle) {
    int answer = 0;    
    dp[0][0] = triangle[0][0];
    
    for(int i=1 ; i<triangle.size() ; i++) {
        
        // n번째 줄 원소를 순환하면서 n-1번째 줄 원소 2개 중 더 큰 값 선택해서 더함
        /*    2       "4"
                \ 7 /        */
        for(int j=0 ; j<triangle[i].size() ; j++) {
            if(j==0) 
                dp[i][j] = triangle[i][j] + dp[i-1][j];     // 우측
            
            else if(j==triangle[i].size()-1)
                dp[i][j] = triangle[i][j] + dp[i-1][j-1];   //  좌측
            
            else
                dp[i][j] = triangle[i][j] + max(dp[i-1][j-1], dp[i-1][j]);  // 우 vs 좌 중에서 큰 값
        }
    }
    
    for(int i=0 ; i<triangle.size()-1 ; i++) {
        answer = max(answer, dp[triangle.size()-1][i]);
    }
     
    return answer;
}