problem-link:https://www.codingninjas.com/codestudio/problems/search-in-rotated-sorted-array_1082554?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2&leftPanelTab=0




#include<vector>
using namespace std;

int pivoteElement(vector<int>& arr,int n)
{
    int s=0,e=n-1;
    int mid=s+(e-s)/2;
    while(s<e)
    {
        if(arr[mid]>=arr[0])
        {
            s=mid+1;
        }else{
            e=mid;
        }
        mid=s+(e-s)/2;
    }
    return s;
}

int binarySearch(vector<int>& arr,int s,int e,int k){
    int start=s,end=e;
    int mid=start+(end-start)/2;
    while(start<=end)
    {
        if(arr[mid]==k)
        {
            return mid;
        }
        if(arr[mid]>k)
        {
            end=mid-1;
        }else{
            start=mid+1;
        }
        mid=start+(end-start)/2;
    }
    return -1;
}

int findPosition(vector<int>& arr, int n, int k)
{
    // Write your code here.
    // Return the position of K in ARR else return -1.
    int l=pivoteElement(arr, n);
    if(k>=arr[l] && k<=arr[n-1])
    {
        return binarySearch(arr,l,n-1,k);
    }else{
        return binarySearch(arr,0,l-1,k);
    }
}



