#include<iostream>
using namespace std;




// 58. Length of Last Word
int lengthOfLastWord(string s) {
        int ans=0;
        bool counting=false;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]!=' '){
                ans++;
                counting=true;
            }
            else if(counting){
                break;
            }
        }
        return ans;
    }




    // 1614. Maximum Nesting Depth of the Parentheses
     int maxDepth(string s) {
        int count=0;
        int ans=0;
        for(char c:s){
            if(c=='('){
                count++;
                if(count>ans){
                    ans=count;
                }
            }
            if(c==')'){
                count--;
            }
        }
        return ans;
    }





    // 1544. Make The String Great
    #include<stack>
     string makeGood(string s) {
        stack<char>st;
        for(char c:s){
            if(!st.empty() && abs(st.top()-c)==32){
                st.pop();
            }else{
                st.push(c);
            }
        }
        string ans;
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }





    // 678. Valid Parenthesis String
    bool checkValidString(string s) {
        int leftMin=0,leftMax=0;
        for(char c:s){
            if(c=='('){
                leftMin++;
                leftMax++;
            }
            else if(c==')'){
                leftMin--;
                leftMax--;
            }
            else{
                leftMin--;
                leftMax++;
            }
            if(leftMax<0)return false;
            if(leftMin<0)leftMin=0;
        }
        return leftMin==0;
    }





    
// 1700. Number of Students Unable to Eat Lunch
#include<vector>
 int countStudents(vector<int>& students, vector<int>& sandwiches) {
        vector<int>count(2,0);
        for(int student:students){
            count[student]++;
        }
        int ans=sandwiches.size();
        for(int sandwich:sandwiches){
            if(count[sandwich]==0)break;
            if(ans==0)break;
            count[sandwich]--;
            ans--;
        }
        return ans;
    }





    // 2073. Time Needed to Buy Tickets
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ans=0;
        int n=tickets.size();
        for(int i=0;i<n;i++){
            if(i<=k){
                ans+=min(tickets[i],tickets[k]);
            }else{
                ans+=min(tickets[i],tickets[k]-1);
            }
        }
        return ans;
    }








    // 950. Reveal Cards In Increasing Order
    #include<algorithm>
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        int n=deck.size();
        vector<int>ans(n);
        deque<int>indices;

        for(int i=0;i<n;i++){
            indices.push_back(i);
        }
        for(int card:deck){
            int index=indices.front();
            indices.pop_front();
            ans[index]=card;
            if(!indices.empty()){
                indices.push_back(indices.front());
                indices.pop_front();

            }
        }
        return ans;
    }







    // 42. Trapping Rain Water
    int trap(vector<int>& height) {
        int n=height.size();
        if(n==0)return 0;

        vector<int>left(n,0);
        vector<int>right(n,0);

        left[0]=height[0];
        for(int i=1;i<n;i++){
            left[i]=max(left[i-1],height[i]);
        }

        right[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            right[i]=max(right[i+1],height[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=min(left[i],right[i])-height[i];
        }
        return ans;
    }





    // 404. Sum of Left Leaves
    struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root)return 0;
        int ans=0;
        if(root->left){
            if(!root->left->left && !root->left->right){
                ans+=root->left->val;
            }
            else{
                ans+=sumOfLeftLeaves(root->left);
            }
        }
        ans+=sumOfLeftLeaves(root->right);
        return ans;
    }





    // 129. Sum Root to Leaf Numbers
     int func(TreeNode *node, int ans){
        if(!node)return 0;
        ans= ans*10+node->val;
        if(!node->left && !node->right)return ans;

        return func(node->left,ans)+func(node->right,ans);
    }
    int sumNumbers(TreeNode* root) {
        return func(root,0);
    }




    // 463. Island Perimeter
     int islandPerimeter(vector<vector<int>>& grid) {
        int ans=0;
        int row=grid.size();
        int col=grid[0].size();

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    ans+=4;
                    if(i>0 && grid[i-1][j]==1)ans-=2;
                    if(j>0 && grid[i][j-1]==1)ans-=2;
                }
            }
        }
        return ans;
    }





    // 623. Add One Row to Tree
    TreeNode* addOne(TreeNode *root, int val, int depth, int curr){
        if(!root)return NULL;

        if(curr==depth-1){
            TreeNode *lNode=root->left;
            TreeNode *rNode=root->right;
            root->left=new TreeNode(val);
            root->right=new TreeNode(val);
            root->left->left=lNode;
            root->right->right=rNode;
            return root;
        }
        root->left=addOne(root->left,val,depth,curr+1);
        root->right=addOne(root->right,val,depth,curr+1);
        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode *newRoot=new TreeNode(val);
            newRoot->left=root;
            return newRoot;
        }
        return addOne(root,val,depth,1);
    }





    // 988. Smallest String Starting From Leaf
    void smallestString(TreeNode *root, string path, string& ans){
        if(!root)return;

        path+=char('a'+root->val);
        if(root->left==NULL && root->right==NULL){
            reverse(path.begin(),path.end());
            if(ans.empty() || path<ans){
                ans=path;
            }
            reverse(path.begin(),path.end());
        }
        smallestString(root->left,path,ans);
        smallestString(root->right,path,ans);
     }
    string smallestFromLeaf(TreeNode* root) {
        string ans="";
        smallestString(root,"",ans);
        return ans;
    }





    // 200. Number of Islands
    void islands(vector<vector<char>>& grid, int i, int j){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]!='1'){
            return;
        }
        grid[i][j]='0';
        islands(grid,i,j+1);
        islands(grid,i,j-1);
        islands(grid,i+1,j);
        islands(grid,i-1,j);
      }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty()){
            return 0;
        }
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    ans++;
                    islands(grid,i,j);
                }
            }
        }
        return ans;
    }