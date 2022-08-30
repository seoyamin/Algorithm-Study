#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int w=0,h=0;

    //pair에서 작은 것과 큰 것을 가리고
    //작은 것들 중에서 가장 큰 것 * 큰 것들 중에서 가장 큰 것
    for(int i=0; i<sizes.size(); i++){
        w = max(w, max(sizes[i][0],sizes[i][1]));
        h = max(h, min(sizes[i][0],sizes[i][1]));
    }
    return w*h;
}