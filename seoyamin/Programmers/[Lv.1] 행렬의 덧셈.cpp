#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    int r = arr1.size();
    int c = arr1[0].size();
    
    for(int i=0 ; i<r ; i++) {
        vector<int> v(c);
        for(int j=0 ; j<c ; j++) {
            v[j] = arr1[i][j] + arr2[i][j];
        }
        answer.push_back(v);
    }
    
    
    return answer;
}