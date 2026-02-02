class Solution {
public:
    void dfs(int i,long curval,long lastval,string num,string exp,vector<string>& ans,int target){
        if(i==num.size()){
            if(target==curval)
                ans.push_back(exp);
            return;
        }

        long last=0;
        for(int j=i;j<num.size();j++){
            if(j>i && num[i]=='0') break;

            string temp=num.substr(i,j-i+1);
            last=last*10+(num[j]-'0');

            if(i==0){
                dfs(j+1,last,last,num,temp,ans,target);
            }
            else{
                dfs(j+1,curval+last,last,num,exp+'+'+temp,ans,target);

                dfs(j+1,curval-last,-last,num,exp+'-'+temp,ans,target);

                dfs(j+1,curval-lastval+lastval*last,last*lastval,num,exp+'*'+temp,ans,target);
            }

        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        dfs(0,0,0,num,"",ans,target);
        return ans;
    }
};