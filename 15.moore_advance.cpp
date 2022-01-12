 got a observation: the maximum mjority element will be at Max 2 because it should be > floor(N/3) times and if you mod(%)  any num with 3 at max u can get 2 as remainder
 ex: 5%3=2{1,1,2,2,0}
5/3=1
  5%3=2
 for n/k these should be n%k maximum element

vector<int> majorityElement(vector<int>& a) {
     int n=a.size();
        vector<int> ans;
        int me1=a[0],c1=1;
        int me2=INT_MIN,c2=0;
        for(int i=1;i<n;i++){
            if(me1==a[i]){
                c1++;
            }
            else if(me2==a[i]){
                c2++;
            }
            else if(c1==0){
                me1=a[i];
                c1=1;
            }
            else if(c2==0){
                me2=a[i];
                c2=1;
            }
            else{
                c1--;c2--;
            }
        }
        c1=0;c2=0;
        for(int i=0;i<n;i++){
            if(me1==a[i])c1++;
            if(me2==a[i])c2++;
        }
        if(c1>n/3)ans.push_back(me1);
        if(c2>n/3)ans.push_back(me2);
        return ans;
    }
