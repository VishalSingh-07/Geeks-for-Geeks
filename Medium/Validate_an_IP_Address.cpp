/*
Validate an IP Address

You are given a string str in the form of an IPv4 Address. Your task is to validate an IPv4 Address, if it is valid return true otherwise return false.

IPv4 addresses are canonically represented in dot-decimal notation, which consists of four decimal numbers, each ranging from 0 to 255, separated by dots, e.g., 172.16.254.1

A valid IPv4 Address is of the form x1.x2.x3.x4 where 0 <= (x1, x2, x3, x4) <= 255. Thus, we can write the generalized form of an IPv4 address as (0-255).(0-255).(0-255).(0-255)

Note: Here we are considering numbers only from 0 to 255 and any additional leading zeroes will be considered invalid.

Examples :

Input: str = 222.111.111.111
Output: true
Explanation: Here, the IPv4 address is as per the criteria mentioned and also all four decimal numbers lies in the mentioned range.



Input: str = 5555..555
Output: false
Explanation: 5555..555 is not a valid. IPv4 address, as the middle two portions are missing.



Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
- 1<=str.length() <=15
*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++


// Brute Force Approach
// Time complexity -> O(n) and Space -> O(n)
class Solution {
  public:
    int isValid(string str) {
        vector<string> temp; // Vector to store the segments of the IP address
        stringstream ss(str); // String stream to split the input string by '.'
        string word;
        
        // Split the input string by '.' and store each segment in the vector 'temp'
        while (getline(ss, word, '.')) {
            temp.push_back(word);
        }
        
        int count = 0; // Counter to keep track of the number of valid segments
        
        // Iterate through each segment in the vector
        for (string x : temp) {
            // Check if the segment is empty or has leading zeros
            if (x == "" || (x[0] == '0' && x.size() > 1)) {
                return 0; // Return 0 if any segment is invalid
            }
            
            // Convert the segment to an integer
            int digit = stoi(x);
            
            // Check if the integer is within the valid range (0-255)
            if (digit >= 0 && digit <= 255) {
                count++; // Increment the counter if the segment is valid
            }
        }
        
        // Check if there are exactly 4 valid segments and return true (1) or false (0) accordingly
        return count == 4 ? true : false;
    }
};


// Optimized Approach
// Time complexity -> O(n) and Space -> O(1)
class Solution {
  public:
    int isValid(string str) {
        string temp = ""; // Temporary string to store each segment of the IP address
        int dot = 0; // Counter to keep track of the number of dots in the IP address
        
        // Loop through each character in the input string
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '.') { // If the character is a dot
                dot++; // Increment the dot counter
                
                // Check if the segment is empty
                if (temp.empty()) {
                    return false; // Return false if the segment is empty
                }
                // Check if the segment has leading zeros
                else if (temp.size() > 1 && temp[0] == '0') {
                    return false; // Return false if the segment has leading zeros
                }
                
                // Convert the segment to an integer
                int num = stoi(temp);
                
                // Check if the integer is within the valid range (0-255)
                if (num < 0 || num > 255) {
                    return false; // Return false if the integer is not in the valid range
                }
                
                temp = ""; // Reset the temporary string for the next segment
            } else { // If the character is not a dot
                temp += str[i]; // Append the character to the temporary string
            }
        }
        
        // Check the last segment after the loop ends
        if (temp.empty()) {
            return false; // Return false if the last segment is empty
        }
        else if (temp.size() > 1 && temp[0] == '0') {
            return false; // Return false if the last segment has leading zeros
        }
        
        // Convert the last segment to an integer
        int num = stoi(temp);
        
        // Check if the last segment is within the valid range (0-255)
        if (num < 0 || num > 255) {
            return false; // Return false if the last segment is not in the valid range
        }
        
        // Check if there are exactly 3 dots (4 segments in total) and return true (1) or false (0) accordingly
        return dot == 3 ? true : false;
    }
};



//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends


// Question link -- https://www.geeksforgeeks.org/problems/validate-an-ip-address-1587115621/1