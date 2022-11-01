#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// 성격 유형 판단
char getType(map<char, int> &m, char c1, char c2) {
    if(m[c1] >= m[c2]) return c1;
    else return c2;
}

string solution(vector<string> survey, vector<int> choices) {
    vector<vector<char>> type = {{'R', 'T'}, {'C', 'F'}, {'J', 'M'}, {'A', 'N'}};
    map<char, int> m;
    string answer = "";
    
    // map 초기화
    for(int i=0 ; i<type.size() ; i++) {
        m.insert({type[i][0], 0});
        m.insert({type[i][1], 0});
    }
    
    // 점수 계산
    for(int i=0 ; i<choices.size() ; i++) {
        if (choices[i] == 4) continue;
        else if(choices[i] < 4) m[survey[i][0]] += (4-choices[i]);
        else m[survey[i][1]] += (choices[i]-4);
    }
    
    // 성격 유형 판단
    for(int i=0 ; i<type.size() ; i++) {
        sort(type[i].begin(), type[i].end());            // 알파벳순으로 정렬
        answer += getType(m, type[i][0], type[i][1]);
    }
    
    
    return answer;
}