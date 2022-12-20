#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> glory;
    vector<int> answer;
    
    for(int i=0 ; i<score.size() ; i++) {
        if(glory.size() < k) glory.push_back(score[i]);
        else if(glory[0] < score[i]) glory[0] = score[i];
        
        sort(glory.begin(), glory.end());
        answer.push_back(glory[0]);
    }
    
    return answer;
}