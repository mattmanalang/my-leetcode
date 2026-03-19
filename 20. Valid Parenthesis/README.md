# 20. Valid Parenthesis

Given a string `s` containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['`, and `'}'`, determine if the input string is valid.

An input string is valid if:
1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
3. Every close bracket has a corresponding open bracket of the same type

<br>

**Example 1**:
> **Input**: s = "()" \
> **Output**: true

**Example 2**:
> **Input**: "()[]{}" \
> **Output**: true

**Example 3**:
> **Input**: "(]" \
> **Output**: false

**Example 4**:
> **Input**: "([])" \
> **Output**: true

**Example 5**:
> **Input**: "([)]"
> **Output**: false

<br>

**Constraints**:
* 1 <= `s.length` <= 10<sup>4</sup>
* `s` consists of parenthesis only `'()[]{}'`
