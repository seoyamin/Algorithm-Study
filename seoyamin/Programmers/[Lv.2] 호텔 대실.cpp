#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    vector<pair<int, int>> v;
    
    for(int i=0 ; i<book_time.size() ; i++) {
        int start_hour = stoi(book_time[i][0].substr(0, 2));
        int start_min = stoi(book_time[i][0].substr(3, 2));
        int end_hour = stoi(book_time[i][1].substr(0, 2));
        int end_min = stoi(book_time[i][1].substr(3, 2));
        
        v.push_back(make_pair(start_hour * 60 + start_min, end_hour * 60 + end_min + 10));
    }
    
    sort(v.begin(), v.end());            // 예약 건수들을 시작 시간 순으로 정렬
    
    
    vector<pair<int, int>> running;      // 현재 진행중인 예약 건수 목록 (예약 건수 개수 = 차 있는 객실 개수)
    
    for(auto currBook : v) {
        vector<pair<int, int>> temp;     // currBook과 동시에 현재 진행중인 예약 건수(runningBook) 목록
        
        for(auto runningBook : running) {
            if(currBook.first < runningBook.second) {
                temp.push_back(runningBook);
            }
            /* [else] currBook.first >= runningBook.second
               : currBook이 현재 runningBook 다음에 그 객실 이용 가능 */
        }
        
        running = temp;                                 // 현재 진행중인 예약 건수 목록 업데이트
        running.push_back(currBook);                    // currBook도 진행중 상태로 변경
        answer = max(answer, (int) running.size());     // currBook도 추가한 후에 answer값 업데이트
    }
    
    return answer;
}