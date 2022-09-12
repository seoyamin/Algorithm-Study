include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer={-1};

    for(int a: arr){
        if(a!=answer.back()){
            answer.push_back(a);
        }
    }
    answer.erase(answer.begin());

    return answer;
}
