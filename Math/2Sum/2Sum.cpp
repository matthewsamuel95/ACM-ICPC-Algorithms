#include <algorithm>
#include <ctime>
#include <iostream>
#include <random>
#include <vector>

long long random_number()
{
    const long long min = -100'000'000'000;
    const long long max =  100'000'000'000;
    static std::mt19937_64 gen(std::time(nullptr));
    static std::uniform_int_distribution<long long> dist(min, max);
    return dist(gen);
}

bool is_sum_exist(const std::vector<long long>& data, long long x)
{
    auto j = std::lower_bound(data.begin(), data.end(), x)  -  data.begin();
    decltype(j) i = 0;
    if(j == data.size()) --j;
    while (i < j)  {
        long long sum = data[i]+data[j];
             if (sum == x)  return true;
        else if (sum >  x)  --j;
        else                ++i;
    }
    return false;
}

int main()
{
    const std::size_t data_size = 1'000'000;
    const std::size_t requests = 100000;
    std::cin.sync_with_stdio(false); //In case I need to output actual numbers

    //creating dataset
    std::vector<long long> data(data_size);
    std::generate_n(data.begin(), data.size(), random_number);
    std::sort(data.begin(), data.end());

    //creating values we will search sum of
    std::vector<long long> rand_values(requests);
    std::generate_n(rand_values.begin(), rand_values.size(), random_number);
    std::cout << "done" << std::endl;

    long long counter = 0;
    for(auto t: rand_values) {
        if(is_sum_exist(data, t))
            ++counter;
    }
    std::cout << counter;
}
