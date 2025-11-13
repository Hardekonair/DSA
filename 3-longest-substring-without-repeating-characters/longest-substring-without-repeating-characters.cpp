class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        

        // TAKING TWO POINTER TO FIND SUBSTRING
        int i=0,j=0;
        unordered_map<char,int> mpp;
        int maxlen=0;
        while(j<=s.size()){
            while(j<s.size() && mpp.find(s[j])==mpp.end()){
                mpp[s[j]]=j;
                j++;
            }
            maxlen=max(maxlen,j-i);
            i=max(i,mpp[s[j]]+1);
            mpp[s[j]]=j;
            j++;
        }
        return maxlen;


        // int n=0;
        // while(s[n]!='\0')
        //     n++;

        // int lastind[256];

        // for(int i=0;i<256;i++){
        //     lastind[i]=-1;
        // }

        // int maxi=0,start=0;


        // for(int i=0;i<n;i++){

        //     if(lastind[s[i]]>=start)
        //         start=lastind[s[i]]+1;

        //     lastind[s[i]]=i;

        //     int len=i-start+1;
        //     if(len>maxi)
        //         maxi=len;
        // }

        // return maxi;
        


        // int n=s.size();
        // int maxi=0;
        // for(int i=0;i<n;i++){
        //     unordered_map<char,int> mpp;
        //     for(int j=i;j<n;j++){
        //         if(mpp[s[j]]==1)
        //             break;
        //         mpp[s[j]]++;
        //         maxi=max(maxi,j-i+1);
        //     }
        // }
        // return maxi;


        // int n=s.size();
        // int maxi=0;
        // for(int i=0;i<n;i++){
        //     unordered_map<char,int> mpp;
        //     bool booli=true;
        //     while(booli){
        //         for(int j=i;j<n;j++){
        //             if(mpp[s[j]]==1 )
        //                 break;
        //             mpp[s[j]]++;
                    
        //         }
        //         int len=0;
        //         for(auto it:mpp){
        //             if(it.second==1)
        //                 len++;
        //         }
        //         maxi=max(len,maxi);
        //         booli=false;
        //     }

        // }
        // return maxi;
        
    }
};