int myAtoi(char* s) {
    int sign = 1;
    long result = 0;

    // Step 1: Whitespace removal
    while (isspace((unsigned char)*s)) { s++; }
    if (*s == '\0') return 0;

    // Step 2: Sign check
    if (*s == '-' || *s == '+') {
        if (*s == '-') sign = -1;
        s++;
    }

    // Step 3: Digit reading
    while (isdigit((unsigned char)*s)) {
        result = result * 10 + (*s - '0');

        // Step 4: Rounding (clamp early to avoid overflow)
        if (result * sign > INT_MAX) return INT_MAX;
        if (result * sign < INT_MIN) return INT_MIN;

        s++;
    }

    return (int)(result * sign);
}
