/**
 * 在金融资产交易中，经常涉及到资产包的挑选打包。
 * 在资产包打包过程中，每种类型的资产有固定的数量与价值，需选择某几种资产打包，使得资产包总价值最大。
 * 打包时每种资产只能整体打包，不能分割。假设现有可容纳M条资产的资产包，另外有N种资产。资产Na数量为Ta条，总价值为Va元；
 * 资产Nb数量为Tb条，总价值为Vb元；资产Nc数量为Tc条，总价值为Vc元......；资产Nn数量为Tn，总价值为Vn。
 * 编写算法，挑选哪些类型资产放入资产包可使得资产包总价值最大？
 * 
 * 输入描述：
 * 资产总量,资产种类,每类资产条数,每类资产价值(逗号分隔)；其中每类资产条数与每类资产价值为空格分隔。
 * 总格式如下：
 * 资产总量,资产种类,资产A条数 资产B条数 资产C条数,资产A价值 资产B价值 资产C价值！
 * 举例，资产总量为12，资产种类3种，3种资产条数分别为4，5，7，三种资产价值分别是500元，600元，800元，输入如下：
 * 12,3,4 5 7,500 600 800
 * 资产总量和资产种类都不超过1000，资产条数不超过1000，资产价值不超过10000，所有数值均为正整数。
 * 
 * 输出描述：
 * 资产包中资产最大总价值
 */
#include <iostream>
#include <vector>
using namespace std;
/**
 * bagV:            背包大小
 * num:             物品数
 * w[num]：         物品体积
 * v[num]：         物品价值
 * dp[num][bagV]：  二维数组，动态规划表，dp[i][j]表示容量为j的背包只装前i项物品的最大价值
 */
class KnapsackProblem {
public:
    long run(int bagV, int num, vector<int> w, vector<long> v) {
        vector<vector<long> > dp(num+1, vector<long>(bagV+1));
        w.insert(w.begin(), 0);
        v.insert(v.begin(), 0);

        for(int i = 1; i <= num; ++i) {
            for(int j = 1; j < w[i]; ++j) {
                dp[i][j] = dp[i-1][j];
            }
            for(int j = w[i]; j <= bagV; ++j) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]);
            }
        }

        return dp[num][bagV];
    }
};

int main() {
    int bagV;
    int num;
    char c;
    cin >> bagV >> c >> num >> c;
    vector<int> w(num);
    vector<long> v(num);
    for(int i = 0; i < num; ++i) {
        cin >> w[i];
    }
    cin >> c;
    for(int i = 0; i < num; ++i) {
        cin >> v[i];
    }
    KnapsackProblem k;
    cout << k.run(bagV, num, w, v);
}