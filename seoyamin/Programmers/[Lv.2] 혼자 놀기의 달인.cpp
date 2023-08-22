#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> cards) {
    int answer = 0;
    vector<int> status(cards.size() + 1, 0);    // 각 상자의 열림 여부
    vector<int> group;                          // 각 그룹의 상자 개수
    
    for(int i=0 ; i<cards.size() ; i++) {
        int count = 0;          // 현재 그룹의 총 상자 개수
        int card = cards[i];    // 현재 상자의 카드 (숫자)
        
        // 닫혀있는 상자인 경우
        while(status[card] == 0) {
            status[card] = 1;        // 현재 상자 열기
            count++;                 // 그룹 상자 개수 추가
            card = cards[card-1];    // 다음 번째 상자로 탐색
        }
        
        group.push_back(count);
    }
    
    sort(group.begin(), group.end(), greater<>());
    if(group.size() > 1) answer = group[0] * group[1];    
    
    return answer;
}