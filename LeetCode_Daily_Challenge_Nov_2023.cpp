#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>

// 501. Find Mode in Binary Search Tree 
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
void inorder(TreeNode *root,vector<int>&in){
        if(!root){
            return;
        }
        in.push_back(root->val);
        inorder(root->left,in);
        inorder(root->right,in);
    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int>mp;
        vector<int>in;
        int maxi=0;
        inorder(root,in);
        vector<int>ans;
        for(auto i:in){
            mp[i]++;
            maxi=max(mp[i],maxi);
        }
        for(auto i:mp){
            if(i.second==maxi){
                ans.push_back(i.first);
            }
        }
        return ans;
    }




    // 2265. Count Nodes Equal to Average of Subtree 
    #include<pair>
    pair<int,int> traverse(TreeNode *root,int &ans){
        if(!root){
            return {0,0};
        }
        auto [left_sum,left_count]=traverse(root->left,ans);
        auto [right_sum,right_count]=traverse(root->right,ans);
        int curr_sum= root->val+left_sum+right_sum;
        int curr_count=1+left_count+right_count;
        if(curr_sum/curr_count ==root->val){
            ans++;
        }
        return {curr_sum,curr_count};
    }
    int averageOfSubtree(TreeNode* root) {
        int ans=0;
        traverse(root,ans);
        return ans;
    }




    // 1441. Build an Array With Stack Operations 
    vector<string> buildArray(vector<int>& target, int n) {
        unordered_set<int>target_set(target.begin(),target.end());
        vector<string>ans;
        for(int i=1;i<=target.back();i++){
            if(target_set.find(i)!=target_set.end()){
                ans.push_back("Push");
            }else{
                ans.push_back("Push");
                ans.push_back("Pop");
            }
        }
        return ans;
    }




    // 1503. Last Moment Before All Ants Fall Out of a Plank 
     int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int maxLeft=left.empty()?0:*max_element(left.begin(),left.end());
        int minRight=right.empty()?n:*min_element(right.begin(),right.end());
        return max(maxLeft,n-minRight);
    }



    // 2849. Determine if a Cell Is Reachable at a Given Time 
     bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int xDist=abs(sx-fx);
        int yDist=abs(sy-fy);
        if(xDist==0 && yDist==0){
            return t!=1;
        }
        return xDist<=t && yDist<=t;
    }




    // 1759. Count Number of Homogenous Substrings 
     int countHomogenous(string s) {
        long long ans=0;
        int left=0;
        for(int right=0;right<s.size();right++){
            if(s[left]==s[right]){
                ans+=right-left+1;
            }else{
                ans++;
                left=right;
            }
        }
        return (int)(ans%1000000007);
    }




    // 1930. Unique Length-3 Palindromic Subsequences   
    int countPalindromicSubsequence(string s) {
        int ans=0;
        unordered_set<char>unique;
        for(char c:s){
            unique.insert(c);
        }
        for(char c:unique){
            int start=s.find(c);
            int end=s.rfind(c);
            if(start<end){
                unordered_set<char>st;
                for(int i= start+1;i<end;i++){
                    st.insert(s[i]);
                }
                ans+=st.size();
            }
        }
        return ans;
    }




    // 1877. Minimize Maximum Pair Sum in Array 
    int minPairSum(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MIN;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n/2;i++){
            ans=max(ans,nums[i]+nums[n-i-1]);
        }
        return ans;
    }




    // 1838. Frequency of the Most Frequent Element 
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long long i=0,j=0,ans=0,sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            while((i-j+1)*nums[i]-sum>k){
                sum-=nums[j];
                j++;
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }






    #include<windows.h>
#include<iostream>
using namespace std;
#include<GL/freeglut.h>
#include<math.h>

int rround(float n);
void makeStar();

int rround(float n)
{
    if (n - (int)n < 0.5)
        return (int)n;
    return (int)(n + 1);
}

void standardLine(float a0, float b0, float a1, float b1)
{
    int x0= rround(a0);
    int x1 = rround(a1);
    int y0 = rround(b0);
    int y1 = rround(b1);

    float m = float(y1 - y0)/(x1 - x0);

    float c = (y0 - m*x0);
    float s;
    if(abs(m)<1)
    {
        s= x0>x1?x1:x0;
        for(int i=0; i<=abs(x1-x0); i++)
        {
            float y = m*(s+i)+ c;
            glVertex2f(rround(s+i), rround(y));
            cout << "(" << round(s+i) << " " << round(y) << ")";
        }

    }
    else
    {
        s= y0>y1?y1:y0;
        for(int i=0; i<= abs(y1 - y0) ; i++)
        {
            float x = (s+i - c)/m;
            glVertex2f(rround(x), rround(s+i));
            cout << "(" << rround(x) << " " << rround(s+i) << ")";
        }
    }

    cout<<endl;

}

void DDALine(float a0, float b0, float a1, float b1)
{
    int x0= rround(a0);
    int x1 = rround(a1);
    int y0 = rround(b0);
    int y1 = rround(b1);


    // Calculate dx and dy
    int dx = x1 - x0;
    int dy = y1 - y0;

    int step;

    if (abs(dx) > abs(dy))
        step = abs(dx);
    else
        step = abs(dy);
    float x_incr = (float)dx / step;
    float y_incr = (float)dy / step;

    float x = x0;
    float y = y0;


    for (int i = 0; i <= step; i++) {


        glVertex2d(rround(x), rround(y));
        cout << "(" <<rround(x) << "," << rround(y) <<")";
        x += x_incr;
        y += y_incr;

    }
}

void makeA(float x1, float y1, float x2, float y2, float x3, float y3,float x4,float y4, float x5,float y5)
{
    glColor3f(0, 0, 1.0);
    DDALine(x1, y1, x2, y2);
    glColor3f(0, 1.0, 0.4);
    DDALine(x1, y1, x3, y3);
    glColor3f(1.0f, 0.5f, 0.0f);
    DDALine(x3, y3, x2, y2);
    glColor3f(0, 0, 1.0);
    DDALine(x2, y2, x4, y4);
    glColor3f(0, 1.0, 0.4);
    DDALine(x3, y3, x5, y5);
}

void makerectangle(float x1, float y1, float x2, float y2, float x3, float y3,float x4,float y4)
{
    DDALine(x1, y1, x2, y2);
    DDALine(x2, y2, x3, y3);
    DDALine(x3, y3, x4, y4);
    DDALine(x4, y4, x1, y1);
}





void drawCircleMidpoint(int xc, int yc, int radius) {
    int x = 0;
    int y = radius;
    int p = 1 - radius;

    // Plot the initial point in each quadrant
    glVertex2f(x, y);

    while (x < y) {
        x++;
        if (p < 0) {
            p += 2 * x + 1;
        } else {
            y--;
            p += 2 * (x - y) + 1;
        }
        glVertex2f(x, y);
    }
}

void plotEPoints(int x, int y) {

    glVertex2i(x , y );
    glVertex2i(-x , y );
    glVertex2i(x , -y );
    glVertex2i(-x , -y );

}

void drawEllipseMidpoint(int xc, int yc, int a, int b) {
    int x = 0;
    int y = b;
    double d1 = b * b - a * a * b + 0.25 * a * a;
    int dx = 2 * b * b * x;
    int dy = 2 * a * a * y;

    // Plot the initial point in each quadrant
    plotEPoints(x+xc, y+yc);

    while (dx < dy) {
        x++;
        if (d1 < 0) {
            dx += 2 * b * b;
            d1 += dx + b * b;
        } else {
            y--;
            dx += 2 * b * b;
            dy -= 2 * a * a;
            d1 += dx - dy + b * b;
        }
        plotEPoints(x+xc, y+yc);
    }

    double d2 = b * b * (x + 0.5) * (x + 0.5) + a * a * (y - 1) * (y - 1) - a * a * b * b;

    while (y >= 0) {
        y--;
        if (d2 > 0) {
            dy -= 2 * a * a;
            d2 += a * a - dy;
        } else {
            x++;
            dx += 2 * b * b;
            dy -= 2 * a * a;
            d2 += dx - dy + a * a;
        }
        plotEPoints(x, y);
    }
}

void plotHPoints(int x, int y) {
    // Assuming you're using glVertex2i for plotting points
    glVertex2i(x, y);
    glVertex2i(-x, y);
    glVertex2i(x, -y);
    glVertex2i(-x, -y);
}

void drawHyperbolaMidpoint(int xc, int yc, int a, int b) {
    int x = 0;
    int y = b;
    double d1 = b * b - a * a * b + 0.25 * a * a;
    int dx = 2 * b * b * x;
    int dy = 2 * a * a * y;

    // Plot the initial point in each quadrant
    plotHPoints(x + xc, y + yc);

    while (dx < dy) {
        x++;
        if (d1 < 0) {
            dx += 2 * b * b;
            d1 += dx + b * b;
        } else {
            y--;
            dx += 2 * b * b;
            dy -= 2 * a * a;
            d1 += dx - dy + b * b;
        }
        plotHPoints(x + xc, y + yc);
    }

    double d2 = b * b * (x + 0.5) * (x + 0.5) + a * a * (y - 1) * (y - 1) - a * a * b * b;

    while (y >= 0) {
        y--;
        if (d2 > 0) {
            dy -= 2 * a * a;
            d2 += a * a - dy;
        } else {
            x++;
            dx += 2 * b * b;
            dy -= 2 * a * a;
            d2 += dx - dy + a * a;
        }
        plotHPoints(x + xc, y + yc);
    }
}

void drawParabola(int x0, int y0, int a) {
    int x = 0;
    int y = 0;
    int Pk = 1 - 2 * a;

    // Offset the initial position by (x0, y0)
    x += 0;
    y += 0;

    glVertex2i(x+x0, y+y0);

    while (x < 2 * a) {
        x++;
        if (Pk < 0) {
            Pk += 2 * x + 3;
        } else {
            y++;
            Pk += 2 * x + 3 - 4 * a;
        }

        // Plot points in all octants
        glVertex2i(x + x0, y + y0);
        glVertex2i(-x + x0, y + y0);
    }

    Pk = 1 / 4 - 2 * a;
    while (y < 25 * a) {
        y++;
        if (Pk > 0) {
            Pk -= 4 * a;
        } else {
            x++;
            Pk += 2 * y + 2 - 4 * a;
        }

        glVertex2i(x + x0, y + y0);
        glVertex2i(-x + x0, y + y0);
    }
}

void drawHyperbola(int a, int b, int xc, int yc) {
    glColor3f(0.0, 1.0, 1.0);
    glPointSize(2.0);

    //glBegin(GL_POINTS);

    for (int x = -a; x <= a; x++) {
        float y = b * sqrt(1 + (x * x) / (float)(a * a));
        glVertex2f(x + xc, y + yc);
        glVertex2f(x + xc, -y + yc);
    }

    //glEnd();
}




void makeStar()
{
DDALine(-6, -6, 6,-6);
   DDALine(6, -6, 0, 9);
   DDALine(0, 9, -6, -6);

   DDALine(-6, 6, 6,6);
   DDALine(6, 6, 0, -9);
   DDALine(0, -9, -6, 6);
}

void display()
{
   glClear(GL_COLOR_BUFFER_BIT);
   glPointSize(3.0);
   glBegin(GL_POINTS);
   glColor3f(1.0, 0.0, 0.0);
//using standard line equation to draw the line
   //standardLine(60,60, -60, 60);
   //makeStar();
   //makeA(50, 100, 25, 0, 75, 0, 0, -100, 100, -100);
   //makerectangle(20.0,50.0,70.0,50.0,70.0,20.0,20.0,20.0);
   //DDALine(40.0, -40.0, -40.0, 40.0);
   //standardLine(40.0, 40.0, -40.0, -40.0);
   glColor3f(1.0, 0.5, 0.5);
   //drawEllipseMidpoint(0, 0, 10, 20);
   drawHyperbola(10, 20, 0, 0);
   drawParabola(5, 4, 5);
   //drawHyperbola(2, 1);

   glEnd();
   glFlush();
}



int main(int argc, char** argv )
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(512, 512);
    glutCreateWindow("OpenGL standard line draw");
    glClearColor(0.1, 0.5, 0.6, 0.2);
    //glMatrixMode(GL_PROJECTION);
    //glLoadIdentity();

    // Set up the viewing area
    glOrtho(-100.0, 100.0, -100.0, 100.0, -10.0, 10.0);

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}


   //DDALine(4.0, -4.0, -4.0, 4.0);
   //makerectangle(2.0,5.0,7.0,5.0,7.0,2.0,2.0,2.0);
   //standardLine(4.0, 4.0, -4.0, -4.0);
   //star making
   //DDALine(2.1, 2.3, 6.7,5.2);
   //DDALine(9, -9, 0, 9);
   //(0, 9, -9, -9);
   //makeStar();


//for star
//triangle1
// (3.46, 4.02), (6.93, -2), (0, -2) ,
// (3.46, -4.02), (0,2), (6.93, 2)