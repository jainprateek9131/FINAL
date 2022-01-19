int solve(string st) {
  unordered_set<int>s;
        int l=0,r=0;
        int ans = 0;
        while(r<st.size()){
            if(s.find(st[r])!=s.end()){
                s.erase(st[l]);
                l++;
            }else{
                ans = max(ans,r-l+1);
                s.insert(st[r]);
                r++;
            }
        }
        return ans;
}
