#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<string>> clothes) {
    string current_type = "";
    int current_num = 0;
    int answer = 1;
    
    string temp;
    for(int i=0 ; i<clothes.size() ; i++) {       // [type, name] 형태로 SWAP
        temp = clothes[i][0];
        clothes[i][0] = clothes[i][1];
        clothes[i][1] = temp;
    }
    
    sort(clothes.begin(), clothes.end());         // 동일한 type끼리 모이도록 정렬
    current_type = clothes[0][0];                 // type 초기값 설정
    
    
    
    for(auto j : clothes) {
        if(current_type == j[0]) current_num++;   // 동일한 type이면 종류 +1
        else {
            answer *= (current_num + 1);          // 1 : 아무것도 선택하지 않은 경우
            
            current_type = j[0];                  // type값 갱신
            current_num = 1;                      // 해당 type의 종류 갱신
        }
    }
    
    // 맨 마지막 type 처리
    answer *= (current_num + 1);   
    
    // 의상을 하나도 입지 않은 경우 제외
    answer--;
    
    return answer;
}