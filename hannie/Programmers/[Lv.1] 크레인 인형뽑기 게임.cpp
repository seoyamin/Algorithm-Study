
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

// board : 5x5 이상 30x30 이하의 정사각형
int solution(vector<vector<int>> board, vector<int> moves) {

    int answer=0;
    stack<int> st;

    for(auto m:moves){
        for(int j=0; j<board[0].size(); j++){

            if(board[j][m-1]!=0){ // j와 i를 반전!
                if(!st.empty() && (board[j][m-1]==st.top())){ // empty 여부를 꼭 체크
                    cout<< "pop: "<< board[j][m-1] << endl;
                    st.pop(); answer+=2;
                }
                else{
                    cout<< "push: " << board[j][m-1] << endl;
                    st.push(board[j][m-1]);
                }

                board[j][m-1]=0;
                break;
            }
        }
    }

    return answer;
}
