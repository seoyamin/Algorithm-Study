#include <iostream>
#include <vector>

using namespace std;

int strSum(string s) {
    string num = "";
    int result = 0;

    for(auto c : s) {
        if(c != '+') num += c;
        else {
            result += stoi(num);
            num = "";
        }
    }

    result += stoi(num);
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string input;
    cin >> input;

    string temp = "";
    vector<string> v;

    for(auto c : input) {
        if(c != '-') temp += c;
        else {
            v.push_back(temp);
            temp = "";
        }
    }
    v.push_back(temp);

    int result = 0;
    for(int i=0 ; i<v.size() ; i++) {
        if(i == 0) result += strSum(v[i]);
        else result -= strSum(v[i]);
    }

    cout << result << endl;
}