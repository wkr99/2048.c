#include<stdio.h>
#include<stdbool.h>
#include<curses.h>


#define GW 5 // GRID_WIDTH
#define GH 5 // GRID_HEIGHT


/*
    --- Needs ---
    

    -- Add block
      - adds new block into an empty square
      - val of ew block varies based on game progression
      // outside of fn scope but can add 1 or more than 1 block


    !! win condition: when one or more blocks has val >= 2048
    !! lose condition: when all squares are populated && no mergable neighbors 

*/



int squares[GH][GW] = { [0 ... GH-1] = { [0 ... GW-1] = 0 } };
/*  one line initing magic ig.
    init 2d array of h=GH w=GW, filled w 1s for sanity check.
    
    using "designated initializers" for one line array init 
    
    GCC extension: "such and such indeces = val"  */


void list_all(bool as_grid) {  // print all squares x, y, val; grid or list format
    for (int i = 0; i < GH; i++) {
        for (int j = 0; j < GW; j++) {
            printf("y%dx%d: [%d] ", i, j, squares[i][j]);
            if (!as_grid) { printf("\n"); }
        }
        if (as_grid) { printf("\n"); }
    }
    printf("\n");
}


//flat prints an arr for debug
void print_arr(int * arr, int arr_len) {
    for (int i=0; i < arr_len; i++) {
        printf("[ %d ]", arr[i]);
    }
    printf("\n");
}



void shift_left(int * arr) {
    // take an int arr, shift (swap w zero) non-zero vals to the
    // left until no more shifts can be made
    bool has_shifted = true;
    
    while (has_shifted) {
        has_shifted = false;

        for (int i=0; i < GW - 1; i++) {
            if (arr[i] == 0) {
                if (arr[i + 1] > 0) {
                    arr[i] = arr[i + 1];
                    arr[i + 1] = 0;
                    has_shifted = true;
                }
            } else {  // arr[i] > 0
                if (arr[i + 1] == arr[i]) {  // if like neighbors
                    arr[i] += arr[i + 1];
                    arr[i + 1] = 0;
                    has_shifted = true;
                }
            }
        }
    }
}



void shift_right(int * arr) {
    // take an int arr, shift (swap w zero) non-zero vals to the
    // right until no more shifts can be made
    bool has_shifted = true;

    while (has_shifted) {
        has_shifted = false;


        for (int i = GW - 1; i > 0; i--) {
            if (arr[i] == 0) {
                if (arr[i - 1] > 0) {
                    arr[i] = arr[i - 1];
                    arr[i - 1] = 0;
                    has_shifted = true;
                }
            } else {
                if (arr[i - 1] == arr[i]) {
                    arr[i] += arr[i - 1];
                    arr[i - 1] = 0;
                    has_shifted = true;
                }
            }
        }
    }
}



void shift_up(int * arr, int column) {
    printf("Shift Up\n");
}



void shift_down(int * arr, int row) {
    printf("Shift Down\n");
}






int main() {
    printf("twenty fourty eight.\n");
    
    squares[0][2] = 2;

    list_all(/*as_grid = */true);

    print_arr(squares[0], GW);

    shift_left(squares[0]);

    print_arr(squares[0], GW);

    shift_right(squares[0]);

    print_arr(squares[0], GW);

    return 0;
}












