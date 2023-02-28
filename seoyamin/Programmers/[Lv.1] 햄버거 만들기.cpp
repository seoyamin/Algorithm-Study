#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    string s = "";
    string hamburger = "1231";
    
    for(auto i : ingredient) {
        s += to_string(i);
    }
    
    int pos = 0;
    while(1) {
        int idx = s.find(hamburger, pos);
        if(idx == string::npos) break;
        
        s.erase(idx, 4);
        answer++;
        
        if(idx > 2) pos = idx - 3;        
    }
    
    return answer;
}