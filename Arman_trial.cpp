#include <iostream>
#include <random>
#include "first-task.h"
#include "second-task.h"
#include "third-task.h"
#include "fourth-task.h"

int main()
{
    short test_function = 2;
    switch (test_function) {
        //first
    case 1: {
        First::min_max(34567829);
        break;
    }
        //second
    case 2: {
        Second::List* head = NULL;
        Second::List* cur = NULL;
        std::cout << "Before: ";
        for (auto i = 0; i < 15; i++) {
            Second::List* tmp = new Second::List;
            tmp->payload = rand();
            std::cout << tmp->payload << ' ';
            tmp->next = NULL;
            if (!head) {
                head = tmp;
                cur = head;
            }
            else {
                cur->next = tmp;
                cur = cur->next;
            }
        }
        std::cout << std::endl;

        char* char_list;
        cur = head;
        char_list = Second::serialize(cur);

        cur = Second::deserialize(char_list);

        std::cout << "After: ";
        do {
            std::cout << cur->payload << ' ';
            cur = cur->next;
        } while (cur);
        std::cout << std::endl;
        break;
    }
        //third
    case 3: {
        short example_3[9][9] = { {2,9,3,4,5,7,6,8,1},
                                  {4,7,5,1,8,6,3,9,2},
                                  {1,6,8,3,9,2,7,4,5},
                                  {9,4,2,5,7,1,8,6,3},
                                  {3,8,1,6,2,9,5,7,4},
                                  {6,5,7,8,3,4,1,2,9},
                                  {7,2,6,9,1,3,4,5,8},
                                  {5,1,4,2,6,8,9,3,7},
                                  {8,3,9,7,4,5,2,1,6}, };
        if (Third::check_solution(example_3))
            std::cout << "Solution is correct!" << std::endl;
        else
            std::cout << "Solution is not correct!" << std::endl;
        break;
    }
        //fourth
    case 4:{
        std::string l_sum = "";
        std::string number_1 = "3587230923056320562398452393205962305";
        std::string number_2 = "9328532992353205793259";
        Fourth::long_sum(number_1, number_2, l_sum);
        std::cout << "Summary of " << number_1 << std::endl << " and " << number_2 << std::endl << " is " << l_sum << std::endl;
        break;
    }
    default: {
        std::cerr << "No task chosen!" << std::endl;
        break;
    }
    }
}
