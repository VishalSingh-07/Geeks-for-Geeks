/*
Reverse a linked list

Given a linked list of N nodes. The task is to reverse this list.

Example 1:

Input:
LinkedList: 1->2->3->4->5->6
Output: 6 5 4 3 2 1
Explanation: After reversing the list, 
elements are 6->5->4->3->2->1.


Example 2:

Input:
LinkedList: 2->7->8->9->10
Output: 10 9 8 7 2
Explanation: After reversing the list,
elements are 10->9->8->7->2.


Your Task:
The task is to complete the function reverseList() with head reference as the only argument and should return new head after reversing the list.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 104

*/

//{ Driver Code Starts
//Initial Template for C++// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};



// } Driver Code Ends
/* Linked List Node structure:

struct Node
{
    int data;
    struct Node *next;
}

*/
// Brute Force Approach
// Method 1: Reversing Element (Swapping)
// Time Complexity -> O(n) and space -> O(n)
// class Solution
// {
//     private:
//     int lengthLinkedList(struct Node *head)
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
//     //Function to reverse a linked list.
//     struct Node* reverseList(struct Node *head)
//     {
//         // code here
//         // return head of reversed list
//         int *Arr,i=0;
//         Arr=(int*)malloc(sizeof(int)*lengthLinkedList(head));
        
//         struct Node *p=head;
//         while(p!=NULL)
//         {
//             Arr[i]=p->data;
//             p=p->next;
//             i++;
//         }
//         p=head;
//         i--;
//         while(p!=NULL)
//         {
//             p->data=Arr[i--];
//             p=p->next;
//         }
//         return head;
//     }
    
// };

// Better Approach
// Method 2: Recursive Method
// Time Complexity -> O(n) and space -> O(n)
// class Solution
// {
//     public:
    
//     //Function to reverse a linked list.
//     struct Node* reverseList(struct Node *head)
//     {
//         // code here
//         // return head of reversed list
//         if(head==NULL || head->next==NULL)
//         {
//             return head;
//         }
        
//         struct Node *newhead=reverseList(head->next);
//         head->next->next=head;
//         head->next=NULL;
        
//         return newhead;
        
//     }
    
// };

// Optimized Approach
// Method 3: Reversing Link
// Time Complexity -> O(n) and space -> O(1)
class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
        struct Node *p=head;
        struct Node *q=NULL;
        struct Node *r=NULL;
        while(p!=NULL)
        {
            r=q;
            q=p;
            p=p->next;
            q->next=r;
        }
        head=q;
        return head;
    }
    
};
    
    


//{ Driver Code Starts.

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
       printf("%d ", temp->data);
       temp  = temp->next;
    }
}

/* Driver program to test above function*/
int main()
{
    int T,n,l,firstdata;
    cin>>T;

    while(T--)
    {
        struct Node *head = NULL,  *tail = NULL;

        cin>>n;
        
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        
        for (int i=1; i<n; i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
        
        Solution ob;
        head = ob. reverseList(head);
        
        printList(head);
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends

/*
1. Question link -- https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1

2. Solution link -- https://leetcode.com/problems/reverse-linked-list/solutions/3364713/3-approach-easy-c-solution-brute-force-better-and-optimized-approach/
*/