#include <string>
#include <vector>
#include <cmath>

using namespace std;


// 자기 자신을 제외한 약수 중 최댓값
int biggestDivisor(long long k) {
    if(k==1) return 0;
    
    int result = 1;
    
    for(int i=2 ; i <= sqrt(k) ; i++) {
        if(k % i == 0) {
            if(k / i <= 10000000) return k / i;
            else result = i;
        }
    }
    
    return result;
}

vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    
    for(int i=begin ; i<=end ; i++) {
        answer.push_back(biggestDivisor(i));
    }
    
    return answer;
}