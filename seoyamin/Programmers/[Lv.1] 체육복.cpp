#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> v(n+1, 1);    // 각 학생의 체육복 개수
    
    v[0] = 0;
    
    // 여벌 현황 반영
    for(int i=0 ; i<reserve.size() ; i++) {
        v[reserve[i]]++;
    }
    
    // 도난 현황 반영    
    for(int i=0 ; i<lost.size() ; i++) {
        v[lost[i]]--;
    }
    
    for(int i=1 ; i<=n ; i++) {
        // 체육복 빌려야 하는 경우
        if(v[i] == 0) {
            
            // (1) 앞 학생에게 빌리기
            if(v[i-1] == 2) {
                v[i-1]--;
                v[i]++;
            }
            
            // (2) 뒷 학생에게 빌리기
            else if(v[i+1] == 2) {
                v[i+1]--;
                v[i]++;
            }
        }
    }
    
    // 체육 수업 가능한 학생 수 카운트
    for(auto i : v) {
        if(i > 0) answer++;
    }
    
    return answer;
}