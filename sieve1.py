import time

sieve = [ 0 for i in range(10000000) ]
# sieve[i] -> equals 0 if it's prime
#          -> equals 1 if it's unprim

# we dont'care about sieve[0] and sieve[1] because zero and one
# are exceptions, they're neither prime and nor compound

if __name__ == "__main__":
    current_time = time.time()
    for i in range(2, 10000000, 1):
        if sieve[i]==0: #so if it's prime(2, 3, 5, 7, 11 etc.)
            for j in range(2*i, 10000000, i):# we take every single multiple of i which is smaller or
                sieve[j] = 1 # equals to 10000000 -> 2i, 3i, 4i, .......
                    # and we gave them the 1 value, which by definition points out a number is NOT prime
# this is the end of the algorithm
    current_time = time.time() - current_time
    print("The algorithm took "+ str(current_time) +" seconds\nPress any key to continue:")
    a = input()
    for i in range(2, 10000000):
        if sieve[i] == 0:
            print(i)
