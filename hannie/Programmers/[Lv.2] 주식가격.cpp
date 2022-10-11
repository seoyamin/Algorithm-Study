#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(),-1); // -1로 초기화

    for(int i=0; i<prices.size(); i++){
        for(int j=i; j<prices.size(); j++){
            answer[i]++;
            if(prices[i]>prices[j])
                break;
        }
    }
//    for(auto a: answer)
//        cout << a << ' ';

    return answer;
}
