class Solution {
public:
    bool isvalid(int i,int j,vector<vector<char>>& board,vector<vector<int>>& vis){
        int n=board.size(), m=board[0].size();
        if((i<n && i>=0) && (j<m && j>=0) && vis[i][j]==0)
            return true;
        return false;
    }

    vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
    bool wordsearch(int i,int j,int k,string& word,vector<vector<char>>& board,vector<vector<int>>& vis){
        if(k==word.size()-1 ){
            return true;
        }
        vis[i][j]=1;
        bool ans=false;
        
        for(int x=0;x<4;x++){
            int ni=i+dir[x][0];
            int nj=j+dir[x][1];
            if(isvalid(ni,nj,board,vis) && word[k+1]==board[ni][nj]){
                ans=ans || wordsearch(ni,nj,k+1,word,board,vis);
                if(ans)
                    return true;
                
            }
        }
        vis[i][j]=0;
        return false;
    }

    bool solve(int r,int c,int k,string s,vector<vector<char>>& board,vector<vector<int>>& vis){
        if(k==s.size())
            return true;

        if(!isvalid(r,c,board,vis) || board[r][c]!=s[k])   
            return false;

        vis[r][c]=1;

        int i=r,j=c;
        bool ans=solve(i,j-1,k+1,s,board,vis) || solve(i-1,j,k+1,s,board,vis) || solve(i+1,j,k+1,s,board,vis) || solve(i,j+1,k+1,s,board,vis);

        vis[i][j]=0;
        return ans;
    }
    
    bool exist(vector<vector<char>>& board,string s){
        vector<vector<int>> vis(board.size(), vector<int>(board[0].size(), 0));

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==s[0])
                    // if(solve(i,j,0,s,board,vis))
                    if(wordsearch(i,j,0,s,board,vis))
                        return true;
                
            }
        }
        return false;
    }
};