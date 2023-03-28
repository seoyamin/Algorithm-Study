#include <string>
#include <vector>

using namespace std;

long long max(long long a, long long b){
    return a > b ? a : b;
}

long long solution(vector<int> sequence) {
    long long answer = 0;
    long long result = -50000000000;  // 가능한 sequence 합 중 최소값 (-100,000으로 500,000개 원소) 
    long long sum = 0;
    vector<long long> temp;
    
    // 홀수번째에 -1 곱한 배열 temp 만들기
    for(int i = 0 ; i< sequence.size() ; i++){
        temp.push_back(sequence[i]);
        if(i % 2 == 1)
            temp[i] *= -1;
    }
    
    // temp를 더해보기 (-1, 1, -1)
    for(auto i : temp) {
        sum = max(sum, 0) + i;
        result = max(result, sum);
    }
    
    sum = 0;
    
    // temp를 빼보기 (1, -1, 1)
    for(auto i : temp) {
        sum = max(sum, 0) - i;
        result = max(result, sum);
    }
    
    return result;
}