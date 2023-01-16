#include <string>
#include <vector>

using namespace std;

int getAnswer(string s, int answer) {
    if(s.size() == 0) return answer;     // 더 이상 읽을 글자 없는 s인 경우
    
    int numX = 0, numZ = 0;              // x 횟수, x 아닌 횟수
    char x = s[0];
    
    int i;
    for(i=0 ; i<s.size() ; i++) {
        if(s[i] == x) numX++;
        else numZ++;
        
        if(numX > 0 && numX == numZ) {
            answer++;
            break;
        }
    }
    
    
    if(i > s.size()-1) return ++answer;   // s의 끝까지 다 탐색한 경우 (더이상 남은 부분 없음)
    else s = s.substr(i+1);               // 아직 남은 s 부분 있는 상태로 break한 경우
    
    return getAnswer(s, answer);
}


int solution(string s) {
    int answer = 0;
    
    answer = getAnswer(s, 0);    
    
    return answer;
}