class Solution {
public:
    double myPow(double x, int n) {
        double res=1.0;

        long long tempN=n;

        if(tempN<0)
        {
            tempN=-1*tempN;
        }

        while(tempN!=0)
        {
            if(tempN%2==0)
            {
                x=x*x;
                tempN/=2;
            }
            else
            {
                res*=x;
                tempN=tempN-1;
            }
        }

        if(n<0)
        {
            res=(double)(1.0)/res;
        }

        return res;
    }
};