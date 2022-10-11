using namespace std;

long long solution(int price, int money, int count) {
    long long answer = 0;
    
    // 필요한 금액 먼저 계산
    for(int i=1 ; i<=count ; i++) {
        answer += (i * price);
    }
    
    answer = money - answer;  // answer : 놀이기구 다 타고 남은 금액
    
    if(answer > 0) return 0;  // 금액이 부족하지 않은 경우

    return answer * (-1);     // 부족한 금액 양수화
}