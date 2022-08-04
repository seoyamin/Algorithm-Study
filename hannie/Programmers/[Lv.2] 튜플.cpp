#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <iostream>
#include <sstream>
using namespace std;

// 예시:  "{{4,2,3},{3},{2,3,4,1},{2,3}}"	[3, 2, 4, 1]
// map 정렬 조건
bool comp(pair<string, int>& a, pair<string, int>& b){
    return a.second > b.second; 
}

// 문자열 쉼표(,)로 자르기
vector<string> split(string s){

    stringstream ss(s);
    string temp;
    vector<string> v;
    while(getline(ss,temp,',')){
        v.push_back(temp);
    }
    return v; 
}


vector<int> solution(string s) {
    vector<int> answer={};
    vector<int> length;
    map<string,int> m;
    
    // 필요 없는 {} 기호는 다 지운다.
    s = s.substr(1, s.length()-2);
    s.erase(remove(s.begin(), s.end(), '{'), s.end());
    s.erase(remove(s.begin(), s.end(), '}'), s.end()); 

    vector<string> v = split(s); // 쉼표로 문자열 분리 ex) 4 2 3 3 2 3 4 1 2 3 
    vector<string> v2; // find 조건문 쓰려고 v2 정의!

    for(int i=0; i<v.size(); i++){
        if(find(v2.begin(), v2.end(), v[i])==v2.end()){ // map 에 해당 문자가 없을 시 => map 에 insert
            v2.push_back(v[i]);
            m.insert({v[i], 1});
        }
        else if(m.find(v[i])!=m.end()){ // map 에 해당 문자가 있을 시 => second 값 +1
            m[v[i]]++; 
        }
    }

    // map 을 vector<pair>로 바꿔서 정렬.
    vector<pair<string,  int>> v3(m.begin(), m.end());
    sort(v3.begin(), v3.end(), comp);
    
    // map 의 second 값(=빈도수)을 내림차순 정렬
    for(int i=0; i<v3.size(); i++){
        string str = v3[i].first;
        int ans = atoi(str.c_str()); // string to int
        answer.push_back(ans);
    }
    
    return answer;
}
