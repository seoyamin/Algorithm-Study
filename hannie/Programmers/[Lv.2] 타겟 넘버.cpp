#include <iostream>
#include <vector>
#include <string>
using namespace std;

//벡터, 정답횟수, 찾아야 하는 숫자, 들어간 깊이, 현재까지 합
void dfs(vector<int>& numbers, int& answer, int target, int count = 0, int sum = 0){
    // 순회
    if (count == numbers.size() - 1) {
        // sum + 마지막 원소 == target
        if (target == sum + numbers[count])
            answer++;
        // sum - 마지막 원소 == target
        if (target == sum - numbers[count])
            answer++;
        return;
    }
    // 탐색
    dfs(numbers, answer, target, count + 1, sum + numbers[count]);
    dfs(numbers, answer, target, count + 1, sum - numbers[count]);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    dfs(numbers, answer, target);
    return answer;
}
