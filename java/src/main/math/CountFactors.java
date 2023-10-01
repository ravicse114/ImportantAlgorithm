package main.math;

import java.util.Scanner;

/*
Given an integer A, you need to find the count of it's factors.
Factor of a number is the number which divides it perfectly leaving no remainder.
Example : 1, 2, 3, 6 are factors of 6
*/
public class CountFactors {
	/*
	 * Brute force method will take O(n) time to compute.
	 */
	private static int countOfFactors(int n) {
		int count = 0;
		for(int i=1;i<=n;i++) {
			if(n%i==0) {
				count++;
			}
		}
		return count;
	}
	/*
	 * Efficient method will take O(sqrt(n)) time to compute.
	 */
	private static int countOfFactors2(int n) {
		int count = 0;
		for(int i=1;i*i<=n;i++) {
			if(n%i==0) {
				if(i*i==n) count+=1;
				else count+=2;
			}
		}
		return count;
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		System.out.println("Factors of "+n+" using bruteforce method :: "+countOfFactors(n));
		System.out.println("Factors of "+n+" using efficient method :: "+countOfFactors2(n));
		sc.close();
	}
}
