#include<iostream>
using namespace std;


// 3110. Score of a String
int scoreOfString(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n-1;i++){
            ans+=abs(s[i+1]-s[i]);
        }
        return ans;
    }






    // 344. Reverse String
    #include<vector>
      void reverseString(vector<char>& s) {
        int start=0,end=s.size()-1;
        while(start<=end){
            swap(s[start],s[end]);
            start++;
            end--;
        }
    }






    // 2486. Append Characters to String to Make Subsequence
    int appendCharacters(string s, string t) {
        int s_index=0,t_index=0;
        while(s_index<s.size() && t_index<t.size()){
            if(s[s_index]==t[t_index]){
                t_index++;
            }
            s_index++;
        }
        return t.size()-t_index;
    }






    // 409. Longest Palindrome
    #include <unordered_set>
     int longestPalindrome(string s) {
        int ans=0;
        unordered_set<char>st;
        for(auto c:s){
            if(st.find(c)!=st.end()){
                st.erase(c);
                ans+=2;
            }else{
                st.insert(c);
            }
        }
        if(!st.empty())ans++;
        return ans;
    }






    // 523. Continuous Subarray Sum
    #include<unordered_map>
      bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int sum=0;
        mp[0]=-1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(mp.find(sum%k)!=mp.end()){
                if(i-mp[sum%k]>=2){
                    return true;
                }
            }else{
                mp[sum%k]=i;
            }
        }
        return false;
    }






    // 1002. Find Common Characters
    #include<limits.h>
    vector<string> commonChars(vector<string>& words) {
        vector<string>ans;
        for(char c='a';c<='z';c++){
            int minCount=INT_MAX;
            for(string word:words){
                int count=0;
                for(auto ch:word){
                    if(ch==c)count++;
                }
                minCount=min(minCount,count);
                if(minCount==0)break;

            }
            for(int i=0;i<minCount;i++){
                ans.push_back(string(1,c));
            }
        }
        return ans;
    }





    // 1051. Height Checker
    #include<algorithm>
      int heightChecker(vector<int>& heights) {
        int n=heights.size();
        vector<int>expected=heights;
        sort(expected.begin(),expected.end());
        int ans=0;
        for(int i=0;i<n;i++){
            if(expected[i]!=heights[i])ans++;
        }
        return ans;
    }






    // 75. Sort Colors
     void sortColors(vector<int>& nums) {
        sort(nums.begin(),nums.end());
    }





    // 1122. Relative Sort Array
      vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int>ans;
        for(int i=0;i<arr2.size();i++){
            for(int j=0;j<arr1.size();j++){
                if(arr1[j]==arr2[i]){
                    ans.push_back(arr1[j]);
                    arr1[j]=-1;
                }
            }
        }
        sort(arr1.begin(),arr1.end());
        for(int i=0;i<arr1.size();i++){
            if(arr1[i]!=-1){
                ans.push_back(arr1[i]);
            }
        }
        return ans;
    }





    // 2037. Minimum Number of Moves to Seat Everyone
      int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(),seats.end());
        sort(students.begin(),students.end());
        int ans=0;
        for(int i=0;i<seats.size();i++){
            ans+=abs(seats[i]-students[i]);
        }
        return ans;
    }




    // 945. Minimum Increment to Make Array Unique
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=nums[i-1]){
                ans+=nums[i-1]-nums[i]+1;
                nums[i]=nums[i-1]+1;
            }
        }
        return ans;
    }





    // 330. Patching Array
      int minPatches(vector<int>& nums, int n) {
        long long miss=1;
        int ans=0;
        int i=0;
        while(miss<=n){
            if(i<nums.size() && nums[i]<=miss){
                miss+=nums[i];
                i++;
            }else{
                miss+=miss;
                ans++;
            }
        }
        return ans;
    }





    // 633. Sum of Square Numbers
    #include<math.h>
     bool judgeSquareSum(int c) {
        for(long long a=0;a*a<=c;a++){
            double b=sqrt(c-a*a);
            if(b==int(b))return true;
        }
        return false;
    }





    

// 1038. Binary Search Tree to Greater Sum Tree
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
int sum=0;
void traversal(TreeNode *root){
    if(root){
        traversal(root->right);
        sum+=root->val;
        root->val=sum;
        traversal(root->left);
    }
}
    TreeNode* bstToGst(TreeNode* root) {
        traversal(root);
        return root;
    }






    // 1382. Balance a Binary Search Tree
    vector<TreeNode*>v;
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return sortedArrayToBST(0,v.size()-1);
    }
    void inorder(TreeNode *root){
        if(root==NULL)return;
        inorder(root->left);
        v.push_back(root);
        inorder(root->right);

    }
    TreeNode * sortedArrayToBST(int start, int end){
        if(start>end)return NULL;
        int mid=(start+end)/2;
        TreeNode *root=v[mid];
        root->left=sortedArrayToBST(start,mid-1);
        root->right=sortedArrayToBST(mid+1,end);
        return root;
    }






    // 1791. Find Center of Star Graph
     int findCenter(vector<vector<int>>& edges) {
        if(edges[0][0]==edges[1][0] || edges[0][0]==edges[1][1])return edges[0][0];
        return edges[0][1];
    }