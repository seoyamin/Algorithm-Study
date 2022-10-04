
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<double> fail; // 실패율
    double user = stages.size();

    for(int i = 1; i <= N; i++){
        double cnt = 0;
        for(int j = 0; j < stages.size(); j++){
            if(stages[j] == i)
                cnt++;
        }
        if(cnt == 0)
            fail.push_back(0);
        else
            fail.push_back(cnt / user);
        user -= cnt;
    }

    // 내림차순 sort 정렬 대신! max_element algorithm 사용
    for(int i = 0; i < N; i++){
        // 내림차순 정렬
        auto itr = max_element(fail.begin(), fail.end());
        answer.push_back(itr - fail.begin() + 1);
        *itr=-1; 
    }

    return answer;
}
