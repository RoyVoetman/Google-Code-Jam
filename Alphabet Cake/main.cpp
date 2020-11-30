#include <iostream>

using namespace std;

int main() {
    int case_amount,
        cake_rows,
        cake_columns;

    //Ask the number of test cases (T)
    cin >> case_amount;

    //For each test case
    for(int i = 0; i < case_amount; i++) {

        /*
         *
         * Input
         *
         */
        //Ask the row and column length (R and C)
        cin >> cake_rows >> cake_columns;

        //The cake array to be filled
        char cake[cake_rows][cake_columns];

        //Array to save the rows that will be filling the 'cake' array
        char row[cake_columns];

        //Ask all the cake rows
        for(int r = 0; r < cake_rows; r++) {

            //Ask the cake row
            cin >> row;

            //Copy the given row into the 'cake' array
            strcpy(cake[r], row);

        }

        /*
         *
         * Assign every blank cell of the cake to one child
         *
         */
        int  blank_rows   = 0;

        //Go over each cake row
        for(int r = 0; r < cake_rows; r++) {

            char current_char = NULL;
            int  blank_cells  = 0;

            //Go over each cake column
            for(int c = 0; c < cake_columns; c++) {

                /*
                 * Assign horizontally
                 */

                //If the cell is blank and we have not found a character in the current row yet
                if(cake[r][c] == '?' && current_char == NULL) {

                    blank_cells++;

                // If the cell is blank and we have already found a character in the current row
                } else if(cake[r][c] == '?') {

                    //Assign the blank cell to the most recently found character in this row
                    cake[r][c] = current_char;

                // If we find a character in the current row
                } else {

                    //Define this character as the "current_char"
                    current_char = cake[r][c];

                    //If this is the first found character in the row: Overwrite all the blank cells that came before this character
                    for(int j = 1; j <= blank_cells; j++) {
                        cake[r][c-j] = current_char;
                    }

                    //Reset the "blank_cells" back to 0
                    blank_cells = 0;

                }

                /*
                 * Assign vertically
                 */

                //If the whole row was blank
                if(blank_cells == cake_columns) {

                    //If there are no solved rows yet
                    if(r-1 == -1 || cake[r-1][c] == '?') {

                        blank_rows++;

                    //Assign the current row to be a copy of the above row
                    } else {

                        for(int j = 0; j < cake_columns; j++) {
                            cake[r][c-j] = cake[r-1][c-j];
                        }

                    }

                //If the current row was solved
                } else if(c+1 == cake_columns) {

                    //Check if there are any rows above the current the are not solved yet
                    if(blank_rows > 0) {

                        //Foreach blank row above the current one
                        for(int j = 1; j <= blank_rows; j++) {

                            //Assign the blank row to be a copy of the current row
                            for(int k = 0; k < cake_columns; k++) {

                                cake[r-j][c-k] = cake[r][c-k];

                            }
                        }

                        //Reset the "blank_rows" back to 0
                        blank_rows = 0;

                    }

                }


            }

        }


        /*
         *
         * Output
         *
         */
        printf("Case #%i:\n", i+1);

        for(int r = 0; r < cake_rows; r++) {

            for(int c = 0; c < cake_columns; c++) {

                cout << cake[r][c];

            }

            cout << endl;

        }

    }

    return 0;
}
