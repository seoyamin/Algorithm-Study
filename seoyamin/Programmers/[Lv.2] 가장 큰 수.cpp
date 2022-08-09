#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 두 string 더했을때 더 큰 게 앞인지 확인
bool compare(string a, string b) {
    if(a + b > b + a) return true;
    return false;
}


string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;
    bool all_zero = true;
    
    // int -> string
    for(int i=0 ; i<numbers.size() ; i++) {
        string s = to_string(numbers[i]);
        v.push_back(s);
        
        if(numbers[i] != 0) all_zero = false;
    }
    
    sort(v.begin(), v.end(), compare);
    
    
    
    if(all_zero) return "0";  // 모든 number가 0인 경우
    
    else {
        for(int j=0 ; j<v.size(); j++) {
            answer += v[j];
        }
    }
    
    return answer;
}