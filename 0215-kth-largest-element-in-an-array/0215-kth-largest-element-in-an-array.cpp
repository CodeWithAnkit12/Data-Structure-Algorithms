class Solution {
public:
int func(vector<int>& nums, int l, int r) {
    int p = nums[l];

    int i = l + 1;
    int j = r;

    while (i <= j) {

        while (i <= r && nums[i] <= p) {
            i++;
        }

        while (j >= l && nums[j] > p) {
            j--;
        }

        if (i < j) {
            swap(nums[i], nums[j]);
        }
    }

    swap(nums[l], nums[j]);

    return j;
}
int findKthLargest(vector<int>& nums, int k) {
    int n = nums.size();

    int target = n - k;

    int l = 0;
    int r = n - 1;

    while (true) {

        int p = func(nums, l, r);

        if (p == target) {
            return nums[p];
        }
        else if (p > target) {
            r = p - 1;
        }
        else {
            l = p + 1;
        }
    }
}
};