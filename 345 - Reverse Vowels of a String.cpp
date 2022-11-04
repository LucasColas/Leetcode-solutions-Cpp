/*

Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.
Code : https://leetcode.com/problems/reverse-vowels-of-a-string/
*/

class Solution {
public:
    string reverseVowels(string s) {
        int i = 0;
        int j = s.size()-1;
        char c;
        while (i < j) {
            while (i < s.size() && s[i] != 'a' && s[i] !=  'e' && s[i] != 'i' && s[i] !=  'o' && s[i] != 'u' && s[i] != 'A' && s[i] !=  'E' && s[i] != 'I' && s[i] !=  'O' && s[i] != 'U') {
                i++;
            }
            
            while (j >= 0 && s[j] != 'a' && s[j] !=  'e' && s[j] != 'i' && s[j] !=  'o' && s[j] != 'u' && s[j] != 'A' && s[j] !=  'E' && s[j] != 'I' && s[j] !=  'O' && s[j] != 'U') {
                j--;
            }
            if (i < j) {
                c = s[i];
                s[i] = s[j];
                s[j] = c;
                i++;
                j--;
            }
            
        }
        
        return s;
    }
};
