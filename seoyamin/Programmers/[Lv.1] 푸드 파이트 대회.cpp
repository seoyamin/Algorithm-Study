#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    
    // 물 기준 왼쪽 문자열 완성
    for(int i=0 ; i<food.size() ; i++) {
        if(food[i]%2 == 1) food[i]--;
        if(food[i] == 0) continue;
        
        for(int j=0 ; j<food[i]/2 ; j++) {
            answer += to_string(i);
        }
    }
    
    // 물 추가
    answer += '0';
    
    
    // 대칭으로 오른쪽 문자열 완성
    // reverse 함수 사용 가능
    for(int i=answer.size()-2 ; i>=0 ; i--) {
        answer += answer[i];
    }
    
    
    return answer;
}