class Solution {
public:
    char fn(string s){
        int i=0;
        stack<char>stb;
        stack<char>stc;
        
        for(auto it:s){
            
            if(it==')'){
                int tcount=false;
                int fcount=false;
                while(stb.top()!='('){
                    if(stb.top()=='t')
                        tcount=true;
                    else if(stb.top()=='f')
                        fcount=true;
                    stb.pop();
                }
                stb.pop();
                if(stc.top()=='&'){
                    if(fcount){
                        stb.push('f');
                    }
                    else{
                        stb.push('t');
                    }
                }
                else if(stc.top()=='|'){
                    if(tcount)
                        stb.push('t');
                    else
                        stb.push('f');
                }
                else{
                    if(tcount)
                    stb.push('f');
                    else    
                    stb.push('t');
                }
                stc.pop();
            }
            else{
                if(it=='t' || it=='f' || it=='(')
                    stb.push(it);
                else if(it=='&' || it=='|' || it=='!')
                    stc.push(it);
            }
        }

        return stb.top();
    }
    char solve(vector<char> arr,char op){
        int n=arr.size();
        if(op=='!'){
            if(arr[0]=='t')
                return 'f';
            else 
                return 't';
        }
        else if(op=='&'){
            for(int i=0;i<n;i++){
                if(arr[i]=='f')
                    return 'f';
            }
            return 't';
        }
        else if(op=='|'){
            for(int i=0;i<n;i++){
                if(arr[i]=='t')
                    return 't';
            }
            return 'f';
        }
        return '?';        // Never execute;
    }
    bool parseBoolExpr(string exp) {
        // stack<char> st;
        // for(char it:exp){
        //     if(it==',')
        //         continue;
        //     if(it==')'){
        //         vector<char> vec;
        //         while(st.top()!='('){
        //             vec.push_back(st.top());
        //             st.pop();
        //         }
        //         st.pop();   // removing opening parenthesis
        //         char op=st.top();
        //         st.pop();
        //         st.push(solve(vec,op));
        //     }
        //     else
        //         st.push(it);
        // }
        // return st.top()=='t'?true:false;

        char x=fn(exp);
        if(x=='t')  
            return true;
        return false;
        
    }
};