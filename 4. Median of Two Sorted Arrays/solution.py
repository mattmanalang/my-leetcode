class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        # Make nums1 to contain the smaller array
        if len(nums2) < len(nums1):
            nums1, nums2 = nums2, nums1
        
        # Case: nums1 is empty, return median of nums2
        if not nums1:
            if len(nums2) % 2 == 0:  # Even length
                return ( (nums2[len(nums2)//2 - 1]) + (nums2[len(nums2)//2]) ) / 2
            else:  # Odd length
                return nums2[len(nums2) // 2]

        m, n = len(nums1), len(nums2)
        left, right = 0, m

        # Binary search in the smaller array
        while left <= right:
            i = (left + right) // 2  # partition position in nums1
            j = (m + n + 1)//2 - i

            leftMax1 = nums1[i - 1] if i > 0 else float('-inf')
            rightMin1 = nums1[i] if i < m else float('inf')
            leftMax2 = nums2[j - 1] if j > 0 else float('-inf')
            rightMin2 = nums2[j] if j < n else float('inf')

            if leftMax1 <= rightMin2 and leftMax2 <= rightMin1:  # Valid partitions
                # Calculate and return the median
                if (m + n) % 2 == 0:  # Even length
                    return (max(leftMax1, leftMax2) + min(rightMin1, rightMin2)) / 2
                else:  # Odd length
                    return max(leftMax1, leftMax2)
            else:  # Invalid partitions
                if leftMax1 > rightMin2:  # Too many elements taken from num1 left, decrease i
                    right = i - 1
                elif leftMax2 > rightMin1:  # Too many elements taken from num2 left, increase i
                    left = i + 1
