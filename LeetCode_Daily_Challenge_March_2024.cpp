#include<iostream>
using namespace std;
#include <vector>
#include<algorithm>




// 977. Squares of a Sorted Array
vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums[i]=nums[i]*nums[i];
        }
        sort(nums.begin(),nums.end());
        return nums;
    }




    // 2864. Maximum Odd Binary Number
    string maximumOddBinaryNumber(string s) {
        sort(s.rbegin(),s.rend());
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='1'){
                swap(s[i],s[s.size()-1]);
            }
        }
        return s;
    }





    // 3005. Count Elements With Maximum Frequency
    #include<map>
    #include<unordered_map>
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mp;
        int maxi=0;
        for(auto a:nums){
            mp[a]++;
            maxi=max(maxi,mp[a]);
        }
        int ans=0;
        for(auto a:mp){
            if(a.second==maxi){
                ans+=maxi;
            }
        }
        return ans;
    }





    // 876. Middle of the Linked List
     struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
     ListNode* middleNode(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        if(head->next->next==NULL){
            return head->next;
        }
        ListNode *slow=head;
        ListNode *fast=head->next;
        while(fast!=NULL){
            fast=fast->next;
            if(fast){
                fast=fast->next;
            }
            slow=slow->next;
        }
        return slow;
    }





    // 141. Linked List Cycle
    bool hasCycle(ListNode *head) {
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                return true;
            }
        }
        return false;
    }





    // 2540. Minimum Common Value
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int ans=-1;
        int i=0,j=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]==nums2[j]){
                ans=nums1[i];
                break;
            }
            else if(nums1[i]<nums2[j]){
                i++;
            }
            else{
                j++;
            }
        }
        return ans;
    }





    // 1750. Minimum Length of String After Deleting Similar Ends
     int minimumLength(string s) {
        int left=0,right=s.size()-1;
        while(left<right && s[left]==s[right]){
            char ch=s[left];
            while(left<=right && s[left]==ch){
                left++;
            }
            while(left<=right && s[right]==ch){
                right--;
            }
        }
        return right-left+1;
    }






    // 19. Remove Nth Node From End of List
     ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy=new ListNode(0);
        dummy->next=head;
        ListNode *first=dummy;
        ListNode *second=dummy;
        for(int i=0;i<=n;i++){
            first=first->next;
        }
        while(first){
            first=first->next;
            second=second->next;
        }
        ListNode *temp=second->next;
        second->next=second->next->next;
        delete temp;
        return dummy->next;
    }





    // 349. Intersection of Two Arrays
    #include<unordered_set>
     vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>s1(nums1.begin(),nums1.end());
        unordered_set<int>s2(nums2.begin(),nums2.end());
        vector<int>ans;
        for(auto a:s1){
            if(s2.find(a)!=s2.end()){
                ans.push_back(a);
            }
        }
        return ans;
    }




    // 791. Custom Sort String
     string customSortString(string order, string s) {
        unordered_map<char,int>mp;
        for(auto c:order){
            mp[c]=0;
        }
        for(auto c:s){
            if(mp.find(c)!=mp.end()){
                mp[c]++;
            }
        }
        string ans;
        for(auto c:order){
            ans.append(mp[c],c);
        }
        for(auto c:s){
            if(mp.find(c)==mp.end()){
                ans.push_back(c);
            }
        }
        return ans;
    }







    // 2485. Find the Pivot Integer
    int pivotInteger(int n) {
        int ans=-1;
        for(int i=1;i<=n;i++){
            int a=(i*(i+1))/2;
            int b=(n*(n+1))/2 - (i*(i-1))/2;
            if(a==b){
                ans=i;
            }
        }
        return ans;
    }





    // 930. Binary Subarrays With Sum
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>mp;
        mp[0]=1;
        int sum=0;
        int ans=0;
        for(auto num:nums){
            sum+=num;
            if(mp.find(sum-goal)!=mp.end()){
                ans+=mp[sum-goal];
            }
            mp[sum]++;
        }
        return ans;
    }






    // 238. Product of Array Except Self
     vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        vector<int>prefix(n,1);
        vector<int>suffix(n,1);
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]*nums[i-1];
        }
        for(int i=n-2;i>=0;i--){
            suffix[i]=suffix[i+1]*nums[i+1];
        }
        for(int i=0;i<n;i++){
            ans[i]=prefix[i]*suffix[i];
        }
        return ans;
    }





    // 525. Contiguous Array
    int findMaxLength(vector<int>& nums) {
        int len=0,n0=0,n1=0;
        unordered_map<int,int>mp;
        mp[0]=-1;
        for(int i=0;i<nums.size();i++){
            n0+=nums[i];
            n1=(i+1)-n0;
            if(mp.count(n1-n0)!=0){
                len=max(len,i-mp[n1-n0]);
            }else{
                mp[n1-n0]=i;
            }
        }
        return len;
    }






    // 57. Insert Interval
      vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        int i=0;
        int n=intervals.size();
        while(i<n && intervals[i][1]<newInterval[0]){
            ans.push_back(intervals[i]);
            i++;
        }
        while(i<n && intervals[i][0]<=newInterval[1]){
            newInterval={min(intervals[i][0],newInterval[0]),max(intervals[i][1],newInterval[1])};
            i++;
        }
       ans.push_back(newInterval);
       while(i<n){
        ans.push_back(intervals[i]);
        i++;
       }
       return ans;
    }






    // 452. Minimum Number of Arrows to Burst Balloons
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int ans=1;
        int end=points[0][1];
        for(int i=1;i<points.size();i++){
            if(points[i][0]>end){
                ans++;
                end=points[i][1];
            }else{
                end=min(end,points[i][1]);
            }
        }
        return ans;
    }






    // 206. Reverse Linked List
    void solve(ListNode* &head, ListNode *curr,ListNode *prev){
        if(curr==NULL){
            head=prev;
            return;
        }
        ListNode *forward=curr->next;
        solve(head,forward,curr);
        curr->next=prev;
     }
    ListNode* reverseList(ListNode* head) {
        ListNode *prev=NULL;
        ListNode *curr=head;
        solve(head,curr,prev);
        return head;
    }






    // 234. Palindrome Linked List
    ListNode* getMiddle(ListNode *head){
    ListNode *slow=head;
    ListNode *fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
ListNode* reverse(ListNode *head){
    ListNode *prev=NULL;
    ListNode *curr=head;
    ListNode *forward=NULL;
    while(curr!=NULL){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    return prev;
}
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL){
            return true;
        }
        ListNode *middle=getMiddle(head);
        ListNode *temp=middle->next;
        middle->next=reverse(temp);
        ListNode *head1=head;
        ListNode *head2=middle->next;
        while(head2!=NULL){
            if(head1->val!=head2->val){
                return false;
            }
            head1=head1->next;
            head2=head2->next;
        }
        return true;
    }





    // 1669. Merge In Between Linked Lists
      ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *ptr=list1;
        for(int i=0;i<a-1;i++){
            ptr=ptr->next;
        }
        ListNode *qtr=ptr->next;
        for(int i=0;i<b-a+1;i++){
            qtr=qtr->next;
        }
        ptr->next=list2;
        while(list2->next){
            list2=list2->next;
        }
        list2->next=qtr;
        return list1;
    }





    // 621. Task Scheduler
      int leastInterval(vector<char>& tasks, int n) {
        vector<int>v(26,0);
        for(auto task:tasks){
            v[task-'A']++;
        }
       sort(v.begin(),v.end());
       int chunk=v[25]-1;
       int idle=chunk*n;
       for(int i=24;i>=0;i--){
        idle-=min(v[i],chunk);
       }
       if(idle<0){
        return tasks.size();
       }
       return tasks.size()+idle;
    }






    // 287. Find the Duplicate Number
    int findDuplicate(vector<int>& nums) {
        unordered_set<int>s;
        for(int i=0;i<nums.size();i++){
            if(s.find(nums[i])!=s.end()){
                return nums[i];
            }
            s.insert(nums[i]);
        }
        return -1;
    }






    // 442. Find All Duplicates in an Array
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int>mp;
        vector<int>ans;
        for(auto a:nums){
            mp[a]++;
        }
        for(auto a:mp){
            if(a.second>1){
                ans.push_back(a.first);
            }
        }
        return ans;
    }






    // 41. First Missing Positive
       int firstMissingPositive(vector<int>& nums) {
        unordered_map<int,bool>mp;
        int n=nums.size();
        int maxi=*max_element(nums.begin(),nums.end());
        for(auto a:nums){
            mp[a]=1;
        }
        for(int i=1;i<maxi;i++){
            if(mp.find(i)==mp.end()){
                return i;
            }
        }
        if(maxi<0){
            return 1;
        }
        return maxi+1;
    }





    // 713. Subarray Product Less Than K
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left=0,right=0,product=1,count=0;
        int n=nums.size();
        if(k<=1)return 0;
        while(right<n){
            product*=nums[right];
            while(product>=k)product/=nums[left++];
            count+=(right-left)+1;
            right++;
        }
        return count;
    }






    // 2958. Length of Longest Subarray With at Most K Frequency
     int maxSubarrayLength(vector<int>& nums, int k) {
        int ans=0;
        int n=nums.size();
        unordered_map<int,int>mp;
        int left=0,right=0;
        while(right<n){
            mp[nums[right]]++;
            if(mp[nums[right]]>k){
                while(mp[nums[left]]!=mp[nums[right]]){
                    mp[nums[left]]--;
                    left++;
                }
                mp[nums[left]]--;
                left++;
            }
            ans=max(ans,right-left+1);
            right++;
        }
        return ans;
    }






    // 2444. Count Subarrays With Fixed Bounds
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans=0;
        int b=-1,l=-1,r=-1;
        for(int i=0;i<nums.size();i++){
            if(!(minK<=nums[i] && nums[i]<=maxK)){
                b=i;
            }
            if(minK==nums[i])l=i;
            if(maxK==nums[i])r=i;
            ans+=max(0,min(l,r)-b);
        }
        return ans;
    }