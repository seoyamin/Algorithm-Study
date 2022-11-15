#include <string>
#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    int q_size = queue1.size();    // q1 사이즈 달라지므로 미리 초기 size 받아놓기
    long long sum1 = 0, sum2 = 0;  // q1, q2 원소 합
    int idx1 = 0, idx2 = 0;        // q1, q2 첫번째 원소 가리키는 인덱스
    
    for(auto i : queue1) {
        sum1 += i;
    }
    
    for(auto i : queue2) {
        sum2 += i;
    }
    
    
    // 작업이 queue1.size() 4배 만큼 발생한 경우는 처음으로 되돌아온 상태 -> 방법 X 
    while(answer <= (q_size * 4)) {
        
        if(sum1 == sum2) return answer;
        
        answer++;
        
        // [case 1] q1 < q2 : q2 맨 앞 꺼내서 q1에 넣기
        if(sum1 < sum2) {
            sum1 += queue2[idx2];
            sum2 -= queue2[idx2];
            queue1.push_back(queue2[idx2++]);
        }
        
        // [case 2] q2 < q1 : q1 맨 앞 꺼내서 q2에 넣기
        else {
            sum2 += queue1[idx1];
            sum1 -= queue1[idx1];
            queue2.push_back(queue1[idx1++]);
        }
        
        
    }
    
    return -1;
}