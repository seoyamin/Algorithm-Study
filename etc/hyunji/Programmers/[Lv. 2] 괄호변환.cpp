#include <string>
#include <vector>
#include <stack>

using namespace std;

//올바른 문자열인지 검증하는 함수
bool check (string p)
{
    stack<char> stack;
    for(int i=0; i<p.length(); i++)
    {
        if(p[i]=='(') 
            stack.push(p[i]);
        else //) 인 경우
        {
           if(stack.size() ==0)//stack에 남은 문자가 없는 경우
               return false;
            stack.pop();//아니면 ( 을 빼준다
        }
    }
    if(stack.size()>0)//다 돌았는데도 스택에 남아있으면
        return false;
    return true;
}

string solution(string p) {
    string answer = "";
    if(p =="")
        return "";
    
    
    //균형잡힌 괄호 문자열 u, v로 나누기
    string u, v;
    int left=0, right =0;
    for( int i =0; i< p.length(); i++)
    {
        if(p[i]=='(')
            left ++;
        else
            right++;
        if( left == right)
        {
            u=p.substr(0, i+1);
            v = p.substr(i+1); //right+ left+1 인덱스부터 남은 문자열 v
            break;
        }
    }
    //3. u 가 올바른 문자열 이라면 v에 대해 1단계부터 다시 수행
    if(check(u))
    {
        v=solution (v);
        //3-1. 수행한 결과 문자열을 u에 이어붙인 후 반환
        answer = u+v;
        return answer;
    }
    //4. 문자열 u가 올바른 괄호 문자열이 아니라면
    else
    {
        //4-1. 빈 문자열에 첫번째 문자로 ( 을 붙임
        answer ="(";
        //4-2. 문자열 v에 대해 1단계부터 재귀적으로 수행한 결과 문자열을 이어붙임
        answer += solution(v);
        //4-3. ')'을 다시 붙임
        answer += ')';
        //4-4. u의 첫번째 문자와 마지막 문자를 제거하고 나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙임
        u.erase(0,1);//첫 문자 제거
        u.erase(u.length()-1, 1);//마지막 문자 제거
        
        for(int i=0; i<u.length(); i++)
        {
            if(u[i]=='(')
                answer += ')';//뒤집어서 붙여주기
            else if(u[i]==')')
                answer += '(';
        }    
        return answer;
    }
}