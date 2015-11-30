/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package randommapgeneration;

/**
 *
 * @author hashr25
 */
public class RandomMapGeneration {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        int N = 50;
        StdDraw.setXscale(-N, +N);
        StdDraw.setYscale(-N, +N);
        StdDraw.clear(StdDraw.GRAY);

        int x = 0, y = 0;
        int steps = 0;
        while (Math.abs(x) < N && Math.abs(y) < N) {
            StdDraw.setPenColor(StdDraw.WHITE);
            StdDraw.filledSquare(x, y, 0.45);
            double r = Math.random();
            if      (r < 0.25) x--;
            else if (r < 0.50) x++;
            else if (r < 0.75) y--;
            else if (r < 1.00) y++;
            steps++;
            StdDraw.setPenColor(StdDraw.BLUE);
            StdDraw.filledSquare(x, y, .45);
            StdDraw.show(40);
        }
        StdOut.println("Total steps = " + steps);
    }
}