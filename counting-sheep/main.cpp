#include <iostream>
#include <cstdint>
#include <string>

#define DIGIT(x) (1 << (x))

int main()
{
    int number_of_inputs = 0;

    std::cin >> number_of_inputs;

    uint64_t N;
    for (int i = 0; i < number_of_inputs; ++i)
    {
        std::cin >> N;
        std::cout << "Case #" << (i + 1) << ": ";
        if (N != 0)
        {
            unsigned seen = 0;
            uint64_t sum = N;
            for (; seen != 1023; sum += N)
            {
                for (uint64_t x = sum; x > 0; x /= 10)
                {
                    seen |= DIGIT(x % 10);
                }
            }
            std::cout << (sum - N);
        }
        else
        {
            std::cout << "INSOMNIA";
        }
        std::cout << std::endl;
    }

    return 0;
}


