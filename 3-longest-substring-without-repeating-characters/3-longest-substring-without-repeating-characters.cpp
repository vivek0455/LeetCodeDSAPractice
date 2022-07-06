class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_set<int> st;
        int maxlen = INT_MIN;
        
        int l=0, r= s.size();
        if(r==0)return 0;
        for(int i=0;i<r;i++){
            
            if(st.find(s[i]) !=  st.end()){
                while( l<i && st.find(s[i]) != st.end()){
                    st.erase(s[l++]);
                }
            }
            
            st.insert(s[i]);
            maxlen =  max(maxlen, i-l+1);
        }
        return maxlen;
    }
};