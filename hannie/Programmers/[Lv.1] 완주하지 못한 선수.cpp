#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {

    sort(participant.begin(), participant.end()); // 오름차순 정렬
    sort(completion.begin(), completion.end());

    for(int i=0; i<participant.size(); i++){
        if(participant[i] != completion[i]){
            return participant[i];
        }
    }
}
