#include <iostream>
#include <queue>

using namespace std;

int main() {

    int N;
    cin >> N;

    priority_queue<int, vector<int>, greater<int>> pq;

    int input;
    for(int i=0 ; i<N ; i++) {
        cin >> input;
        pq.push(input);
    }

    int first, second, result = 0;
    while(pq.size() > 1) {
        first = pq.top();
        pq.pop();

        second = pq.top();
        pq.pop();

        result += (first + second);
        pq.push(first + second);
    }

    cout << result << endl;

    return 0;
}