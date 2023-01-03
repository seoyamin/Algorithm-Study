#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

vector<string> getCaseNum(string id, const vector<string> &user_id) {
    vector<string> caseList;
    
    for(int i=0 ; i<user_id.size() ; i++) {
        if(id.size() != user_id[i].size()) continue;   // 길이 다르면 불가능
        
        bool ok = true;
        for(int j=0 ; j<id.size() ; j++) {
            if(id[j] == '*') continue;                  // * 이면 뭐든지 가능
            else if(id[j] == user_id[i][j]) continue;   // 서로 같은 문자면 가능
            
            else {                                      // 그 외 : 불가능
                ok = false;
                break;
            }
        }
        
        if(ok) caseList.push_back(user_id[i]);
    }
    
    return caseList;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    vector<vector<string>> cases;     // banned id별 가능한 경우 저장하는 벡터
    int answer = 1;
    
    for(auto id : banned_id) {
        cases.push_back(getCaseNum(id, user_id));
    }
    
    for(auto i : cases) {   // 최종 경우의 수 구하기
        answer *= i.size();
        for(auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    
    // 중복 케이스 처리..
    
    return answer;
}