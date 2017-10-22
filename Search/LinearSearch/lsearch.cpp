#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::vector<int> myarray;


// implements linear search
bool linear_search(int number)
{
    int n = myarray.size();
    for (int i = 0; i < n; i++)
    {
        if (number == myarray[i])
        {
            std::cout << "found at pos: " << i + 1 << std::endl;
            std::cout << myarray[i] << std::endl;
            return true;
        }
    }
    return false;
}


bool is_digits(const std::string &str)
{
    return std::all_of(str.begin(), str.end(), ::isdigit); // C++11
}


int main(int argc, char const *argv[])
{
    /* code */

    std::string z;
    while(true)
    {
        std::cin>>z;
        if (is_digits(z))
        {
            int input = stoi(z);
            myarray.push_back(input);
        }
        else
            break;
    }



    std::cout<<"enter number you want to search"<<std::endl;
    int k;
    std::cin>>k;
    bool found = linear_search(k);
    if(found == false)
        std::cout<<"couldn't find number"<<std::endl;
    return 0;
}
