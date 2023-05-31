#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 1;     // 0번째 폭격 미사일은 반드시 요격
    
    sort(targets.begin(), targets.end());
    
    int current_e = targets[0][1];
    
    for(int i=1 ; i<targets.size() ; i++) {
        if(targets[i][0] >= current_e) {
            answer++;
            current_e = targets[i][1];
            continue;
        } 
        
        // current_e 업데이트
        current_e = current_e <= targets[i][1] ? current_e : targets[i][1];
    }
    
    return answer;
}