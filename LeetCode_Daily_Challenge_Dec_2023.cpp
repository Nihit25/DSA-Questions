
// 1903. Largest Odd Number in String
#include<iostream>
using namespace std;
 string largestOddNumber(string num) {
        if(num.back()%2==1){
            return num;
        }
        int i=num.size()-1;
        while(i>=0){
            int temp=num[i];
            if(temp%2==1){
                return num.substr(0,i+1);
            }
            i--;
        }
        return "";
    }






// 606. Construct String from Binary Tree
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
void func(TreeNode *root, string &str){
    if(root==NULL){
        return;
    }
    str+=to_string(root->val);
    if(root->left || root->right){
        str+='(';
        func(root->left,str);
        str+=')';
    }
    if(root->right){
        str+='(';
        func(root->right,str);
        str+=')';
    }
}
    string tree2str(TreeNode* root) {
        string str="";
        func(root,str);
        return str;
    }






    // 94. Binary Tree Inorder Traversal 
    #include<vector>
     void inorder(TreeNode *root,vector<int>&ans){
        if(root==NULL){
            return;
        }
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        inorder(root,ans);
        return ans;
    }




    // 867. Transpose Matrix 
      vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        vector<vector<int>>ans(col,vector<int>(row,0));
        for(int i=0;i<col;i++){
            for(int j=0;j<row;j++){
                ans[i][j]=matrix[j][i];
            }
        }
        return ans;
    }




    // 1287. Element Appearing More Than 25% In Sorted Array 
     int findSpecialInteger(vector<int>& arr) {
        int n=arr.size();
        int q=n/4;
        int count=1;
        int temp=arr[0];
        for(int i=1;i<n;i++){
            if(temp==arr[i]){
                count++;
            }
            else{
                count=1;
            }
            if(count>q){
                return arr[i];
            }
            temp=arr[i];
        }
        return temp;
    }





    // 1464. Maximum Product of Two Elements in an Array 
    #include<priority_queue>
     int maxProduct(vector<int>& nums) {
        priority_queue<int>pq;
        for(auto i:nums){
            pq.push(i);
        }
        int a=pq.top()-1;
        pq.pop();
        int b=pq.top()-1;
        return a*b;
    }





    // 1582. Special Positions in a Binary Matrix 
    int numSpecial(vector<vector<int>>& mat) {
        int row=mat.size();
        int col=mat[0].size();
        vector<int>rowCount(row,0);
        vector<int>colCount(col,0);
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(mat[i][j]==1){
                    rowCount[i]++;
                    colCount[j]++;
                }
            }
        }
        int ans=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(mat[i][j]==1){
                    if(rowCount[i]==1 && colCount[j]==1){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }




    // 2482. Difference Between Ones and Zeros in Row and Column 
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        vector<int>rowOnes(row,0);
        vector<int>colOnes(col,0);
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    rowOnes[i]++;
                    colOnes[j]++;
                }
            }
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                grid[i][j]=2*(rowOnes[i]+colOnes[j])-row-col;
            }
        }
        return grid;
    }





    // 1436. Destination City 
     string destCity(vector<vector<string>>& paths) {
        unordered_set<string>cities;
        for(auto path:paths){
            cities.insert(path[0]);
        }
        for(auto path:paths){
            string dest=path[1];
            if(cities.find(dest)==cities.end()){
                return dest;
            }
        }
        return "";
    }






    // 242. Valid Anagram 
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }
        vector<int>v(26,0);
        for(char c:s){
            v[c-'a']++;
        }
        for(char c:t){
            v[c-'a']--;
        }
        for(int i:v){
            if(i!=0){
                return false;
            }
        }
        return true;
    }





    // 1913. Maximum Product Difference Between Two Pairs
    int maxProductDifference(vector<int>& nums) {
        int smallest=INT_MAX,secondSmallest=INT_MAX;
        int largest=INT_MIN,secondLargest=INT_MIN;
        for(int i:nums){
            if(i<smallest){
                secondSmallest=smallest;
                smallest=i;
            }
            else if(i<secondSmallest){
                secondSmallest=i;
            }
            if(i>largest){
                secondLargest=largest;
                largest=i;
            }
            else if(i>secondLargest){
                secondLargest=i;
            }
        }
        return (largest*secondLargest)-(smallest*secondSmallest);
    }





    


// 661. Image Smoother
vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int row=img.size();
        int col=img[0].size();
        vector<vector<int>>res(row,vector<int>(col,0));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                int sum=0;
                int count=0;
                for(int x=max(0,i-1);x<min(i+2,row);x++){
                    for(int y=max(j-1,0);y<min(j+2,col);y++){
                        sum+=img[x][y];
                        count++;
                    }
                }
                res[i][j]=sum/count;
            }
        }
        return res;
    }




    // 2706. Buy Two Chocolates 
    int buyChoco(vector<int>& prices, int money) {
        int smallest=INT_MAX;
        int secondSmallest=INT_MAX;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<smallest){
                secondSmallest=smallest;
                smallest=prices[i];
            }else if(prices[i]<secondSmallest){
                secondSmallest=prices[i];
            }
        }
        int a=smallest+secondSmallest;
        if(a<=money){
            return money-a;
        }
        return money;
    }





    // 1637. Widest Vertical Area Between Two Points Containing No Points
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int>v;
        for(auto point:points){
            v.push_back(point[0]);
        }
        sort(v.begin(),v.end());
        int max_width=INT_MIN;
        for(int i=0;i<v.size()-1;i++){
            max_width=max(max_width,v[i+1]-v[i]);
        }
        return max_width;
    }






    // 1422. Maximum Score After Splitting a String 
    int maxScore(string s) {
        int ans=0;
        int left_zeroes=0;
        int right_ones=count(s.begin(),s.end(),'1');
        for(int i=0;i<s.size()-1;i++){
            left_zeroes+=s[i]=='0';
            right_ones-=s[i]=='1';
            ans=max(ans,left_zeroes+right_ones);
        }
        return ans;
    }




    // 1496. Path Crossing
     bool isPathCrossing(string path) {
        unordered_set<string>s;
        int x=0,y=0;
        s.insert(to_string(x)+","+to_string(y));
        for(auto d:path){
            if(d=='N'){
                y++;
            }
            else if(d=='S'){
                y--;
            }
            else if(d=='W'){
                x--;
            }
            else{
                x++;
            }
            if(s.find(to_string(x)+","+to_string(y))!=s.end()){
                return true;
            }
            s.insert(to_string(x)+","+to_string(y));
        }
        return false;
    }







    // 1758. Minimum Changes To Make Alternating Binary String 
    int minOperations(string s) {
        int a=0,b=0;
        for(int i=0;i<s.size();i++){
            if(i%2==0){
                if(s[i]=='1'){
                    a++;
                }else{
                    b++;
                }
            }
            else{
                if(s[i]=='0'){
                    a++;
                }else{
                    b++;
                }
            }
        }
        return min(a,b);
    }






    // 91. Decode Ways
    int numDecodings(string s) {
        int n=s.size();
        if(s.empty() || s[0]=='0'){
            return 0;
        }
        vector<int>dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            int oneDigit=s[i-1]-'0';
            int twoDigit=stoi(s.substr(i-2,2));
            if(oneDigit!=0){
                dp[i]+=dp[i-1];
            }
            if(twoDigit>=10 && twoDigit<=26){
                dp[i]+=dp[i-2];
            }
        }
        return dp[n];
    }





    // 1578. Minimum Time to Make Rope Colorful 
     int minCost(string colors, vector<int>& neededTime) {
        int n=colors.size();
        vector<int>dp(n+1,0);
        int previousColor='A';
        int previousTime=0;
        for(int i=1;i<=n;i++){
            if(previousColor==colors[i-1]){
                dp[i]=dp[i-1]+min(previousTime,neededTime[i-1]);
                previousTime=max(previousTime,neededTime[i-1]);
            }else{
                dp[i]=dp[i-1];
                previousTime=neededTime[i-1];
                previousColor=colors[i-1];
            }
        }
        return dp[n];
    }



    // 1155. Number of Dice Rolls With Target Sum
    int mod=1e9+7;
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return recursion(dp,n,k,target);
    }
    int recursion(vector<vector<int>>&dp,int n, int k, int target){
        if(n==0 && target==0){
            return 1;
        }
        if(n==0 || target<=0){
            return 0;
        }
        if(dp[n][target]!=-1){
            return dp[n][target]%mod;
        }
        int ways=0;
        for(int i=1;i<=k;i++){
            ways=(ways+recursion(dp,n-1,k,target-i))%mod;
        }
        dp[n][target]=ways%mod;
        return dp[n][target];
      }






    //   1897. Redistribute Characters to Make All Strings Equal 
     bool makeEqual(vector<string>& words) {
        if(words.size()==1){
            return true;
        }
        int totalCharCount=0;
        for(auto s:words){
            totalCharCount+=s.size();
        }
        if(totalCharCount%words.size()!=0){
            return false;
        }
        vector<int>v(26,0);
        for(auto s:words){
            for(auto c:s){
                v[c-'a']++;
            }
        }
        for(int i=0;i<26;i++){
            if(v[i]%words.size()!=0){
                return false;
            }
        }
        return true;
    }




    // 1624. Largest Substring Between Two Equal Characters
    int maxLengthBetweenEqualCharacters(string s) {
        int ans=-1;
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])!=mp.end()){
                ans=max(ans,i-mp[s[i]]-1);
            }else{
                mp[s[i]]=i;
            }
        }
        return ans;
    }