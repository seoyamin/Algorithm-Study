#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef struct Music {
    int idx;
    string genres;
    int plays;
} Music;


// pair <genre, total plays>를 total plays 기준으로 내림차순 정렬
bool compare1(pair<string, int> a, pair<string, int> b)  {
    return a.second >= b.second;
}

// Music을 plays 기준으로 내림차순 정렬
bool compare2(Music a, Music b)  {
    if(a.plays == b.plays) return a.idx < b.idx;
    return a.plays > b.plays;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, vector<Music>> m;
    vector<pair<string, int>> v;
    
    
    // Map m 채우기
    for(int i=0 ; i<genres.size() ; i++) {
        Music item;
        item.idx = i;
        item.genres = genres[i];
        item.plays = plays[i];
        
        if(m.find(genres[i]) == m.end()) {
            vector<Music> temp;
            temp.push_back(item);
            m[genres[i]] = temp;
        } else {
            m[genres[i]].push_back(item);
        }
    }
    
    
    // Vector v 채우기
    for(auto i : m) {
        int totalPlays = 0;
        for(auto j : i.second) {
            totalPlays += j.plays;
        }
        v.push_back(make_pair(i.first, totalPlays));
    }
    
    sort(v.begin(), v.end(), compare1);
    
    
    // 각 장르별 최대 2곡 선정
    for(auto genre : v) {
        vector<Music> mv = m[genre.first];
        sort(mv.begin(), mv.end(), compare2);
        
        if(mv.size() >= 2) {
            answer.push_back(mv[0].idx);
            answer.push_back(mv[1].idx);
        } else {
            answer.push_back(mv[0].idx);
        }
    }
    
    return answer;
}