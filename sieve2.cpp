#include<iostream>
#include<ctime>
using namespace std;
bool sieve[10000000];
//the additional features sieve2 comes with are the efficient
//allocation of sieve[] and the way we iterate through it when
//striking through it

// bool usage of storage implies only 1byte/variable
// comparing to int which holds 4bytes/variable, so x4 more efficient

int main()
{
    double time = clock();
    for(int i=2; i*i<10000000; i++)//here we only search up to square root of the vector's limit
                            //because the second for starts with i*i, so it would be useless to go further with this for
        if( sieve[i] == 0 )
            for(int j=i*i; j<10000000; j+=i) // let i be 11; 22, 44, 66, 88, 110 are marked as unprime when i holds 2
                sieve[j] = 1;               // 33, 99 are marked as unprime when i holds 3
    // 55 is marked as unprime when i holds 5; 77 is marked as unprime when i holds 7
    //so the first position we have to start with for a specific i value to mark as unprime is its square -> i*i
    time = clock() - time;
    cout<<"The algorithm took "<<time/CLOCKS_PER_SEC<<"s\nPress any key to continue:";
    cin.get();
    
    cout<<"ALL PRIME NUMBERS BELOW 10.000.000:\n";
    for(int i=2; i<10000000; i++)
        if( sieve[i] == 0 )
            cout<<i<<'\n';
}