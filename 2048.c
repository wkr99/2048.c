#include<stdio.h>
#include<stdbool.h>
#include<curses.h>


#define GW 5 // GRID_WIDTH
#define GH 5 // GRID_HEIGHT


int squares[GH][GW] = { [0 ... GH-1] = { [0 ... GW-1] = 1 } };
/*  one line initing magic ig.
    init 2d array of h=GH w=GW, filled w 1s for sanity check.
    
    using "designated initializers" for one line array init 
    
    GCC extension: "such and such indeces = val"


*/


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



void squash(bool col_mode, int coord) { 
    
}









int main() {
    printf("twenty fourty eight.\n");

    list_all(/*as_grid = */true);

    return 0;
}












