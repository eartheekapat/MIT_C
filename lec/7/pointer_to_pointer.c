#include <stdio.h>

void swap_1(int **a, int **b);
void swap_2(int *a, int *b) 
;
int main () {
    // initialize 2 integers
    int n_1 = 0;
    int n_2 = 1;
    // initialize 2 pointers
    int * p_n_1 = &n_1;
    int * p_n_2 = &n_2;
    // initialize 2 pointer to pointers
    int ** p_p_n_1 = &p_n_1;
    int ** p_p_n_2 = &p_n_2;
    printf("n_1 = %d\n", n_1);
    printf("n_2 = %d\n", n_2);
    printf("p_n_1 = %p\n", p_n_1);
    printf("p_n_2 = %p\n", p_n_2);
    printf("p_p_n_1 = %p\n", p_p_n_1);
    printf("p_p_n_2 = %p\n", p_p_n_2);
    // // call swap_1
    // swap_1(p_p_n_1, p_p_n_2);
    // call swap_2
    swap_2(p_n_1, p_n_2);

    printf("n_1 = %d\n", n_1);
    printf("n_2 = %d\n", n_2);
    printf("p_n_1 = %p\n", p_n_1);
    printf("p_n_2 = %p\n", p_n_2);
    printf("p_p_n_1 = %p\n", p_p_n_1);
    printf("p_p_n_2 = %p\n", p_p_n_2);
}

void swap_1(int **a, int **b) {
    int *temp = *a;
    *a = *b;
    *b = temp;
}

void swap_2(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}