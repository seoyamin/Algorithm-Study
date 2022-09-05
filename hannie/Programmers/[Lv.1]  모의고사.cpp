#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer={0,0,0};
    vector<int> count;

    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int> v2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> v3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

    for(int i=0; i<answers.size(); i++){
        //1번 수포자
        if(v1[i%v1.size()]==answers[i]) answer[0]++;
        //2번 수포자
        if(v2[i%v2.size()]==answers[i]) answer[1]++;
        //3번 수포자
        if(v3[i%v3.size()]==answers[i]) answer[2]++;
    }
    // answer 중에서 max값 찾기
    int max=0;
    for(auto a:answer){
        if(a > max)
            max = a;
    }
    // max값을 가진 인덱스를 vector에 추가해주기
    for(int i=0; i<answer.size(); i++){
        if(answer[i]==max)
            count.push_back(i+1);
    }

    return count;
}
