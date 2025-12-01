class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& board,vector<vector<int>> &vis){
        vis[i][j]=1;
        vector<int> tr={-1,1,0,0};
        vector<int> tc={0,0,-1,1};
        for(int k=0;k<4;k++){
            int nr=i+tr[k];
            int nc=j+tc[k];
            if(nr>=0 && nr<board.size() && nc>=0 && nc<board[0].size() 
            && vis[nr][nc]==0 && board[nr][nc]=='O')
                dfs(nr,nc,board,vis);
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            if(board[i][0]=='O')
                dfs(i,0,board,vis);
            
            if( board[i][m-1]=='O')
                dfs(i,m-1,board,vis);
        }
        for(int i=0;i<m;i++){
            if(board[0][i]=='O')
                dfs(0,i,board,vis);
            
            if(board[n-1][i]=='O')
                dfs(n-1,i,board,vis);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]!=1)
                    board[i][j]='X';
            }
        }
    }
};