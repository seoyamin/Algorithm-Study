using namespace std;

int GetGcd(int h, int w) //최대공약수 구하는 함수 
{
    int c;
    while (h != 0)
    {
        c = w % h;
        w = h;
        h = c;
    } 
    return w;
}

//사각형을 그려서 패턴을 찾기
//대각선으로 잘린 사각형의 개수는 꼭짓점부터 다음 꼭짓점까지 x+y-1개
//이때 x와 y는 w/최대공역수 + h/최대공약수
//해당 사각형 패턴은 최대공약수 패턴만큼 나타나므로 * 최대공약수
long long solution(int w, int h)
{
    long long answer = 1;

    int rectX = 0; //못쓰는 사각형의 개수 w+h-g
    int gcd = GetGcd(w, h);
    answer = (long long)w * (long long)h - (w + h - gcd);
    return answer;
}