#include <set>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    set<int> s;      // numbers의 숫자 목록 저장  
    int answer = 0;  // 없는 숫자의 합
    
    for(int i=0 ; i<numbers.size() ; i++) {
        s.insert(numbers[i]);
    }
    
    for(int i=1 ; i<=9 ; i++) {
        if(s.find(i) == s.end())  answer += i;
    }
    
    return answer;
}