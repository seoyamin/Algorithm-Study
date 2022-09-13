#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    int share = n;
    int r = -1;

    while (share!=0) {
        r = share % 3;
        share = share / 3;

        if (r == 0) { //3의 배수
            answer = "4" + answer;
            share--;
        }
        else if (r == 1) answer = "1" + answer; // 끝자리부터 채움
        else if (r == 2) answer = "2" + answer;
    }
    return answer;
}
