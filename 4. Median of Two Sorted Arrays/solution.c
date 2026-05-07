#define MAX(a,b) ((a) > (b)? (a) : (b))
#define MIN(a,b) ((a) < (b)? (a) : (b))

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    // Make nums1 contain the smaller array
    if (nums2Size < nums1Size) {
        int *temp = nums1;
        nums1 = nums2;
        nums2 = temp;
        int swap = nums1Size;  // *NOTE1
        nums1Size = nums2Size;
        nums2Size = swap;
    }

    // *NOTE2

    int m = nums1Size, n = nums2Size;
    int left = 0, right = m;
    const int SENTINEL_MIN = -1000001, SENTINEL_MAX = 1000001;  // *NOTE3
    double result = 0.0;

    // Binary search on the smaller array
    while (left <= right) {
        int i = (left + right)/2;  // Partition position in nums1
        int j = (m + n + 1) / 2 - i;  // Partition position in nums2

        int left_max1 = (i > 0)? nums1[i - 1] : SENTINEL_MIN;
        int right_min1 = (i < m)? nums1[i] : SENTINEL_MAX;
        int left_max2 = (j > 0)? nums2[j - 1] : SENTINEL_MIN;
        int right_min2 = (j < n)? nums2[j] : SENTINEL_MAX;

        if (left_max1 <= right_min2 && left_max2 <= right_min1) {
            // Valid partitions -- calculate and return median
            if ((m + n) % 2 == 0) { 
                result = (double)(MAX(left_max1, left_max2) + MIN(right_min1, right_min2)) / 2; 
                return result;
            }
            else { 
                result = (double)MAX(left_max1, left_max2); 
                return result;
            }
        }
        else {
            // Invalid partitions -- adjust them
            if (left_max1 > right_min2) {
                // Too many elements taken from num1 left, decrease i
                right = i - 1;
            }
            else if (left_max2 > right_min1) {
                // Too many elements taken from num2 left, increase i
                left = i + 1;
            }
        }
    }
    return result;
}

/* Matthew's Notes:
NOTE1: Compared to the Python solution, we have to swap the sizes of nums1 and nums2 as well. In C, arrays don't carry their length-- it's passed explicitly alongside them.
NOTE2: Compared to the Python solution, we can exclude the logic for checking if nums1 is NULL/empty-- nums1Size is passed explicitly. The algorithm will handle it naturally.
NOTE3: I defined my own sentinel values just outside of the stated bounds. Using INFINITY from <math.h> would also work here.
  */
