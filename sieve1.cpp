#include<iostream>
using namespace std;
// sieve[i] ->equals 0 if it's prime
//          ->equals 1 if it's unprim
int sieve[10000000];
int main()
{
    //we dont'care about sieve[0] and sieve[1] because zero and one
    //are exceptions, they're neither prime and nor compound

    double time = clock();
    for(int i=2; i<=10000000; i++)
        if( sieve[i] == 0 )//so if it's prime(2, 3, 5, 7, 11 etc.)
            for(int j=i*2; j<=10000000; j+=i)// we take every single multiple of i which is smaller or equals to 10000000-> 2i, 3i, 4i, ....... 
                sieve[j] = 1;//and we gave them the 1 value, which by definition points out a number is NOT prime
    time = clock() - time;
    cout << "The algorithm took " << time / CLOCKS_PER_SEC << "s\nPress any key to continue:";
    cin.get();

    cout<<"ALL THE PRIME NUMBERS BELOW 10.000.000:\n";
    for(int i=2; i<=10000000; i++) cout<<i<<'\n';
}