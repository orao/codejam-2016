#include <iostream>
#include <cstdint>
#include <string>
#include <algorithm>


// TODO: If going down the bit-twiddles route...
//uint64_t reverse32(register uint64_t x)
//{
//    x = (((x & 0xaaaaaaaaaaaaaaaa) >> 1) | ((x & 0x5555555555555555) << 1));
//    x = (((x & 0xcccccccccccccccc) >> 2) | ((x & 0x3333333333333333) << 2));
//    x = (((x & 0xf0f0f0f0f0f0f0f0) >> 4) | ((x & 0x0f0f0f0f0f0f0f0f) << 4));
//    x = (((x & 0xff00ff00ff00ff00) >> 8) | ((x & 0x00ff00ff00ff00ff) << 8));
//    return((x >> 16) | (x << 16));
//}
//
//uint32_t reverse64(register uint32_t x)
//{
//    x = (((x & 0xaaaaaaaaaaaaaaaa) >> 1) | ((x & 0x5555555555555555) << 1));
//    x = (((x & 0xcccccccccccccccc) >> 2) | ((x & 0x3333333333333333) << 2));
//    x = (((x & 0xf0f0f0f0f0f0f0f0) >> 4) | ((x & 0x0f0f0f0f0f0f0f0f) << 4));
//    x = (((x & 0xff00ff00ff00ff00) >> 8) | ((x & 0x00ff00ff00ff00ff) << 8));
//    x = (((x & 0xffff0000ffff0000) >> 16) | ((x & 0x0000ffff0000ffff) << 16));
//    return((x >> 32) | (x << 32));
//}

std::string flip_full_stack(const std::string& s)
{
    std::string rv;
    for (auto& c : s)
    {
        if (c == '+') rv += '-';
        else rv += '+';
    }
    return rv;
}

std::string flip_part_stack(const std::string& s, int pancakes)
{
    std::string sub = s.substr(0, pancakes);
    std::string rv = flip_full_stack(sub) + s.substr(pancakes);
    return rv;
}

int main()
{
    int number_of_inputs = 0;

    std::cin >> number_of_inputs;

    std::string stack;
    for (int i = 0; i < number_of_inputs; ++i)
    {
        std::cin >> stack;

        std::cout << "Case #" << (i + 1) << ": ";

        int steps = 0;
        for (auto lastMinus = stack.rfind('-'); lastMinus != std::string::npos; lastMinus = stack.rfind('-'))
        {
            if (stack[0] == '+')
            {
                auto lastPlus  = stack.rfind('+', lastMinus - 1);
                stack = flip_part_stack(stack, lastPlus + 1);
                ++steps;
            }
            stack = flip_part_stack(stack, lastMinus + 1);
            ++steps;
        }

        std::cout << steps << std::endl;
    }

    return 0;
}


