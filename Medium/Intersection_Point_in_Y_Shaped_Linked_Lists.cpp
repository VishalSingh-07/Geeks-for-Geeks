/*
Intersection Point in Y Shaped Linked Lists

Given two singly linked lists of size N and M, write a program to get the point where two linked lists intersect each other.

 

Example 1:

Input:
LinkList1 = 3->6->9->common
LinkList2 = 10->common
common = 15->30->NULL
Output: 15
Explanation:
Y ShapedLinked List


Example 2:

Input: 
Linked List 1 = 4->1->common
Linked List 2 = 5->6->1->common
common = 8->4->5->NULL
Output: 8
Explanation: 

4              5
|              |
1              6
 \             /
  8   -----  1 
   |
   4
   |
  5
  |
  NULL       
Your Task:
You don't need to read input or print anything. The task is to complete the function intersectPoint() which takes the pointer to the head of linklist1(head1) and linklist2(head2) as input parameters and returns data value of a node where two linked lists intersect. If linked list do not merge at any point, then it should return -1.
Challenge : Try to solve the problem without using any extra space.

 

Expected Time Complexity: O(N+M)
Expected Auxiliary Space: O(1)

 

Constraints:
Length of Both linkedList before intersection(if any) is greater than 0.
2 ≤ N + M ≤ 2*105
-1000 ≤ value ≤ 1000

 
*/

//{ Driver Code Starts
#include<iostream>

#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

vector<int> take(int n){
    vector<int> ans(n);
    for(int i=0;i<n;i++) cin>>ans[i];
    return ans;
}

Node* inputList(int size, vector<int> v)
{
    if(size==0) return NULL;
    
    int val = v[0];
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        val = v[i+1];
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

/* Driver program to test above function*/
int main()
{
    srand(time(0));
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        
        int p = rand()%3;
        
        vector<int> v1 = take(n1);
        vector<int> v2 = take(n2);
        vector<int> v3 = take(n3);
        
        
        Node* head1 = NULL;
        Node* head2 = NULL;
        Node* common = NULL;
        
        if(p==0){
            common = inputList(n3, v3);
            head1 = inputList(n1, v1);
            head2 = inputList(n2, v2);
        }
        else if(p==1){
            
            head1 = inputList(n1, v1);
            common = inputList(n3, v3);
            head2 = inputList(n2, v2);
        }
         else{
            
            head1 = inputList(n1, v1);
            head2 = inputList(n2, v2);
            common = inputList(n3, v3);
        }
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}


// } Driver Code Ends


/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

//Function to find intersection point in Y shaped Linked Lists.

// Brute Force Approach
// Time complexity -> O(n + m) and Space -> O(n) or O(m)
// where n: Length of the LinkedList head1 and m: Length of the LinkedList head2
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    unordered_map<Node*,int> mpp;
    Node *temp;
    temp=head1;
    while(temp!=nullptr)
    {
        mpp[temp]=1;
        temp=temp->next;
    }
    temp=head2;
    while(temp!=nullptr)
    {
        if(mpp.find(temp)!=mpp.end())
        {
            return temp->data;
        }
        temp=temp->next;
    }
    return -1;
}


// Better Approach
// Time complexity -> O(n + 2m) and Space -> O(1)
// where n: Length of the LinkedList head1 and m: Length of the LinkedList head2
int collisionPoint(Node *small, Node *large, int diff)
{
    while(diff)
    {
        diff--;
        large=large->next;
    }
    while(small!=large)
    {
        small=small->next;
        large=large->next;
    }
    return (small && large) ? small->data : -1;
}
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    Node *temp1=head1,*temp2=head2;
    int n=0,m=0;
    while(temp1!=nullptr)
    {
        n++;
        temp1=temp1->next;
    }
    while(temp2!=nullptr)
    {
        m++;
        temp2=temp2->next;
    }
    if(n<m)
    {
        // return collisionPoint(smaller Length LinkedList,Larger Length LinkedList,m-n);
        return collisionPoint(head1,head2,m-n);
    }
    else
    {
        // return collisionPoint(smaller Length LinkedList,Larger Length LinkedList,n-m);
        return collisionPoint(head2,head1,n-m);
    }
}

// Optimized Approach
// Time complexity -> O(n + m) and Space -> O(1)
// where n: Length of the LinkedList head1 and m: Length of the LinkedList head2
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    if(head1==nullptr || head2==nullptr)
    {
        return -1;
    }
    Node *temp1=head1,*temp2=head2;
    while(temp1!=temp2)
    {
        temp1=temp1->next;
        temp2=temp2->next;
        
        if (temp1 == temp2)
        {
            if (temp1 != nullptr)
            {
                return temp1->data;
            }
            else
            {
                return -1;  // One of the lists is exhausted, no intersection
            }
        }
        if(temp1==nullptr)
        {
            temp1=head2;
        }
        if(temp2==nullptr)
        {
            temp2=head1;
        }
    }
    return (temp1 != nullptr) ? temp1->data : -1;
}



/*
1. Question Link -- https://www.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1

2. Solution Link -- https://leetcode.com/problems/intersection-of-two-linked-lists/solutions/4722278/detailed-solution-easy-c-solution-3-approach-dry-run-using-figure

3. Video Link -- https://youtu.be/0DYoPz2Tpt4
*/