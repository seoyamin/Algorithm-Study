#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer={};

    // 전체 넓이 = brown+yellow
    int area = brown+yellow;
    for(int h=2; h<=sqrt(area); h++){
        // 면적이 h로 나누어 떨어짐
        if(area%h==0){
            int w = area/h;
            if(yellow==((w-2)*(h-2))) // yellow 조건을 만족하면 리턴
                return {w,h};
        }
    }

    return answer;
}
