#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> cache;
    
    if (cacheSize == 0)
        return cities.size() * 5;
    
    //도시 이름 모두 소문자로 변환
    for (int a = 0; a < cities.size(); a++) {
        for (int b = 0; b < cities[a].size(); b++) {
            cities[a][b] = tolower(cities[a][b]);
        }
    }
    
    cache.push_back(cities[0]);
    answer += 5;
    for (int i = 1; i < cities.size(); i++) {
        bool flag = true;
        if (cache.size() < cacheSize) {
            for (int j = 0; j < cache.size(); j++) {
                if (cache[j] == cities[i]) {
                    cache.erase(cache.begin() + j);
                    answer += 1;
                    cache.push_back(cities[i]);
                    flag = false;
                    j = cacheSize;
                }
            }
            if (flag) {
                //cache.erase(cache.begin()); cacheSize보다 작으니 삭제할 필요 없음
                cache.push_back(cities[i]);
                answer += 5;
            }
        }
        else { //cache가 꽉 찬 경우
            for (int j = 0; j < cacheSize; j++) {
                if (cache[j] == cities[i]) {
                    cache.erase(cache.begin() + j);
                    answer += 1;
                    cache.push_back(cities[i]);
                    flag = false;
                    j = cacheSize;
                }
            }
            if (flag) {
                cache.erase(cache.begin());
                cache.push_back(cities[i]);
                answer += 5;
            }
        }
    }
    
    return answer;
}
