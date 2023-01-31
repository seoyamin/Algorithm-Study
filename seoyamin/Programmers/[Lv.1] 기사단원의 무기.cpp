#include <string>
#include <vector>
#include <cmath>

using namespace std;

// 약수 개수 구하기
int getDivNum(int n) {
    int num = (floor(sqrt(n)) == sqrt(n)) ? 1 : 0;    // 제곱수이면 1로 시작
    
    for(int i=1 ; i<sqrt(n) ; i++) {
        if(n % i == 0) num += 2;                      // 제곱근 아닌 약수 개수 카운트
    }
    
    return num;
}

int solution(int number, int limit, int power) {
    int answer = 0;
    
    // number ~ 1
    while(number) {
        int divNum = getDivNum(number);                     // 약수의 개수
        int myPower = (divNum > limit) ? power : divNum;    // 기사별 최종 공격력
        answer += myPower;
        
        number--;
    }
    
    return answer;
}