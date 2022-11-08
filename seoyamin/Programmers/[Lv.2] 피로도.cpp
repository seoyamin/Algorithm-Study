#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    
    // next_permutation 돌리기 위한 던전 종류 벡터
    vector<int> dList;
    for(int i=0 ; i<dungeons.size() ; i++) {
        dList.push_back(i);
    }
    
    do {
        int current_k = k;      // 현재 남은 피로도
        int visited_num = 0;    // 방문한 던전 수
        
        for(int i=0 ; i<dungeons.size() ; i++) {
            if(current_k < dungeons[dList[i]][0]) break;  
            
            current_k -= dungeons[dList[i]][1];  // 방문
            visited_num++;
        }
        
        answer = max(answer, visited_num);
        
    } while(next_permutation(dList.begin(), dList.end()));  
    
    return answer;
}