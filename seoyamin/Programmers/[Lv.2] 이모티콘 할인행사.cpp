#include <string>
#include <vector>

using namespace std;

int percent[4] = {40, 30, 20, 10};
vector<int> permutation;    // 각 중복 순열 케이스 임시 저장
vector<vector<int>> p;      // 모든 중복 순열 케이스 저장

// 중복 순열 만드는 함수
void repeatedPermutation(int count) {
    
    // 원하는 순열 개수만큼 뽑은 경우 -> 종료
    if(count == permutation.size()) {
        vector<int> temp;
        for(int i=0 ; i<permutation.size() ; i++) {
            temp.push_back(permutation[i]);
        }
                           
        p.push_back(temp);
        return;
    }
                           
    for(int i=0 ; i<4 ; i++) {
        permutation[count] = percent[i];
        repeatedPermutation(count+1);
    }
}


vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    permutation = vector<int>(emoticons.size(), 0);   // 중복 순열 하나 당 크기 초기화
    
    repeatedPermutation(0);     // 중복 순열 뽑아서 p에 저장
    
    
    int maxJoinNum = 0;         // 이모티콘 플러스 최대 가입자수
    int maxBenefit = 0;         // 이모티콘 최대 판매액
    
    for(int i=0 ; i<p.size() ; i++) {
        int currentJoinNum = 0;     // 현재 중복 순열의 이모티콘 플러스 가입자수
        int currentBenefit = 0;     // 현재 중복 순열의 이모티콘 판매액
        
        for(int j=0 ; j<users.size() ; j++) {
            int ld = users[j][0];    // 현재 사용자 기준 할인율 limit discount
            int lp = users[j][1];    // 현재 사용자 기준 구매 비용 limit price
            int cp = 0;              // 현재 사용자가 지금까지 구매한 비용 current price
            
            
            for(int k=0 ; k<p[i].size() ; k++) {
                if(p[i][k] >= ld) {
                    cp += (emoticons[k] * (100 - p[i][k]) / 100);
                }
            }
            
            // 이모티콘 플러스 가입 O
            if(cp >= lp) {
                currentJoinNum++;
            }
            
            // 가입 X
            else {
                currentBenefit += cp;
            }
        }
        
        // 1번 목표 >> 2번 목표
        if(maxJoinNum == currentJoinNum) {
            maxBenefit = max(maxBenefit, currentBenefit);
        }
        
        // 1번 목표
        else if(maxJoinNum < currentJoinNum) {
            maxJoinNum = currentJoinNum;
            maxBenefit = currentBenefit;
        }
    }
    
    answer.push_back(maxJoinNum);
    answer.push_back(maxBenefit);
    
    return answer;
}