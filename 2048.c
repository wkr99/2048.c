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


void list_all() {  // print all squares x, y, val
    for (int i = 0; i < GH; i++) {
        for (int j = 0; j < GW; j++) {
            printf("x=%d y=%d == %d\n", i, j, squares[i][j]);
        }
    }
    printf("\n");
}


void pretty_print() {

}


void squash(bool col_mode, int coord) { 

}



int main() {
    printf("twenty fourty eight.\n");

    printf("┌──────┌─\n");

    //list_all();

    return 0;
}

