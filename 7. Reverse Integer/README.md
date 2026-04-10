# 7. Reverse Integer

Given a signed 32-bit integer `x`, return `x` with it's digits reversed. If reversing `x` causes the value to go outside the signed 32-bit integer range [-2<sup>31</sup>, 2<sup>31</sup> - 1], then return `0`.

**Assume the environment does not allow you to store 64-bit integers (signed or unsigned).**

<br>

**Example 1**:
> **Input**: x = 123
> 
> **Output**: 321

**Example 2**:
> **Input**: x = -123
> 
> **Output**: -321

**Example 3**:
> **Input**: 120
> 
> **Output**: 21

<br>

**Constraints**:
* -2<sup>31</sup> <= `x` <= 2<sup>31</sup> - 1

<br>

Notes:
* When extracting the last digit at the start of the while loop, I originally ran into a logic error where I used `modulo 10` on negative numbers directly. This resulted in something like `-123 % 10 = 7`. To avoid this behavior, I decided to strip the sign from `x`, which allowed me to work on integers uniformly, then reapply the sign before returning.
* Taking the absolute value of `x` and working on the positive side of the range, it's possible to forego performing negative-side overflow checks.
  * If the reversed positive number fits within `2147483647`, then its negative mirror `-reversed` will always fit within `-2147483648`
  * The only edge case would be if the reversed number equaled exactly `2147483648`, but that can't happen because no 32-bit integer's reversal produces that value
  * `2147483648` reversed is `8463847412`, which is way outside 32-bit range — so it could never be a *valid input*. This means we'd never encounter a situation where reversing a valid input produces exactly `2147483648`.
  * The constraints of the problem naturally protect from illegal inputs
