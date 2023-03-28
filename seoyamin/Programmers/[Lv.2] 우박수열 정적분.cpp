#include <string>
#include <vector>
#include <iostream>

using namespace std;

int getWidth(int a, int b, int end) {
    if(a > end + b) return -1;
    else if(a == end + b) return 0;
    else return (end + b) - a;
}

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    int count = 0;
    vector<int> height;
    
    height.push_back(k);
    
    while(k > 1) {
        if(k%2 == 0) k /= 2;
        else k = k*3 + 1;
        height.push_back(k);
        count++;
    }
    
    height.push_back(1);
    
    for(auto r : ranges) {
        if(getWidth(r[0], r[1], count) == -1) answer.push_back(-1);
        
        else if(getWidth(r[0], r[1], count) == 0) answer.push_back(0);
        
        else {
            double space = 0;
            
            for(int i=r[0] ; i<count + r[1] ; i++) {
                double temp = (double)(height[i]+height[i+1])/2;
                space += temp;
            }
            answer.push_back(space);
        }
    }
    
    return answer;
}