#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    map<char, int> m;

    for(int i=0; i<choices.size(); i++){
        // 4점보다 클 경우 => key: 오른쪽 글자
        if(choices[i]>4){
            if(m.find(survey[i][1])!=m.end()){
                m[survey[i][1]] += (choices[i]-4);
            }
            else
                m.insert({survey[i][1],choices[i]-4});
        }
        // 4점보다 작을 경우 => key: 왼쪽 글자
        if(choices[i]<4){
            if(m.find(survey[i][0])!=m.end()){
                m[survey[i][0]] += (4-choices[i]);
            }
            else
                m.insert({survey[i][0],4-choices[i]});
        }
    }
    // map에 잘 들어갔는지 확인
//    for(auto iter:m)
//        cout << iter.first << " " <<iter.second << endl;

    // value 비교 => 더 높은 값의 key를 answer에 더함.
    if(m['R']>=m['T'])
        answer+='R';
    else answer+='T';
    if(m['C']>=m['F'])
        answer+='C';
    else answer+='F';
    if(m['J']>=m['M'])
        answer+='J';
    else answer+='M';
    if(m['A']>=m['N'])
        answer+='A';
    else answer+='N';

    return answer;
}
