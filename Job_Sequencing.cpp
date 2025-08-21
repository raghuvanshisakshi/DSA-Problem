class Solution {
  public:
  static bool cmp(pair<int,int>&a, pair<int,int>& b){
      return a.second>b.second;
  }
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int sum  = 0;
        unordered_map<int,int>mpp;
        vector<pair<int,int>>vp;
        
        for(int i=0; i<deadline.size(); i++){
            vp.push_back(make_pair(deadline[i],profit[i]));
        }
        
        sort(vp.begin(),vp.end(),cmp);
        int maxi = INT_MIN;
        for(int i=0; i<vp.size(); i++){
            maxi = max(maxi, vp[i].first);
        }
        vector<int>slot(maxi+1,-1);
        int count  = 0;
        for(int i=0; i<vp.size(); i++){
            int m = vp[i].first;
            int s = vp[i].second;
            for(int d = m; d>0; d--){
                if(slot[d]==-1){
                    slot[d] = i;
                    count++;
                    sum = sum+s;
                    break;
                }
            }
        }
        return {count,sum};
    }
};











