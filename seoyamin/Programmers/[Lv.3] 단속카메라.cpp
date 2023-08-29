#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> v1, vector<int> v2) {
    return v1[1] < v2[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 1;
    
    sort(routes.begin(), routes.end(), cmp);
    
    int currentCam = routes[0][1];
    
    for(int i=1 ; i<routes.size() ; i++) {
        if(currentCam >= routes[i][0] && currentCam <= routes[i][1]) {
            continue;
        } 
        
        else {
            answer++;
            currentCam = routes[i][1];
        }
    }
    
    return answer;
}