#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    int len_p = p.size();
    
    for(int i=0 ; i <= t.size()-len_p ; i++) {
        string temp = t.substr(i, len_p);
        if(stol(temp) <= stol(p)) answer++;
    }  
    
    return answer;
}