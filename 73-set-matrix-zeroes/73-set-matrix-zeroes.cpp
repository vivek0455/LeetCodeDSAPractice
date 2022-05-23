class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool flag = false;
        
        for(int i=0;i<matrix.size();i++){
            if(matrix[i][0]==0){
                flag=true;
            }
            for(int j=1;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
         
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
    // if first cell is set zero then whole  row or column will set zero
        // Row check
        for(int i=1;i<matrix.size();i++){
            
            for(int j=1;j<matrix[0].size();j++){
                if(matrix[i][0]==0 || matrix[0][j]==0){
         
                     matrix[i][j]=0;
                }
            }
        }
        // cout<<matrix[i][j];
        int i=0, j=0;
        if(matrix[0][0]==0){
            for(j=0;j<matrix[0].size();j++){
                matrix[0][j]=0;
            } 
        }
        if(flag){
            for( i=0;i<matrix.size();i++){
                matrix[i][0]=0;
            }
        }
    }
};