int majorityElement(vector<int>& a) {               
        int me=a[0],c=1;
        int n=a.size();
        for(int i=1;i<n;i++){
            if(a[i]==me){
                c++;
            }
            else{
                c--;
            }
            if(c==0){
                me=a[i];
                c=1;
            }
        }c=0;
        for(int i=0;i<n;i++){
            if(a[i]==me)c++;
        }
        if(c>(n/2))return me;
        else return -1;
    }
