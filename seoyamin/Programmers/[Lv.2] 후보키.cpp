#include <string>
#include <vector>
#include <set>

using namespace std;

// 최소성 여부 확인 : 기존 조합 중 이번에 들어온 조합과 같은 것이 존재하는지 확인
bool check_min(vector<int> v, int current) {
    for(int i = 0; i < v.size(); i++) {
        if((v[i] & current) == v[i]) return false;
    }

    return true;
}

int solution(vector<vector<string>> relation) {
    vector<int> answer;
    int row = relation.size();
    int col = relation[0].size();
    
    for(int i=1 ; i < (1 << col) ; i++) {
        set<string> s;
        
        for(int j=0 ; j<row ; j++) {
            string temp = "";  // 모든 예비 후보키 값들 이어 붙인 string
            
            for(int k=0 ; k<col ; k++) {
                if(i & (1<<k)) {
                    temp += relation[j][k];
                } 
            }
            
            s.insert(temp);
        }
        
        if(s.size() == row && check_min(answer, i)) {
            answer.push_back(i);
        }
    }
    
    return answer.size();
}