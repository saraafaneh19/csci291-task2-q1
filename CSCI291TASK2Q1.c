//Sara Afaneh 8955232
//GITHUB LINK:


#include<stdio.h> 
#include <stdbool.h> //to use true/false
#define SIZE 24
#define nRows 8  //defining constants for array sizes
#define nCols 3

// FUNCTION PROTOTYPES
void print_array(int array[], int length); 
void print_matrix(int mat[][nCols], int rows); 
 
void set_array(int arr[], int length);
void rem_align(int arr[], int length, int pos);
void insert_align(int arr[], int length, int pos, int value);
void reshape(int arr[], int length, int arr2d[nRows][nCols]);
void print_trans_matrix(int arr2d[nRows][nCols]);
bool found_duplicate(int arr[], int length);
void flip_array(int arr[], int length, int out[]);

int main()
{
 
   
    int arr[SIZE]; //creates 1d array with 24 integers
    int arr2d[nRows][nCols]; //creates 2d matrix (8x3)
    int reversed[SIZE];  // to keep the reversed array
    
    
    //printing outputs to verify each function works properly

    puts("=== 1. set_array function ===");
    set_array(arr, SIZE);          // fills array with numbers 0-23, and prints each number
    print_array(arr, SIZE);

    puts("\n=== 2. rem_align function ===");
    rem_align(arr, SIZE, 5);       // removes element at index 5 and shifts everything else left, places 0 at last element
    print_array(arr, SIZE);

    puts("\n=== 3. insert_align function ===");
    insert_align(arr, SIZE, 5, 75); // inserts 75 at index 5 and shifts everything else right
    print_array(arr, SIZE);

    puts("\n=== 4. reshape function ===");
    reshape(arr, SIZE, arr2d);     // copies the 1D array into 8x3 matrix row by row, first 3 elemnts go into row zero, the next 3 go to row 1...
    puts("Matrix (row by row):");
    print_matrix(arr2d, nRows);

    puts("\n=== 5. print_trans_matrix function ==="); // displays elemnts in matrix column by column
    puts("Matrix printed by columns:");
    print_trans_matrix(arr2d);

    puts("\n=== 6. found_duplicate function ===");
    bool hasDup = found_duplicate(arr, SIZE);             // looks for any duplicates in the array, prints true or false accordingly
    printf("Duplicates? %s\n", hasDup ? "true" : "false");

    puts("\n=== 7. flip_array function ===");
    flip_array(arr, SIZE, reversed); // copies all elements from array into reversed, in reverse order
    print_array(reversed, SIZE);

    return 0;
    
    
//HELPER FUNCTION DEFINITIONS
}

void print_array(int array[], int length){     //loops through array and prints every element in it
   for(int i=0;i<length; i++)
      printf("array[%d]= %d\n", i, array[i]);
}

void print_matrix(int mat[][nCols], int rows){   //loops through matrix and prints every column and row
   for(int i=0;i<rows; i++){
    for(int j=0;j<nCols; j++)
         printf("mat[%d][%d]= %d\n", i,j, mat[i][j]);
    puts("");     
   }     
}


//FUNCTION DEFINITIONS

void set_array(int arr[], int length){
    for(int i = 0; i < length; i++){
        arr[i] = i;
    }
}
// fills array so that arr[i] = i -> using a single for loop so that each element of the array has the value of its index


void rem_align(int arr[], int length, int pos){
    if(pos < 0 || pos >= length){
        printf("invalid index %d\n", pos);    // prints error message if position is negative or bigger than or equal to the length
        return;
    }
    for(int i = pos; i < length - 1; i++){
        arr[i] = arr[i + 1];
    }
    arr[length - 1] = 0;
}

//single for loop, runs from position to length-2 to remove element at index position by shifting left and clearing the last slot


void insert_align(int arr[], int length, int pos, int value){
    if(pos < 0 || pos >= length){
        printf("invalid index %d\n", pos);  // prints an error message if the position is negative or the position is bigger than or equal to the length
        return;
    }
    for(int i = length - 1; i > pos; i--){
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
}
// using a single for loop that runs backwards(from i=length-1 to pos+1), to insert a value at index position by shifting other elementsone slot to the right 



void reshape(int arr[], int length, int arr2d[nRows][nCols]){
    if(length != nRows * nCols){
        printf("length %d does not match nRows*nCols = %d\n",  //displays an error message if the length does not equal the number of rows*the number of columns
               length, nRows * nCols);
        return;
    }
    int k = 0;
    for(int r = 0; r < nRows; r++){
        for(int c = 0; c < nCols; c++){
            arr2d[r][c] = arr[k];
            k++;
        }
    }
}

// nested for loop, (outer loop for 8 rows, inner loop for 3 columns), copies 1D array into 2D matrix row-by-row



void print_trans_matrix(int arr2d[nRows][nCols]){
    for(int c = 0; c < nCols; c++){
        for(int r = 0; r < nRows; r++){
            printf("%d ", arr2d[r][c]);
        }
        puts("");
    }
}

// nested for loop(outer loop for columns 0-2, inner loop for rows 0-7) to print matrix column-by-column (prints columns as rows)

bool found_duplicate(int arr[], int length){
    for(int i = 0; i < length; i++){
        for(int j = i + 1; j < length; j++){
            if(arr[i] == arr[j]){
                return true;
            }
        }
    }
    return false;
}

// outer loop i starts from 0 to length-1, inner loop j starts from i+1 to length-1 
//to compare each element with the element after it, and thr function returns true if any duplicate values appear in the array




void flip_array(int arr[], int length, int out[]){
    for(int i = 0; i < length; i++){
        out[i] = arr[length - 1 - i];
    }
}

//using a single for loop to create a reversed copy of array inside out

























