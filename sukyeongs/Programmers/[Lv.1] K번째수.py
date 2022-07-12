# 42748 - Lv.1 K번째 수

def solution(array, commands):
    answer = []
    
    # 반복문을 통해 commands 순회
    for c in commands:
        # 리스트 분할 (시작 인덱스는 포함, 끝 인덱스는 포함 X)
        list = array[c[0]-1:c[1]]
        # Python list 정렬 함수 sort()
        list.sort()
        # answer에 k번째 원소 추가
        answer.append(list[c[2]-1])
    return answer
