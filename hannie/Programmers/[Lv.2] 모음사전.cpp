#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> v;
string ch[5] = {"A", "E", "I", "O", "U"};
// 재귀
void Rank(int l, string s){
    if(l==s.size()){
        v.push_back(s);
        return;
    }
    for(int i=0; i<5; i++) Rank(l,s+ch[i]); 
}
int solution(string word) {
    int answer = 0;
    for(int i=1 ; i<=5 ; i++) Rank(i, "");

    sort(v.begin(), v.end()); // 정렬
    answer = find(v.begin(), v.end(), word)-v.begin()+1;

    return answer;
}
