/*
Flattening a Linked List

Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:

(i) a next pointer to the next node,

(ii) a bottom pointer to a linked list where this node is head.


Each of the sub-linked-list is in sorted order.
Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order. 


Note: The flattened list will be printed using the bottom pointer instead of the next pointer.
For more clarity have a look at the printList() function in the driver code.

 

Example 1:

Input:
5 -> 10 -> 19 -> 28
|     |     |     | 
7     20    22   35
|           |     | 
8          50    40
|                 | 
30               45

Output:  5-> 7-> 8- > 10 -> 19-> 20->22-> 28-> 30-> 35-> 40-> 45-> 50.

Explanation:
The resultant linked lists has every 
node in a single level.
(Note: | represents the bottom pointer.)
 

Example 2:

Input:
5 -> 10 -> 19 -> 28
|          |                
7          22   
|          |                 
8          50 
|                           
30              

Output: 5->7->8->10->19->22->28->30->50

Explanation:
The resultant linked lists has every node in a single level.

(Note: | represents the bottom pointer.)
 

Your Task:
You do not need to read input or print anything. Complete the function flatten() that takes the head of the linked list as input parameter and returns the head of flattened link list.

Expected Time Complexity: O(N*N*M)
Expected Auxiliary Space: O(N)

Constraints:
0 <= N <= 50
1 <= Mi <= 20
1 <= Element of linked list <= 103
*/

//{ Driver Code Starts
#include <bits/stdc++.h>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}

// } Driver Code Ends


/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */


// Brute Force Approach
// Time complexity -> O(x)*2 + (n*m)log(n*m) and Space -> O(n*m)*2
// where x=n*m
// and n: Number of Horizontal Nodes and m: Number of Vertical Nodes
Node *convertVerticalLinkedList(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *temp = head;
    for(int i=1;i<arr.size();i++)
    {
        Node *newNode=new Node(arr[i]);
        temp->bottom=newNode;
        temp=temp->bottom;
    }
    return head; 
}

Node *flatten(Node *root)
{
    // Your code here
    vector<int> arr;
    Node *temp=root;
    while(temp!=nullptr)
    {
        Node *t2=temp;
        while(t2!=nullptr)
        {
            arr.push_back(t2->data);
            t2=t2->bottom;
        }
        temp=temp->next;
    }
    sort(arr.begin(),arr.end());
    root=convertVerticalLinkedList(arr);
    return root;
}


// Optimized Approach
// Time complexity -> O(2*n*m) and Space -> O(n)
// where n: Number of Horizontal Nodes and m: Number of Vertical Nodes

Node *mergeTwoVerticalLinkedLists(Node* list1, Node* list2)
{
    Node *dummyNode=new Node(-1);
    Node *res=dummyNode;
    while(list1!=nullptr && list2!=nullptr)
    {
        if(list1->data<list2->data)
        {
            res->bottom=list1;
            res=list1;
            list1=list1->bottom;
        }
        else
        {
            res->bottom=list2;
            res=list2;
            list2=list2->bottom;
        }
        res->next=nullptr;
    }
    if(list1!=nullptr)
    {
        res->bottom=list1;
    }
    else
    {
        res->bottom=list2;
    }
    return dummyNode->bottom;
}

Node *flatten(Node *root)
{
    // Your code here
    if(root==nullptr || root->next==nullptr)
    {
        return root;
    }
    Node *mergeHead=flatten(root->next);
    return mergeTwoVerticalLinkedLists(root,mergeHead);
}

/*
1. Question link -- https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1

2. Video Link -- https://youtu.be/ykelywHJWLg
*/