class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int target) {
        bool ans = false;
        
        int c = arr[0].size()-1;
        int r = arr.size()-1;
        for(int i=0; i<=r;i++){
            if(arr[i][c]>= target)
                r = i;
        }
        for(int i=0 ; i<=c ; i++){
            if(arr[r][i]==target)
                return true;
        }
        return false;
    }
};
