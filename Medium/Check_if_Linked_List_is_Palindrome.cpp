/*
Check if Linked List is Palindrome

Given a singly linked list of size N of integers. The task is to check if the given linked list is palindrome or not.

Example 1:

Input:
N = 3
value[] = {1,2,1}
Output: 1
Explanation: The given linked list is
1 2 1 , which is a palindrome and
Hence, the output is 1.


Example 2:

Input:
N = 4
value[] = {1,2,3,4}
Output: 0
Explanation: The given linked list
is 1 2 3 4 , which is not a palindrome
and Hence, the output is 0.


Your Task:
The task is to complete the function isPalindrome() which takes head as reference as the only parameter and returns true or false if linked list is palindrome or not respectively.

Expected Time Complexity: O(N)
Expected Auxialliary Space Usage: O(1)  (ie, you should not use the recursive stack space as well)

Constraints:
1 <= N <= 105
*/


//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
#include <bits/stdc++.h>
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

// Brute Force Approach
// Time complexity -> O(n) and Space -> O(n)
// class Solution{
//   public:
//     //Function to check whether the list is palindrome.
//     bool isPalindrome(Node *head)
//     {
//         //Your code here
//         vector<int> ans;
//         if(head==NULL || head->next==NULL)
//         {
//             return true;
//         }
        
//         while(head!=NULL)
//         {
//             ans.push_back(head->data);
//             head=head->next;
//         }
//         for(int i=0;i<ans.size()/2;i++)
//         {
//             if(ans[i]!=ans[ans.size()-i-1])
//             {
//                 return false;
//             }
//         }
//         return true;
        
//     }
// };

// Better Approach
// Time complexity -> O(n) and Space -> O(n)
// class Solution{
//   public:
//     //Function to check whether the list is palindrome.
//     bool isPalindrome(Node *head)
//     {
//         //Your code here
//         Node *r_head=NULL;
//         Node *ptr=head;
//         while(ptr!=NULL)
//         {
//             Node *temp=new Node(ptr->data);
//             temp->next=r_head;
//             r_head=temp;
//             ptr=ptr->next;
//         }
//         while(r_head!=NULL && head!=NULL)
//         {
//             if(r_head->data!=head->data)
//             {
//                 return false;
//             }
//             r_head=r_head->next;
//             head=head->next;
//         }
//         return true;
        
//     }
// };


// Optimized Approach
// Time complexity -> O(n) and Space -> O(1)
class Solution{
private:
    Node *reverseList(Node *head)
    {
        Node *p=head,*q=NULL,*r=NULL;
        while(p!=NULL)
        {
            r=q;
            q=p;
            p=p->next;
            q->next=r;
        }
        return q;
    }
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        Node *slow=head,*fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=reverseList(slow->next);
        slow=slow->next;
        while(slow!=NULL)
        {
            if(slow->data!=head->data)
            {
                return false;
            }
            head=head->next;
            slow=slow->next;
        }
        return true;
        
    }
};


//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends

/*

1. Question link -- https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1

2. Solution link -- https://leetcode.com/problems/palindrome-linked-list/solutions/3398025/3-approach-easy-c-solution-brute-force-better-and-optimized-approach/

3. Video link -- https://youtu.be/-DtNInqFUXs
*/