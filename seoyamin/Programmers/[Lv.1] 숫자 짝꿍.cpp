#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<char, int> toMap(string s) {
    map<char, int> m;
    
    for(auto i : s) {
        if(m.find(i) == m.end()) m.insert({i, 1});
        else m[i]++;
    }
    
    return m;
}

string solution(string X, string Y) {
    string answer = "";
    map<char, int> xMap, yMap;
    
    xMap = toMap(X);
    yMap = toMap(Y);
    
    if(xMap.size() > yMap.size()) xMap.swap(yMap);  // size 더 작은 맵이 xMap이 되게끔
    
    for(auto iter : xMap) {
        if(yMap.find(iter.first) != yMap.end()) {
            if(yMap[iter.first] == 0) continue;
            
            int count = (xMap[iter.first] <= yMap[iter.first]) ? xMap[iter.first] : yMap[iter.first];
            yMap[iter.first] -= count;
            
            while(count--) {
                answer += iter.first;
            }
        }
    }
    
    sort(answer.begin(), answer.end(), greater<>());
    
    if(answer == "") return "-1";
    if(answer[0] == '0') return "0";
    
    return answer;
}