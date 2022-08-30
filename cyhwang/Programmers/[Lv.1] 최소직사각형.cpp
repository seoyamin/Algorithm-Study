#include <string>
#include <vector>

using namespace std;

vector<int> find_max(vector<vector<int>> sizes);

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    vector<int> max = find_max(sizes);
    
    for (int i = 0; i < sizes.size(); i++) {
        if (sizes[max[0]][0] > sizes[max[1]][1]) {
            if (sizes[max[1]][1] < sizes[max[1]][0])
                break;
            int tmp = sizes[max[1]][1];
            sizes[max[1]][1] = sizes[max[1]][0];
            sizes[max[1]][0] = tmp;
            max = find_max(sizes);
        }
        else {
            if (sizes[max[0]][0] < sizes[max[0]][1])
                break;
            int tmp = sizes[max[0]][0];
            sizes[max[0]][0] = sizes[max[0]][1];
            sizes[max[0]][1] = tmp;
            max = find_max(sizes);
        }
    }
    answer = sizes[max[0]][0] * sizes[max[1]][1];

    return answer;
}

vector<int> find_max(vector<vector<int>> sizes) {
    vector<int> max(2);
    //max[0]에 제일 큰 w의 index값, max[1]에 제일 큰 h의 index값
    
    for (int i = 0; i < sizes.size(); i++) {
        if (sizes[i][0] > sizes[max[0]][0])
            max[0] = i;
        if (sizes[i][1] > sizes[max[1]][1])
            max[1] = i;
    }
    
    return max;
}
