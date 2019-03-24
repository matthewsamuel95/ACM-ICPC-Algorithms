/*
	Name: RED BLACK TREE
	Copyright: greatSharma
	Author: Gaurav Sharma
	Date: 02-03-19 15:45
	Description: This project consists of creation of a red-black tree under c++03 standards with documentary
                comments, so anyone having idea with a minimum of C++ is good to go. The project consists
                of atomic and fundamental operations with RBT. Beside this there are some application modules also.  
    Prerequisites: Basic C++, Pointers, OOP and Basic BST.
*/

#include "menu.hpp"

void make_tree()
{
    RBT tree;
    while (true)
    {
        menu(tree);
        cout << "\n\nEnter 0 to exit : ";
        std::cin >> data;
        if (data == 0)
            break;
    }

    return;
}

int main(void)
{
    do
    {
        make_tree();
        cout << "\n\nwant to make new tree(if not press 0)? ";
        std::cin >> data;
    } while (data != 0);

    return 0;
}