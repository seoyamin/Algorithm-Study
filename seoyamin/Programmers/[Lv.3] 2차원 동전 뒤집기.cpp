#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, ans = 11;
vector<vector<int>> beginning, target;

void flip_row(int r) {
    for (int j = 0; j < m; j++)
        beginning[r][j] = (beginning[r][j] + 1) % 2;   //   0  <=>  1
}


// 1-3 케이스 중 몇번째 경우인지 
int compare_colunm(int c) {
    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (beginning[i][c] == target[i][c]) cnt++;

    if (cnt == 0) return 1;  // 1)  해당 열(=c)에서 beginning과 target 전부 반대인 경우
    if (cnt == n) return 0;  // 2)  해당 열(=c)에서 beginning과 target 전부 동일한 경우
    else return -1;          // 3)  1), 2)가 아닌 경우
    return true;
}


void dfs(int r, int c, int cnt) {
    
    // 모든 행에서 뒤집O / 뒤집X 선택을 완료한 경우
    if (r == n) {
        int flag = 1;
        
        // 열의 상태를 비교하여 TARGET과 동일하게 만들 수 있는지 판별
        for (int j = 0; j < m; j++) {
            int ret = compare_colunm(j);
            
            // 현재 상태에서 TARGET과 동일하게 만들 수 없음 -> flag = 0;
            if (ret == -1) { 
                flag = 0;       
                continue;
            } 
            
            // 해당 열이 전부 반대인 경우 1이 반환되어 뒤집기 횟수가 1 증가
            // 해당 열이 전부 동일한 경우 0이 반환되어 뒤집기 횟수가 증가 X
            cnt += ret; 
        }
        
        //  TARGET과 동일하게 만들 수 있는 경우 최소 뒤집기 횟수 갱신
        if (flag) {
            ans = min(ans, cnt);  
        } 
        
        return;
    }
    
    
    if (r != n) {
        dfs(r + 1, c, cnt);       //  해당 행 뒤집기 X
        flip_row(r);
        
        dfs(r + 1, c, cnt + 1);   //  해당 행 뒤집기
        flip_row(r);
    }

}

int solution(vector<vector<int>> _beginning, vector<vector<int>> _target) {
    beginning = _beginning; 
    target = _target;
    
    n = beginning.size(); 
    m = beginning[0].size();
    
    dfs(0, 0, 0);
    
    if (ans == 11)  return -1;   // 목표 상태 만들지 못하는 경우
    return ans;
}