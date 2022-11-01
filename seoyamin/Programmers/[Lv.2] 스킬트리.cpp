#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    set<char> s;   // skill 문자 1개씩 저장
    
    for(int i=0 ; i<skill.size() ; i++) {
        s.insert(skill[i]);
    }
   
    for(int i=0 ; i<skill_trees.size() ; i++) {
        for(int j=0 ; j<skill_trees[i].size() ; j++) {
            if(s.find(skill_trees[i][j]) == s.end()) {  // set에 없는 문자는 제거하기
                skill_trees[i].erase(skill_trees[i].begin() + j);
                j--;  // 제거했으므로 인덱스 하나 감소
            }
        }
        
        if(skill.substr(0, skill_trees[i].size()) == skill_trees[i]) answer++;
    }
    
    return answer;
}