#define MAX(a,b) ((a) > (b)? (a) : (b))

int getLength(char *s, int left, int right) {
    int s_length = strlen(s);
    while (left >= 0 && right < s_length && s[left] == s[right]) {
        left = left - 1;
        right = right + 1;
    }
    return right - left - 1;
}

char* longestPalindrome(char* s) {
    int max_length = 0;
    int start = 0;

    for (int i = 0; i < strlen(s); i++) {
        int length_odd = getLength(s, i, i);
        int length_even = getLength(s, i, i+1);
        int length = MAX(length_odd, length_even);
        if (length > max_length) {
            max_length = length;
            start = i - (length - 1)/2;
        }
    }

    // *NOTE1
    char *result = (char*)malloc((max_length+1) * sizeof(char));
    if (result == NULL) {
        return NULL;
    }

    memcpy(result, &s[start], max_length);
    result[max_length] = '\0';

    return result;
}

/* Matthew's Notes
  NOTE1: result needs to be dynamically allocated. The caller (LeetCode's server) will handle the release of memory.
         I ran into an issue where my output was (null), and it was because I was allocating the result on the stack, which gets destroyed after the function returns.
  */
