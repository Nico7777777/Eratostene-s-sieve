import java.util.Scanner;
public class sieve3 {
    public static void main(String []args){
        //the first mind blowing trick implemented in addition in this version is that we'll get rid
        //of even numbers(2, 4, 6,....), because they have the gen. form. 2K and they store half of the memory
        Scanner cin = new Scanner(System.in);
        //to get things work properly we'll handle the vector in a different approach:
        // IMPORTANT:      sieve[i] WILL GONNA HELD THE 'PRIME-ITY' OF 2*i + 1
        //example   sieve[1] -> number 3
        //          sieve[2] -> number 5
        //          sieve[3] -> numbers 7
        //the only number that is going to be out of the sieve's memory is 2, just keep this in mind if choosing this version!!!
        
        boolean []sieve = new boolean[5000000+1];
        // 5000000*2 + 1 = 10000001; this is the range of our computation now, impressive, right!?
        

        
        long time_before = System.currentTimeMillis();
        for(int i=1; (i<<1)+1 <= 10000001; i++) // i<<1 is a bit operation(read more here: https://www.javatpoint.com/bitwise-operator-in-java)
            if(sieve[i]==false)         // i<<1 is equivalent to i*2, just a little bit more efficient and smarty
                for(int j=3*i + 1; (j<<1)+1 <= 10000001; j+= (i<<1)+1)  
                    sieve[j] = true;
        long time_after = System.currentTimeMillis();
        //------------this where the algorithm itself ends--------------------------
        float result = time_after - time_before;    result /= 100;
        System.out.printf("The algorithm took %.3fs\nPress enter key to continue:", result);
        String c = cin.nextLine();  cin.close();



        System.out.println("ALL THE PRIME NUMBERS BELOW 10.000.000:");
        System.out.println(2);
        for(int i=1; i<=5000000; i++)
            if(sieve[i] == false) System.out.println(2*i+1);
    }
}
