/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

struct Entry {
    int value;
    int index;
};

int value_in_array(int val, struct Entry *arr, int arr_size) {
    for (int i = 0; i < arr_size; i++) {
        if (arr[i].value == val) return i;
    }
    return -1;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // 1. Allocate the result array
    *returnSize = 2;
    int *result = malloc(*returnSize * sizeof(int));

    // 2. Create an array of structs to store seen values
    struct Entry seen_vals[numsSize];

    // 3. Keep track of how many entries have been seen
    int seen_count = 0;

    // 4. Loop through nums
    for (int i = 0; i < numsSize; i++) {
        // Calculate complement
        int complement = target - nums[i];
        // Linear search through seen array for complement
        int complement_index = value_in_array(complement, seen_vals, seen_count);
        // If found: populate result and return
        if (complement_index >= 0){
            result[0] = complement_index;
            result[1] = i;
            return result;
        }
        // If not found: add current value to seen array
        seen_vals[seen_count].value = nums[i];
        seen_vals[seen_count].index = i;
        seen_count++;
    }

    return result;
}

/*
* Matt's note: This solution adds a struct and a function to linearly search through an array of those structs. 
* Although this solution sets some groundwork for future optimization, the time complexity is the same as a brute-force solution. 
* Performance would improve with the implentation of a hash table.

* Time Complexity: O(n^2)
* Space Complexity: O(n)
*/
