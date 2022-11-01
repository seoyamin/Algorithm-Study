#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<int> order) {
    int answer = 1;
    int main_front = order[0] + 1; //기존 벨트, main_front가 가장 작은 번호의 상자
    stack<int> assist;
    for (int i = 1; i < order[0]; i++)
        assist.push(i);
    
    //int index = 1;
    for (int index = 1; index < order.size(); index++) {
        if (order[index] >= main_front) { //기존 벨트에 상자가 있을 때
            for (int j = main_front; j < order[index]; j++)
                assist.push(j);
            main_front = order[index] + 1;
            answer++;
        }
        else {
            if (!assist.empty()) { //보조 벨트에 상자가 있을 때
                if (assist.top() == order[index]) {
                    assist.pop();
                    answer++;
                }
                else //보조 벨트에 상자가 있지만 뺄 수 없음.
                    break;
            }
            else //모든 벨트에 상자 없음
                break;
        }
    }
    
    return answer;
}
