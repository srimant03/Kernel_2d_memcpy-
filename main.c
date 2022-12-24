#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <errno.h>
#include <linux/kernel.h>

int main(){
    //hardcode a 2D matrix
    float matrix_initial[2][2] = {{1,2},{3,4}};
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            printf("%f ", matrix_initial[i][j]);
        }
        printf("\n");
    }
    float matrix_final[2][2];
    //call the syscall
    int x;
    x = syscall(451, matrix_final, matrix_initial);
    if (x==-1){
        printf("Error in system call");
    }
    else{
        //syscall worked
    }
    //print the final matrix
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            printf("%f ", matrix_final[i][j]);
        }
        printf("\n");
    }
    return 0;
}

