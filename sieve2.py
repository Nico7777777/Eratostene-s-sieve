import math
import time

sieve = [False for i in range(10000000)]
# the additional features sieve2 comes with are the efficient
# allocation of sieve[] and the way we iterate through it when
# striking through it

# bool usage of storage implies only 1byte/variable
# comparing to int which holds 4bytes/variable, so x4 more efficient


if __name__ == "__main__":

    current_time = time.time()
    for i in range(2, math.floor(math.sqrt(10000000)), 1):  # here we only search up to square root of the vector's limit
        if sieve[i] == 0:  # because the second for starts with i*i, so it would be useless to go further with this for
            
            for j in range(i*i, 10000000, i):# let i be 11; 22, 44, 66, 88, 110 are marked as unprime when
                                                # i holds 2
                sieve[j] = 1 # 33, 99 are marked as unprime when i holds 3
        #55 is marked as unprime when i holds 5
        #77 is marked as unprime when i holds 7
        #so the first position we have to start with for a specific i value to mark as
        #unprime is its square -> i*i   
    current_time = time.time() - current_time
    print("The algorithm took " + str(current_time) +
          " seconds\nPress any key to continue:")
    a = input()
    for i in range(2, 10000000):
        if sieve[i] == 0:
            print(i)
