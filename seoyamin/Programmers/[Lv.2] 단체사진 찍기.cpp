#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<string> data) {
    int answer = 0;
    vector<char> friends = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};  // 나란히 선 상태 저장
    
    do {
        int f1, f2;   // 두 프렌즈의 현재 위치(=인덱스) 저장하는 f1, f2
        
        for(int i=0 ; i<n ; i++) {
            
            //  f1, f2 저장
            for(int j=0 ; j<8 ; j++) {
                if(friends[j] == data[i][0]) f1 = j;
                else if(friends[j] == data[i][2]) f2 = j;
            }
            
            char op = data[i][3];                 // 연산자  = , >, <
            int jump = data[i][4] - '0' + 1;      // 요구되는 두 프렌즈 사이의 칸 수
            
            // 불가능 케이스 하나라도 있으면 break
            if(op == '=' && abs(f1 - f2) != jump) break;
            else if(op == '>' && abs(f1 - f2) <= jump) break;
            else if(op == '<' && abs(f1 - f2) >= jump) break;
            
            if(i == n-1) answer++;  // 불가능 케이스 한번도 없어서 break 안하고 끝까지 탐색한 경우 -> 가능한 경우
        }
    } while(next_permutation(friends.begin(), friends.end()));
    
    return answer;
}