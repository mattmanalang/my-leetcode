class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        if target <= nums[0]:
            return 0
        elif target > nums[-1]:
            return len(nums)
        else:
            head = 0
            tail = len(nums) - 1
            middle = (head + tail) // 2
            while head <= tail:
                if nums[middle] < target:
                    head = middle + 1
                elif nums[middle] == target:
                    return middle
                else:
                    tail = middle - 1
                middle = (head + tail) // 2
            return head
