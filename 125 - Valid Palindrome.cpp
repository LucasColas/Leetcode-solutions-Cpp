class Solution {
public:
    bool isPalindrome(string s) {
        string new_string = "";
        
        for (int i = 0; i < s.length(); i++) {
            if (iswalnum(s[i])) {
                new_string += tolower(s[i]);
            }
        }
        cout << new_string;
        
        int i = 0;
        int j = new_string.length()-1;
        while (i < new_string.length()/2) {
            if (new_string[i] != new_string[j]) {
                return false;
            }
            
            i++;
            j--;
        }
        return true;

    
    }
};
