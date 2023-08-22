#include <vector>
#include <iostream>
using namespace std;

// 소수 여부 판단하는 함수
bool checkPrimeNum(int n) {
    for(int i=2 ; i*i <= n ; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

int solution(vector<int> nums) {
    int answer = 0;
    int size = nums.size();

    for(int i=0 ; i<size-2 ; i++) {
        for(int j=i+1 ; j<size-1 ; j++) {
            for(int k=j+1 ; k<size ; k++) {
                if(checkPrimeNum(nums[i] + nums[j] + nums[k])) answer++;
            }
        }
    }

    return answer;
}