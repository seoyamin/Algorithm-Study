#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> get_div (int n);

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int w, h;
    //width * 2 + (height - 2) * 2 == brown;
    //(width - 2) * (height - 2) == yellow;
    vector<int> s = get_div(yellow);
    
    for (int i = 0; i < s.size(); i++) {
        h = s[i] + 2;
        w = yellow / s[i] + 2;
        if (w * 2 + (h - 2) * 2 == brown) {
            answer.push_back(w);
            answer.push_back(h);
            return answer;
        }
    }
    
    return answer;
}

vector<int> get_div (int n) {
    vector<int> s;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0)
            s.push_back(i);
    }
    return s;
}
