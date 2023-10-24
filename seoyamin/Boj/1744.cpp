#include <iostream>
#include <queue>

using namespace std;

int main() {

    int N;
    cin >> N;

    priority_queue<int> pqPos;                              // 양수 내림차순 (절댓값 내림차순)
    priority_queue<int, vector<int>, greater<int>> pqNeg;   // 음수 오름차순 (절댓값 내림차순)
    int one = 0, zero = 0;

    int input;
    for(int i=0 ; i<N ; i++) {
        cin >> input;
        if(input > 1) pqPos.push(input);
        else if(input == 1) one++;
        else if(input == 0) zero++;
        else pqNeg.push(input);
    }

    int first, second, sumPos = 0, sumNeg = 0;

    while(pqPos.size() > 1) {
        first = pqPos.top();
        pqPos.pop();

        second = pqPos.top();
        pqPos.pop();

        sumPos += (first * second);
    }

    if(!pqPos.empty()) {
        sumPos += pqPos.top();
        pqPos.pop();
    }

    while(pqNeg.size() > 1) {
        first = pqNeg.top();
        pqNeg.pop();

        second = pqNeg.top();
        pqNeg.pop();

        sumNeg += (first * second);
    }

    if(!pqNeg.empty()) {
        if(zero == 0) {
            sumNeg += pqNeg.top();
            pqNeg.pop();
        }
    }

    cout << (sumPos + sumNeg + one) << endl;

    return 0;
}