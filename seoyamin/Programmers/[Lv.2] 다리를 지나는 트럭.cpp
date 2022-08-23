#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> bridge;  // 다리 위의 트럭 무게 큐
    
    // 큐 초기화
    for(int q=0 ; q<bridge_length ; q++) {
        bridge.push(0);
    }
    
    int bridge_weight = 0;  // 현재 다리 위 무게
    int bridge_idx = 0;     // 다리 올라가려는 맨 앞 트럭 인덱스
    
    while(!bridge.empty()) {
        answer++;
        bridge_weight -= bridge.front();
        bridge.pop();
        
        if(bridge_idx < truck_weights.size()) {
            
            // [1] 다리 위 남은 무게 충분한 경우
            if(weight - bridge_weight >= truck_weights[bridge_idx]) {  
                bridge.push(truck_weights[bridge_idx]);      // 다리 위로 이번 트럭 올라감
                bridge_weight += truck_weights[bridge_idx];  
                bridge_idx++;                
            }
            
            
            // [2] 다리 위 남은 무게 부족한 경우
            else {  
                bridge.push(0);  // 대기 시간 만큼 0 push
            }
        }
        
    }
    
    return answer;
}