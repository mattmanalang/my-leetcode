class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        result = ""
        sorted_strs = sorted(strs)

        first_word = sorted_strs[0]
        last_word = sorted_strs[-1]

        for i in range(min(len(first_word), len(last_word))):
            if first_word[i] != last_word[i]:
                return result
            result += first_word[i]
          
        return result
