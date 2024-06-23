class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        vector<bool> ans;
        int maxy = 0;
        map<int,int> mp;
        for(auto i:queries){
            if(i[0] == 1){ mp[i[1]] = 1; maxy = max(maxy,i[1]);}
            else{
                if(i[2] > i[1]){
                    ans.push_back(false);
                }
                else{
                    int start = i[1] - i[2];
                    if(maxy <= start){
                        ans.push_back(true);
                    }
                    else{
                        int end = i[1];
                        int pos = 1;
                        while(start >= 0){
                            auto x = mp.lower_bound(start+1);
                            if(x->first >= start + i[2]){
                                ans.push_back(true);
                                pos = 0;
                                break;
                            }
                            else{
                                end = x->first;
                                start = x->first - i[2];
                            }
                        }
                        if(pos) ans.push_back(false);
                    }
                }
            }
        }
        return ans;
    }
};