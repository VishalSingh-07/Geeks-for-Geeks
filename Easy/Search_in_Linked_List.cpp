/*
Search in Linked List

Given a linked list of n nodes and a key , the task is to check if the key is present in the linked list or not.

Example:

Input:
n = 4
1->2->3->4
Key = 3

Output:
True

Explanation:
3 is present in Linked List, so the function returns true.


Your Task:
Your task is to complete the given function searchKey(), which takes a head reference and key as Input and returns true or false boolean value by checking the key is present or not in the linked list.

Constraint:
1 <= n <= 105
1 <= key <= 105

Expected Time Complexity: O(n)
Expected Space Complexity: O(1)

*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Link list node */
/*
struct Node
{
    int data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
}; */

// Optimized Approach
// Time complexity -> O(n) and Space -> O(1)
class Solution {
  public:
    // Function to count nodes of a linked list.
    bool searchKey(int n, struct Node* head, int key) {
        // Code here
        while(head!=NULL)
        {
            if(head->data==key)
            {
                return true;
            }
            head=head->next;
        }
        return false;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int data;
        cin >> data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < n - 1; ++i) {
            cin >> data;
            tail->next = new Node(data);
            tail = tail->next;
        }

        int key;
        cin >> key;
        Solution ob;
        cout << ob.searchKey(n, head, key) << endl;
    }
    return 0;
}
// } Driver Code Ends

// Question link -- https://practice.geeksforgeeks.org/problems/search-in-linked-list-1664434326/1