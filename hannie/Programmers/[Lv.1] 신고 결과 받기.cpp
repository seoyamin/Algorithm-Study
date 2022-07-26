
// 신고 결과 받기
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>
 
using namespace std;
 
map<string, int> mapping;
map<string, int> reportCount;
vector<string> reportList[1010];
vector<string> blacklist;
 
void countReport(vector<string> report, int k) {
    
    int num = 1;
    
    for (int i = 0; i < report.size(); i++) {
        
        string str = report[i];
        stringstream streamStr(str);
        string userID, blacklistID;
        streamStr >> userID >> blacklistID;
 
        if (mapping[userID] == 0) mapping[userID] = num++;
        if (mapping[blacklistID] == 0) mapping[blacklistID] = num++;
        if (find(reportList[mapping[userID]].begin(), reportList[mapping[userID]].end(), blacklistID) == reportList[mapping[userID]].end()) {
            reportList[mapping[userID]].push_back(blacklistID);
            reportCount[blacklistID]++;
            if (reportCount[blacklistID] >= k) {
                blacklist.push_back(blacklistID);
            }
        }
    }
}
 
vector<int> findAnswer(vector<string> id_list) {
    vector<int> ans;
    for (auto userID : id_list) {
        
        int mappingID = mapping[userID];
        int result = 0;
        
        for (auto reportID : reportList[mappingID]) {
            if (find(blacklist.begin(), blacklist.end(), reportID) != blacklist.end()) {
                result++;
            }
        }
        ans.push_back(result);
    }
    return ans;
}
 

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> ans;
    countReport(report, k);
    ans = findAnswer(id_list);
    return ans;
}
