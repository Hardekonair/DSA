class Solution {
public:
    bool isvalid(int r,int c,int n,vector<string>& temp){

    for(int i=0;i<r;i++){
        if(temp[i][c]=='Q')
            return false;
    }        
    for(int i=r-1,j=c-1;i>=0 && j>=0;i--,j--){
        if(temp[i][j]=='Q')
            return false;
    }
    for(int i=r-1,j=c+1;i>=0 && j<n;i--,j++){
        if(temp[i][j]=='Q')
            return false;
    }
    return true;
    }
    void nqueen(int r,int n,vector<string>& temp,vector<vector<string>>& ans){
        if(r==n){
            ans.push_back(temp);
            return;
        }
        for(int c=0;c<n;c++){
            if(isvalid(r,c,n,temp)){
                temp[r][c]='Q';
                nqueen(r+1,n,temp,ans);
                temp[r][c]='.';
            }
        }
    }
    bool issafe(int r,int c,vector<string>& board,int n){
        int row=r;
        int col=c;
        while(row>=0 && col>=0){
            if(board[row][col]=='Q')
                return false;
            row--;
            col--;
        }
         row=r;
         col=c;
        while( col>=0){
            if(board[row][col]=='Q')
                return false;
            // row--;
            col--;
        }
         row=r;
         col=c;
        while(row<n && col>=0){
            if(board[row][col]=='Q')
                return false;
            row++;
            col--;
        }
        return true;
    }
    void solve(int col,int n,vector<vector<string>>& ans,vector<string>& board){
        if(col==n){
            ans.push_back(board);
            return;
        }

        for(int r=0;r<n;r++){
            if(issafe(r,col,board,n)){
                board[r][col]='Q';
                solve(col+1,n,ans,board);
                board[r][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        vector<vector<string>> ans;
        // solve(0,n,ans,board);
        nqueen(0,n,board,ans);
        return ans;
    }
};