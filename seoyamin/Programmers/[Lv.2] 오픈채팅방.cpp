#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer, action;
    map<string, string> nickname;
    
    for(int i=0 ; i<record.size() ; i++) {
        string item[3];
        int idx = 0;
        stringstream ss(record[i]);
        
        string str;
        while(ss >> str)
            item[idx++] = str;
        
        if(item[0] == "Enter") {
            answer.push_back(item[1]);
            nickname[item[1]] = item[2];
            action.push_back("님이 들어왔습니다.");
        }
        
        else if(item[0] == "Leave") {
            answer.push_back(item[1]);
            action.push_back("님이 나갔습니다.");
        }
        
        else 
            nickname[item[1]] = item[2];
    }
    
    for(int i=0 ; i<answer.size() ; i++) 
        answer[i] = nickname[answer[i]] + action[i];
    
    return answer;
}
