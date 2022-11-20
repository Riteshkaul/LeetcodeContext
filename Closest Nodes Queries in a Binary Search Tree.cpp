class Solution {
public:
    void inorder(TreeNode* root, vector<int>& v)
    {
        if(!root)
        {
            return;
        }
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
         int n=queries.size();
        vector<vector<int>>ans;
        
       vector<int>v;
        inorder(root,v);
        for(auto q:queries)
        {
            int num1=-1;
            int num2=-1;
            int l=0;
            int h=v.size()-1;
            while(l<=h)
            {
                int mid =(l+h)/2;
                if(v[mid]<=q)
                {
                    num1=v[mid];
                    l=mid+1;
                }
                else{
                    h=mid-1;
                }
            }
            l=0,h=v.size()-1;
            while(l<=h)
            {
                int mid = (l+h)/2;
                if(v[mid]>=q)
                {
                    num2=v[mid];
                    h=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            ans.push_back({num1,num2});
        }
        return ans;
    }
};
