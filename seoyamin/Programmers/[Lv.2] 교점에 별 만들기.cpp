#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

long long minX, minY, maxX, maxY;

// 교점 존재 여부 판단
bool hasPoint(long long a, int b, long long c, long long d) {
    return (a*d - b*c != 0);
}

// 교점의 실수 좌표 구하기 
pair<double, double> getPoint(long long a, long long b, long long e, long long c, long long d, long long f) {
    double x = (double) (b*f - e*d) / (a*d - b*c);
    double y = (double) (e*c - a*f) / (a*d - b*c);
    
    return make_pair(x, y);
}

// minX, minY, maxX, maxY 업데이트
void updateMinMax(long long x, long long y) {
    if(x < minX) minX = x;
    if(x > maxX) maxX = x;
    
    if(y < minY) minY = y;
    if(y > maxY) maxY = y;    
}

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    set<pair<double, double>> points;    
    
    for(int i=0 ; i<line.size() ; i++) {
        long long a = line[i][0];
        long long b = line[i][1];
        long long e = line[i][2];
        
        for(int j=i+1 ; j<line.size() ; j++) {
            long long c = line[j][0];
            long long d = line[j][1];
            long long f = line[j][2];
            
            if(hasPoint(a, b, c, d)) {
                pair<double, double> p = getPoint(a, b, e, c, d, f);              
                
                if(p.first == (long long)p.first && p.second == (long long)p.second) {     
                    if(points.empty()) {
                        minX = maxX = p.first;
                        minY = maxY = p.second;
                    }
                    points.insert(p);                    
                    updateMinMax(p.first, p.second);
                }
                
            }
        }
    }

    if(points.size() == 1) {
        answer.push_back("*");
    }
    
    else {
        // answer 초기화
        string str = "";
        for(long long i=minX ; i<=maxX ; i++) 
            str += ".";
        answer = vector<string>(maxY-minY+1, str);
        
        // 별 그리기
        for(auto p : points) {
            long long x = p.first - minX;
            long long y = p.second - minY;
            
            // (-4, 1)  (-4, 2)  (-4, 3)            
            answer[maxY-minY-y][x] = '*';       
        }
    }
    
    return answer;
}