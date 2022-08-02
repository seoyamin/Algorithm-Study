#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    int countP, countY;

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    for(int i=0; i< s.length(); i++)
    {
        if( 'p' == tolower(s[i]))
            countP++;
        if( 'y' == tolower(s[i]))
            countY++;        
    }
    if(countP == countY) return true;
    

    return false;
}