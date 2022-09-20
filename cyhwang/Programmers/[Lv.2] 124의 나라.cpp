#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#define SUM(x) (pow(3,x) - 3)/2

using namespace std;

string find_after_3(int *n, int cipher, string answer);
string find_before_3 (int n, string answer);

string solution(int n) {
    string answer = "";
    n--;
    
    for (int i = 16; i > 1; i--) {
        answer = find_after_3(&n, i, answer);
    }
    answer = find_before_3(n, answer);
    
    return answer;
}

string find_after_3(int *n, int cipher, string answer) {
    //cout << "n: " << *n << " cipher: " << cipher << " SUM : " << SUM(cipher) << endl;
    if (*n >= SUM(cipher)) {
        if (*n >= SUM(cipher) + 2*pow(3, (cipher - 1))) {
            answer.append("4");
            *n -= (3* pow(3, (cipher - 1)));
        }
        else if (*n >= SUM(cipher) + pow(3,(cipher - 1))) {
            answer.append("2");
            *n -= (2*pow(3,(cipher - 1)));
        }
        else {
            answer.append("1");
            *n -= (pow(3,(cipher - 1)));
        }
    }
    return answer;
}
string find_before_3 (int n, string answer) {
    switch (n)
    {
        case 0 :
            answer.append("1");
            break;
        case 1 :
            answer.append("2");
            break;
        case 2 :
            answer.append("4");
            break;
    }
    
    return answer;
}
