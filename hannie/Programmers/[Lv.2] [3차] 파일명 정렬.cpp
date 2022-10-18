#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Body {
    string name;
    string head;
    int number;
    string tail;
    int ordered;
};
vector<Body> filenames;
// 알파벳 내리기
string to_lower(string s) {
    for(int i=0;i<s.length();i++) {
        s[i]=tolower(s[i]);
    }
    return s;
}

Body split_Body(string s,int nums) {
    Body body;
    string temp="";
    int idx;
    body.name = s; 
    
    s=to_lower(s);
    for(int i=0; i<s.length(); i++) {
        if(s[i]>='0' && s[i]<='9') { // 숫자 나오면 head 끝냄
            body.head=temp; // HEAD
            temp=""; // 초기화
            idx=i; // 인덱스
            break;
        }
        temp+=s[i];
    }
    
    bool flag=true;
    for(int i=idx; i<idx+5; i++) {
        if(!(s[i]>='0' && s[i]<='9')) { // 문자 나오면 number 끝냄
            flag=false;
            body.number=stoi(temp); // string -> int 
            temp="";
            idx=i;
            break;
        }
        temp+=s[i];
    }
    if(flag) {
        body.number=stoi(temp);
        temp="";
        idx=s.length();
    }
    for(int i=idx;i<s.length();i++) {
        temp+=s[i];
    }
    body.tail=temp; // 남은 거 TAIL 
    body.ordered=nums; // 순서
    return body;
}
// 정렬
bool comp(const Body &B1, const Body &B2) {
    if(B1.head.compare(B2.head)==0) {
        if(B1.number==B2.number) 
            return B1.ordered<B2.ordered;
        
        return B1.number<B2.number;
    }
    return B1.head<B2.head;
}
vector<string> solution(vector<string> files) {
    vector<string> answer;
    Body temp_file;
    for(int i=0;i<files.size();i++) {
        temp_file=split_Body(files[i],i+1);
        filenames.push_back(temp_file);
    }
    // 정렬
    sort(filenames.begin(),filenames.end(),comp);
    for(int i=0;i<filenames.size();i++) {
        answer.push_back(filenames[i].name);
    }
    return answer;
}
