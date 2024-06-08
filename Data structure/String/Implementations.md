# Complex number parsing
Parse a complex number with this format "1+1i", "123+-456i",... into their real and img part (e.g real = 123, imagine = -456); and do multiply between 2 complex numbers: [string_complex_number_parsing.cpp](src/string_complex_number_parsing.cpp)

# Longest substring without repeating characters

Leetcode 3: Given a string s, find the length of the longest substring without repeating characters.

**Test case 1** Input: s = "abcabcbb"; Output: 3; Explanation: The answer is "abc", with the length of 3.

**Test case 2** Input: s = "bbbbb"; Output: 1; Explanation: The answer is "b", with the length of 1.

**Test case 3**: Input: s = "pwwkew"; Output: 3; Explanation: The answer is "wke", with the length of 3.

**Analysis**: Test case "abcabcbb", the loop traversal to form it will be:

i = 0: sub_str = "a"; i = 1: sub_str = "ab"; i = 2: sub_str = "abc"

i = 3, "a" wil be duplicated in "abc" at index = 0 in sub_str, so form a new string start from index = 1 of sub_str, i.e "bc" and finally the new character "a" from the original string. The new substring will be "bca".

Program: [longest_substr_without_repeating_char.cpp](src/longest_substr_without_repeating_char.cpp)