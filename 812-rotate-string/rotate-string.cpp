class Solution {
public:
    bool solve(int i,string s,string goal){
        int x=i,y=0;
        while(y<goal.size()){
            if(s[x]!=goal[y])
                return false;
            x=(x+1)%s.size();
            y++;
        }
        return true;
    }
    bool rotateString(string s, string goal) {
        int a=s.size(), b=goal.size();
        if(a!=b)
            return false;
        for(int i=0;i<a;i++){
            if(s[i]==goal[0]){
                if(solve(i,s,goal))
                    return true;
            }
        }
        return false;
                            // OPTIMISED CODE

        // if(s.size()!=goal.size())
        //     return false;
        // string comp=s+s;
        // int pos=comp.find(goal);       // RETURN THE STARTING INDEX OF MATCHED SUBSTRING
        // if(pos<comp.size())
        //     return true;
        // return false;
                            // INCORRECT CODE
        // int i=0,j=0,val=0;
        // while(s[i]!=goal[j]){
        //         val=i;
        //         i++;
        // }
        // for(int k=val+1;k<s.size();k++){
        //     if(s[k]!=goal[j])
        //         return false;
        //     j++;
        // }
        // for(int k=0;k<val+1;k++){
        //     if(s[k]!=goal[j])
        //         return false;
        //     j++;
        // }
        // return true;
        
    }
};