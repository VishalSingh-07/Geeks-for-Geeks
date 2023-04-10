/*
Finding middle element in a linked list

Given a singly linked list of N nodes.
The task is to find the middle of the linked list. For example, if the linked list is
1-> 2->3->4->5, then the middle node of the list is 3.
If there are two middle nodes(in case, when N is even), print the second middle element.
For example, if the linked list given is 1->2->3->4->5->6, then the middle node of the list is 4.

Example 1:

Input:
LinkedList: 1->2->3->4->5
Output: 3 
Explanation: 
Middle of linked list is 3.


Example 2: 

Input:
LinkedList: 2->4->6->7->5->1
Output: 7 
Explanation: 
Middle of linked list is 7.


Your Task:
The task is to complete the function getMiddle() which takes a head reference as the only argument and should return the data at the middle node of the linked list.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 5000

*/
//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
/* Link list Node 
struct Node {
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
}; */


// Brute Force Approach
// Time complexity -> O(2n) ~ O(n) and Space -> O(1)
// class Solution{
//     private:
//     int sizeLinkedList(Node *head)
//     {
//         int count=0;
//         while(head!=NULL)
//         {
//             count++;
//             head=head->next;
//         }
//         return count;
//     }
//     public:
//     /* Should return data of middle node. If linked list is empty, then  -1*/
//     int getMiddle(Node *head)
//     {
//         // Your code here
//         int count=sizeLinkedList(head);
//         int pos=count/2;
//         Node *temp=head;
//         while(pos--)
//         {
//             temp=temp->next;
//         }
//         return temp->data;
//     }
// };


// Optimized Approach
// Time complexity -> O(n) and Space -> O(1)
class Solution{
    public:
    /* Should return data of middle node. If linked list is empty, then  -1*/
    int getMiddle(Node *head)
    {
        // Your code here
        Node *slow=head,*fast=head;
        if(head==NULL)
        {
            return head->data;
        }
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow->data;
    }
};




//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        cout << ob.getMiddle(head) << endl;
    }
    return 0;
}

// } Driver Code Ends

/*
1. Question link -- https://practice.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1

2. Solution link -- https://leetcode.com/problems/middle-of-the-linked-list/solutions/3386996/2-approach-easy-c-solution-brute-force-and-optimized-approach/

3. Video link -- https://youtu.be/5blSG0JZNbg
*/