#include<iostream>
#include<ctime>
using namespace std;
bool sieve[5000000 + 1];
// 5000000*2 + 1 = 10000001; this is the range of our computation now, impressive, right!?

// the first mind blowing trick implemented in addition in this version is that we'll get rid
// of even numbers(2, 4, 6,....), because they have the gen. form. 2K and they store half of the memory

int main()
{
    // to get things work properly we'll handle the vector in a different approach:
    // IMPORTANT:      sieve[i] WILL GONNA HELD THE 'PRIME-ITY' OF 2*i + 1
    // example   sieve[1] -> number 3
    //          sieve[2] -> number 5
    //          sieve[3] -> numbers 7
    // the only number that is going to be out of the sieve's memory is 2, just keep this in mind if choosing this version!!!


    double time = clock();
    for(int i=1; (i<<1)+1 <= 10000001; i++)
        if( !sieve[i] )
            for(int j=3*i+1; (j<<1)+1 <= 10000001; j+=(i<<1)+1)
                sieve[j] = true;
    time = (clock() - time)/CLOCKS_PER_SEC;
    /*let's consider the following 4 values:
        1. P - the real prime number which we test if the if above, for instance 5
        2. I - the i from the first for which equals: (P-1)/2
        3. J - the initialization of j from the second for which equals: 3*I + 1
        4. X - the real value of the j which equals: 2*J+1

        I = (P-1)/2 |
                    | => J = 3[(P-1)/2] + 1
        J = 3*I+1   |

        J = 3[(P-1)/2] + 1  |
                            | => X = 2{3[(P-1)/2] + 1} + 1   <=>   X = 6*(P-1)/2 + 2 + 1   <=>   X = 3*P - 3 + 3   <=>   X = 3P
        X = 2*J + 1         |

        The calculus above prove that we started the second for iterating all the multiples of the prime number P with 3P, but why? Because we could miss any even multiple
        smaller then the perfect square. Case in point: I=7, so in sieve2.cpp the second for starts with J=49, but here we should start from J=15 because 
    */
   cout<<"The algorithm took "<<time<<"s\nPress enter to continue:";
   cin.get();

   cout<<"ALL PRIME NUMBERS BELOW 10.000.000:\n";
    for(int i=2; i<=5000000; i++)
        if( sieve[i] == 0 )
            cout<<2*i+1<<'\n';
}