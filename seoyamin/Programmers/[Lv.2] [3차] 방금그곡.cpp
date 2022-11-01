#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Music {
    int order;
    int time;
    string title;
    string melody;
};

// 재생 시간 구하는 함수
int getTime(string start, string end) {
    int min_start = 60 * stoi(start.substr(0, 2)) + stoi(start.substr(3, 2));
    int min_end = 60 * stoi(end.substr(0, 2)) + stoi(end.substr(3, 2));
    
    return min_end - min_start;
}

// 멜로디 #을 소문자 1개로 변형하는 함수
string getMelody(string s) {
    for(int i=1 ; i<s.size(); i++) {
        if(s[i] == '#') {
            s[i-1] = tolower(s[i-1]);  // C# -> c 
            s.erase(s.begin() + i);    // # 삭제
            i--;                       // 삭제했으니까 인덱스 하나 감소
        }
    }
    return s;
}

// Music 우선순위 맞게 정렬하기 위한 비교함수
bool cmp(Music a, Music b) {
    if(a.time != b.time) return a.time > b.time;
    
    return a.order < b.order;
}


string solution(string m, vector<string> musicinfos) {
    vector<Music> musicList;
    
    m = getMelody(m);
    
    // vector<string> musicinfos  ->  vector<Music> musicList
    for(int i=0 ; i<musicinfos.size() ; i++) {
        Music m;
        m.order = i;

        string start = musicinfos[i].substr(0, 5);
        string end = musicinfos[i].substr(6, 5);
        m.time = getTime(start, end);
        
        for(int j=12 ; j<musicinfos[i].size() ; j++) {
            if(musicinfos[i][j] == ',') {
                m.title = musicinfos[i].substr(12, j-12);
                m.melody = getMelody(musicinfos[i].substr(j+1, musicinfos[i].size()-1));
            }
        }
        musicList.push_back(m);
    }
    
    // 조건과 일치하는 음악들 저장하기 위한 벡터
    vector<Music> right_musicList;
    
    for(int i=0 ; i<musicList.size() ; i++) {
        string play = "";
        for(int j=0 ; j<musicList[i].time ; j++) {
            int idx = j%(musicList[i].melody.size());
            play += musicList[i].melody[idx];
        }
        
        // 조건과 일치하는 음악인 경우
        if(play.find(m) != string::npos) {
            right_musicList.push_back(musicList[i]);
        }
    }
    
    
    // (1) 조건과 일치하는 음악 없는 경우
    if(right_musicList.size() == 0) return "(None)";
    
    // (2) 조건과 일치하는 음악들 중 우선순위 제일 높은 것 리턴
    else {
        sort(right_musicList.begin(), right_musicList.end(), cmp);
        return right_musicList[0].title;
    }
}