class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        stored_vals = {}  # {val: index}

        for index, val in enumerate(nums):
            diff = target - val
            if diff in stored_vals:
                return [stored_vals[diff], index]
            stored_vals[val] = index
