package chapter1;

import java.util.Scanner;

class Main {

    public static String maxCycleLengths(int start, int end) {

        int max = 0;
        String result = "";
        int less = Math.min(start, end);
        int more = Math.max(start, end);
        for (int i = less; i <= more; i++) {
            max = Math.max(max, cycleLength(i));
        }
        result += start + " " + end + " " + max;
        return result;

    }

    public static int cycleLength(int n) {

        int cycle = 1;
        while (n != 1) {
            if (n % 2 == 0) {
                n /= 2;
            } else {
                n = 3 * n + 1;
            }
            cycle++;
        }
        return cycle;

    }

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        int start;
        int end;
        while (scanner.hasNext()) {
            start = scanner.nextInt();
            end = scanner.nextInt();
            System.out.println(maxCycleLengths(start, end));
        }

    }

}
