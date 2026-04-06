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
                for(int i=0;i<it;i++){
                    // if({x,y}!={0,0} && st.count({x,y})) break;

                    if(xpos || ypos)
                        (*active)++;
                    else    
                        (*active)--;
                    if(st.count({x,y})){
                        // rollback
                        if(xpos || ypos)
                            (*active)--;
                        else
                            (*active)++;

                        break;
                    }

                }
            }
            ans=max(ans,x*x+y*y);
        }
        return ans;
    }
};