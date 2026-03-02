class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<int>trailingZeros;
        for(int i=0;i<m;i++){
            int czero=0;
            for(int j=n-1;j>=0;j--){
                if(grid[i][j]==1)
                    break;
                czero++;                
            }
            trailingZeros.push_back(czero);
        }
        int swaps=0;
        for(int i=0;i<n;i++){
            int req=n-1-i;
            int j=i;
            while(j<n && trailingZeros[j]<req)
                j++;
            if(j==n)        
                return -1;

            while(j!=i){
                swap(trailingZeros[j],trailingZeros[j-1]);
                j--;
                swaps++;
            }
        }
        return swaps;
    }
};