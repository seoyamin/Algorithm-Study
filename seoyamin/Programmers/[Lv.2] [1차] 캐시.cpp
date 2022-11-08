#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
    <LRU>
    - 차례대로 캐시에 저장
    - 캐시에 없으면 맨 뒤에 저장
    - 캐시에 있으면 맨 뒤로 이동
    - 캐시 꽉 차면 맨 처음 삭제하고 맨 뒤에 저장
*/

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> cache;
    
    if(cacheSize==0) return cities.size() * 5;  // 캐시 사용 불가능한 경우
    
    // 대문자 -> 소문자
    for(int i=0 ; i<cities.size(); i++) {
        for(int j=0 ; j<cities[i].size() ; j++) {
            cities[i][j] = tolower(cities[i][j]);
        }
        
        // 1. 캐시에 없는 경우
        if(find(cache.begin(), cache.end(), cities[i]) == cache.end()) {
            answer += 5; 
            
            // 캐시 꽉 찬 경우 : 맨 처음 삭제해서 자리 확보
            if(cache.size() == cacheSize) {
                cache.erase(cache.begin());
            }
            
            // 맨 뒤에 저장
            cache.push_back(cities[i]);
        }
        
        // 2. 캐시에 이미 있는 경우
        else {
            answer += 1;
            cache.erase(find(cache.begin(), cache.end(), cities[i])); // 기존 데이터 삭제 
            cache.push_back(cities[i]); // 맨 뒤에 저장
        }
    }    
    
    
    return answer;
}