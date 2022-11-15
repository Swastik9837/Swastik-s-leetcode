//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        queue<pair<string,int>> q;
        q.push({startWord , 1});
        unordered_set<string> st(wordList.begin() , wordList.end()); // ab set mai puri wordList aagyi
        st.erase(startWord);// as ham visited mai mark kr dete hai so yha ham delete kr rhe hai set mai se
        while(!q.empty()){
            string word= q.front().first;
            int steps = q.front().second;
            q.pop();
            if(word==targetWord) return steps; // matlab ham last word pe aagye yehi hame return krna hia
            
            for(int i=0;i<word.size();i++)  // we iterate to word so that we change the word
            {
                char original=word[i];// this is the character that we are going to change
                for(char ch='a' ; ch<='z' ; ch++ ){
                    word[i] = ch;// we change the word to ch
                    // it exists in the set
                    if(st.find(word) != st.end()){
                        st.erase(word); // phele toh set se erase krdia
                        q.push({word, steps + 1}); //then step bdadie 
                    }
                }
                word[i] = original;
            }
        }
        return 0;
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends