/*
Implement Queue using array

Implement a Queue using an Array. Queries in the Queue are of the following type:
(i) 1 x   (a query of this type means  pushing 'x' into the queue)
(ii) 2     (a query of this type means to pop element from queue and print the poped element)

Example 1:

Input:
Q = 5
Queries = 1 2 1 3 2 1 4 2
Output: 2 3
Explanation:
In the first test case for query 
1 2 the queue will be {2}
1 3 the queue will be {2 3}
2   poped element will be 2 the 
    queue will be {3}
1 4 the queue will be {3 4}
2   poped element will be 3 

Example 2:

Input:
Q = 4
Queries = 1 3 2 2 1 4   
Output: 3 -1

Explanation:
In the second testcase for query 
1 3 the queue will be {3}
2   poped element will be 3 the
    queue will be empty
2   there is no element in the
    queue and hence -1
1 4 the queue will be {4}. 


Your Task :
You are required to complete the two methods push() which take one argument an integer 'x' to be pushed into the queue and pop() which returns a integer poped out from othe queue. If the queue is empty, it should return -1 on a pop operation. 

Expected Time Complexity: O(1) for both push() and pop().
Expected Auxiliary Space: O(1) for both push() and pop().

Constraints:
1 ≤ Q ≤ 105
1 ≤ x ≤ 105
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct QueueNode
{
    int data;
    QueueNode *next;
};

class MyQueue {
private:
    int arr[100005];
    int front;
    int rear;

public :
    MyQueue(){front=0;rear=0;}
    void push(int);
    int pop();
};

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        MyQueue *sq = new MyQueue();

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            sq->push(a);
        }else if(QueryType==2){
            cout<<sq->pop()<<" ";

        }
        }
        cout<<endl;
    }
    }

// } Driver Code Ends


/* 

The structure of the class is
class MyQueue {
private:
    int arr[100005];
    int front;
    int rear;

public :
    MyQueue(){front=0;rear=0;}
    void push(int);
    int pop();
};
 */

int size=100005;
//Function to push an element x in a queue.
void MyQueue :: push(int x)
{
        // Your Code
        if(rear==size-1)
        {
            return;
        }
        arr[rear]=x;
        rear++;
}

//Function to pop an element from queue and return that element.
int MyQueue :: pop()
{
        // Your Code
        if(front>=rear)
        {
            return -1;
        }
        int x=arr[front];
        front++;
        
        return x;
}

/*
Question link -- https://practice.geeksforgeeks.org/problems/implement-queue-using-array/1
*/