class Solution:
    def myAtoi(self, s: str) -> int:
        INT_MIN = -2**31
        INT_MAX = 2**31 - 1

        # Step 1: Whitespace removal
        s = s.lstrip()
        if not s: return 0

        current = 0
        result = ""

        # Step 2: Sign check
        if s[current] == '-' or s[current] == '+':
            result += s[current]
            current += 1

        # Step 3: Digit reading
        while current < len(s):
            if not s[current].isdigit():
                break
            result += s[current]
            current += 1

        result_int = int(result) if result and result[-1].isdigit() else 0

        # Step 4: Rounding
        if result_int < INT_MIN:
            return INT_MIN
        if result_int > INT_MAX:
            return INT_MAX
        return result_int
