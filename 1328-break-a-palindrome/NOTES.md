If the string's length is odd, we can not change the character in the middle of the string, the string will remain palindrome.
​
Since the first half and the second half of the palindrome string are symmetric, so we only need to be traverse the first half.
​
While traverse the first half of the string, if the character is not a, we can replace it with a, and then return the result directly.
​
If the first half of the string are all a, the second half is also a, so just change the last character to b directly.
​
​