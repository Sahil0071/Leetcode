class Solution {
public:
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n=nums1.size()+nums2.size();
        vector<int>v(n);
        int k=0,i=0,j=0;double d;
        while(i<nums1.size()&&j<nums2.size())
        {
            if(nums1[i]<nums2[j])
            {
                v[k++]=nums1[i];
                i++;
            }
            else
            {
                v[k++]=nums2[j];
                j++;
            }
            if(k==(n/2)+1)
            {
                if(n&1)
                {
                     d=v[n/2];

                }
                else
                     d=(v[(n-1)/2]+v[n/2])/2.0;
                return d;
            }
        }
        while(i<nums1.size())
        {
            v[k++]=nums1[i++];
        }
        while(j<nums2.size())
        {
            v[k++]=nums2[j++];
        }
        
        if(n&1)
        {
             d=v[n/2];
            
        }
        else
             d=(v[(n-1)/2]+v[n/2])/2.0;
        
        return d;
        
    }
};
