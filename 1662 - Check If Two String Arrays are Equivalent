class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
        string string1 = word1[0];
        string string2 = word2[0];
        
        for (int i = 1; i < word1.size(); i++) {
            string1.append(word1[i]);
        }
        
        for (int i = 1; i < word2.size(); i++) {
            string2.append(word2[i]);
        }
        
        if (!string1.compare(string2)) {
            return 1;
        }
        
        return 0;
    }
};
