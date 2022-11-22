#include <string>
#include <vector>
#include <sstream>
#include <regex>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<vector<string>> infoList;
    vector<vector<string>> queryList;
    vector<int> answer;
    
    // infoList 만들기
    for(auto i : info) {
        vector<string> v;
        
        stringstream ss(i);
        ss.str(i);
        
        string item;
        while(ss >> item) {
            v.push_back(item);
        }
        
        infoList.push_back(v);
    }
    
    // queryList 만들기
    for(auto q : query) {
        vector<string> v;
        q = regex_replace(q, regex(" and"), "");  // and 말고 공백 기준으로 바꾸기
        
        stringstream ss(q);
        ss.str(q);
        
        string item;
        while(ss >> item) {
            v.push_back(item);
        }
        queryList.push_back(v);
    }
    
    for(auto q : queryList) {
        int num = 0;  // 이번 query에 해당하는 지원자 명수
        
        for(auto i : infoList) {
            int ok = true;         // query에 해당하는 지원자인지 여부 
            
            for(int k=0 ; k<5 ; k++) {
                if(q[k] == "-") {
                    continue;
                }
                else if((k<4 && q[k] != i[k]) || (k==4 && stoi(i[k]) < stoi(q[k]))) {
                    ok = false;
                    break; 
                } 
            }
            if(ok) num++;
        }
        
        answer.push_back(num);
    }
    
    return answer;
}