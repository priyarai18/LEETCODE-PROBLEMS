class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        int m = nums1.size(), n = nums2.size(), low = 0, high = m;
        while (low <= high) {
            int i = (low + high) / 2, j = (m + n + 1) / 2 - i;
            int l1 = i ? nums1[i - 1] : INT_MIN, r1 = i < m ? nums1[i] : INT_MAX;
            int l2 = j ? nums2[j - 1] : INT_MIN, r2 = j < n ? nums2[j] : INT_MAX;
            if (l1 <= r2 && l2 <= r1) {
                return (m + n) % 2 ? max(l1, l2) : (max(l1, l2) + min(r1, r2)) / 2.0;
            }
            l1 > r2 ? high = i - 1 : low = i + 1;
        }
        return 0.0;
    }
};