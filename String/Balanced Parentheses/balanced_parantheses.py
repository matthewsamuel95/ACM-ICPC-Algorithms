# A small check for balanced parantheses in Python 3
# Added regex as a little extra

import re

any_parantheses = re.compile("[\[({})\]]+")
opening_parantheses = ['[', '(', '{']
closing_parantheses = [']', ')', '}']


def is_balanced(expr):
    stack = []
    n = len(expr)
    for i in range(0, n):
        if (expr[i] in opening_parantheses):
            stack.append(expr[i])
        elif (expr[i] in closing_parantheses):
            matching_paranthesis = opening_parantheses[closing_parantheses.
                                                       index(expr[i])]
            if (stack.pop() != matching_paranthesis):
                return False

    return True if len(stack) == 0 else False


def main():
    expr = input(
        "Please enter an expression with parantheses ('[','(','{','}',')',']') or 'test' for a fixed test: "
    )
    if (expr == "test"):
        expr = "({}[](([{()}])))"

    if (not any_parantheses.match(expr)):
        print("No parantheses found!")
    elif (is_balanced(expr)):
        print("%s is balanced!" % expr)
    else:
        print("%s is not balanced!" % expr)


if __name__ == '__main__':
    main()
