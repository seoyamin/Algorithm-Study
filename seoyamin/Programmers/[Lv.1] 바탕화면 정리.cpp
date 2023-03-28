#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    vector<int> x;
    vector<int> y;
    
    int n = wallpaper[0].size();
    
    for(int i=0 ; i<wallpaper.size() ; i++) {
        for(int j=0 ; j<n; j++) {
            if(wallpaper[i][j] == '#') {
                y.push_back(i);
                x.push_back(j);
            }
        }
    }
    
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    
    
    answer.push_back(y[0]);
    answer.push_back(x[0]);
    answer.push_back(y.back()+1);
    answer.push_back(x.back()+1);

    
    return answer;
}