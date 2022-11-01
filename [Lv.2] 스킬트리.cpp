#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    for(auto s:skill_trees){
        int idx = -1; // 인덱스 -1로 고정
        for(int i=skill.size()-1; i>=0; i--){
            if(s.find(skill[i])!=string::npos){
                idx = i; // s에 있는 스킬 중 가장 오른쪽 인덱스.
                break;
            }
        }
        for(int i=s.size()-1; i>=0; i--){  // ex. B<-A<-C<-D<-E 
            if(s[i]==skill[idx]) // ex. "CBD"
                idx--;
        }
        if(idx==-1)
            answer++;
    }
    return answer;
}
