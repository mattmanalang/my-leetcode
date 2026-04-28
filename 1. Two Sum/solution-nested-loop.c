/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int *result = malloc(*returnSize * sizeof(int));
    
    // Nested loops: check every pair
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    
    return result;
}

/*
* Matt's note: This solution uses brute force.
* Time Complexity: O(n^2)
* Space Complexity: O(n)
*/
