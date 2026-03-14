class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        left = 0
        seen = {}
        max_length = 0

        for right in range(len(s)):
            char = s[right]
            if char in seen:  # Found duplicate
                left = max(left, seen[char] + 1)  # Move left to the furthest point where a duplicate is currently known
            seen[char] = right  # always update current info
            max_length = max(max_length, right - left + 1)

        return max_length
