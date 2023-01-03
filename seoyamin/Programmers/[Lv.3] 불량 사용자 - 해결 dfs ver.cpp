#include <string>
#include <vector>
#include <set>

using namespace std;
set<int> s;
bool check[8];
int len;

void dfs(vector<string> &user_id, vector<string> &banned_id, int i, int num) {
    if(i == len) {             // 모든 banned id 처리한 경우 종료
        s.emplace(num);
        return;
    }
    
    for(int j=0 ; j<user_id.size() ; j++) {
        int k;
        if(banned_id[i].size() != user_id[j].size()) continue;   // 길이 다르면 불가능
        
        if(check[j] == true) continue;   // 이미 선택한 id 이면 불가능
        
        
        for(k=0 ; k<user_id[j].size() ; k++) {
            if(banned_id[i][k] == '*') continue;               // * 이면 뭐든지 가능
            if(banned_id[i][k] != user_id[j][k]) break;        // 서로 다른 문자면 불가능
        }
        
        if(k == user_id[j].size()) {
            check[j] = true;
            dfs(user_id, banned_id, i+1, num | (1 << j));
            check[j] = false;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    len = banned_id.size();
    dfs(user_id, banned_id, 0, 0);
    
    return s.size();
}