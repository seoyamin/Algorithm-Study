#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    vector<string> v(1);          // p - c 차집합 결과를 담을 vector
    vector<string>::iterator it;  // p - c 차집합 결과를 담을 iterator
    
    
    // 알파벳순으로 두 벡터 p, c 정렬
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    
    int pSize = participant.size();
    int cSize = completion.size();
    it = set_difference(participant.begin(), participant.end(), completion.begin(), completion.end(), v.begin());
    
    answer = v[0];

    return answer;
}