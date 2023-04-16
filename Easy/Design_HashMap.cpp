/*
Design HashMap

Design a HashMap without using any built-in hash table libraries.

To be specific, your design should include these functions:

put(key, value) : Insert a (key, value) pair into the HashMap. If the value already exists in the HashMap, update the value.
get(key): Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
remove(key) : Remove the mapping for the value key if this map contains the mapping for the key.
 
Example 1:

Input:
n = 8
put(1 1) 
put(2 2)
get(1) 
get(3)
put(2 1) 
get(2)
remove(2)
get(2)
Output: 
1
-1
1
-1
Explanation: 
MyHashMap hashMap = new MyHashMap();
hashMap.put(1, 1);          
hashMap.put(2, 2);         
hashMap.get(1);// returns 1
hashMap.get(3);// returns -1 (not found)
hashMap.put(2, 1);// update the existing value
hashMap.get(2);// returns 1 
hashMap.remove(2);// remove the mapping for 2
hashMap.get(2);// returns -1 (not found)


Example 2:

Input:
n = 8
put(1 1) 
put(2 2)
get(1) 
get(2)
put(3 1) 
get(3)
remove(2)
remove(3)
Output: 
1
2
1
Explanation: same explaination as first one. 

Your Task:
You only need to complete the provided function put(), remove(), get(). 

Expected Time Complexity: O(1) for put(), remove(), get().
Expected Auxiliary Space: O(n) for put(), remove(), get().

Constraints:
1 <= q <= 104
1 <= key <= 104
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

// Approach 1 [Using Vector]
// Time complexity -> O(1) and Space -> O(n)
// class MyHashMap {
// public:
//     /** Initialize your data structure here. */
//     vector<int> m;
//     int size;
//     MyHashMap() {
//         size=1e6+1;
//         m.resize(size,-1);
//     }

//     /** value will always be non-negative. */
//     void put(int key, int value) {
//         m[key]=value;
//     }

//     /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
//     int get(int key) {
//         if(m[key]!=-1)
//         {
//             return m[key];
//         }
//         return -1;
//     }

//     /** Removes the mapping of the specified value key if this map contains a mapping for the key */
//     void remove(int key) {
//         m[key]=-1;
//     }

// };



// Approach 2 [Using Vector]
// Time complexity -> O(1) and Space -> O(n)
class MyHashMap {
public:
    /** Initialize your data structure here. */
    vector<list<pair<int,int>>> m;
    int size;
    MyHashMap() {
        size=100;
        m.resize(size);
    }
    
    int hash(int key)
    {
        return key%size;
    }
    list<pair<int,int>> :: iterator search(int key)
    {
        int i=hash(key);
        list<pair<int,int>> :: iterator it=m[i].begin();
        while(it!=m[i].end())
        {
            if(it->first==key)
            {
                return it;
            }
            it++;
        }
        return it;
    }
    /** value will always be non-negative. */
    void put(int key, int value) {
        int i=hash(key);
        remove(key);
        m[i].push_back({key,value});
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int i=hash(key);
        list<pair<int,int>> :: iterator it=search(key);
        if(it==m[i].end())
        {
            return -1;
        }
        return it->second;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int i=hash(key);
        list<pair<int,int>> :: iterator it=search(key);
        if(it!=m[i].end())
        {
            m[i].erase(it);
        }
    }

};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        MyHashMap obj;
        int q;
        cin >> q;
        while (q--) {
            string s;
            cin >> s;
            if (s == "put") {
                int key, val;
                cin >> key >> val;
                obj.put(key, val);
            }
            else if ( s == "remove") {
                int key;
                cin >> key;
                obj.remove(key);
            }
            else {
                int key;
                cin >> key;
                cout << obj.get(key) << endl;
            }
        }
}
    return 0;
}

// } Driver Code Ends


/*
1. Question link -- https://practice.geeksforgeeks.org/problems/design-hashmap/1

2. Solution link -- https://leetcode.com/problems/design-hashmap/solutions/3423030/2-approach-easy-c-solution-solve-using-vector-and-hashing-method/

3. Video link -- https://youtu.be/xVEGczCJCHs

*/