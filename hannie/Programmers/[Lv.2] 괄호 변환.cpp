
#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool isRight(string s){
    int cnt=0;
    for(char c:s){
        if(c=='(')
            cnt++;
        else
            cnt--;

        if(cnt<0) return false; // 여기서 헤맸음!
    }
    return cnt==0; // 0이면 true 0이 아니면 false
}


string solution(string p) {

    if(p=="") return p; // p가 빈 문자열일 경우, 빈 문자열을 반환.

    string u,v;
    int cnt=0; int ans=0;

    for(int i=0; i<p.size(); i++){

        if(p[i]=='(')
            cnt++;
        else
            cnt--;

        if(cnt==0){
            u=p.substr(0,i+1);
            v=p.substr(i+1);
            break;
        }
    }

    if(isRight(u))
        return u+solution(v); // u가 맞을 경우엔 그대로 리턴

    string answer = "("+solution(v)+")";
    for(int i=1; i<u.size()-1; i++){
        if(u[i]=='(')
            answer+=")";
        else
            answer+="(";
    }

    return answer;
}

