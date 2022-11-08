#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

string solution(string X, string Y) {
    map<char, int> visited;

    for(char c:X)
        visited[c]++;

    string s;
    for(char c:Y){
        if (visited[c] != 0) {
            s+=c;
            visited[c]--;
        }
    }

    if(s=="")
        return "-1";

    sort(s.begin(), s.end(), greater<char>());

    if(s[0]=='0')
        return "0"; // 00이든 000이든 모두 0으로 출력!

    return s;
}
