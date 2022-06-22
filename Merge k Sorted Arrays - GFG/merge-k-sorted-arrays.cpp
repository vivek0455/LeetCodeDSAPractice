// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


 // } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeTwoSortedArrays(vector<int> &a, vector<int> &b){
    vector<int> ans;
    int n  = a.size();
    int m  = b.size();
    int i=0, j=0;
    while(i<n && j<m){
        if(a[i]<=b[j]){
            ans.push_back(a[i]);
            i++;
        }else{
            ans.push_back(b[j]);
            j++;
        }
    }
    while(i<n){
        ans.push_back(a[i]);
        i++;
    }
    while(j<m){
        ans.push_back(b[j]);
        j++;
    }
    return ans;
    }

    vector<int> mergeKArrays(vector<vector<int>> kArrays, int k)
    {
        //code here
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> minheap;
    for(int i=0;i<k;i++){
        minheap.push({kArrays[i].size(), kArrays[i]});
    }
    while(minheap.size()>1){
        vector<int> v1 = minheap.top().second;
        minheap.pop();
        vector<int> v2 = minheap.top().second;
        minheap.pop();
        vector<int> v3 = mergeTwoSortedArrays(v1, v2);
        minheap.push({v3.size(), v3});
    }
   
    return minheap.top().second;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}





  // } Driver Code Ends