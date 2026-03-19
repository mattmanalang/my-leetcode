class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        last_word_len = 0
        end = len(s) - 1
        while s[end] == ' ':
            end -= 1
        while end >= 0 and s[end] != ' ':
            last_word_len += 1
            end -= 1
        return last_word_len
