
# 단순화 하여 푼 문제 (시간초과 발생!)
def dailyTemperaturesSimple(temperatures):
    result = []
    for i in range(len(temperatures)):
        currentTemperature = temperatures[i]
        check = False
        for j in range(i + 1, len(temperatures)):
            if currentTemperature < temperatures[j]:
                result.append(j - i)
                check = True
                break
        if check is False:
            result.append(0)
    return result

def dailyTemperatures(temperatures):
    ans = [0] * len(temperatures)
    stack = []
    for cur_day, cur_temp in enumerate(temperatures):   # enumerate: 인덱스와 값을 동시에 가져오겠다
        while stack and stack[-1][1] < cur_temp:    # stack[-1]: 스택의 가장 위 요소
            prev_day, _ = stack.pop()
            ans[prev_day] = cur_day - prev_day
        stack.append((cur_day, cur_temp))
    return ans

