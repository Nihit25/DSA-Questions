#include<iostream>
using namespace std;
#include<string>
#include<string.h>
#include<algorithm>




// 2000. Reverse Prefix of Word
string reversePrefix(string word, char ch) {
        int position=-1;
        position=word.find(ch);
        if(position){
            reverse(word.begin(),word.begin()+position+1);
        }
        return word;
    }





    // 2441. Largest Positive Integer That Exists With Its Negative
    #include<vector>
    #include<unordered_set>
    int findMaxK(vector<int>& nums) {
        int ans=-1;
        unordered_set<int>s(nums.begin(),nums.end());
        for(int a:s){
            if(s.find(-a)!=s.end()){
                ans=max(ans,a);
            }
        }
        return ans;
    }




    // 165. Compare Version Numbers
     int compareVersion(string version1, string version2) {
        int i=0,j=0;
        while(i<version1.size() || j<version2.size()){
            int num1=0,num2=0;
            while(i<version1.size() && version1[i]!='.'){
                num1=num1*10+(version1[i++]-'0');
            }
            while(j<version2.size() && version2[j]!='.'){
                num2=num2*10+(version2[j++]-'0');
            }
            if(num1>num2)return 1;
            if(num2>num1)return -1;
            i++;
            j++;
        }
        return 0;
    }





    // 881. Boats to Save People
    int numRescueBoats(vector<int>& people, int limit) {
        int ans=0;
        sort(people.begin(),people.end());
        int i=0,j=people.size()-1;
        while(i<=j){
            if(people[i]+people[j] <=limit){
                i++;
            }
            j--;
            ans++;
        }
        return ans;
    }





    // 237. Delete Node in a Linked List
    struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
    void deleteNode(ListNode* node) {
        node->val=node->next->val;
        node->next=node->next->next;
    }







    // 2487. Remove Nodes From Linked List
    #include<stack>
      ListNode* removeNodes(ListNode* head) {
        ListNode *curr=head;
        stack<ListNode*>st;
        while(curr){
            while(!st.empty() && st.top()->val<curr->val){
                st.pop();
            }
            st.push(curr);
            curr=curr->next;
        }
        ListNode *forward=NULL;
        while(!st.empty()){
            curr=st.top();
            st.pop();
            curr->next=forward;
            forward=curr;
        }
        return curr;
    }





    // 2373. Largest Local Values in a Matrix
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>v(n-2,vector<int>(n-2));
        for(int i=1;i<n-1;i++){
            for(int j=1;j<n-1;j++){
                int temp=0;
                for(int k=i-1;k<=i+1;k++){
                    for(int l=j-1;l<=j+1;l++){
                        temp=max(temp,grid[k][l]);
                    }
                }
                v[i-1][j-1]=temp;
            }
        }
        return v;
    }






    // 506. Relative Ranks
    #include<unordered_map>
     vector<string> findRelativeRanks(vector<int>& score) {
        vector<int>sortedScore=score;
        sort(sortedScore.begin(),sortedScore.end(),greater<int>());
        vector<string>medals={"Gold Medal","Silver Medal","Bronze Medal"};
        unordered_map<int,string>mp;
        for(int i=0;i<score.size();i++){
            if(i<3){
                mp[sortedScore[i]]=medals[i];
            }
            else{
                mp[sortedScore[i]]=to_string(i+1);
            }
        }
        vector<string>ans;
        for(int s:score){
            ans.push_back(mp[s]);
        }
        return ans;
    }






    // 3075. Maximize Happiness of Selected Children
     long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(),happiness.end(),greater<int>());
        long long ans=0;
        int i=0;
        while(k--){
            happiness[i]=max(happiness[i]-i,0);
            ans+=happiness[i++];
        }
        return ans;
    }






    // 2816. Double a Number Represented as a Linked List
     ListNode *reverse(ListNode *head){
    ListNode *forward=NULL;
    ListNode *prev=NULL;
    ListNode *curr=head;
    while(curr){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    head=prev;
    return head;
   }

   void insert(ListNode* &head, ListNode* &tail, int value){
    ListNode *temp=new ListNode(value);
    if(head==NULL){
        head=temp;
        tail=temp;
        return;
    }
    else{
        tail->next=temp;
        tail=temp;
    }
   }
    

    ListNode* doubleIt(ListNode* head) {
        head=reverse(head);
        int carry=0;
        ListNode *ansHead=NULL;
        ListNode *ansTail=NULL;
        while(head || carry){
            int value=0;
            if(head){
                value=head->val*2;
            }
            int sum=value+carry;
            insert(ansHead,ansTail,sum%10);
            carry=sum/10;
            if(head){
                head=head->next;
            }
        }
        ListNode *ans=reverse(ansHead);
        return ans;
    }





    // 1219. Path with Maximum Gold
    vector<int>row={1,-1,0,0};
vector<int>col={0,0,-1,1};
int maxGold=0;
int Gold(vector<vector<int>>&grid, int x,int y,int n, int m){
    if(x<0 || x>=n || y<0 || y>=m || grid[x][y]==0)return 0;
    int curr=grid[x][y];
    grid[x][y]=0;
    int localMaxGold=curr;
    for(int i=0;i<4;i++){
        int newX=x+row[i];
        int newY=y+col[i];
        localMaxGold=max(localMaxGold,curr+Gold(grid,newX,newY,n,m));
    }
    grid[x][y]=curr;
    return localMaxGold;
    
}
    int getMaximumGold(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                maxGold=max(maxGold,Gold(grid,i,j,n,m));
            }
        }
        return maxGold;
    }






    // 2331. Evaluate Boolean Binary Tree
    struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
     bool evaluateTree(TreeNode* root) {
        if(root->val==0 || root->val==1)return root->val==1;
        else if(root->val==2)return evaluateTree(root->left)||evaluateTree(root->right);
        else if(root->val==3)return evaluateTree(root->left)&&evaluateTree(root->right);
        return false;
    }





    
// 1325. Delete Leaves With a Given Value
TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(!root)return NULL;
        root->left=removeLeafNodes(root->left,target);
        root->right=removeLeafNodes(root->right,target);
        if(!root->left && !root->right && root->val==target)return NULL;
        return root;
    }







    // 979. Distribute Coins in Binary Tree
    int ans;

    int distributeCoins(TreeNode* root) {
        ans=0;
        countSteps(root);
        return ans;
    }
    int countSteps(TreeNode *root){
        if(root==NULL)return 0;
        int rootLeft=countSteps(root->left);
        int rootRight=countSteps(root->right);
        ans+=abs(rootLeft)+abs(rootRight);
        return (root->val-1)+rootLeft+rootRight;
    }





    // 1863. Sum of All Subset XOR Totals
     int subsetXORSum(vector<int>& nums) {
        int var=0;
        for(auto num:nums){
            var|=num;
        }
        return var<<(nums.size()-1);
    }




    // 78. Subsets
     void subsets(vector<int>output,vector<int>nums,vector<vector<int>>&ans,int index){
        if(index>=nums.size()){
            ans.push_back(output);
            return;
        }
        subsets(output,nums,ans,index+1);
        output.push_back(nums[index]);
        subsets(output,nums,ans,index+1);
     }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>output;
        vector<vector<int>>ans;
        subsets(output,nums,ans,0);
        return ans;
    }





    // 1442. Count Triplets That Can Form Two Arrays of Equal XOR
      int countTriplets(vector<int>& arr) {
        int ans=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int a=0;
                for(int k=i;k<j;k++){
                    a^=arr[k];
                }
                int b=0;
                for(int k=j;k<n;k++){
                    b^=arr[k];
                    if(a==b){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }






    // 260. Single Number III
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int>mp;
        vector<int>ans;
        for(auto a:nums){
            mp[a]++;
        }
        for(auto a:mp){
            if(a.second==1){
                ans.push_back(a.first);
            }
        }
        return ans;
    }