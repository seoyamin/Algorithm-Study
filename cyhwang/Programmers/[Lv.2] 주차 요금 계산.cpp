#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<string>> time_classification (vector<string> records);
int calculate_time (string start, string end);
int get_accumulate_time (vector<string> car_record);
int calculate_fee (vector<int> fees, int time);

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    vector<int> time;
    
    vector<vector<string>> record_class;
    record_class = time_classification(records);
    sort(record_class.begin(), record_class.end());
    
    for (int i = 0; i < record_class.size(); i++) {
        time.push_back(get_accumulate_time(record_class[i]));
    }
    
    for (int i = 0; i < time.size(); i++) {
        answer.push_back(calculate_fee(fees, time[i]));
    }

    
    return answer;
}

vector<vector<string>> time_classification (vector<string> records) {
    
    vector<vector<string>> record_class;
    
    record_class.push_back(vector<string>());
    record_class[0].push_back(records[0].substr(6,4));
    record_class[0].push_back(records[0].substr(0,5));
    int car_count = 1;
    bool flag = true;
    
    for (int i = 1; i < records.size(); i++) {
        for (int j = 0; j < car_count; j++) {
            if (record_class[j][0] == records[i].substr(6,4)) {
                record_class[j].push_back(records[i].substr(0,5));
                flag = false;
            }
        }
        if (flag) {
            record_class.push_back(vector<string>());
            record_class[car_count].push_back(records[i].substr(6,4));
            record_class[car_count].push_back(records[i].substr(0,5));
            car_count++;
        }
        flag = true;
    }
    
    return record_class;
}

int calculate_time (string start, string end) {
    int time_minute;
    int tmp_hour;
    int tmp_min;
    
    tmp_hour = stoi(end.substr(0,2)) - stoi(start.substr(0,2));
    tmp_min = stoi(end.substr(3,2)) - stoi(start.substr(3,2));
    
    if (tmp_min < 0) {
        tmp_hour--;
        tmp_min += 60;
    }
    
    time_minute = tmp_hour * 60 + tmp_min;
    
    return time_minute;
}

int get_accumulate_time (vector<string> car_record) {
    int accumulate_time = 0;
    if (car_record.size() % 2 == 1) {
        for (int i = 1; i < car_record.size(); i += 2) {
            accumulate_time += calculate_time (car_record[i], car_record[i + 1]);
        }
    }
    
    else {
        for (int i = 1; i < car_record.size() - 1; i += 2) {
            accumulate_time += calculate_time (car_record[i], car_record[i + 1]);
        }
        accumulate_time += calculate_time (car_record[car_record.size() - 1], "23:59");
    }

    return accumulate_time;
}

int calculate_fee (vector<int> fees, int time) {
    if (time <= fees[0])
        return fees[1];
    else {
        if ((time - fees[0]) % fees[2] == 0)
            return (fees[1] + ((time- fees[0])/fees[2] * fees[3]));
        else
            return (fees[1] + (((time- fees[0])/fees[2] + 1) * fees[3]));
    }
}
