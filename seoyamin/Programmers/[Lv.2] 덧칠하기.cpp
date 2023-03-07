#include <string>
#include <vector>

using namespace std;

// 그냥 section 하나하나 탐색해보고, 안칠해졌으면 m만큼 칠하기

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int end = 0;     // 현재까지 페인트 칠해진 가장 끝 구역 번호 (n)
    
    for(int i=0 ; i<section.size() ; i++) {
        if(section[i] > end) {         // section[i]가 아직 안 칠해진 경우
            end = section[i] + m - 1;  // 칠하기
            answer++;
        }
    }
    
    return answer;
}