#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    vector<int> x (10,0);
    vector<int> y (10,0);
    
    for (int i = 0; i < X.length(); i++) {
        x[X[i] - '0']++;
    }
    
    for (int i = 0; i < Y.length(); i++) {
        y[Y[i] - '0']++;
    }
    
    
    for (int i = 9; i >= 0; i--) {
        string str = to_string(i);
        if (i == 0 && x[0] != 0 && y[0] !=0 && answer.length() == 0) {
            answer += "0";
            continue;
        }
        if (x[i] > y[i]) {
            for (int j = 0; j < y[i]; j++){
                answer += str;
            }
        }
        else {
            for (int j = 0; j < x[i]; j++) {
                answer += str;
            }
        }
    }
    
    /*if (answer.length() != 0) {
        if (stoi(answer) == 0)
            answer = "0";
    }*/
    

    if (answer.length() == 0)
        answer += "-1";
    
    return answer;
}
