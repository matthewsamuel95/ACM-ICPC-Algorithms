/**
 * Find Factors Cpp
 * You put in a number and it prints out the factors
 */

#include <stack>
#include <vector>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

typedef struct PrimeAndPower {
    int prime;
    int power;
} PrimeAndPower ;

vector<int> findFactors(int number){
  vector<int> factors;
  stack<int> other_factors;
  double midroot = floor(sqrt(number)) + 1;
  for(int guess = 1; guess < midroot; guess++){
    if(guess == 1 || number % guess == 0){
      factors.push_back(guess);
      int other_factor = number / guess;
      if(guess != other_factor){
        other_factors.push(other_factor);
      }
    }
  }
  while(!other_factors.empty()){
    factors.push_back(other_factors.top());
    other_factors.pop();
  }
  return factors;
}

vector<PrimeAndPower> primeFactors(int number){
  vector<PrimeAndPower> prime_factors;

  int workingNumber = number;
  for(int guess = 2; guess <= workingNumber; guess ++){
    if(workingNumber % guess == 0){
      PrimeAndPower primeAndPower;
      primeAndPower.prime = guess;
      primeAndPower.power = 0;
      while( workingNumber > 1 && workingNumber % guess == 0){
        workingNumber /= guess;
        primeAndPower.power++;
      }
      prime_factors.push_back(primeAndPower);
    }
  }
  return prime_factors;
}

void usage(string progName){
  cout << "USAGE:\n";
  cout << "\t" << progName << " <position integer>\n";
  cout << "prints out all factors then the prime factorization with primes and powers.\n";
}

int main(int argc, char * argv[]){
  if(argc > 1){
    cout << "Factors for " <<  argv[1] << "\n";
    int number = stoi(argv[1]);
    vector<int> factors = findFactors(number);
    for( auto factor : factors ){
      cout << factor << " ";
    }
    cout << "\n";

    cout << "Prime Factorization of " << number << "\n";
    vector<PrimeAndPower> prime_factors = primeFactors(number);
    if(prime_factors.empty()){
      cout << number << " is prime.\n";
    } else {
      for( PrimeAndPower pf : prime_factors ){
        cout << pf.prime << "^" << pf.power << " ";
      }
    }
    cout << "\n";
  } else {
    usage(argv[0]);
  }
  return 0;
}


