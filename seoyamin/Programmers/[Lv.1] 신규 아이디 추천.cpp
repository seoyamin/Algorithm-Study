#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    
    // [1-3 단계]
    for(int i=0 ; i<new_id.size() ; i++) {
        
        // [1단계]
        new_id[i] = tolower(new_id[i]);
        
        // [2단계]
        if(!((new_id[i] >= 'a' && new_id[i] <= 'z') 
             || (new_id[i] >= '0' && new_id[i] <= '9')
             || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')) {
            new_id.erase(i, 1);
            i--;
        }      
        
        // [3단계]
        if(new_id[i] == '.' && new_id[i+1] == '.') {
            new_id.erase(i, 1);  
            i--;
        }  
    }
    
    // [4단계]
    if(new_id.front() == '.') new_id.erase(0,1);
    if(new_id.back() == '.') new_id.erase(new_id.size()-1);
    
    // [5단계]
    if(new_id.empty()) new_id += "a";
    
    // [6단계]
    if(new_id.size() >= 16) new_id.erase(15);
    if(new_id.back() == '.') new_id.erase(new_id.size()-1);
    
    // [7단계]
    if(new_id.size() <= 2) {
        while(new_id.size() < 3) new_id += new_id.back();
    }
    
    answer = new_id;
    return answer;
}