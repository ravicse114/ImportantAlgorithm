package main.bit;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/*
We define f(X, Y) as the number of different corresponding bits in the binary representation of X and Y.
For example, f(2, 7) = 2, since the binary representation of 2 and 7 are 010 and 111, respectively. 
The first and the third bit differ, so f(2, 7) = 2.

You are given an array of N positive integers, A1, A2,..., AN. Find sum of f(Ai, Aj) for all pairs (i, j) 
such that 1 ≤ i, j ≤ N. Return the answer modulo 10^9+7.
 */
public class BitSumPair {
	private static int cntBits(List<Integer> array) {
        int bitCount[] = new int[32];
        /*
         * Stores the count of set bit at ith index for all numbers.
         */
        for(int i=0;i<array.size();i++) {
            int arrayElement = array.get(i);
            int ind = 0;
            while(arrayElement>0) {
                if(arrayElement%2==1) bitCount[ind]+=1;
                arrayElement/=2;
                ind++;
            }
        }
        long mod = 1000000007;
        long ans = 0;
        /*
         * Difference can be counted based on number of 0s and 1s for all positions
         */
        for(int i=0;i<32;i++) {
            long cnt1 = bitCount[i];
            long cnt0 = array.size()-cnt1;
            //We're multiplying by 2 because pairs can be in reverse order as well
            ans = (ans+(cnt0*cnt1*2)%mod)%mod;
        }
        return (int)ans;
    }
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int size = sc.nextInt();
		List<Integer> inputList = new ArrayList<>();
		for(int i=0;i<size;i++) {
			int num = sc.nextInt();
			inputList.add(num);
		}
		System.out.println("Total differences :: "+cntBits(inputList));
		sc.close();
	}
}
