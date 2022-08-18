# 60058 - Lv.2 괄호 변환

# w를 u, v로 나누는 함수
def divide(p):
    open_p = 0
    close_p = 0

    for i in range(len(p)):
        if p[i] == '(':
            open_p += 1
        else:
            close_p += 1
        if open_p == close_p:
            return p[:i + 1], p[i + 1:]

# 문자열이 올바른 문자열인지 아닌지 판별하는 함수
def check(u):
    stack = []

    for p in u:
        if p == '(':
            stack.append(p)
        else:
            if not stack:
                return False
            stack.pop()

    return True


def solution(p):
    if not p:
        return ""

    u, v = divide(p)

    if check(u):
        return u + solution(v)

    else:
        answer = '('
        answer += solution(v)
        answer += ')'

        for p in u[1:len(u) - 1]:
            if p == '(':
                answer += ')'
            else:
                answer += '('

        return answer
