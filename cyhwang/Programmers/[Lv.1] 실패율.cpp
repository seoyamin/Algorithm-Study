#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<double> xpeople_num (N, 0);
    vector<double> fail_rate (N, 0);
    
    for (int i = 0; i < stages.size(); i++) {
        if (stages[i] == N + 1)
            continue;
        xpeople_num[stages[i] - 1]++;
    }
    

    fail_rate[0] = xpeople_num[0]/stages.size();
    int num_people = xpeople_num[0];
    for (int i = 1; i < N; i++) {
        if (xpeople_num[i] == 0){
            fail_rate[i] = xpeople_num[i];
            continue;
        }
        fail_rate[i] = xpeople_num[i]/(stages.size() - num_people);
        num_people += xpeople_num[i];
    }
    
    for (int i = 0; i < N; i++) {
        int max_index = max_element(fail_rate.begin(), fail_rate.end()) - fail_rate.begin();
        answer.push_back(max_index + 1);
        fail_rate[max_index] = -1;
    }
    
    return answer;
}
