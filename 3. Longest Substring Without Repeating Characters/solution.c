#define MAX(a,b) ((a) > (b)? (a) : (b))

int lengthOfLongestSubstring(char* s) {
    int left = 0;
    int seen[128] = {-1};  // seen[ascii_value] = index_seen
    memset(seen, -1, sizeof(seen));
    int max_length = 0;

    int len = strlen(s);
    for (int right = 0; right < len; right++) {
        char c = s[right];
        // Check if we've seen this before and it's within the window
        if (seen[c] != -1 && seen[c] >= left) {
            // If yes, update the left pointer
            left = seen[c] + 1;  // NOTE1
        }
        // Update seen array
        seen[c] = right;
        max_length = MAX(max_length, right - left + 1);
    }

    return max_length;
}

/*
NOTE1: In C, characters are internally stored as an integer, so they already "are" the ASCII value.
       The integer values can be retrieved implicitly (as is the case in seen[c]) or by explicit casting.
*/
