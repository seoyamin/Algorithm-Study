
#include <vector>
#include <iostream>
using namespace std;

const int inf = 1e8; //100000000

int bridge(int N, vector<int> distance, vector<bool> found){

    int min_d = inf;
    int min;

    for(int i=1; i<N+1; i++){
        if((distance[i] < min_d) && (found[i]==false)){
            min_d = distance[i];
            min=i;
        }
    }
    return min;
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    vector<int> distance(N+1, inf);
    vector<bool> found(N+1, false);
    vector<vector<int>> village(N+1, vector<int>(N+1, inf));

    for(const auto&r:road){
        village[r[0]][r[1]] = min(r[2], village[r[0]][r[1]]);
        village[r[1]][r[0]] = min(r[2], village[r[1]][r[0]]);
    }

    for(int i=1; i<N+1; i++){
        distance[i] = village[1][i];
    }
    found[1] = true;
    distance[1] = 0;

    for(int i=0; i<N-1; i++){
        int v = bridge(N, distance, found);
        found[v] = true;

        for(int w=1; w<N+1; w++){
            if(found[w] == false){
                distance[w] = min(distance[w], distance[v]+village[v][w]);
            }
        }
    }

    for(const auto&d: distance){
        if(d<=K)
            answer++;
    }

    return answer;
}

int main(){
    // road 의 크기는 다리의 개수.
    vector<vector<int>> road = {{1,2,1},{2,3,3},{5,2,2},{1,4,2},{5,3,1},{5,4,2}};
    // n개의 마을, k시간 이내로, 1번마을 기준
    int n=5; int k=3;

    cout << solution(n,road,k) << endl;

    return 0;
}
