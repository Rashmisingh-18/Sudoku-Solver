# Sudoku-Solver
This is Sudoku Solver, which works as follws:
Suppose we have a Sudoku grid and we have to solve the number maze problem, Sudoku. Since, Sudoku is a 9 x 9 number grid, and the whole grid are also divided into 3 x 3 boxes There are some rules to solve the Sudoku.

* We have to use digits 1 to 9 for solving this problem.
* One digit cannot be repeated in one row, one column or in one 3 x 3 box.

To solve, try every configuration one by one until the correct configuration is found, i.e. for every unassigned position fill the position with a number from 1 to 9. After filling all the unassigned position check if the matrix is safe or not. If safe print else recurs for other cases.
