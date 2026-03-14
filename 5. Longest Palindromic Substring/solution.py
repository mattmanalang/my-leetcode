class Solution:
    def getLength(self, s: str, left: int, right: int) -> int:
        m = len(s)

        while left >= 0 and right < m and s[left] == s[right]:
                left -= 1
                right += 1

        return right - left - 1

    def longestPalindrome(self, s: str) -> str:
        max_length = 0
        start = 0

        for i in range(len(s)):
            length_odd = self.getLength(s, i, i)
            length_even = self.getLength(s, i, i+1)
            length = max(length_odd, length_even)
            if length > max_length:
                max_length = length
                start = i - (length - 1) // 2


        return s[start:start + max_length]
