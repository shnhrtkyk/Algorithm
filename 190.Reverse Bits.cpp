class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = 0;
        for(int i = 0; i< 32; ++i){
            ret <<= 1;
            if((n & 1) == 1) ++ret;
            n >>= 1;
        }
        return ret;
    }
};
/*
思路：
1.目的是反转，但是方法中的数值类型和返回值都是uint32_t,因此不需要考虑int->二进制的问题
2.建立一个新的ret，从原数的尾部开始不断添加到ret中
3.ret的原始值为0， 每次进入循环后，ret向左移动一位，给新的数字腾出一个空间
4.用原数与1做位与运算，位与：都是1才为1，否则为0.e.g. 1010 & 0001 = 0000， 1011 & 0001 = 0001，可用来判断奇偶数
5.如果为偶数，ret无变化；如果为奇数，ret+1
6.将原数向右移动一位，最后循环结束返回即可
注意：
1.ret <<= 1;  <=> ret = ret << 1;
*/