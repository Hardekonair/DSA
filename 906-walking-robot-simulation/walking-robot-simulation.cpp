class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x=0,y=0;
        int *active=&y;
        int ans=0;
        bool xpos=false,ypos=true,xneg=false,yneg=false;
        set<pair<int,int>>st;
        for(auto it:obstacles){
            st.insert({it[0],it[1]});
        }

        for(auto it:commands){
            if(it==-1){
                active=active==&x?&y:&x;
                if(xpos){
                    xpos=false;
                    yneg=true;
                }
                else if(ypos){
                    xpos=true;
                    ypos=false;
                }
                else if(xneg){
                    ypos=true;
                    xneg=false;
                }
                else if(yneg){
                    xneg=true;
                    yneg=false;
                }
            }
            else if(it==-2){
                active=active==&x?&y:&x;
                if(xpos){
                    xpos=false;
                    ypos=true;
                }
                else if(ypos){
                    xneg=true;
                    ypos=false;
                }
                else if(xneg){
                    yneg=true;
                    xneg=false;
                }
                else if(yneg){
                    xpos=true;
                    yneg=false;
                }
            }
            else{
                for(int i = 0; i < it; i++){

                    int nx = x, ny = y;

                    if(xpos) nx++;
                    else if(ypos) ny++;
                    else if(xneg) nx--;
                    else if(yneg) ny--;

                    if(st.count({nx, ny})) break;

                    // safe → move
                    x = nx;
                    y = ny;
                }
            }
            ans=max(ans,x*x+y*y);
        }
        return ans;
    }
};