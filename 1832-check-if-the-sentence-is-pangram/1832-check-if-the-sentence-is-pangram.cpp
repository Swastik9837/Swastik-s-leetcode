class Solution {
public:
   
    bool checkIfPangram(string sentence) {
        // we iterate over 'sentence' for 26 times, one for each letter 'currChar'
       
        for(int i=0;i<26;i++)
        {
            char currChar='a' + i;
            
            //if sentence doen't contain currChar, it is not a pangram
            if(sentence.find(currChar) ==  string::npos)
            {
                return false;
            }
            
        }
        return true;
        
        
    }
};