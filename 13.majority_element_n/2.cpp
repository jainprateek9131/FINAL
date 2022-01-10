using sorting
int majorityElement(vector<int>& a) {               
        sort(a.begin(),a.end());
        int n=a.size();
        if(n==1)return a[0];
        int count=1,ans,m=INT_MIN;
        for(int i=0;i<n-1;i++){
            if(a[i]==a[i+1]){
                count++;
            }else{
                
                count=1;
            }
            if(count>m){
                m=count;
                if(m>(n/2)){
                    return a[i];
                }
            }
        }
        return -1;
    }
