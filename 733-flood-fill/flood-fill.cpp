class Solution {
public:
    void fill(int sr,int sc,int color,int prevcolor,vector<vector<int>>& img){
        if(img[sr][sc]==color)
            return;
        img[sr][sc]=color;
        vector<int> tr={-1,1,0,0};
        vector<int> tc={0,0,-1,1};
        for(int i=0;i<4;i++){
            int nr=sr+tr[i];
            int nc=sc+tc[i];
            if(nr>=0 && nr<img.size() && nc>=0  && nc<img[0].size() && img[nr][nc]==prevcolor){
                fill(nr,nc,color,prevcolor,img);
            }
        }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& img, int sr, int sc, int color) {
        

        fill(sr,sc,color,img[sr][sc],img);

        return img;

    }
};