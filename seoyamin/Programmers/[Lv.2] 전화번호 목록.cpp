#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(), phone_book.end());  // 정렬하면 앞뒤 관계들만 파악하면 됨 (자동으로 상하 관계가 설정 : 오름차순, 길이)

    for (int i = 0; i < phone_book.size() - 1; i++) {
        if (phone_book[i + 1].find(phone_book[i]) == 0) {  // 뒷 번호에 앞 번호가 포함되어 있고, 첫 등장 인덱스가 0이면 접두어
            return false;
        } 
    }
    
    return answer;  // if문의 조건 만족 케이스가 없음 -> 접두어 관계 없음
}