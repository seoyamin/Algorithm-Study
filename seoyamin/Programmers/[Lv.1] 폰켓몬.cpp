#include <vector>
#include <map>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    map<int, int> monsters;
    
    // monsters에 폰켓몬 종류 저장 (map이라 중복 X)
    for(auto item : nums) {
        monsters.insert({item, 1});
    }
    
    // answer 결정    
    answer = min(monsters.size(), nums.size()/2);
    
    return answer;
}