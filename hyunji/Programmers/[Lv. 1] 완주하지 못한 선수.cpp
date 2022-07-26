#include <string>
#include <vector>
#include<algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    //완주한 선수의 배열 정렬
    //완주하지 못한 선수의 배열 정렬
    
	sort(participant.begin(), participant.end());
	sort(completion.begin(), completion.end());
    //한명을 제외하고 모두 완주했으므로 하나씩 비교 후 completion에 없는 참가자만 반환
	for (int i = 0; i < participant.size(); i++)
	{
		if (participant[i] != completion[i])
			return participant[i];
	}
}