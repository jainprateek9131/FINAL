int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        if(nums.empty())return 0;
        int ans = 1;
        int count=0;
        for(auto it:nums)
            s.insert(it);
        for(int i=0;i<nums.size();i++){
            count=1;
            if(s.find(nums[i]-1)==s.end()){
                int cur_num=nums[i];
                while(s.find(cur_num+1)!=s.end()){
                    count++;
                    cur_num++;
                }
                ans=max(ans,count);
            }
        }
        return ans;
    }
