/**
 * 小明同学把1到n这n个数字按照一定的顺序放入了一个队列Q中。现在他对队列Q执行了如下程序：
 * while(!Q.empty())              //队列不空，执行循环
 * {
 *      int x=Q.front();         //取出当前队头的值x
 *      Q.pop();                 //弹出当前队头
 *      Q.push(x);               //把x放入队尾
 *      x = Q.front();           //取出这时候队头的值
 *      printf("%d\n",x);        //输出x
 *      Q.pop();                 //弹出这时候的队头
 * }
 * 小明同学发现，这段程序恰好按顺序输出了1,2,3,...,n。现在小明想让你构造出原始的队列，你能做到吗？
 * 输入描述：第一行一个整数T（T ≤ 100）表示数据组数，每组数据输入一个数n（1 ≤ n ≤ 100000），输入的所有n之和不超过200000。
 * 输出描述：对于每组数据，输出一行，表示原始的队列。数字之间用一个空格隔开，不要在行末输出多余的空格.
 */
/**
 * 思路：
 * 观察程序段发现本段代码的实质为：不断取出队列元素，并将第偶数个输出并弹出
 * 构造时可以逆向还原，先申明一个大小为n的数组
 * 刚开始数组所有位置为空，堆数组进行遍历，每当遇到第二个空位置时插入
 * 通过此方法可将1到n-1插入，接着将n插入剩余的一个空格中
 */

#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> v);

vector<int> helper(int n) {
    vector<int> res(n,0);
    int isTwo = 0;      //是否遇到第二个空位置的标志
    int j = 0;
    for(int i=1; i<n; ++i) {
        while(1) {
            if(res[j] == 0) ++isTwo;
            if(isTwo == 2) {
                isTwo = 0;
                res[j] = i;
                break;
            }
            j = (++j)%n;
        }
        //print(res);
    }
    for(int i=0; i<n; i++) {
        if(res[i] == 0) res[i] = n;
    }

    return res;
}

void print(vector<int> v) {
    int i=0;
    for( ; i<v.size()-1; ++i) {
        cout << v[i] << ' ';
    }
    cout << v[i] << endl;
}

int main() {
    int T = 0;
    cin >> T;
    vector<int> v(T);
    for(int i=0; i<T; ++i) {
        cin >> v[i];
    }
    for(int i=0; i<T; ++i) {
        print(helper(v[i]));
    }
}