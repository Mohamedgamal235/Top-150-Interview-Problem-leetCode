class Solution {
    public:
        int mySqrt(int x) {
            double l = 0 , r = x ;
            while (r - l > 1e-9){
                double mid = l + (r - l)/2 ;
                if (sqrt(x) > mid)
                    l = mid ;
                else
                    r = mid ;
            }
            return l + 1e-9 ;
        }
    };