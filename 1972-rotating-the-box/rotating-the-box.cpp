class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int r=box.size(),c=box[0].size();
        vector<vector<char>>grid(c,vector<char>(r,'.'));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                grid[j][r-1-i]=box[i][j];
            }
        }
                                    // USING QUEUE
        // for(int col=0;col<r;col++){
        //     queue<pair<int,int>>q;
        //     for(int row=0;row<c;row++){
        //         if(grid[row][col]=='#')
        //             q.push({row,col});
                
        //         else if(grid[row][col]=='*')
        //             q=queue<pair<int,int>>();   // to make entire queue empty
                
        //         else if(grid[row][col]=='.' && !q.empty()){
        //             int ro=q.front().first, co=q.front().second;
        //             q.pop();
        //             grid[row][col]='#';
        //             grid[ro][co]='.';
        //             q.push({row,col});
        //         }
        //     }
        // }

                                        // DIRECT GRAVITY
        for(int col=0;col<r;col++){
            int bottom=c-1;
            for(int row=c-1;row>=0;row--){
                if(grid[row][col]=='#'){
                    if(row!=bottom)
                        swap(grid[row][col],grid[bottom][col]);
                    bottom--;
                }
                else if(grid[row][col]=='*'){
                    bottom=row-1;
                }
            }
        }
        return grid;
    }
};