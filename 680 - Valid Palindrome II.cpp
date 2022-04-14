/*

Given a string s, return true if the s can be palindrome after deleting at most one character from it.
Problem : https://leetcode.com/problems/valid-palindrome-ii/

*/

class Solution {
public:
    
    bool check_palindrome(string s, int ptr1, int ptr2) {
        while (ptr1 < ptr2) {
            if (s[ptr1] != s[ptr2]) {
                return false;
            }
            
            ptr1++;
            ptr2--;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        int ptr1 = 0;
        int ptr2 = s.size()-1;
        while (ptr1 < ptr2) {
            if (s[ptr1] != s[ptr2]) {
                return check_palindrome(s, ptr1+1, ptr2) || check_palindrome(s, ptr1, ptr2-1);
                
            }
            ptr1++;
            ptr2--;
        }
        
        return true;
        
    }
};
