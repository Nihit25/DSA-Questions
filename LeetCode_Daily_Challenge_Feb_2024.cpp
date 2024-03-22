
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


// 2966. Divide Array Into Arrays With Max Difference
vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans(n/3,vector<int>(3));
        int index=0;
        for(int i=0;i<n;i+=3){
            if(i+2<n && nums[i+2]-nums[i]<=k){
                ans[index]={nums[i],nums[i+1],nums[i+2]};
                index++;
            }
            else{
                return vector<vector<int>>();
            }
        }
        return ans;
    }





    // 1291. Sequential Digits
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        for(int i=1;i<=9;i++){
            int num=i;
            int nextDigit=i+1;
            while(num<=high && nextDigit<=9){
                num=num*10+nextDigit;
                if(num>=low && num<=high){
                    ans.push_back(num);
                }
                nextDigit++;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }





    // 1043. Partition Array for Maximum Sum
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        int t=k+1;
        vector<int>dp(t,0);
        for(int start=n-1;start>=0;start--){
            int currMax=0;
            int end=min(n,start+k);
            for(int i=start;i<end;i++){
                currMax=max(currMax,arr[i]);
                dp[start%t]=max(dp[start%t],dp[(i+1)%t]+currMax*(i-start+1));
            }
        }
        return dp[0];
    }





    // 387. First Unique Character in a String
    #include<unordered_map>
    int firstUniqChar(string s) {
        unordered_map<char,int>mp;
        for(char c:s){
            mp[c]++;
        }
        for(int i=0;i<s.size();i++){
            if(mp[s[i]]==1){
                return i;
            }
        }
        return -1;
    }





    // 49. Group Anagrams
     vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>groups;
        for(string s:strs){
            string key=s;
            sort(key.begin(),key.end());
            groups[key].push_back(s);
        }
        for(auto entry:groups){
            ans.push_back(entry.second);
        }
        return ans;
    }




    // 451. Sort Characters By Frequency
    #include<multimap>
     string frequencySort(string s) {
        unordered_map<char,int>mp;
        multimap<int,char>r;
        for(auto a:s){
            mp[a]++;
        }
        for(auto a:mp){
            r.insert({a.second,a.first});
        }
        string ans="";
        for(auto it=r.rbegin();it!=r.rend();it++){
            ans+=string(it->first,it->second);
        }
        return ans;
    }





    // 279. Perfect Squares
    int numSquares(int n) {
        vector<int>dp(n+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j*j<=i;j++){
                dp[i]=min(dp[i],dp[i-j*j]+1);
            }
        }
        return dp[n];
    }




    // 647. Palindromic Substrings
    string str;
int check(int l, int r, int ans=0){
    while(l>=0 && r<=str.size()){
        if(str[l--]==str[r++]){
            ans++;
        }else{
            break;
        }
    }
    return ans;
}
    int countSubstrings(string s) {
        int n=s.size();
        int ans=0;
        str=s;
        for(int i=0;i<n;i++){
            ans+=check(i,i);
            ans+=check(i,i+1);
        }
        return ans;
    }





    // 169. Majority Element
     int majorityElement(vector<int>& nums) {
        int majority=nums[0];
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(majority==nums[i]){
                count++;
            }else{
                count--;
            }
            if(count==0){
                majority=nums[i];
                count++;
            }
        }
        return majority;
    }





    // 2108. Find First Palindromic String in the Array
      string firstPalindrome(vector<string>& words) {
        for(int i=0;i<words.size();i++){
            string s=words[i];
            reverse(s.begin(),s.end());
            if(s==words[i]){
                return words[i];
            }
        }
        return "";
    }





    // 2149. Rearrange Array Elements by Sign
     vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>ans(nums.size(),0);
        int pos=0,neg=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                ans[pos]=nums[i];
                pos+=2;
            }else{
                ans[neg]=nums[i];
                neg+=2;
            }
        }
        return ans;
    }




    // 2971. Find Polygon With the Largest Perimeter
    long long largestPerimeter(vector<int>& nums) {
        long long sum=0;
        int n=nums.size();
        for(auto i:nums){
            sum+=i;
        }
        sort(nums.begin(),nums.end());
        for(int i=n-1;i>=2;i--){
            sum-=nums[i];
            if(sum>nums[i]){
                return sum+nums[i];
            }
        }
        return -1;
    }




    // 1481. Least Number of Unique Integers after K Removals
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        for(auto a:arr){
            mp[a]++;
        }
        vector<int>v;
        for(auto a:mp){
            v.push_back(a.second);
        }
        sort(v.begin(),v.end());
        int count=0;
        for(int i=0;i<v.size();i++){
            if(k>v[i]){
                k-=v[i];
                v[i]=0;
            }else{
                v[i]-=k;
                k=0;
            }
            if(v[i])count++;
        }
        return count;
    }




    // 1642. Furthest Building You Can Reach
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int>p;
        int i=0,diff=0;
        for(i=0;i<heights.size()-1;i++){
            diff=heights[i+1]-heights[i];
            if(diff<=0)continue;
            bricks-=diff;
            p.push(diff);
            if(bricks<0){
                bricks+=p.top();
                p.pop();
                ladders--;
            }
            if(ladders<0)break;
        }
        return i;
        
    }




    // 231. Power of Two
    bool isPowerOfTwo(int n) {
        int ans=1;
        for(int i=0;i<=30;i++){
            if(ans==n){
                return true;
            }
            if(ans<INT_MAX/2){
                ans*=2;
            }
        }
        return false;
    }





    // 268. Missing Number
    int missingNumber(vector<int>& nums) {
        set<int>s;
        for(auto i:nums){
            s.insert(i);
        }
        for(int i=0;i<=nums.size();i++){
            if(s.find(i)==s.end()){
                return i;
            }
        }
        return -1;
    }





    // 201. Bitwise AND of Numbers Range
     int rangeBitwiseAnd(int left, int right) {
        int count=0;
        while(left!=right){
            left>>=1;
            right>>=1;
            count++;
        }
        return left<<count;
    }





    // 997. Find the Town Judge
     int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>in(n+1,0),out(n+1,0);
        for(auto a:trust){
            in[a[0]]++;
            out[a[1]]++;
        }
        for(int i=1;i<=n;i++){
            if(in[i]==0 && out[i]==n-1){
                return i;
            }
        }
        return -1;
    }





    // 100. Same Tree
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL){
            return true;
        }
        if(p!=NULL && q==NULL){
            return false;
        }
        if(p==NULL && q!=NULL){
            return false;
        }
        bool b=p->val==q->val;
        return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right)&&b;
    }





    // 543. Diameter of Binary Tree
    ic:
    int diameter(TreeNode *root,int &ans){
        if(!root)return 0;
        int left=diameter(root->left,ans);
        int right=diameter(root->right,ans);
        ans=max(ans,left+right);
        return max(left,right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        diameter(root,ans);
        return ans;
    }





    // 513. Find Bottom Left Tree Value
     int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode *>q;
        q.push(root);
        int ans;
        while(!q.empty()){
            TreeNode *node=q.front();
            q.pop();
            ans=node->val;
            if(node->right){
                q.push(node->right);
            }
            if(node->left){
                q.push(node->left);
            }


        }
        return ans;
    }






    // 1609. Even Odd Tree
     bool isEvenOddTree(TreeNode* root) {
        int level=0;
        queue<TreeNode *>q;
        q.push(root);
        if(!root)return true;

        while(!q.empty()){
            TreeNode *node=q.front();
            int size=q.size();
            int prev_val=level%2==0?INT_MIN:INT_MAX;
            for(int i=0;i<size;i++){
                TreeNode *node=q.front();
                q.pop();
                if((level%2==0 && (node->val%2==0 || node->val<=prev_val))
                ||(level%2==1 && (node->val%2==1 || node->val>=prev_val))){
                    return false;
                }
                prev_val=node->val;
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            level++;
        }
        return true;
    }