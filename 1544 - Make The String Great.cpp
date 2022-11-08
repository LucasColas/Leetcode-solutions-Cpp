/*

Given a string s of lower and upper case English letters.

A good string is a string which doesn't have two adjacent characters s[i] and s[i + 1] where:

    -0 <= i <= s.length - 2
    -s[i] is a lower-case letter and s[i + 1] is the same letter but in upper-case or vice-versa.

To make the string good, you can choose two adjacent characters that make the string bad and remove them. You can keep doing this until the string becomes good.

Return the string after making it good. The answer is guaranteed to be unique under the given constraints.

Notice that an empty string is also good.

https://leetcode.com/problems/make-the-string-great/

*/

class Solution {
public:
    string makeGood(string s) {
        int i;
        bool found;
        while (s.size() > 1) {
            found = false;
            for (i = 0; i < s.size()-1; i++) {
                if (abs(s[i] - s[i+1]) == 32) { 
                    s = s.substr(0, i) + s.substr(i+2);
                    found = true;
                    break;
                }
                
            }
            
            if (!found) {
                break;
            }
        }
        
        return s;
    }
};
