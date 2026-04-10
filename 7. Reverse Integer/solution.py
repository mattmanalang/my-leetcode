class Solution:
    def reverse(self, x: int) -> int:
        positive = True if x >= 0 else False
        x = abs(x)
        max = 2**31 -1
        preop_max = max // 10
        reversed = 0

        while x != 0:
            # Extracting the last digit
            digit = x % 10
            # Cutting it down
            x = x // 10
            # Checking before multiplying by 10 if it the result will go over 32-bit range
            if reversed > preop_max:
                return 0
            # Case: checking if adding the next ones digit will exceed 32-bit range    
            if (reversed == preop_max and digit > 7):
                return 0 
            # Expanding the result before adding the latest extracted digit
            reversed = reversed * 10 + digit

        return reversed if positive else -1 * reversed
