#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for(auto i : numbers) {
        
        // 1) 짝수 : 최하위 비트 0 -> [자신 + 1]이 정답
        if(i%2 == 0) answer.push_back(i + 1);
        
        // 2) 홀수 : [1st] 가장 하위에 있는 0 -> 1 변경
        //          [2nd] 이후 원래 0 뒤에 있는 1 -> 0 변경
        else {
            long long bit = 1;
            
            // 0이 나오기 전까지 1로 이루어진 bit 구하기
            while(true) {       
                
                // & : 두 비트가 모두 1이면 결과 1
                if((i & bit) == 0) break;         // 최하위 비트가 0이 되면 전체 &가 0되면서 break
                
                bit *= 2;      // 다음 비트로
            }
            bit = bit / 2;                        // 최하위 0 이전 1을 0으로
            answer.push_back(i + bit);
        }
    }
    
    return answer;
}