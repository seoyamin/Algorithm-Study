#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

//문자열의 길이 순으로 정렬한다
bool compare(string a, string b)
{
    return a.size()< b.size();
}

//string형식으로 되어있는 문자열을 delimeter기준으로 나눠서 벡터로 반환하는 함수
vector<string> split(string str, char delimiter)
{
    vector<string> internal;//끊어진 문자를 담을 벡터
    string temp;//나눠질 문자
    stringstream ss(str);//문자열 스트림으로 만들기
    while (getline(ss, temp, delimiter))
    {
        internal.push_back(temp);
    }
    return internal; 
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<string> tempV;

    string tempStr="";
    for(int i=2; i< s.length()-2; i++)
    {
        if(s[i-1] == '{') 
            tempStr="";
        tempStr += s[i];
        if(s[i+1]=='}')
        {
            tempV.push_back(tempStr);//괄호를 뺀 나머지 문자 ex) {2,3,1} ==> 2,3,1
            tempStr="";
        }
    }
    
    sort(tempV.begin(), tempV.end(), compare); // 문자열 길이순으로 정렬
    answer.push_back(stoi(tempV[0])); //정렬했으니까 가장 앞 문자는 하나짜리 ex) 2

    for(int i=1; i< tempV.size(); i++)
    {
        string str=tempV[i];//임시 string을 담는 곳
        vector<string> elements = split(str, ',');// 2,3,4, -> 2 3 4 int로 벡터에 담음
        for(int j=0; j<elements.size(); j++)
        {
            //벡터 안의 원소를 하나씩 가져옴
            int element=stoi(elements[j]);
            auto itr =find(answer.begin(), answer.end(), element);//해당 원소가 이미 벡터 안에 있는지 찾기
            if(itr ==answer.end())//없다면 
            {
                answer.push_back(element);
            }
        }
    }

    return answer;
}