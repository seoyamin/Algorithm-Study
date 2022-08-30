#include <iostream>
#include <vector>

using namespace std;

// in: {{60,50}, {30,70}, {60,30}, {80,40}}
// out: 4000

int solution(vector<vector<int>> sizes) {

    int width = 0;
    int height = 0;

    for(auto s: sizes){
        width = max(width, max(s[0], s[1])); // 모든 명함의 긴 면 중 가장 긴 면 ex. 60 70 60 80
        height = max(height, min(s[0], s[1])); // 모든 명함의 짧은 면 중 가장 긴 면 ex. 50 30 30 40
    }

    return width*height;
}
