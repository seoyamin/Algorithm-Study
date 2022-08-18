# 12916 - Lv.1 문자열 내 p와 y의 개수

from collections import Counter

def solution(s):
    s = s.lower()  # lower() : 소문자로 변환
    
    if Counter(s)['p'] == Counter(s)['y']:
        return True
    else:
        return False
      
