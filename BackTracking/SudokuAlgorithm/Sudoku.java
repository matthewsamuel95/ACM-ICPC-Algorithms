public class Sudoku {

    public final int SUDOKU_SIZE = 9;
    public final int UNASSIGNED = 0;


    private int unassignedPositionRow;
    private int unassignedPositionColumn;
    private int[][] matrix = new int[SUDOKU_SIZE][SUDOKU_SIZE];

    public Sudoku() {

        clear();
    }

    public void clear() {
        for(int i = 0; i < SUDOKU_SIZE; i++)
            for(int j = 0; j < SUDOKU_SIZE; j++)
                matrix[i][j] = UNASSIGNED;
    }

    public void insertRandomNumbers(int n) {

        for(int i = 0; i < n; i++) {
            int randomRow = (int)(Math.random() * (SUDOKU_SIZE - 1));
            int randomColumn = (int)(Math.random() * (SUDOKU_SIZE - 1));
            int randomNumber = (int)(Math.random() * (SUDOKU_SIZE - 1) + 1);
            matrix[randomRow][randomColumn] = randomNumber;
        }
    }

    public boolean solve() {

        if(!findUnassignedPosition())
            return true;

        for(int n = 1; n <= SUDOKU_SIZE; n++) {

            if(canBePlaced(unassignedPositionRow, unassignedPositionColumn, n)) {
                final int i = unassignedPositionRow;
                final int j = unassignedPositionColumn;
                matrix[i][j] = n;

                if(solve())
                    return true;

                matrix[i][j] = UNASSIGNED;
            }
        }

        return false;
    }

    private boolean findUnassignedPosition() {

        for(int i = 0; i < SUDOKU_SIZE; i++) {
            for(int j = 0; j < SUDOKU_SIZE; j++) {
                if(matrix[i][j] == UNASSIGNED) {
                    unassignedPositionRow = i;
                    unassignedPositionColumn = j;
                    return true;
                }
            }
        }

        return false;
    }

    private boolean canBePlaced(int row, int column, int number) {

        return !isUsedInRow(row, number) && !isUsedInColumn(column, number) && !isUsedInBox(row, column, number);
    }

    private boolean isUsedInRow(int row, int number) {

        for(int i = 0; i < SUDOKU_SIZE; i++)
            if(matrix[row][i] == number)
                return true;
        return false;
    }

    private boolean isUsedInColumn(int column, int number) {

        for(int i = 0; i < SUDOKU_SIZE; i++)
            if(matrix[i][column] == number)
                return true;
        return false;
    }

    private boolean isUsedInBox(int row, int column, int number) {

        int startRow = row - row % 3;
        int startColumn = column - column % 3;

        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                if(matrix[startRow + i][startColumn + j] == number)
                    return true;
        return false;
    }

    public void print() {
        System.out.println("-------------------------");

        for(int i = 0; i < SUDOKU_SIZE; i++) {
            for (int j = 0; j < SUDOKU_SIZE; j++) {
                if (j == 0)
                    System.out.print("| ");
                System.out.print(matrix[i][j] + " ");
                if (j % 3 == 2)
                    System.out.print("| ");

            }
            System.out.println();
            if(i % 3 == 2)
                System.out.println("-------------------------");
        }
        
    }

    public static void main(String[] args) {

        Sudoku sudoku = new Sudoku();
        sudoku.insertRandomNumbers(3);
        System.out.println("Current sudoku state:");
        sudoku.print();
        System.out.println("Solving...");
        if(sudoku.solve())
            sudoku.print();
        else
            System.out.println("No solution found! :(");
    }
}