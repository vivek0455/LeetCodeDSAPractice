// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int at[], int dt[], int n)
    {
    	// Your code here
   int platform[2361]={0};

   int required=1;

   for(int i=0;i<n;i++){

       ++platform[at[i]];

       --platform[dt[i]+1];

   }

   for(int i=0;i<2361;i++){

       platform[i]=platform[i]+platform[i-1];

       required=max(required,platform[i]);

   }

   return required;
    }
};


// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  // } Driver Code Ends