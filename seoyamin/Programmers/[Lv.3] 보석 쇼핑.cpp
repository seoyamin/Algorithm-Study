#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2);
    set<string> kind;
    
    // 총 보석 종류 개수 구하기 (kind.size())
    for (int i = 0; i < gems.size(); ++i) {
        kind.insert(gems[i]); 
    }
        
    int minLen = 100000;      // 구하는 구간 길이 (초기값은 gems 최대 크기로 설정)
    map<string, int> count;           
    
    // 구간의 시작과 끝을 나타내는 포인터
    int start = 0;   
    int end = 0;
    
    int i;
    while (true) {
        
        // [1] end 구하기
        for (i = end; i < gems.size(); ++i) {
            count[gems[i]]++;
            
            if (count.size() == kind.size()) {  // 모든 종류 포함하게 된 경우
                end = i;                        // 
                break;
            }
        }
        
        // end가 업데이트 안된 채로 for문 종료(i가 gems 끝을 넘음) -> 그냥 break
        if (i == gems.size()) {
            break;
        }
            
        // [2] start 구하기
        for (i = start; i < gems.size(); ++i) {
            
            // 그 종류 보석이 1개만 남은 경우 종료
            if (count[gems[i]] == 1) {
                start = i;
                break;
            }
            
            // 2개 이상이면 start 좀 더 뒤로 해도 됨 (개수 1개 줄이기)
            else count[gems[i]]--;
        }
        
        // minLen 업데이트
        if (end - start < minLen) {
            answer[0] = start + 1;
            answer[1] = end + 1;
            minLen = end - start;
        }
        
        // 새로운 다음 구간 탐색
        // gems[start] 는 제외해야하므로 count 에서 제거 
        count.erase(gems[start]);
        start++;
        end++;
    }
    
    return answer;
}