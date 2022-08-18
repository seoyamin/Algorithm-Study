# 42576 - Lv.1 완주하지 못한 선수

# 내 풀이
def solution(participant, completion):
    # 참가자 이름을 key, 각 이름의 인원수를 value로 하는 딕셔너리 생성
    participant_dic = {p:0 for p in participant}
    
    for p in participant:
        participant_dic[p] += 1
        
    for c in completion:
        participant_dic[c] -= 1
    
    # dict.items() : key, value 쌍을 저장하는 함수
    for key, value in participant_dic.items():
        if value == 1:
            return key
        else:
            pass

          
# 다른 사람의 풀이 - collections 모듈의 Counter 함수 사용
import collections

def solution(participant, completion):
    # collections.Counter(a) : a안에 데이터들이 몇 개씩 있는지 반환하는 함수
    answer = list(collections.Counter(participant) - collections.Counter(completion))
    
    return answer[0]
