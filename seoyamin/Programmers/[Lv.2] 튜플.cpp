#include <string>
#include <vector>
#include <map>
#include <regex>
#include <sstream>

using namespace std;

vector<int> solution(string s) {
    map<int, int> m;
    vector<int> answer;
    
    // s 가공 : {{1,2,3},{2,1},{1,2,4,3},{2}}   ->   {1,2,3 {2,1 {1,2,4,3 {2
    s = s.substr(1, s.size() - 1);
    s = s.substr(0, s.size() - 2);
    s = regex_replace(s, regex("},"), " ");
    
    
    // s 가공 : {1,2,3 {2,1 {1,2,4,3 {2     1 2 3    1 2 3    2 1    1 2 4 3    2
    stringstream ss(s);
    ss.str(s);
    string item;
    int itemNum = 0;
    
    while(ss >> item) {
        itemNum++;
        item = item.substr(1, item.size() - 1);
        item = regex_replace(item, regex(","), " ");
        
        // s의 item 가공 : 1 2 3  ->  1    2    3
        stringstream ss2(item);
        ss2.str(item);
        string item2;
        
        // map에 <숫자, 등장개수> 저장
        while(ss2 >> item2) {
            if(m.find(stoi(item2)) == m.end()) m.insert(make_pair(stoi(item2), 1));
            else m[stoi(item2)]++;
        }
    }
    
    
    // answer 완성
    for(int i=itemNum ; i>0 ; i--) {
        for(auto const &[key, value] :m) {
            if(value == i) answer.push_back(key);
        }
    }
    
    return answer;
}