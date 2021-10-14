import math
import time

sieve = [False for i in range(5000000 + 1)]
# 5000000*2 + 1 = 10000001 this is the range of our computation now, impressive, right!?

# the first mind blowing trick implemented in addition in this version is that we'll get rid
# of even numbers(2, 4, 6, ....), because they have the gen. form. 2K and they store half of the memory
# to get things work properly we'll handle the list(because python offers lists rather than vectors which 
# have way more interesting features) in a different approach:
# IMPORTANT:      sieve[i] WILL GONNA HELD THE 'PRIME-ITY' OF 2*i + 1
# example   sieve[1] -> number 3
# sieve[2] -> number 5
# sieve[3] -> numbers 7
# the only number that is going to be out of the sieve's memory is 2, just keep this in mind if choosing this version!!!


if __name__ == "__main__":

    current_time = time.time()
    # here we only search up to square root of the vector's limit
    for i in range(2, (10000000>>1)+1, 1): # i>>1 is a bit operation which means /2 and we add one more unit
                                           #to make 5000000 the last checkable value for i
        if sieve[i] == 0:  # i<<1 is equivalent to i*2, just a little bit more efficient and smarty

            # let i be 11; 22, 44, 66, 88, 110 are marked as unprime when
            # the same math trick as in the first for, here we search within [3*i+1, 10000001]
            for j in range(3*i + 1, (10000000 >> 1)+1, (i << 1)+1):
                # i holds 2
                sieve[j] = 1
#------------------this where the algorithm itself ends--------------------------

    current_time = time.time() - current_time
    print("The algorithm took " + str(current_time) +
          " seconds\nPress any key to continue:")
    a = input()
    for i in range(2, 10000000):
        if sieve[i] == 0:
            print(i)
