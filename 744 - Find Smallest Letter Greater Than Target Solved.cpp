class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char res = '{'; // ASCII after 'z'
        for (char c : letters) {
            
            if (c > target && c < res) res = c;
        }
        return (res == '{') ? letters[0] : res;
    }
};
