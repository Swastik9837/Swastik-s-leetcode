// class Solution
// {
//     public:
//         bool checkIfPangram(string sentence)
//         {

//            	//2nd method  	// 	// Add every letter of 'sentence' to hash set 'seen'.
//            	// unordered_set<char> seen(sentence.begin(), sentence.end());
//            	// 	// If the size of 'seen' is 26, then 'sentence' is a pangram.
//            	// return seen.size() == 26;

//            	///////////////////////////////////////////////////////////
//            	//     3rd method    array<bool, 26> seen{};

//            	//        	// For every letter 'currChar', we find its ASCII code, 
//            	//        	// and update value at the mapped index as true.
//            	//         for (auto currChar : sentence)
//            	//             seen[currChar - 'a'] = true;

//            	//        	// Once we finish iterating, check if 'seen' contains false.
//            	//         for (auto status : seen)
//            	//             if (!status)
//            	//                 return false;
//            	//         return true;     
//            	// }
//         };


// BY BIT MANIPULATION
// Algorithm
// Initialize the status of encountered letters as seen = 0.
// Iterate over sentence, for each letter currChar:
// Find the mapped index mappedIndex using its ASCII code.
// Get the value representing the bit of currChar as currBit = 1 << mappedIndex.
// Add the currBit to seen by letting seen |= currBit.
// Once we finish iterating, check if seen equals (1 << 26) - 1.



class Solution {
public:
    bool checkIfPangram(string sentence) {
        // Initialize seen = 0 since we start with no letter.
        int seen = 0;
        
        // Iterate over 'sentence'.
        for (auto currChar : sentence) {
            // Map each 'currChar' to its index using its ASCII code.
            int mappedIndex = currChar - 'a';

            // 'currBit' represents the bit for 'currChar'.
            int currBit = 1 << mappedIndex;

            // Use 'OR' operation since we only add its bit for once.
            seen |= currBit;
        }
        
        // Once we finish iterating, check if 'seen' contains 26 bits of 1.
        return seen == (1 << 26) - 1;
    }
};









