#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> s[3];
    vector<int> answer;
    vector<int> cnt(3,0);
    int maxCnt=0;
    s[0] = {1,2,3,4,5};
    s[1] = {2,1,2,3,2,4,2,5,2};
    s[2] = {3,3,1,1,2,2,4,4,5,5};

    //반복되는 부분으로 잘라서 비교해주기
    for(int i=0; i<answers.size(); i++){
        if(s[0][i%5]==answers[i]) cnt[0]++;
        if(s[1][i%8]==answers[i]) cnt[1]++;
        if(s[2][i%10]==answers[i]) cnt[2]++;
    }

    //제일 많이 맞춘 개수 찾기
    for(int i=0;i<3;i++){
        maxCnt = max(maxCnt,cnt[i]);
    }

    //최대 개수랑 동일한 사람들 색출해서 넣어줌
    for(int i=0; i<3;i++){
        if(maxCnt == cnt[i])
            answer.push_back(i+1);
    }
    return answer;
}