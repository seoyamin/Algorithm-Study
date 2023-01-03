#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    map<int, int> m;    // <크기, 개수> 담는 맵
    for(auto item : tangerine) {
        if(m.find(item) != m.end()) m[item]++;
        else m.insert({item, 1});
    }
    
    vector<int> v;       // 귤의 개수만 담는 벡터 (벡터의 크기 = 귤 종류 개수)
    for(auto item : m) {
        v.push_back(item.second);
    }
    sort(v.begin(), v.end(), greater<>());  // 개수 많은 순으로 정렬
    
    
    int count = 0;           // 전체 귤 개수
    for(auto item : v) {
        count += item;       // 전체 귤 개수 업데이트
        answer++;            // 전체 귤 종류 업데이트
        
        if(count >= k) return answer;
    }
    
    return answer;
}