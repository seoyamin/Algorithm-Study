#include <string>
#include <vector>
#include <algorithm>
#include <ctype.h>

using namespace std;

struct File{
    int idx;
    string head;
    string num;
    string tail;
};


// string -> File 함수
File toStruct(string file, int idx) {
    File f;
    int idx_h, idx_n;
    
    for(idx_h = 0 ; idx_h <file.size() ; idx_h++) {
        if(file[idx_h] >= '0' && file[idx_h] <= '9') {  // 숫자가 처음 등장 -> head 끝, num 시작
            idx_h--;  // head의 맨끝 index 저장
            break;
        }
    }
    
    
    for(idx_n = idx_h + 1 ; idx_n <file.size() ; idx_n++) {
        if(idx_n == file.size()-1) break;
        else if(file[idx_n] >= '0' && file[idx_n] <= '9') continue;
        
        else {        // 숫자 아닌 문자가 처음 등장 -> num 끝, tail 시작
            idx_n--;  // num의 맨끝 index 저장
            break;
        }
    }
    
    f.idx = idx;
    f.head = file.substr(0, idx_h + 1);
    f.num = file.substr(idx_h + 1, idx_n - idx_h);
    f.tail = file.substr(idx_n + 1);
    
    return f;    
}


// 대문자 -> 소문자 함수
string getLower(string s) {
    string result = "";
        
    for(int i=0 ; i<s.size() ; i++) {
        result += tolower(s[i]);     
    }
    
    return result;
}


// 조건에 맞게 정렬하는 비교함수
bool cmp(File a, File b) {
    
    if(getLower(a.head) != getLower(b.head)) {
        return getLower(a.head) < getLower(b.head);   // head 사전순 정렬
    } 
    
    if(stoi(a.num) != stoi(b.num)) {
        return stoi(a.num) < stoi(b.num);   // num 크기순 정렬
    } 
    
    return a.idx < b.idx;   // head, num 같으면 처음 순서 유지
}


vector<string> solution(vector<string> files) {
    vector<File> struct_list;  
    vector<string> answer;
    
    
    // file_list 채우기
    for(int i=0 ; i<files.size() ; i++) {
        File f = toStruct(files[i], i);   // head, num, tail 나눈 File 구조체 구하기
        struct_list.push_back(f);    
    }
    
    
    sort(struct_list.begin(), struct_list.end(), cmp);  // cmp 함수 기준으로 정렬
    
    
    // answer 벡터 채우기
    for(int i=0 ; i<struct_list.size() ; i++) {
        answer.push_back(struct_list[i].head + struct_list[i].num + struct_list[i].tail);
    }
    
    return answer;
}