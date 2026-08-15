class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        // Sort both arrays so we can use two pointers.
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        // This will store the unique common elements.
        vector<int> ans;

        // Two pointers, one for each array.
        int i = 0;
        int j = 0;

        // Continue until we reach the end of either array.
        while (i < nums1.size() && j < nums2.size()) {

            // If both elements are equal,
            // we found an element present in both arrays.
            if (nums1[i] == nums2[j]) {

                // Add the element only if the answer is empty
                // or the previous element is different.
                if (ans.empty() || ans.back() != nums1[i]) {
                    ans.push_back(nums1[i]);
                }

                // Move both pointers forward.
                i++;
                j++;
            }

            // If nums1[i] is smaller,
            // move i forward to find a bigger value.
            else if (nums1[i] < nums2[j]) {
                i++;
            }

            // If nums2[j] is smaller,
            // move j forward to find a bigger value.
            else {
                j++;
            }
        }

        // Return the unique intersection.
        return ans;
    }
};