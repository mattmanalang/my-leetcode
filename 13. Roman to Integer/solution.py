class Solution:
    def romanToInt(self, s: str) -> int:
        numerals = {
            "I": 1,
            "V": 5,
            "X": 10,
            "L": 50,
            "C": 100,
            "D": 500,
            "M": 1000
        }

        total = 0
        last_number = s[-1]
        for numeral in s[::-1]:
            current_value = numerals[numeral]
            if current_value < numerals[last_number]:
                total -= current_value
            else:
                total += current_value
            last_number = numeral

        return total
        
