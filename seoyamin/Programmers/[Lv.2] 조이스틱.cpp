#include <string>
#include <vector>

using namespace std;

// up & down 횟수 구하는 메소드
int alphabet(char c) {
    return min(c-'A', 'Z'-c+1);
}


int solution(string name) {
    int answer = 0;
    int answer_cursor = name.size() - 1;
    
    for(int i=0 ; i < name.size() ; i++) {
        answer += alphabet(name[i]);       // 알파벳 맞추기
        
        int next = i + 1;
        while(next < name.size() && name[next] == 'A') next++; // name[i] 이후 처음으로 A 아닌 문자 찾기
        
        int left = i;
        int right = name.size() - next;
        answer_cursor = min(answer_cursor, min(2*left + right, 2*right + left));
    }
    
    answer += answer_cursor;
    
    return answer;
}