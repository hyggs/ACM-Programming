package chapter1.problem110102or10189;

import java.util.Scanner;

class Main {

    public static void increment(int i, int j, int n, int m, int[][] result) {

       if (i == 0) {
           if (j == 0) {
               if (i + 1 < n) {
                   result[i + 1][j]++;
               }
               if (j + 1 < m) {
                   result[i][j + 1]++;
               }
               if (i + 1 < n && j + 1 < m) {
                   result[i + 1][j + 1]++;
               }
           } else if (j == m - 1) {
               if (i + 1 < n) {
                   result[i + 1][j]++;
               }
               if (j - 1 >= 0) {
                   result[i][j - 1]++;
               }
               if (i + 1 < n && j - 1 >= 0) {
                   result[i + 1][j - 1]++;
               }
           } else {
               result[i][j - 1]++;
               result[i][j + 1]++;
               if (i + 1 < n) {
                   result[i + 1][j - 1]++;
                   result[i + 1][j]++;
                   result[i + 1][j + 1]++;
               }
           }
       } else if (i == n - 1) {
           if (j == 0) {
               result[i - 1][j]++;
               if (j + 1 < m) {
                   result[i - 1][j + 1]++;
                   result[i][j + 1]++;
               }
           } else if (j == m - 1) {
               result[i - 1][j]++;
               result[i - 1][j - 1]++;
               result[i][j - 1]++;
           } else {
               result[i - 1][j - 1]++;
               result[i - 1][j]++;
               result[i - 1][j + 1]++;
               result[i][j - 1]++;
               result[i][j + 1]++;
           }
       } else {
           if (j == 0) {
               result[i - 1][j]++;
               result[i + 1][j]++;
               if (j + 1 < m) {
                   result[i - 1][j + 1]++;
                   result[i + 1][j + 1]++;
                   result[i][j + 1]++;
               }
           } else if (j == m - 1) {
               result[i - 1][j]++;
               result[i + 1][j]++;
               result[i - 1][j - 1]++;
               result[i][j - 1]++;
               result[i + 1][j - 1]++;
           } else {
               result[i - 1][j - 1]++;
               result[i - 1][j]++;
               result[i - 1][j + 1]++;
               result[i][j - 1]++;
               result[i][j + 1]++;
               result[i + 1][j - 1]++;
               result[i + 1][j]++;
               result[i + 1][j + 1]++;
           }
       }

    }

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        int n;
        int m;
        int x = 0;
        char field[][];
        String line;
        int result[][];
        while (scanner.hasNext()) {
            x++;
            n = scanner.nextInt();
            m = scanner.nextInt();
            if (m == 0 && n == 0) {
                break;
            }
            result = new int[n][m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    result[i][j] = 0;
                }
            }
            field = new char[n][m];
            for (int i = 0; i < n; i++) {
                line = scanner.next();
                while (line.isEmpty()) {
                    line = scanner.next();
                }
                for (int j = 0; j < m; j++) {
                    field[i][j] = line.charAt(j);
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (field[i][j] == '*') {
                        result[i][j] = -10;
                        increment(i, j, n, m, result);
                    }
                }
            }
            if (x != 1) System.out.println();
            System.out.println("Field #" + x + ":");
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (result[i][j] < 0) {
                        System.out.print('*');
                    } else {
                        System.out.print(result[i][j]);
                    }
                }
                System.out.println();
            }
        }

    }

}
