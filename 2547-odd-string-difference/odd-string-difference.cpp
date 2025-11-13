class Solution {
public:
    string oddString(vector<string>& words) {
        // // STORING DIFF ARRAY IN MAP
        // int n=words.size();
        // int m=words[0].size();
        // unordered_map<string,vector<int>> mpp;
        // for(int i=0;i<n;i++){
        //     vector<int> temp;
        //     for(int j=0;j<m-1;j++){
        //         temp.push_back(words[i][j+1]-words[i][j]);
        //     }
        //     mpp[words[i]]=temp;
        // }

        // // STORING FREQUENCY OF EACH DIFF ARRAY
        // map<vector<int>, int>freq;
        // for(auto it:mpp)
        //     freq[it.second]++;

        // // FETCHNG DIFF ARRAY WITH UNIQUE FREQ
        // vector<int> target;
        // for(auto it:freq){
        //     if(it.second==1)
        //     target=it.first;
        // }

        // // FINDING STRING CORRESPONDS TO THAT DIF ARRAY
        // for(auto it:mpp)
        //     if(it.second==target)   
        //         return it.first;

        // return "";

        // STORE VECTOR OF DIFF AND THEIR CORRESPONDING WORD IN MAP
        map<vector<int>,vector<string>> mpp;
        int n=words.size();
        int m=words[0].size();
        for(int i=0;i<n;i++){
            vector<int> temp;
            for(int j=0;j<m-1;j++){
                temp.push_back(words[i][j+1]-words[i][j]);
            }
            mpp[temp].push_back(words[i]);
        }

        // RETURN WORD FROM ARRAY CONTAINING SINGLE WORD OR LESS THAN OTHER
        for(auto it:mpp){
            if(it.second.size()==1)
                return it.second[0];
        }
        return "";

    }
};