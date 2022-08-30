#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int solution(vector<vector<int>> sizes) {
    int row = 0, col = 0;  // 최종 지갑 크기의 가로, 세로
    int answer = 0;
    
    
    // 무조건 '가로 >= 세로' 이게끔 변형
    for(int i=0 ; i<sizes.size() ; i++) {
        if(sizes[i][0] < sizes[i][1]) {
            int temp = sizes[i][0];
            sizes[i][0] = sizes[i][1];
            sizes[i][1] = temp;
        }
        
        // 가로, 세로 최댓값 구하기
        row = max(row, sizes[i][0]);
        col = max(col, sizes[i][1]);
    }
    
    answer = row * col;
    return answer;
}