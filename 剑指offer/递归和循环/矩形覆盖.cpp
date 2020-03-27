class Solution {
public:
    int rectCover(int number) {
        if(number <= 2) return number;
        int i = 1;
        int j = 2;
        int res = 0;

        for(int k=2; k<number; ++k) {
            res = i + j;
            i = j;
            j = res;
        }

        return res;
    }
};