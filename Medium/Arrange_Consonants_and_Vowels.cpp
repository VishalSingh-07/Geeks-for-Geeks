/*
Arrange Consonants and Vowels

Given a singly linked list having n nodes containing english alphabets ('a'-'z'). Rearrange the linked list in such a way that all the vowels come before the consonants while maintaining the order of their arrival. 

Example 1:

Input:
n = 9
linked list: a -> b -> c -> d -> e -> f -> g -> h -> i 
Output: 
a -> e -> i -> b -> c -> d -> f -> g -> h
Explanation: 
After rearranging the input linked list according to the condition the resultant linked list will be as shown in output.


Example 2:

Input:
n = 8
linked list: a -> b -> a -> b -> d -> e -> e -> d 
Output: 
a -> a -> e -> e -> b -> b -> d -> d
Explanation: 
After rearranging the input linked list according to the condition the resultant linked list will be as shown in output.

Your Task:
- Your task is to complete the function arrangeCV(), which takes head of linked list and arranges the list in such a way that all the vowels come before the consonants while maintaining the order of their arrival and returns the head of the updated linked list.

Expected Time Complexity :  O(n)
Expected Auxiliary Space :  O(1)

Constraints:
- 1 <= n <= 104
- 'a' <= elements of linked list <= 'z'
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printlist(Node *head) {
    if (head == NULL)
        return;
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void append(struct Node **headRef, char data) {
    struct Node *new_node = new Node(data);
    struct Node *last = *headRef;

    if (*headRef == NULL) {
        *headRef = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}


// } Driver Code Ends
/*
Structure of the node of the linked list is as
struct Node
{
    char data;
    struct Node *next;

    Node(char x){
        data = x;
        next = NULL;
    }

};
*/

// Brute Force Approach
// Time complexity -> O(3n) ~ O(n) and Space -> O(n)
class Solution {
  public:
    // task is to complete this function
    // function should return head to the list after making
    // necessary arrangements
    struct Node* arrangeCV(Node* head) {
        // Code here
        vector<char> vows,conso;
        while(head!=nullptr){
            if(head->data=='a' || head->data=='e' || head->data=='i' || head->data=='o'
                || head->data=='u'){
                  vows.push_back(head->data);
            }else{
                conso.push_back(head->data);
            }
            head=head->next;
        }
        Node* dummy=new Node(-1);
        Node* temp=dummy;
        for(int i=0;i<vows.size();i++){
            Node* nextNode=new Node(vows[i]);
            temp->next=nextNode;
            temp=temp->next;
        }
        for(int i=0;i<conso.size();i++){
            Node* nextNode=new Node(conso[i]);
            temp->next=nextNode;
            temp=temp->next;
        }
        return dummy->next;
    }
};


// Optimized Approach
// Time complexity -> O(n) and Space -> O(1)
class Solution {
  public:
    // task is to complete this function
    // function should return head to the list after making
    // necessary arrangements
    struct Node* arrangeCV(Node* head) {
        // Code here
        Node *vowel=new Node('a');
        Node *vowelHead=vowel;
        Node *conso=new Node('b');
        Node *consoHead=conso;
        
        while(head!=nullptr){
            char temp=head->data;
            if(temp=='a' || temp=='e' || temp=='i' || temp=='o' || temp=='u'){
                vowel->next=head;
                vowel=vowel->next;
            }else{
                conso->next=head;
                conso=conso->next;
            }
            head=head->next;
        }
        conso->next=nullptr;
        vowel->next=consoHead->next;
        return vowelHead->next;
    }
};



//{ Driver Code Starts.

// task is to complete this function
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        char tmp;
        struct Node *head = NULL;
        cin >> n;
        while (n--) {
            cin >> tmp;
            append(&head, tmp);
        }
        Solution obj;
        head = obj.arrangeCV(head);
        printlist(head);
    }
    return 0;
}

// } Driver Code Ends


/*
1. Question link -- https://www.geeksforgeeks.org/problems/arrange-consonants-and-vowels/1

2. Video Link -- https://youtu.be/wEOXxScGrsQ?feature=shared
*/