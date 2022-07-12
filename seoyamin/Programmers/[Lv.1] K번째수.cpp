#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// v를 정렬하고, kth 원소 return하는 메소드
int sortResult(vector<int> v, int k) {
    int result = 0;
    
    sort(v.begin(), v.end());
    result = v[k];
    
    return result;
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(int i=0 ; i<commands.size() ; i++) {
        vector<int> v;
        int start = commands[i][0] - 1;   // start index
        int end = commands[i][1] - 1;     // end index
        int k = commands[i][2] - 1;       // k index
        
        for(int i=start ; i<end+1 ; i++) {
            v.push_back(array[i]);
        }
        
        answer.push_back(sortResult(v, k));
    }
    
    return answer;
}