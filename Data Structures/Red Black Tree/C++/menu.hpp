#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include "RB_Tree.hpp"

using std::cin;
using std::cout;

int data;
string props;

void menu(RBT &tree)
{
    cout << "\n\n========MENU========";
    cout << "\n\n1.Insert";
    cout << "\n2.Delete";
    cout << "\n3.Display Full Horizontal Tree";
    cout << "\n4.Preorder";
    cout << "\n5.Inorder";
    cout << "\n6.Postorder";
    cout << "\n7.Node Props";
    cout << "\n8.Tree Props";
    cout << "\n9.Search Node";
    cout << "\n\nEnter your choice : ";
    int choice;
    std::cin >> choice;

    Node *new_tree_root;

    switch (choice)
    {
    case 1:
        cout << "\nEnter data to be inseted(except -1) : ";
        cin >> data;

        tree.insert(data);
        tree.show_tree(0);

        break;

    case 2:
        cout << "\nEnter data to be deleted : ";
        cin >> data;

        tree.delete_node(data);
        tree.show_tree(0);

        break;

    case 3:
        tree.show_tree(0);
        break;

    case 4:
        tree.show_tree(1);
        break;

    case 5:
        tree.show_tree(2);
        break;

    case 6:
        tree.show_tree(3);
        break;

    case 7:
        cout << "\nEnter data for which props are to be shown : ";
        cin >> data;

        props = tree.get_node_prop(data);
        cout << props;

        break;

    case 8:
        props = tree.get_tree_prop();
        cout << props;
        break;

    case 9:
        cout << "\nEnter data to search : ";
        cin >> data;

        if (tree.search(data))
            cout << "\nFound :)";
        else
            cout << "\nNot Found !";

        break;

    default:
        cout << "\nInvalid choice...";
        break;
    }

    return;
}

#endif