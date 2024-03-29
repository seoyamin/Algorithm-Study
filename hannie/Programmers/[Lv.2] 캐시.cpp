#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
        int answer = 0;

        for(int i=0; i<cities.size();i++){
            for(int j=0; j<cities[i].size(); j++){
                cities[i][j] = tolower(cities[i][j]); // 모두 소문자로 변환
            }
        }

        vector<string> cache; // 캐시 벡터
        for(int i=0; i<cities.size(); i++) {

            auto iter = find(cache.begin(), cache.end(), cities[i]);
            if (iter == cache.end()) {
                answer += 5;
                if (cache.size() < cacheSize)
                    cache.push_back(cities[i]);
                else if (cache.size() == cacheSize && cacheSize > 0) {
                    cache.erase(cache.begin()); // 맨 앞 삭제
                    cache.push_back(cities[i]);
                }
            } else {
                answer += 1;
                cache.erase(iter);
                cache.push_back(cities[i]);
            }
        }
        return answer;

}
