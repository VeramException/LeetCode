class Solution
{
    public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {        
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        if (n1 < n2)
            return findMedianSortedArrays(nums2, nums1); // nums2 should have less# elements
        
        int lo = 0;
        int hi = n2*2;        
        while (lo <= hi)
        {
            int cut2 = (lo+hi)/2;
            int cut1 = (n1+n2) - cut2;
            
            double l1 = (cut1 == 0)? INT_MIN: nums1[(cut1-1)/2];
            double l2 = (cut2 == 0)? INT_MIN: nums2[(cut2-1)/2];
            
            double r1 = (cut1 == n1*2)? INT_MAX: nums1[cut1/2];
            double r2 = (cut2 == n2*2)? INT_MAX: nums2[cut2/2];
            
            // This condition should be satisified: l1 < r2 && l2 < r1)
            if (l1 > r2)
                lo = cut2+1;
            else if (l2 > r1)
                hi = cut2-1;
            else
                return (max(l1,l2)+min(r1,r2))/2;
        }
        
        return -1;
    }
};