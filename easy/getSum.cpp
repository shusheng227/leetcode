// Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.
// 将数字当作二进制数看待，二进制异或为相加结果、想与为相加进位
#include <stdio.h> 

int getSum(int a, int b){
    unsigned int result1 = a;
    unsigned int result2 = b;
    int count = 1;
    while(result2) {
        unsigned int temp = result1;
        result1 = result1^result2;
        result2 = (temp&result2)<<1;
        printf("The %dth result：result1(%d),result2(%d)\n",
				count++,result1,result2);
    }
    return (int)result1;
    // 更便捷的表达方式 
	// return b==0? a:getSum(a^b, (unsigned int)(a&b)<<1);
}

int main() {
	printf("%d\n",getSum(-10,2));
	return 0;
} 

