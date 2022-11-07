/*
You are given a positive integer num consisting only of digits 6 and 9.

Return the maximum number you can get by changing at most one digit (6 becomes 9, and 9 becomes 6).
https://leetcode.com/problems/maximum-69-number/

*/

class Solution {
public:
    int maximum69Number (int num) {
        vector<int> arr;
        while (num > 0) {
            arr.push_back(num%10);
            num = num/10;
        }
        
        int k = 0;
        int l = arr.size()-1;
        int temp;
        while (k < l) {
            temp = arr[k];
            arr[k] = arr[l];
            arr[l] = temp;
            k++;
            l--;
        }
        
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 6) { 
                arr[i] = 9;
                //cout << arr[i];
                break;
                
            }
            
        }
        
        int res = 0;
        for (int i = 0; i < arr.size(); i++) {
            res += arr[i]*pow(10, arr.size()-1-i);
        }
        
        return res;
    }
};
