#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string number, int k) {

    string answer = "";
    int index = 0;
    // number="4177252841", k=4
    for(int i=0; i<number.size() - k; i++){
        char max = number[index];
        int cnt = index;
        for(int j=index; j<=i+k; j++){
            if(max < number[j]){
                max = number[j];
                cnt = j;
            }
        }
        index = cnt + 1;
        answer += max;
    }

    return answer; // "775841"
}

int main(){

    cout << solution("4177252841",4) << endl;

    return 0;
}
