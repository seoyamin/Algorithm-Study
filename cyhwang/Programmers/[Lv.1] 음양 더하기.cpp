#include <string>
#include <vector>

using namespace std;
int get_number(int n, bool sign);

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    
    for (int i = 0; i < absolutes.size(); i++) {
        answer += get_number(absolutes[i], signs[i]);
    }
    
    return answer;
}

int get_number(int n, bool sign) {
    return sign ? n : n * (-1);
}
