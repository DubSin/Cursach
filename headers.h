#pragma once


int partition(int arr[], int size, int start, int end);

void quick_sort(int arr[], int size, int start, int end);

void insert_sort(int arr[], int size);

void buble_sort(int arr[], int size);

void show_array(int arr[], int size);

int a_quantity(int arr[], int size, int a);

int b_quantity(int arr[], int size, int b);

int binary_search(int arr[], int start, int end, int value);

int avarage_value(int arr[], int size);

void show_same_avarage(int arr[], int size, int avg, bool is_sorted);

void make_sum_cur_next(int arr[], int size);

void init_matrix(int *arr, int size);

void standart_init(int* arr, int size);

void diagonal_transpon(int* arr, int size);

void vertical_transpon(int* arr, int size);

void curcle_transpon(int* arr, int size);

void horizontal_transpon(int* arr, int size);

void operation_with_matrix(int* arr, int size, int num, char action);

void spiral_init(int* arr, int size);

int partition(int* arr, int low, int high);

void determinant_of_matrix(int* arr, int size);

void quicksort(int* arr, int low, int high);

void vertical_output(char *str, int cur_size);

void partition_output(char *str, int start_pos, int end_pos);

void ordered_output(char *str, int cur_size);

int linear_search(char *str, char *substr, int str_legth, int sub_length);

void computeLps(char* pattern, int* &lps);

int kmp(char* text, char* pattern);

void clear_string(char* str, int length);

void First();

void Second();

void Third();

void Fourth();

void second_laba_menu();

void third_laba_menu();

void fourth_laba_menu();
