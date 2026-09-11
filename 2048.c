#include<stdio.h>
#include<stdbool.h>
#include<curses.h>


#define GW 5 // GRID_WIDTH
#define GH 5 // GRID_HEIGHT


/*
    --- Needs ---
    
    !!fns:

    -- Move L, R, U, D
      - slide all arr elements to $(dir)
      - check for any matching neighor blocks
      - merge matching neighbors (val *= 2, rm one neighbor)
      - re-slide elements to $(dir)
      - repeat til no more matching neighbors
      // easy for L, R; trickier for U, D

    -- Add block
      - adds new block into an empty square
      - val of ew block varies based on game progression
      // outside of fn scope but can add 1 or more than 1 block


    !! win condition: when one or more blocks has val >= 2048
    !! lose condition: when all squares are populated && no mergable neighbors 
*/

// algo to move all items in an array leftward and combine like neighbors
// bool is_not_shifted = true;
// while(is_not_shifted) {
// 	is_not_shifted = false;
// 	for(int i=0; i<arrlen; i++) {
//		if(arr[i] == 0) {
//			printf("nice\n");
//		}
//
// 	}
//
// }
// 
//  HAHAAA iterate backwards over array rather than wrack your brain 5head
// 
//
//  void shift_left(): 
// 
//  bool has_shifted = true;
//
//  while (has_shifted) {
//      bool has_shifted = false
//
//      for (int i=0; i<arrlen-1; i++) {  //no need to check last num
// 		    if arr[i] == 0  {
// 			    if arr.next > 0 {
// 				    arr[i] = arr.next;
// 				    arr.next = 0;
//                  has_shifted = true;
// 			    } else { 
// 				    continue; 
// 			    }
// 		    } else { //arr[i] > 0
// 			    if arr.next == arr[i] {  // if like neighbors
//				    arr[i] += arr.next;
//				    arr.next = 0;
//                  has_shifted = true;
// 			    } else {
// 				    continue;
// 			    }
// 		    }
//      }
//  }
//




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
    bool has_shifted = true;
    
    while (has_shifted) {
        has_shifted = false;

        // iter over arr, combines like members,
        // moves non-zero members if neighbor is zero
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








int main() {
    printf("twenty fourty eight.\n");
    
    squares[0][2] = 2;

    list_all(/*as_grid = */true);

    print_arr(squares[0], GW);

    shift_left(squares[0]);

    print_arr(squares[0], GW);

    return 0;
}












