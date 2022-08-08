#include <string>
#include <vector>
#include <stack>

using namespace std;


// move번 위치에서 가장 위에 있는 인형 번호 return 
int getTop(int move, vector<vector<int>> &board) {
    int result = 0;
    
    int i = 0;
    while(i < board.size()) {
        if(board[i][move-1] != 0) {     // 맨 위에서부터 0이 아닐 때까지
            result = board[i][move-1];
            board[i][move-1] = 0;
            break;
        }
        i++;
    }
    
    return result;
}


int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> st;   // 바구니용 stack
    
    
    for(int i=0 ; i<moves.size() ; i++) {
        int top = getTop(moves[i], board);  // 가장 위에있는 인형 번호 top
        
        if(top != 0) {            
            if(st.empty() || st.top() != top) st.push(top);

            else {
                st.pop();
                answer += 2;   // [주의] 터지는 횟수 X, 터지는 인형 개수 O
            }
        }
    }
    
    return answer;
}