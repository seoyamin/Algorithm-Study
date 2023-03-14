#include <string>
#include <vector>
#include <map>

using namespace std;

void setPress(vector<string> keymap, map<char, int> &press) {
    for(auto i : keymap) {
        for(int j=0 ; j<i.size() ; j++) {
            if(press.find(i[j]) == press.end()) press[i[j]] = j+1;   // press에 저장된 이력 없는 문자
            else if(press[i[j]] > j + 1) press[i[j]] = j+1;          // 더 작은 횟수로 만들 수 있는 경우, 업데이트
        }
    }
}

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    map<char, int> press;
    
    // 각 문자마다 눌러야할 최소 키 횟수 press에 저장
    for(auto i : keymap) {
        setPress(keymap, press);
    }
    
    
    for(auto i : targets) {
        int temp = 0;  // target 완성하는데 필요한 누르기 수
        
        for(int j=0 ; j<i.size() ; j++) {
            if(press.find(i[j]) == press.end()) {  // keymap에 없는 문자인 경우
                temp = -1;
                break;
            }
            else {
                temp += press[i[j]];
            }
        }
        
        answer.push_back(temp);
    }
    
    return answer;
}