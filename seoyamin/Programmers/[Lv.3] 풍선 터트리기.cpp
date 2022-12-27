#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> a) {
    int answer = 1;
    int min_value = a[0], min_index = 0;
    
    // 최솟값 풍선 찾기
    for(int i=0 ; i<a.size() ; i++) {
        if(a[i] <= min_value) {
            min_value = a[i];
            min_index = i;
        }
    }
    
    
    // 최솟값 풍선의 왼쪽 영역
    int current_left_min = 1000000000;
    for(int i=0 ; i<min_index ; i++) {
        
        // [case 1] current a[i]의 왼쪽 탐색 결과, a[i]보다 작은 값(K)이 있음 
        // -> 왼쪽에도(K), 오른쪽에도(min_value) 자신보다 작은 값이 있음 => 불가능 상태
        if(a[i] >= current_left_min) continue;     
        
        // [case 2] 가능 상태
        else {
            current_left_min = a[i];  // current_left_min 업데이트
            answer++;
        }
    }
    
    
    // 최솟값 풍선의 오른쪽 영역
    int current_right_min = 1000000000;
    for(int i=a.size()-1 ; i>min_index ; i--) {
        
        // [case 1] current a[i]의 오른쪽 탐색 결과, a[i]보다 작은 값(K)이 있음 
        // -> 왼쪽에도(min_value), 오른쪽에도(K) 자신보다 작은 값이 있음 => 불가능 상태
        if(a[i] >= current_right_min) continue;     
        
        // [case 2] 가능 상태
        else {
            current_right_min = a[i];  // current_left_min 업데이트
            answer++;
        }
        
    }
    
    
    return answer;
}