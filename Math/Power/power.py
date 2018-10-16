#!/usr/bin/env python
import optparse



def powerint(x, n):
    if n == 0:
        return 1
    elif n == 1:
        return x
    elif n > 1:
        return x ** n
    else:
        return "Please wirte only natural numbers"


def main():
    p = optparse.OptionParser(description="Try power operator in Python",
                              prog='powert.py',
                              usage='%prog --base <number>  --power <number>',
                              version='0.1')
    p.add_option('--base', action='store_true')
    p.add_option('--power', action='store_true')

    # Parse arguments
    options, arguments = p.parse_args()

    # Verify arguments and process
    if len(arguments) == 2:
        base = arguments[0]
        power = arguments[1]
        print(powerint(base, power))
    else:
        p.print_help()



if __name__ == '__main__':
    main()