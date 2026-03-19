class Solution:
    def isValid(self, s: str) -> bool:
        pairs = {
            ")": "(",
            "]": "[",
            "}": "{"
        }
        
        if len(s) % 2 != 0:
            return False

        stack = []
        for character in s:
            if character == "(" or character == "[" or character == "{":
                stack.append(character)
            elif len(stack) != 0 and stack[-1] == pairs[character]:
                stack.pop()
            else:
                return False

        return True if len(stack) == 0 else False
