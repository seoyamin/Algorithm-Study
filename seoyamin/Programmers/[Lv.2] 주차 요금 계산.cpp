#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>

using namespace std;

struct carInfo {
    string in;
    string out = "23:59"; 
    double time = 0;
    double fee = 0;
    string last_action;
};

map<string, carInfo> getMap(vector<string> &records) {
    map<string, carInfo> cars;  //  <차량번호, carInfo> 저장하는 맵 cars : 자량번호 작은 순으로 자동 정렬
    
    for(int i=0 ; i<records.size() ; i++) {
        vector<string> record;
        
        stringstream ss(records[i]);
        ss.str(records[i]);
        
        string item;
        while(ss >> item) {
            record.push_back(item);  // record[0] : 시각, record[1] : 차량번호, record[2] : IN/OUT
        }
        
        // [case 1] IN
        if(record[2] == "IN") {
            
            // 처음 주차하는 경우
            if(cars.find(record[1]) == cars.end()) { 
                carInfo c;
                c.in = record[0];
                c.last_action = "IN";
                cars.insert({record[1], c});
            }
            
            // 재방문인 경우
            else { 
                cars[record[1]].in = record[0];
                cars[record[1]].last_action = "IN";
            }
            
        }
        
        // [case 2] OUT
        else {
            cars[record[1]].out = record[0];
            int hour_diff = stoi(cars[record[1]].out.substr(0, 2)) - stoi(cars[record[1]].in.substr(0, 2));
            int min_diff = stoi(cars[record[1]].out.substr(3, 2)) - stoi(cars[record[1]].in.substr(3, 2));
            
            if(min_diff < 0) {
                hour_diff--;
                min_diff = 60 + min_diff;
            }

            cars[record[1]].time += (hour_diff * 60 + min_diff); // 주차 시간 갱신
            cars[record[1]].last_action = "OUT";
        }
    }
    
    
    // 출차 기록 없는 경우 23:59
    for(auto iter = cars.begin() ; iter != cars.end() ; iter++) {
        if(iter->second.last_action == "IN") {
            iter->second.out = "23:59";
            int hour_diff = stoi(iter->second.out.substr(0, 2)) - stoi(iter->second.in.substr(0, 2));
            int min_diff = stoi(iter->second.out.substr(3, 2)) - stoi(iter->second.in.substr(3, 2));
            
            if(min_diff < 0) {
                hour_diff--;
                min_diff = 60 + min_diff;
            }

            iter->second.time += (hour_diff * 60 + min_diff); // 주차 시간 갱신
            iter->second.last_action = "OUT";
        }
    }
    
    return cars;
}


void getFees(const vector<int> &fees, map<string, carInfo> &cars) {
    
    for(auto iter = cars.begin() ; iter != cars.end() ; iter++) {        
        
        if(iter->second.time <= fees[0]) iter->second.fee = fees[1];
        else iter->second.fee = fees[1] + ceil((iter->second.time - fees[0]) / fees[2]) * fees[3];

    }
}


vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, carInfo> m = getMap(records);
    
    getFees(fees, m);
    
    for(auto iter = m.begin() ; iter != m.end() ; iter++) {
        answer.push_back(iter->second.fee);
    }
    
    return answer;
}