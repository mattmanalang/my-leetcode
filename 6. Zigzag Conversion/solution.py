class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s
        
        rows = [[] for _ in range(numRows)]
        current_row = 0
        direction = 1

        for char in s:
            rows[current_row].append(char)
            current_row += direction
            if current_row == 0 or current_row == numRows - 1:
                direction *= -1

        return "".join("".join(row) for row in rows)
