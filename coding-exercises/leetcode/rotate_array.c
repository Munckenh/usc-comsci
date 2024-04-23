/*
 * 189. Rotate Array
 *
 * Given an integer array `nums`, rotate the array to the right by `k`
 * steps, where `k` is non-negative.
 *
 * Example 1:
 * > Input: nums = [1,2,3,4,5,6,7], k = 3
 * > Output: [5,6,7,1,2,3,4]
 * > Explanation:
 * >    rotate 1 steps to the right: [7,1,2,3,4,5,6]
 * >    rotate 2 steps to the right: [6,7,1,2,3,4,5]
 * >    rotate 3 steps to the right: [5,6,7,1,2,3,4]
 * 
 * Example 2:
 * > Input: nums = [-1,-100,3,99], k = 2
 * > Output: [3,99,-1,-100]
 * > Explanation:
 * >    rotate 1 steps to the right: [99,-1,-100,3]
 * >    rotate 2 steps to the right: [3,99,-1,-100]
 * 
 * Constraints:
 *      - `1 <= nums.length <= 10^5`
 *      - `-2^31 <= nums[i] <= 2^31-1`
 *      - `0 <= k <= 10^5`
 */

#include <stdio.h>
#include <string.h>

void rotate(int* nums, int size, int k);
void print_array(int* arr, int size);

int main() {
    int nums[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    rotate(nums, 9, 2);
    print_array(nums, 9);
    return 0;
}

void rotate(int* nums, int size, int k) {
    if (k >= size) {
        k -= size * (k / size);
    }
    int tmp[k];
    memcpy(tmp, nums + size - k, k * sizeof(int));
    memcpy(nums + k, nums, (size - k) * sizeof(int));
    memcpy(nums, tmp, k * sizeof(int));
}

void print_array(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}