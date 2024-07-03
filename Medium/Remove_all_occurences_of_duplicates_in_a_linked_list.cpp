/*
Remove all occurences of duplicates in a linked list

Given a sorted linked list, delete all nodes that have duplicate numbers (all occurrences), leaving only numbers that appear once in the original list, and return the head of the modified linked list. 

Examples:

Input: Linked List = 23->28->28->35->49->49->53->53
Output: 23 35
Explanation: 

The duplicate numbers are 28, 49 and 53 which are removed from the list.
Input: Linked List = 11->11->11->11->75->75
Output: Empty list
Explanation: 
All the nodes in the linked list have duplicates. Hence the resultant list would be empty.


Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)
Constraints:
1 ≤ size(list) ≤ 10^5
*/


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
// User function Template for C++

/* Linked List node structure

struct Node {
    int data;
    struct Node *next;
};

*/

// Optimized Approach
// Time complexity -> O(n) and Space -> O(1)
class Solution {
  public:
    Node* removeAllDuplicates(struct Node* head) {
        // code here
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        Node *dummy=new Node(-1);
        Node *ans=dummy;
        Node *prev=head;
        Node *curr=head->next;
        
        int count=1;
        while(curr!=nullptr){
            if(prev->data==curr->data){
                count++;
            }    
            else if(count==1){
                ans->next=prev;
                ans=ans->next;
            }
            else{
                count=1;
            }
            prev=curr;
            curr=curr->next;
        }
        if(count==1){
            ans->next=prev;
        }
        else {
            ans->next=nullptr;
        }
        return dummy->next;
    }
    
};






//{ Driver Code Starts.
/* Function to print linked list */
void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Driver program to test above functions
int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;

        cin >> N;

        Node *head = NULL;
        Node *temp = head;

        for (int i = 0; i < N; i++) {
            int data;
            cin >> data;
            if (head == NULL)
                head = temp = new Node(data);
            else {
                temp->next = new Node(data);
                temp = temp->next;
            }
        }

        Solution ob;
        head = ob.removeAllDuplicates(head);
        printList(head);

        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends

// Question link -- https://www.geeksforgeeks.org/problems/remove-all-occurences-of-duplicates-in-a-linked-list/1