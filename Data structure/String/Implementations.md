# Complex number parsing
Parse a complex number with this format "1+1i", "123+-456i",... into their real and img part (e.g real = 123, imagine = -456); and do multiply between 2 complex numbers: [string_complex_number_parsing.cpp](src/string_complex_number_parsing.cpp)
# Multiply strings
* num1 = "2", num2 = "3", result = "6"
* num1 = "123", num2 = "456", result = "56088"

A naive approach is to convert 2 number to number then start the multiplying. This approaches will fail for the numbers bigger than the long long size.

The best approach for this problem is to "multiplying manually", i.e: 123 x 456 = (3 * 456) + (2 * 456 * 10) + (1 * 456 * 100). As traversing the string, we need to reverse the 2 number string at first to multiply manually. 

Program: [multiply_strings.cpp](multiply_strings.cpp)
# Time conversion in AM/PM format
* 12:01:00PM -> 12:01:00
* 12:01:00AM -> 00:01:00
* 07:05:45PM -> 19:05:45
* 12:45:54PM -> 12:45:54

<details>
  
```cpp
vector<string> splitStringByDelimiter(string s, string delim) {
    vector<string> all_substr;
    std::size_t index = s.find(delim, 0);
    string sub_str  = s.substr(0, index);
    string new_string = s.substr(index+1);

    while (index != string::npos) { 
        if (sub_str != delim && sub_str.size() >= 1) {
            all_substr.push_back(sub_str);
        }

        index = new_string.find(delim, 0);
        sub_str  = new_string.substr(0, index);
        new_string = new_string.substr(index+1);
    }

    if (sub_str != delim && sub_str.size() >= 1) {
        all_substr.push_back(sub_str);
    }

    return all_substr;
}

string timeConversion(string s) {
    string twenty_4hr_clock;

    vector<string> all_substr = splitStringByDelimiter(s, ":");
    std::string clock =  all_substr[2].substr(2, 2);
    int hour = stoi(all_substr[0]);
    if (clock == "AM") {
        if (hour == 12) return "00:" + all_substr[1] + ":" + all_substr[2].substr(0, 2);
        else return s.substr(0, 8);// Test case: 06:40:03AM -> 06:40:03
    }
    else {
        if (hour == 12 && all_substr[1].substr(0, 2) == "00" && all_substr[2].substr(0, 2) == "00")
        return "00:00:00AM";

        if (hour < 12) hour +=12;
    }
    twenty_4hr_clock = std::to_string(hour) + ":" + all_substr[1] + ":" + all_substr[2].substr(0, 2);
    return twenty_4hr_clock;
}
```
</details>
# Longest substring without repeating characters

Leetcode 3: Given a string s, find the length of the longest substring without repeating characters.

**Test case 1** Input: s = "abcabcbb"; Output: 3; Explanation: The answer is "abc", with the length of 3.

**Test case 2** Input: s = "bbbbb"; Output: 1; Explanation: The answer is "b", with the length of 1.

**Test case 3**: Input: s = "pwwkew"; Output: 3; Explanation: The answer is "wke", with the length of 3.

**Analysis**: Test case "abcabcbb", the loop traversal to form it will be:

i = 0: sub_str = "a"; i = 1: sub_str = "ab"; i = 2: sub_str = "abc"

i = 3, "a" wil be duplicated in "abc" at index = 0 in sub_str, so form a new string start from index = 1 of sub_str, i.e "bc" and finally the new character "a" from the original string. The new substring will be "bca".

Program: [longest_substr_without_repeating_char.cpp](src/longest_substr_without_repeating_char.cpp)
# Convert string to integer
Create a function to convert a string to integer with the following conditions:

* Read in and ignore any leading whitespace.
* Check if the next character (if not already at the end of the string) is **-** or **+**. Read this character in if it is either. This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present.
* Read in next the characters until the next non-digit character or the end of the input is reached. The rest of the string is ignored.
* Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits were read, then the integer is 0. Change the sign as necessary (from step 2).
* If the integer is out of the 32-bit signed integer range **[-2^31, 2^31 - 1]**, then clamp the integer so that it remains in the range. Specifically, integers less than **-2^31** should be clamped to **-231**, and integers greater than **2^31 - 1** should be clamped to **2^31 - 1**.

Some test cases:
* 42 -> 42
* "   -42" -> -42
* "4193 with words" -> 4193
* 3.14abc -> 3
* "  +0 123" -> 0
* "20000000000000000000" -> 2147483647
* "-9223372036854775809" -> -2147483648

Leetcode: [8. String to Integer (atoi)](https://leetcode.com/problems/string-to-integer-atoi/description/)

Source code: [string_to_integer.cpp](https://github.com/TranPhucVinh/C/blob/master/Algorithms/src/string_to_integer.cpp)

# Repeated substring pattern

Given a string **s**, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.

* s = "abab" -> true as it is the substring **ab** twice
* s = "aba" -> false
* s = "abcabcabcabc" -> true as it is the substring "abc" four times or the substring "abcabc" twice.

**Algorithm**: 
* The substring size must not be greater than half length of string **s**: ``substr_size <= length/2``
* String **s** length must be divided by the substring size: ``substr_size*k = length``
From that, we will generate all possible size of the substring then start finding if at least one among them can form the original string **s**.

Source code: [string_repeated_substring_pattern.cpp](https://github.com/TranPhucVinh/C/blob/master/Algorithms/src/string_repeated_substring_pattern.cpp)
