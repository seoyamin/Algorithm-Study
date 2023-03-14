#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> answer;
bool visited[10001];

bool dfs(string start, int count, vector<vector<string>> &tickets) {
    if(count == tickets.size()) return true;
    
    for(int i=0 ; i<tickets.size() ; i++) {
        if(visited[i] == true) continue;
        
        if(start == tickets[i][0]) {
            visited[i] = true;
            answer.push_back(tickets[i][1]);
            bool next = dfs(tickets[i][1], count+1, tickets);
            
            if(next) return true;
            visited[i] = false;
        }
    }
    
    answer.pop_back();  // 더이상 갈 곳 없으면 이 길 아님 -> 이 길의 도착지는 answer에서 제거 (부적합 판정)
    return false;
}



vector<string> solution(vector<vector<string>> tickets) {
    answer.push_back("ICN");  // 항상 ICN 공항에서 출발
    
    sort(tickets.begin(), tickets.end());  // tickets를 알파벳순으로 정렬
    
    dfs("ICN", 0, tickets);  
    
    return answer;
}