def power(base, powerRaised):
    if (powerRaised != 0):
        return (base*power(base, powerRaised-1))
    else:
        return 1;

base=float(input("Enter base:"))
powerRaised=float(input("Enter power raised:"))

if ( powerRaised >=0 ):
    print(power(base,powerRaised))
else:
    print(1/(power(base,powerRaised*-1)))
