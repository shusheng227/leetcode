/**
 * 求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
 */
/**
 * 使用递归即可计算和，但会使用if判断参数是否为0
 * 可使用逻辑与判断是否大于0，如果n小于0逻辑与会直接结束步计算后一项从而奇数递归
 */

class Solution {
public:
    int Sum_Solution(int n) {
        int ret = n;
        n && (ret += Sum_Solution(n-1)); 
        return ret;
    }
};
