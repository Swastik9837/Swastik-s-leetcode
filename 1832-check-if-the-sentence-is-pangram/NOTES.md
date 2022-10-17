```
*
Once we finish iterating, we know if sentence contains all 26 letters by checking the size of seen. Note that hash set has no duplicated elements, thus we don't need to worry that seen contains some same letters.
​
​
Algorithm
Initialize an empty hash set seen.
Iterate over sentence, and add every letter to seen.
Once we finish the iteration, check if the size of seen equals 26.
class Solution {
public:
bool checkIfPangram(string sentence) {
// Add every letter of 'sentence' to hash set 'seen'.
unordered_set<char> seen(sentence.begin(), sentence.end());
​
// If the size of 'seen' is 26, then 'sentence' is a pangram.
return seen.size() == 26;
}
};
*
​
​
}
};