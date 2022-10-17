class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> frequency(26,0);
        
        for (int i = 0; i < sentence.length(); i++) {
            frequency[sentence[i]-'a']++;
        }
        
        for (int i = 0; i < frequency.size(); i++) {
            if (!frequency[i]) {
                return false;
            }
        }
        
        return true;
        
    }
};
