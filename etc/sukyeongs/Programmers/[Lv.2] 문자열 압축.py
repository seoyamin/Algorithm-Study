# 60057 - Lv.2 문자열 압축

def solution(s):
    answer = len(s)
    
    # 문자열 자르는 단위를 1부터 문자열 길이의 1/2까지 반복하여 최소 길이 찾기
    for length in range(1, len(s) // 2 + 1):
        count = 1    # 반복 횟수
        prev = s[0:length]    # 비교 대상
        compressed = ""    # 압축 결과
        
        # length에 따라 전체 문자열 길이 확인
        for j in range(length, len(s), length):
            
            if prev == s[j:j+length]:
                count += 1    # 겹친다면 count +1
            
            else:
                compressed += str(count) + prev if count >= 2 else prev    # count가 2 이상이면 숫자 표기, 1이면 숫자X
                prev = s[j:j+length]
                count = 1
        
        compressed += str(count) + prev if count >= 2 else prev
        answer = min(answer, len(compressed))

    return answer
