#include <string>
#include <vector>
#include <cmath>

using namespace std;

int setAction(int num) {
    int i = floor(sqrt(num));
    int result = (sqrt(num) - i == 0) ? -1 : 1;
    
    return result;
}

int solution(int left, int right) {
    int answer = 0;
    
    for(int i=left ; i<= right ; i++) {
        answer += (setAction(i) * i);
    }
    
    return answer;
}