//We include de I/O library
#include <iostream>
/* We include the stdenteredNumeramespace so we don't have to write std::
Everytime we want to use "cout" or "cin" */
using namespace std;

int main()
{
//    We declare our variables
    int enteredNumer, i, factorization;
    
//    Ask for a number
    cout << "Enter a number of your choice (positive and integeer): ";
//    Assing the entered value to the "enteredNumer" variable
    cin >> enteredNumer;
    
    cout << "These are the factors for " << enteredNumer << ": " << endl;
    
    factorization = enteredNumer;
    
//    Every number has 1 as it's factor, so we'll say this right away
    cout << 1 << endl;
    
//    Check the factors (starting with 2, until the number is reached)
    for(i = 2; i <= enteredNumer; ++i)
    {
//        If the divided number has 0 as the division reminder, it'll be a factor
        
        while (factorization % i == 0){
//            Print this number everytime
            cout << i << endl;
            
//            As it is a factor, let's divide by it to find the next one!
            factorization = factorization / i;
        };
    }
    
    return 0;
}

