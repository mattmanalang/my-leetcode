class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        clean_index = 0
        for i in range(len(nums)):
            if nums[i] != val:
                nums[clean_index] = nums[i]
                clean_index += 1

        return clean_index
        
