#include<bits/stdc++.h>
using namespace std;


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}


class Solution
{
    public:
    
        int prime=101;
    
        long long calculateHash(string pattern){
            long long hash=0;
            
            for(int i=0;i<pattern.length();i++){
                hash=hash+((pattern[i])*pow(prime,i));
            }
            return hash;
        }
        
        long long updateHash(long long prevHash,char oldChar,char newChar,int patternLength){
            long long newHash=(prevHash-oldChar)/prime;
            newHash=newHash+newChar*pow(prime,patternLength-1);
            return newHash;
        }
        
        vector <int> search(string pattern, string text)
        {
            int length_pattern=pattern.length();
            int length_text=text.length();
            vector<int> ans;
            
            long long patternHash=calculateHash(pattern);
            long long textHash=calculateHash(text.substr(0,length_pattern));
            
            for(int i=0;i<=length_text-length_pattern;i++){
                if(textHash==patternHash){
                    if(text.substr(i,length_pattern)==pattern){
                        ans.push_back(i+1);
                    }
                }
                if(i<length_text-length_pattern){
                    textHash=updateHash(textHash,text[i],text[i+length_pattern],length_pattern);
                }
            }
            return ans;
        }
     
};
