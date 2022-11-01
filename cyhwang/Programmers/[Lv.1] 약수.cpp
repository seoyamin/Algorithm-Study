#include <string>
#include <vector>

using namespace std;

int get_div (int n) ;

int solution(int n) {
    int answer = 0;

    answer = get_div (n);
    
    return answer;
}

int get_div (int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0)
            sum += i;
    }
    return sum;
}
