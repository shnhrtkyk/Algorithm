题意：
找到数组中有几个子数组的乘积小于目标值。
思路：
1.遇到在数组中找子数组的问题，首先想到两个指针。
注意两个指针式滑动窗口的变形，也就是说不仅仅表示了两个可移动的指针，只要是确定窗口之间的范围，同时及时进行边界的移动。
2.因为题目中的要求是严格小于，同时所有的数字都是正数，因此最小值为1，如果目标值小于等于1，那么直接返回0。
3.设立左边界，用右边界进行遍历，每次算上乘积。
一旦乘积大于目标值，那么用while循环开始缩小左边界，一旦小于之后，将左右边界之间有几个数字的结果输入到结果数组中,即表示以该数字为结尾的数，能构成的子数组的个数。
比如[5 2 6]这个窗口，k还是100，右边界刚滑到6这个位置，这个窗口的大小就是包含6的子数组乘积小于k的个数，即[6], [2 6], [5 2 6]，正好是3个
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        int left = 0;
        int total = 1;
        int ret = 0;
        for(int i = 0; i < nums.size(); ++i){
            total *= nums[i];
            while(total >= k) total /= nums[left++];
            ret += i-left+1;
        }
        return ret;
    }
};

2.4复习
注意：
因为题目中说的是所有小于K的子数组，所以如果能找到一种情况，那么它区间范围内的所有取值都应该计算，那么结果就是这个区间的长度。
注意如果k<=1的时候不需要判断，直接返回0。因为如果不提前判断的话，k为1时，while循环中left会直接进入到最后一位,会得到错误结果。
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        int total = 1;
        int count = 0;
        int left = 0;
        for(int i = 0; i < nums.size(); ++i){
            total *= nums[i];
            while(total >= k){
                total /= nums[left];
                ++left;
            }
            count += i-left+1;
        }
        return count;
    }
};