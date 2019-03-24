#include "Node.hpp"

Node::Node(int data, int color = RED, Node *left, Node *right, Node *parent)
    : data(data), color(color), left(left), right(right), parent(parent) {}

string Node::getProps()
{
    /*
    DESCR -> returns all the properties of a invoked node.
    Return Type -> string
    */

    return "\ndata : " + to_string(this->data) +
           "\ncolor ( RED= 1, BLACK= 0 ): " + to_string(this->color) +
           "\nleft child : " + to_string(this->left->data) +
           "\nright child : " + to_string(this->right->data) +
           "\nparent : " + to_string(this->parent->data);
}

Node::~Node() {}