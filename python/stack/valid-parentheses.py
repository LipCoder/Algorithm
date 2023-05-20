def isValidByMe(str) -> bool:
    container = []
    for c in str:
        if c == '(' or c == '{' or c == '[':
            container.append(c)
        else:
            if len(container) == 0:
                return False
            last = container[len(container) - 1]
            if c == ')' and last == '(':
                container.pop()
            elif c == '}' and last == '{':
                container.pop()
            elif c == ']' and last == '[':
                container.pop()
            else:
                return False
    if len(container) == 0:
        return True
    else:
        return False


def isValid(s):
    stack = []
    for p in s:
        if p == "(":
            stack.append(")")
        elif p == "{":
            stack.append("}")
        elif p == "[":
            stack.append("]")
        elif not stack or stack.pop() != p:
            return False
    return not stack        # 빈 스택 여부를 반환