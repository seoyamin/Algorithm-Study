#include <iostream>
#include <string>
#include <vector>
using namespace std;

int cnt=0;
vector<int> answer(1,-1);

// 작은 점수가 많은 사람
bool isRight(vector<int>& ryan) {
    for(int i=10; i>=0; i--) {
        if(ryan[i] > answer[i]) return true;
        else if(ryan[i] < answer[i]) return false;
    }
}

// 점수 계산
void Score(vector<int>& ryan, vector<int>& apeach) {
    int ryScore = 0, apScore = 0;
    for(int i=0; i<=10; i++) {
        if(ryan[i] > apeach[i]) ryScore += 10-i;
        else if(apeach[i] > 0) apScore += 10-i;
    }

    int diff = ryScore-apScore;
    if(diff > 0 && diff >= cnt) {
        if( cnt == diff && !isRight(ryan)) return;
        cnt = diff;
        answer = ryan;
    }
}

// 완전 탐색
void solve(int idx, int n, vector<int>& ryan, vector<int>& apeach) {

    if(idx==11 || n==0) {
        ryan[10] += n; // 라이언의 남은 화살은 모두 0
        Score(ryan, apeach);
        ryan[10] -= n;
        return;
    }

    if(apeach[idx] < n) {
        ryan[idx] += apeach[idx]+1;
        // 재귀
        solve(idx+1,n-apeach[idx]-1,ryan,apeach);
        ryan[idx] -= apeach[idx]+1;
    }
    // 재귀
    solve(idx+1,n,ryan,apeach);
}


vector<int> solution(int n, vector<int> info) {
    vector<int> ryan(11,0); // 10점 ~ 0점 : 11개 구역
    solve(0,n,ryan,info);

    return answer;
}
