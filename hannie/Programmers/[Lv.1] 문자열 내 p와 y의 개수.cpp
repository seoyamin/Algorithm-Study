#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    int cnt=0;
    bool answer = true; //1
    for(char c: s){
        if(c=='P'||c=='p')  // P 또는 p 
            cnt++; 
        else if(c=='Y'||c=='y') // Y 또는 y
            cnt--;
    }
    if(cnt!=0) answer=false;

    return answer;
}
