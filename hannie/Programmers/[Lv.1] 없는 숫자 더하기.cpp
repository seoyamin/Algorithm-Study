#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    for(auto n:numbers)
        answer+=n;
    return 45-answer;
}
