#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        // Facciamo in modo che nums1 sia sempre l'array più piccolo
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();

        int left = 0;
        int right = m;

        while (left <= right) {
            int partitionA = (left + right) / 2;
            int partitionB = (m + n + 1) / 2 - partitionA;

            // Elementi a sinistra e a destra delle partizioni
            int maxLeftA  = (partitionA == 0) ? INT_MIN : nums1[partitionA - 1];
            int minRightA = (partitionA == m) ? INT_MAX : nums1[partitionA];

            int maxLeftB  = (partitionB == 0) ? INT_MIN : nums2[partitionB - 1];
            int minRightB = (partitionB == n) ? INT_MAX : nums2[partitionB];

            // Partizione corretta
            if (maxLeftA <= minRightB && maxLeftB <= minRightA) {

                // Se il totale è dispari
                if ((m + n) % 2 == 1) {
                    return max(maxLeftA, maxLeftB);
                }

                // Se il totale è pari
                return (max(maxLeftA, maxLeftB) +
                        min(minRightA, minRightB)) / 2.0;
            }

            // Ci siamo spostati troppo a destra in nums1
            else if (maxLeftA > minRightB) {
                right = partitionA - 1;
            }

            // Ci siamo spostati troppo a sinistra in nums1
            else {
                left = partitionA + 1;
            }
        }

        return 0.0; // Non dovrebbe mai essere raggiunto
    }
};