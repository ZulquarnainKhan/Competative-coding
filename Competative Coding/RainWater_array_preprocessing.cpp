class Solution {
public:
    int trap(vector<int>& a) {
        int n = a.size();
        vector<int> left(n);
        vector<int> right(n);

        left[0] = a[0];
        for(int i=1;i<n;i++){
            left[i] = max(left[i-1],a[i]);
        }

        right[n-1] = a[n-1];
        for(int i=n-2;i>=0;i--){
            right[i] = max(right[i+1],a[i]);
        }

        int vol = 0;
        for(int i=0;i<n;i++){
            int v = min(right[i],left[i])-a[i];
            vol = vol + v;
        }

        return vol;


    }
};