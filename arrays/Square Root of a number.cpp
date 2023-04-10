problem link=[https://www.codingninjas.com/codestudio/problems/square-root_893351?source=youtube&campaign=love_babbar_codestudio2&leftPanelTab=0]
       
              
long long int floorSqrt(long long int N)
{
    // Write your code here.
    if(N < 2)

    {

        return N;

    }
    long long int s=0,e=N;
    unsigned long long int mid=s+(e-s)/2;
    long long int ans=-1;
    while(s<=e)
    {
       unsigned long long int sq=mid*mid;
        if((sq)==N)
        {
            return mid;
        }
        if(sq >N)
        {
            e=mid-1;
        }else{
            ans=mid;
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}
