#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    bool isFirst = true;

    for(int i=0; i<s.length(); i++){

        if(s[i]==' '){
            answer += s[i];
            isFirst =true;
            continue;
        }

        if(isFirst){
            if(s[i]>='a'&&s[i]<='z'){
                answer += s[i]-'a'+'A';
            }else{
                answer += s[i];
            }
        }else{
            if(s[i]>='A'&&s[i]<='Z'){
                answer += s[i]-'A'+'a';
            }else{
                answer += s[i];
            }
        }
        isFirst = false;
    }
    return answer;
}