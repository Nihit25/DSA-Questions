#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



// 455. Assign Cookies 
int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans=0;
        int i=0,j=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        while(i<g.size() && j<s.size()){
            if(g[i]<=s[j]){
                ans++;
                i++;
                j++;
            }else{
                j++;
            }
        }
        return ans;
    }





    // 2610. Convert an Array Into a 2D Array With Conditions
    #include<unordered_map>
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int count=0;
        unordered_map<int,int>mp;
        for(auto i:nums){
            mp[i]++;
            count=max(count,mp[i]);
        }
        vector<vector<int>>v(count);
        for(auto i:mp){
            int num=i.first;
            int size=i.second;
            for(int j=0;j<size;j++){
                v[j].push_back(num);
            }
        }
        return v;
    }





    // 2125. Number of Laser Beams in a Bank 
    int calc(string s){
    int count=0;
    for(auto c:s){
        count+=c-'0';
    }
    return count;
}
    int numberOfBeams(vector<string>& bank) {
        int ans=0;
        int prevCount=0;
        for(auto str:bank){
            int cnt=calc(str);
            if(cnt==0){
                continue;
            }
            ans+=prevCount*cnt;
            prevCount=cnt;
        }
        return ans;
    }




    // 2870. Minimum Number of Operations to Make Array Empty 
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto i:nums){
            mp[i]++;
        }
        int count=0;
        for(auto i:mp){
            int a=i.second;
            if(a==1){
                return -1;
            }
            count+=a/3;
            if(a%3)count++;
        }
        return count;
    }




    // 300. Longest Increasing Subsequence 
     int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }





    // 938. Range Sum of BST 
    struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root==NULL)return 0;
        int c;
        if(root->val<=high && root->val>=low){
            c=root->val;
        }else{
            c=0;
        }
        int l=rangeSumBST(root->left,low,high);
        int r=rangeSumBST(root->right,low,high);
        return c+l+r;
    }





    // 872. Leaf-Similar Trees
    void similarLeaves(TreeNode *root,vector<int>&v){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            v.push_back(root->val);
            return;
        }
        similarLeaves(root->left,v);
        similarLeaves(root->right,v);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>v1,v2;
        similarLeaves(root1,v1);
        similarLeaves(root2,v2);
        return v1==v2;
    }





    // 2385. Amount of Time for Binary Tree to Be Infected 
    #include<unordered_set>
    #include<queue>
     unordered_map<int,vector<int>>graph;
     void constructGraph(TreeNode *root){
         if(root==NULL){
             return;
         }
         if(root->left){
             graph[root->val].push_back(root->left->val);
             graph[root->left->val].push_back(root->val);
         }
         if(root->right){
             graph[root->val].push_back(root->right->val);
             graph[root->right->val].push_back(root->val);
         }
         constructGraph(root->left);
         constructGraph(root->right);
     }
    int amountOfTime(TreeNode* root, int start) {
        int minutesPassed=-1;
        constructGraph(root);
        queue<int>q;
        q.push(start);
        // q.push(start);
        unordered_set<int>visited;
        while(!q.empty()){
            minutesPassed++;
            for(int level=q.size();level>0;level--){
                int currNode=q.front();
                q.pop();
                visited.insert(currNode);
                for(int adjacentNode:graph[currNode]){
                    if(!visited.count(adjacentNode)){
                        q.push(adjacentNode);
                    }
                }
            }
        }
        return minutesPassed;
    }





    // 2225. Find Players With Zero or One Losses
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int>lost_map;
        for(int i=0;i<matches.size();i++){
            lost_map[matches[i][1]]++;
        }
        vector<int>notLost;
        vector<int>onceLost;
        for(int i=0;i<matches.size();i++){
            int winner=matches[i][0];
            int looser=matches[i][1];
            if(lost_map.find(winner)==lost_map.end()){
                notLost.push_back(winner);
                lost_map[winner]=10;
            }
            if(lost_map[looser]==1){
                onceLost.push_back(looser);
            }
        }
        sort(notLost.begin(),notLost.end());
        sort(onceLost.begin(),onceLost.end());
        return {notLost,onceLost};
    }





    // 380. Insert Delete GetRandom O(1) 
     unordered_map<int,int>mp;
    vector<int>v;
    bool search(int val){
        if(mp.find(val)!=mp.end()){
            return true;
        }
        return false;
    }
    
    
    bool insert(int val) {
        if(search(val)){
            return false;
        }
        v.push_back(val);
        mp[val]=v.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(!search(val)){
            return false;
        }
        auto it=mp.find(val);
        v[it->second]=v.back();
        v.pop_back();
        mp[v[it->second]]=it->second;
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
 




//  1026. Maximum Difference Between Node and Ancestor 
int diff=0;
    void differ(TreeNode *root,int minVal, int maxVal){
        if(!root){
            return ;
        }
        diff=max(diff,max(abs(root->val-minVal),abs(root->val-maxVal)));
        minVal=min(minVal,root->val);
        maxVal=max(maxVal,root->val);
        differ(root->left,minVal,maxVal);
        differ(root->right,minVal,maxVal);
    }
    int maxAncestorDiff(TreeNode* root) {
        if(!root){
            return 0;
        }
        int minVal=root->val,maxVal=root->val;
        differ(root,minVal,maxVal);
        return diff;
    }





    // 70. Climbing Stairs
    int climbStairs(int n) {
        vector<int>dp(n+1);
        dp[0]=dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }





    // 1657. Determine if Two Strings Are Close 
     bool closeStrings(string word1, string word2) {
        vector<int>freq1(26,0);
        vector<int>freq2(26,0);
        for(char ch:word1){
            freq1[ch-'a']++;
        }
        for(char ch:word2){
            freq2[ch-'a']++;
        }
        for(int i=0;i<26;i++){
            if((freq1[i]==0 && freq2[i]!=0)||(freq1[i]!=0 &&freq2[i]==0)){
                return false;
            }
        }
        sort(freq1.begin(),freq1.end());
        sort(freq2.begin(),freq2.end());
        for(int i=0;i<26;i++){
            if(freq1[i]!=freq2[i]){
                return false;
            }
        }
        return true;

    }




    // 1347. Minimum Number of Steps to Make Two Strings Anagram 
     int minSteps(string s, string t) {
        vector<int>freq1(26,0);
        vector<int>freq2(26,0);
        for(char ch:s){
            freq1[ch-'a']++;
        }
        for(char ch:t){
            freq2[ch-'a']++;
        }
        int count=0;
        for(int i=0;i<26;i++){
            count+=abs(freq1[i]-freq2[i]);
        }
        return count/2;
    }





    // 1704. Determine if String Halves Are Alike
     bool halvesAreAlike(string s) {
        unordered_set<char>vowels={'a','e','i','o','u','A','E','I','O','U'};
        int mid=s.size()/2;
        int vowelsCount=0;
        for(int i=0;i<mid;i++){
            char c1=s[i];
            char c2=s[i+mid];
            if(vowels.count(c1))vowelsCount++;
            if(vowels.count(c2))vowelsCount--;

        }
        return vowelsCount==0;
    }





    // 1207. Unique Number of Occurrences 
     bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        unordered_set<int>s;
        for(auto i:arr){
            mp[i]++;
        }
        for(auto i:mp){
            s.insert(i.second);
        }
        return mp.size()==s.size();
    }




    // 198. House Robber
     int rob(vector<int>& nums) {
        int rob=0;
        int norob=0;
        for(int i=0;i<nums.size();i++){
            int newrob=norob+nums[i];
            int newnorob=max(rob,norob);
            rob=newrob;
            norob=newnorob;
        }
        return max(rob,norob);
    }





    // 232. Implement Queue using Stacks 
    #include<stack>
    stack<int>s1;
    stack<int>s2;
    // MyQueue() {
        
    // }
    
    void push(int x) {
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int temp=s1.top();
        s1.pop();
        return temp;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }





    // 645. Set Mismatch
     vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        vector<int>v(n+1,0);
        for(int i=0;i<n;i++){
            v[nums[i]]++;
        }
        int duplicate=0;
        int missing=0;
        for(int i=1;i<=n;i++){
            if(v[i]==2)duplicate=i;
            if(v[i]==0)missing=i;
        }
        return {duplicate,missing};
    }





    // 150. Evaluate Reverse Polish Notation 
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        for(string token:tokens){
            if(token.size()>1 || isdigit(token[0])){
                s.push(stoi(token));
            }else{
                int op2=s.top();
                s.pop();
                int op1=s.top();
                s.pop();
                switch(token[0]){
                    case '+':
                    s.push(op1+op2);
                    break;
                    case '-':
                    s.push(op1-op2);
                    break;
                    case '*':
                    s.push(op1*op2);
                    break;
                    case '/':
                    s.push(op1/op2);
                    break;
                }
            }
        }
        return s.top();
    }






    // 739. Daily Temperatures 
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int>ans(n,0);
        stack<int>s;
        for(int i=0;i<n;i++){
            while(!s.empty() && temperatures[s.top()]<temperatures[i]){
                ans[s.top()]=i-s.top();
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }