import java.util.Scanner;
public class sieve1{
    // sieve[i] ->equals 0 if it's prime
    // ->equals 1 if it's unprim
    public static void main(String []args){
        Scanner cin = new Scanner(System.in);
        int sieve[] = new int[10000000];
        // we dont'care about sieve[0] and sieve[1] because zero and one
        // are exceptions, they're neither prime and nor compound

        long time_before = System.currentTimeMillis();
        for(int i=2; i<10000000; i++)
            if( sieve[i] == 0 )// so if it's prime(2, 3, 5, 7, 11 etc.)
                for(int j=i*2; j<10000000; j+=i)// we take every single multiple of i which is smaller or
                                                         // equals to 10000000-> 2i, 3i, 4i, .......
                    sieve[j] = 1;// and we gave them the 1 value, which by definition points out a number is NOT
                                 // prime

        // ------this is where erastostene's sieve algorithm itself ends
        long time_after = System.currentTimeMillis();
        float result = time_after - time_before;    result /= 100;
        System.out.printf("The algorithm took %.3f\nPress enter to continue:", result);
        String c = cin.nextLine(); cin.close();
        
        System.out.println("THE PRIME NUMBERS BELOW 10.000.000:");
        for(int i=2; i<10000000; i++)
            if(sieve[i] == 0)
                System.out.println(i);
    }
}