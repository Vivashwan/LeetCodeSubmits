class Solution {
private:
    long long func(long long n)
    {
        if(n==1)
        {
            return 0;
        }

        long long ans = 0;

        if(n%2==0)
        {
            ans+=1+func(n/2);
        }
        else
        {
           ans+= 1+ min(func(n-1), func(n+1));
        }

        return ans;
    }
public:
    int integerReplacement(int n) 
    {
        return func(n);
    }
};