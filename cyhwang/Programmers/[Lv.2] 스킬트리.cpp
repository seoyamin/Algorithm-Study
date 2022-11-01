#include <string>
#include <vector>

using namespace std;
int is_skill_tree (string skill, string skill_tree);

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for (auto st: skill_trees) {
        answer += is_skill_tree(skill, st);
    }
    
    return answer;
}

int is_skill_tree (string skill, string skill_tree) {
    int st_index = 0;
    int s_index = 0;
    while (st_index < skill_tree.length() && s_index < skill.length()) {
        if(skill[s_index] == skill_tree[st_index]) {
            s_index++;
        }
        for (int i = s_index + 1; i < skill.length(); i++) {
            if (skill[i] == skill_tree[st_index])
                return 0;
        }
        st_index++;
    }
    
    if(s_index != 0) {
        return 1;
    }
}
