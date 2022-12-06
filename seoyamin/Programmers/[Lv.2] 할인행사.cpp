#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    map<string, int> m_want;
    map<string, int> m_temp;
    bool is_ok = true;         // 회원가입 가능 여부
    int answer = 0;
    
    // m_want 초기화
    for(int i=0 ; i<want.size() ; i++) {
        m_want.insert({want[i], number[i]});
    }
    
    // 회원가입 가능 날짜 카운트
    for(int i=0 ; i<=discount.size()-10 ; i++) {
        is_ok = true;
        m_temp = m_want;
        
        for(int j=0 ; j < 10 ; j++) {
            if(m_temp.find(discount[i+j]) != m_temp.end() && m_temp[discount[i+j]] > 0) {
                m_temp[discount[i+j]]--;  // 구매 -> 수량 감소
            }
        }
        
        for(auto iter : m_temp) {
            if(iter.second > 0) {   // 아직 구매 못한 제품이 남아 있는 경우
                is_ok = false; 
                break;
            }
        }
        
        if(is_ok) answer++;
    }
    
    return answer;
}