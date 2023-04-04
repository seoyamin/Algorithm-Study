#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    int x=0, y=0;
    int w = park[0].size();
    int h = park.size();
    
    for(int i=0 ; i<park.size() ; i++) {
        for(int j=0 ; j<park[0].size() ; j++) {
            if(park[i][j] == 'S') {
                x = j;
                y = i;
                break;
            }
        }
    }
    
    for(int i=0 ; i<routes.size() ; i++) {
        char op = routes[i][0];
        int n = routes[i][2] - '0';
        
        if(op == 'E') {
            if(x + n >= w) continue;
            else {
                int j;
                for(j=1 ; j < n ; j++) {
                    if(park[y][x+j] == 'X') break;
                }
                
                if(j > 1 && j == n) x += n;
                if(j == 1 && park[y][x+j] != 'X') x += n;
            }
        }
        
        else if(op == 'W') {
            if(x - n < 0) continue;
            else {
                int j;
                for(j=1 ; j < n ; j++) {
                    if(park[y][x-j] == 'X') break;
                }
                
                if(j > 1 && j == n) x -= n;
                if(j == 1 && park[y][x-j] != 'X') x -= n;
            }
        }
        
        else if(op == 'S') {
            if(y + n >= h) continue;
            else {
                int j;
                for(j=1 ; j < n ; j++) {
                    if(park[y+j][x] == 'X') break;
                }
                
                if(j > 1 && j == n) y += n;
                if(j == 1 && park[y+j][x] != 'X') y += n;
            }
        }
        
        else if(op == 'N') {
            if(y - n < 0) continue;
            else {
                int j;
                for(j=1 ; j < n ; j++) {
                    if(park[y-j][x] == 'X') break;
                }
                
                if(j > 1 && j == n) y -= n;
                if(j == 1 && park[y-j][x] != 'X') y -= n;
            }
        }
        
    }
    
    answer.push_back(y);
    answer.push_back(x);
    
    return answer;
}