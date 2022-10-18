#include <string>
#include <vector>

using namespace std;
int get_harshad (int x);

bool solution(int x) {
    bool answer = true;
    int h = get_harshad(x);
    if (x % h != 0)
        answer = false;
    
    return answer;
}

int get_harshad (int x) {
    int h = x % 10; // 1의 자리수 입력
    int i = 10;
    for (int i = 10000; i > 1; i = i/10) { // 10000의 자리수부터 감소하면서 더함
        int tmp = x/i;
        h += tmp;
        x -= tmp * i; //x에서 해당 자릿수 뺌. 그 다음 반복문에서 고려 안되도록.
    }
    return h;
}
