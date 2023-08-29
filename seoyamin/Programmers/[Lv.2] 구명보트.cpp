#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end());
    
    int idx_back = people.size() - 1;
    
    for(int idx_front = 0 ; idx_front <= idx_back ; ) {
        if(idx_front == idx_back) {
            answer++;
            break;
        }
        
        // 2명이 같이 탈 수 있는 경우
        if(people[idx_front] + people[idx_back] <= limit) {
            idx_front++;
            idx_back--;
        }
        
        // 2명이 같이 탈 수 없는 경우
        else {
            idx_back--;
        }
        
        answer++;
    }
    
    return answer;
}