package main.bit;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/*
You have an array A with N elements. We have two types of operation available on this array :
1. We can split an element B into two elements, C and D, such that B = C + D.
2. We can merge two elements, P and Q, to one element, R, such that R = P ^ Q i.e., XOR of P and Q.
You have to determine whether it is possible to convert array A to size 1, 
containing a single element equal to 0 after several splits and/or merge?

Return "Yes" if it is possible otherwise return "No".
 */

public class ArrayWithXOROperation {
	private static String solve(List<Integer>array) {
		long xors = 0;
        for(int i=0;i<array.size();i++) {
            xors = xors^array.get(i);
        }
        if(xors%2==0) return "Yes";
        return "No";
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int size = sc.nextInt();
		List<Integer> inputList = new ArrayList<>();
		for(int i=0;i<size;i++) {
			int num = sc.nextInt();
			inputList.add(num);
		}
		System.out.println("Total differences :: "+solve(inputList));
		sc.close();
	}

}
