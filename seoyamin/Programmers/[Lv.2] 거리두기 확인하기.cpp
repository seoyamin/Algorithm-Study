#include <string>
#include <vector>

#define SIZE 5
using namespace std;


// 거리두기 지켰는지 확인하는 메소드
bool check_ok(vector<pair<int, int>> &people, vector<vector<string>> &places, int room) {
    bool result = true;
    
    for(int i=0 ; i<people.size() - 1 ; i++) {
        for(int j=i+1 ; j<people.size() ; j++) {
            
            // 거리가 1인 경우
            if(abs(people[i].first - people[j].first) + abs(people[i].second - people[j].second) == 1) {
                return false;
            }
            
            // 거리가 2인 경우
            else if(abs(people[i].first - people[j].first) + abs(people[i].second - people[j].second) == 2) {
                
                //  [1 X 3]  
                //   P O P
                if(people[i].first - people[j].first == 0) {
                    if(places[room][people[i].first][people[i].second+1] == 'O') return false;
                }
                
                // [3 X 1]
                //    P
                //    O
                //    P
                else if(people[i].second - people[j].second == 0) {
                    if(places[room][people[i].first+1][people[i].second] == 'O') return false;
                }
                
                // [2 X 2]
                //   ?  P
                //   P  ?
                else if(people[i].second > people[j].second) {
                    if(places[room][people[i].first][people[i].second-1] == 'O'
                      || places[room][people[i].first+1][people[i].second] == 'O') {
                        return false;
                    }
                }
                
                // [2 X 2]
                //   P  ?
                //   ?  P
                else if(people[i].second < people[j].second) {
                    if(places[room][people[i].first][people[i].second+1] == 'O'
                      || places[room][people[i].first+1][people[i].second] == 'O') {
                        return false;
                    }
                }
            }
        }
    }
    
    return result;
}


vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(int i=0 ; i<SIZE ; i++) {
        int result = 1;
        vector<pair<int, int>> people;
        
        for(int j=0 ; j<SIZE ; j++) {
            for(int k=0 ; k<SIZE ; k++) {
                if(places[i][j][k] == 'P') {
                    people.push_back(make_pair(j, k));
                }
            }
        }
        
        if(people.empty()) result = 1;
        else if(!check_ok(people, places, i)) result = 0;
        
        answer.push_back(result);
    }
    
    return answer;
}