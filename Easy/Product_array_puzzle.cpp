//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++

// Brute Force Approach
// Time complexity --> O(n^2) and Space --> O(1)
class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here    
        vector<long long int> ans;
        for(int i=0;i<n;i++)
        {
            long long int product=1;
            for(int j=0;j<n;j++)
            {
                if(i!=j)
                {
                    product*=nums[j];
                }
            }
            ans.push_back(product);
        }
        return ans;
    }
};


// Better Approach 
// Time complexity --> O(n) and Space --> O(1)
class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here    
        long long int product=1;
        int countZero=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                countZero++;
            }
            else
            {
                product*=nums[i];
            }
        }
        if(countZero==0)
        {
            for(int i=0;i<n;i++)
            {
                nums[i]=product/nums[i];
            }
        }
        else if(countZero==1)
        {
            for(int i=0;i<n;i++)
            {
                if(nums[i]==0)
                {
                    nums[i]=product;
                }
                else
                {
                    nums[i]=0;
                }
                
            }
        }
        else
        {
            for(int i=0;i<n;i++)
            {
                nums[i]=0;
            }
        }
        
        return nums;
    }
};

/*
This above ❌ approach is not allowed according to the question 
because in the question it clearly mentioned that we have to solve a 
problem without using the division operation. But approach follow division 
operation to solve a problem.
*/

// Prefix and Suffix Product Approach
// Time complexity --> O(n) and Space --> O(n)
class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here    
        vector<long long int> ans(n);
        vector<long long int> left(n);
        vector<long long int> right(n);
        left[0]=1;
        for(int i=1;i<n;i++)
        {
            left[i]=left[i-1]*nums[i-1];
        }
        right[n-1]=1;
        for(int i=n-2;i>=0;i--)
        {
            right[i]=right[i+1]*nums[i+1];
        }
        for(int i=0;i<n;i++)
        {
            ans[i]=left[i]*right[i];
        }
        return ans;
    }
};


// Optimized Approach
// Time complexity --> O(n) and Space --> O(1)
class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here    
        vector<long long int> ans;
        long long int product=1;
        if(n<1)
        {
            return ans;
        }
        for(int i=0;i<n;i++)
        {
            product*=nums[i];
            ans.push_back(product);
        }
        product=1;
        for(int i=n-1;i>0;i--)
        {
            ans[i]=ans[i-1]*product;
            product*=nums[i];
        }
        ans[0]=product;
        return ans;
    }
};





//{ Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends

/*
1. Question link -- https://practice.geeksforgeeks.org/problems/product-array-puzzle4525/1

2. My Solution link -- 

            i)  https://leetcode.com/problems/product-of-array-except-self/solutions/3225593/4-approach-easy-c-solution-brute-force-optimized-prefix-suffix-product-approach/

            ii) https://leetcode.com/problems/product-of-array-except-self/solutions/3186745/best-c-3-solution-dp-space-optimization-brute-force-optimize-one-stop-solution/

3. Video Link -- https://youtu.be/gREVHiZjXeQ
*/