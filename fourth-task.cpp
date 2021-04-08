#include "fourth-task.h"
namespace Fourth {
    void long_sum(std::string& str_number_1, std::string& str_number_2, std::string& str_sum) {
        std::vector<int> vec_number_1;
        std::vector<int> vec_number_2;
        for (auto i = 0; i < str_number_1.size(); i++)
            vec_number_1.push_back(str_number_1[i]-'0');
        for (auto i = 0; i < str_number_2.size(); i++)
            vec_number_2.push_back(str_number_2[i] - '0');

        auto i = vec_number_1.size()-1;
        auto j = vec_number_2.size()-1;
        int tmp_sum = 0;
        bool rest = false; // if has +1 from last digit
        //sum of last min(i,j)
        while ((i+1  > 0) && (j+1 > 0)) {
            tmp_sum = vec_number_1[i--] + vec_number_2[j--] + rest;
            if (tmp_sum > 9) {
                tmp_sum %= 10;
                rest = true;
            }
            else
                rest = false;
            str_sum = static_cast<char>('0' + tmp_sum) + str_sum;
        }
        //sum of i-j if i is greater then j
        while (i + 1 > 0) {
            if (rest)
                if (vec_number_1[i] + 1 < 10) 
                    rest = false;
                else
                    vec_number_1[i] = 0;
                str_sum = static_cast<char>('0' + vec_number_1[i--]) + str_sum;
        }
        //sum of j-i if j is greater then i
        while (j + 1 > 0) {
            if (rest)
                if (vec_number_2[j] + 1 < 10)
                    rest = false;
                else
                    vec_number_2[j] = 0;
            str_sum = static_cast<char>('0' + vec_number_2[j--]) + str_sum;
        }
        // if i == j and first digit sum is greater then 9
        if (rest)
            str_sum = '1' + str_sum;
    }
}