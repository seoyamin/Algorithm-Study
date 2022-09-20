using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1;
    
    long long total_count = (1 + count) * count / 2;
    answer = total_count * price - money;
    
    if (answer <= 0)
        answer = 0;

    return answer;
}
