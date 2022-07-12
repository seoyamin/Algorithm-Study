# 92334 - Lv.1 신고 결과 받기

def solution(id_list, report, k):
    # 결과값 반환 리스트
    answer = [0] * len(id_list)
    # set()함수로 집합 -> 중복 제거
    result = set(report)
    # 집합을 리스트로 변환
    result = list(result)

    # 신고 결과를 저장할 딕셔너리
    report_dic = {}

    # 딕셔너리의 value를 리스트로 선언
    for id in id_list:
        report_dic[id] = []

    for i in result:
        reporter, reported = i.split()
        # 딕셔너리 값에 신고자 추가
        report_dic[reported].append(reporter)

    for key, value in report_dic.items():
        if len(value) >= k:
            for person in value:
                answer[id_list.index(person)] += 1
                
    return answer
