
#include<iostream>
using namespace std;


// 557. Reverse Words in a String III 
#include<string>
#include<<sstream>
string reverseWords(string s) {
        stringstream ss(s);
        string temp, ans;
        while(ss>>temp){
            reverse(temp.begin(),temp.end());
            ans+=temp+" ";
        }
        return ans.substr(0,ans.size()-1);
    }



// 2038.  Remove Colored Pieces if Both Neighbours are the Same Color    
bool winnerOfGame(string colors) {
        int count=0,alice_plays=0,bob_plays=0;
        for(int i=1;i<colors.size();i++){
            if(colors[i-1]==colors[i]){
                count++;
            }
            else{
                if(colors[i-1]=='A'){
                    alice_plays+=max(0,count-1);
                }else{
                    bob_plays+=max(0,count-1);
                }
                count=0;
            }
        }
        if(colors.back()=='A'){
            alice_plays+=max(0,count-1);
        }else{
            bob_plays+=max(0,count-1);
        }
        return alice_plays>bob_plays;
    }




// 1512. Number of Good Pairs  
int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int>mp;
        int ans=0;
        for(int num:nums){
            ans+=mp[num]++;
        }
        return ans;
    }




    // 229. Majority Element II 
     vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size();
        int x=n/3;
        for(auto num:nums){
            mp[num]++;
        }
        vector<int>ans;
        for(auto a:mp){
            int element=a.first;
            int count=a.second;
            if(count>x){
                ans.push_back(element);
            }
        }
        return ans;
    }




    // 343. Integer Break  
    int integerBreak(int n) {
        if(n<=3){
            return n-1;
        }
        int quotient=n/3,remainder=n%3;
        if(remainder==0){
            return pow(3,quotient);
        }
        else if(remainder==1){
            return pow(3,quotient-1)*4;
        }
        return pow(3,quotient)*2;
    }



// 2009. Minimum Number of Operations to Make Array Continuous  
int minOperations(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> uniqueNums(nums.begin(),unique(nums.begin(),nums.end()));
        int ans=INT_MAX;
        for(int i=0;i<uniqueNums.size();i++){
            int s=uniqueNums[i];
            int e= s+n-1;
            auto it=upper_bound(uniqueNums.begin(),uniqueNums.end(),e);
            int idx=distance(uniqueNums.begin(),it);
            ans=min(ans,n-(idx-i));
        }
        return ans;
    }




    // 2251. Number of Flowers in Full Bloom 
     vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> start,end;
        for(auto i:flowers){
            start.push_back(i[0]);
            end.push_back(i[1]);
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        vector<int>res;
        for(int p:people){
            int s=upper_bound(start.begin(),start.end(),p)-start.begin();
            int e=lower_bound(end.begin(),end.end(),p)-end.begin();
            res.push_back(s-e);
        }
        return res;
    }




    

// 1095. Find in Mountain Array   
int findInMountainArray(int target, MountainArray &mountainArr) {
        int s=0,e=mountainArr.length()-1;
        int mid=s+(e-s)/2;
        while(s<e){
            if(mountainArr.get(mid)<mountainArr.get(mid+1)){
                s=mid+1;
            }else{
                e=mid;
            }
            mid= s+(e-s)/2;
        }
        int peak=mid;
        s=0,e=peak;
        int left=-1;
        mid=s+(e-s)/2;
        while(s<=e){
            int middle= mountainArr.get(mid);
            if(middle==target){
                left=mid;
            }if(middle<target){
                s=mid+1;
            }else{
                e=mid-1;
            }
            mid=s+(e-s)/2;
        }
        int right=-1;
        s=peak;
        e=mountainArr.length()-1;
        mid=s+(e-s)/2;
        while(s<=e){
            int middle=mountainArr.get(mid);
            if(middle==target){
                right=mid;
            }if(middle>target){
                s=mid+1;
            }else{
                e=mid-1;
            }
            mid=s+(e-s)/2;
        }
        if(left==right){
            return left;
        }else if(left!=-1){
            return left;
        }else{
            return right;
        }




// 2742. Painting the Walls 
int func(vector<int>& cost, vector<int>& time, int i, int bank, vector<vector<int>>&dp){
        if(bank<=0){
            return 0;
        }
        if(i>=time.size()){
            return 1e9;
        }
        if(dp[i][bank]!=-1){
            return dp[i][bank];
        }
        else{
            int take=func(cost,time,i+1,bank,dp);
            int notTake=cost[i]+func(cost,time,i+1,bank-time[i]-1,dp);
            return dp[i][bank]=min(take,notTake);
        }
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        vector<vector<int>>dp(501,vector<int>(501,-1));
        return func(cost,time,0,time.size(),dp);
    }





// 1269. Number of Ways to Stay in the Same Place After Some Steps 
int numWays(int steps, int arrLen) {
        int m=steps;
        int n=min(arrLen,steps/2 +1);
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        dp[0][0]=1;
        int mod=1e9+7;
        for(int i=1;i<=m;i++){
            for(int j=0;j<n;j++){
                dp[i][j]=dp[i-1][j];
                if(j>0){
                    dp[i][j]=(dp[i][j]+dp[i-1][j-1])%mod;
                }
                if(j< n-1){
                    dp[i][j]=(dp[i][j]+dp[i-1][j+1])%mod;
                }
            }
        }
        return dp[m][0];
    }




    // 119. Pascal's Triangle II 
     vector<int> getRow(int rowIndex) {
        vector<int>ans(1,1);
        long long prev=1;
        for(int k=1;k<=rowIndex;k++){
            int next_val= prev*(rowIndex-k+1)/k;
            ans.push_back(next_val);
            prev=next_val;
        }
        return ans;
    }



    // 844. Backspace String Compare 
    int processString(string &str){
    int k=0;
    for(char c:str){
        if(c!='#'){
            str[k++]=c;
        }else if(k>0){
            k--;
        }
    }
    return k;
}
    bool backspaceCompare(string s, string t) {
        int a=processString(s);
        int b=processString(t);
        if(a!=b){
            return false;
        }
        for(int i=0;i<a;i++){
            if(s[i]!=t[i]){
                return false;
            }
        }
        return true;
    }




    // 341. Flatten Nested List Iterator 
    class NestedIterator {
public:
int index;
vector<int>flattened;
vector<int>flatten(vector<NestedInteger>&nestedList){
    vector<int>result;
    for(auto i:nestedList){
        if(i.isInteger()){
            result.push_back(i.getInteger());
        }
        else{
            auto sublist=flatten(i.getList());
            result.insert(result.end(),sublist.begin(),sublist.end());
        }
    }
    return result;
}
    NestedIterator(vector<NestedInteger> &nestedList) {
        flattened=flatten(nestedList);
        index=0;
    }
    
    int next() {
        return flattened[index++];
    }
    
    bool hasNext() {
        return index<flattened.size();
    }
};




// 779. K-th Symbol in Grammar 
 int kthGrammar(int n, int k) {
        if(n==1){
            return 0;
        }
        int len=1<<(n-2);
        if(k<=len){
            return kthGrammar(n-1,k);
        }else{
            return 1-kthGrammar(n-1,k-len);
        }
    }




    


// 5. Longest Palindromic Substring 
class Solution {
public:
string expandAroundCenter(string s, int left, int right){
    while(left>=0 && right<s.size() && s[left]==s[right]){
        left--;
        right++;
    }
    return s.substr(left+1,right-left-1);
}
    string longestPalindrome(string s) {
        string longest="";
        for(int i=0;i<s.size();i++){
            string odd=expandAroundCenter(s,i,i);
            string even=expandAroundCenter(s,i,i+1);
            if(odd.size()>longest.size()){
                longest=odd;
            }
            if(even.size()>longest.size()){
                longest=even;
            }
        }
        return longest;
    }
};




// 458. Poor Pigs 
int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        return ceil(log2(buckets)/log2(int(minutesToTest/minutesToDie)+1));
    }



