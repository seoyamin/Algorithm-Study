#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    int i, j, k;
    
    for(auto item : commands) {
        vector<int> temp;
        i = item[0];
        j = item[1];
        k = item[2];
        
        for(int t = i-1 ; t <= j-1 ; t++) {
            temp.push_back(array[t]);
        }
        
        sort(temp.begin(), temp.end());
        answer.push_back(temp[k-1]);
    }
    
    return answer;
}