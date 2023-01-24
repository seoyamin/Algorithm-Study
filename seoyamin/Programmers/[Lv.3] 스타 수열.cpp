#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(vector<int> a) {
    int answer = 0;
    map<int, int> m;   // <교집합 원소가 될 숫자, 그 개수>
    
    // m 채우기
    for(auto i : a) {
        m[i]++;
    }
    
    for(auto it : m) {
        
        // 스타 수열 최대 길이 (교집합 원소 개수 * 2) < 현재 answer이면 고려 안함
        if(it.second * 2 < answer) continue;
        
        int temp = 0;  // 이번에 구할 스타 수열 길이
        
        for(int i=0 ; i<a.size()-1 ; i++) {
            if(a[i] == a[i+1]) continue;                          // 조건 3
            if(a[i] != it.first && a[i+1] != it.first) continue;  // 조건 2
            
            temp += 2;    // 스타 수열 길이 update (a[i], a[i+1] 원소 추가)
            i++;          // a[i+1]은 이미 처리했으므로 넘어감
        }
        
        answer = max(answer, temp);  // answer 값 업데이트
    }
    
    return answer;
}