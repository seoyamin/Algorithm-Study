#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct TrafficLight {
    int d;
    int r;
    int g;
};

// 시작 지점에서 가까운 순으로 신호등 정렬
bool compare(TrafficLight t1, TrafficLight t2) {
    return t1.d < t2.d;
}

// i번째 신호등에서 소요하는 시간 구하기
int getPointTime(vector<TrafficLight> &v, int i, int &time) {   // time : i번째 신호등 도착한 시간
    int red = v[i].r;
    int green = v[i].g;

    if(time < red) return (red - time);         // 빨간 신호에 걸림
    else if(time == red) return 0;              // 막 초록 신호로 바뀜

    int remain = time % (red + green);
    if(remain < red) return (red - remain);     // 빨간 신호에 걸림
    else return 0;                              // 초록 신호에 걸림
}

int main() {

    int N, L;                   // 신호등 개수, 도로 길이
    cin >> N >> L;

    int D, R, G;                // 신호등 위치, 빨간색 지속 시간, 초록색 지속 시간
    vector<TrafficLight> v;     // 신호등 목록

    for(int i=0 ; i<N ; i++) {
        cin >> D >> R >> G;
        v.push_back({D, R, G});
    }

    sort(v.begin(), v.end(), compare);

    int time = 0, current = 0;     // 현재까지 소요 시간, 현재 위치

    for(int i=0 ; i<v.size() ; i++) {
        time += (v[i].d - current);                  // current -> 현재 신호등 (1m 당 1초)
        time += getPointTime(v, i, time);     // 현재 신호등에서 시간 소요

        current = v[i].d;
    }

    // 마지막 신호등 -> 도로의 끝
    if(v.back().d < L) {
        time += (L - v.back().d);
    }

    cout << time << endl;

    return 0;
}
