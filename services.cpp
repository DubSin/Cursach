#include "headers.h"
#include <iostream>
#include <Windows.h>
#include <chrono>
#include <conio.h>
#include <fstream>
#include <cstring>
using namespace std;

void First()
{
    cout << "int: " << sizeof(int) << endl;
    cout << "short int: " << sizeof(short int) << endl;
    cout << "long int: " << sizeof(long int) << endl;
    cout << "long long int: " << sizeof(long long int) << endl;
    cout << "float: " << sizeof(float) << endl;
    cout << "double: " << sizeof(double) << endl;
    cout << "long double: " << sizeof(long double) << endl;
    cout << "char: " << sizeof(char) << endl;
    cout << "bool: " << sizeof(bool) << endl;
}


void Second()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int color = 9;
    int A;
    int order = sizeof(int) * 8;
    unsigned int mask = 1 << order - 1;
    cout << "Enter int" << endl;
    cin >> A;

    while (cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Enter int" << endl;
        cin >> A;
    }

    for (int i = 1; i <= order; ++i)
    {
        SetConsoleTextAttribute(hConsole, color);
        putchar(mask & A ? '1' : '0');
        mask >>= 1;
        if (i % 8 == 0 || i == 1)
        {
            putchar(' ');
            color++;
        }
    }
    SetConsoleTextAttribute(hConsole, 7);
    cout << endl;
}


void Third()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int color = 11;
    union
    {
        int tool;
        float F;
    };
    int order = sizeof(float) * 8;
    unsigned int mask = 1 << order - 1;
    cout << "Enter float" << endl;
    cin >> F;

    while (cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Enter float" << endl;
        cin >> F;
    }

    for (int i = 1; i <= order; ++i)
    {
        SetConsoleTextAttribute(hConsole, color);
        putchar(mask & tool ? '1' : '0');
        mask >>= 1;
        if (i == 9 || i == 1)
        {
            putchar(' ');
            color++;
        }
    }
    SetConsoleTextAttribute(hConsole, 7);
    cout << endl;
}


void Fourth()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int color = 11;
    union {
        int tool[2];
        double D;
    };
    int order = sizeof(D) * 8;
    unsigned int mask = 1;
    mask <<= order - 1;
    cout << "Enter double" << endl;
    cin >> D;

    while (cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Enter double" << endl;
        cin >> D;
    }

    for (int i = 1; i >= 0; --i)
    {
        for (int j = 0; j < order / 2; ++j)
        {
            SetConsoleTextAttribute(hConsole, color);
            putchar(mask & tool[i] ? '1' : '0');
            mask >>= 1;
            if ((i == 1 && j == 0) || (i == 1 && j == 11))
            {
                putchar(' ');
                color++;
            }
        }
        mask = 1 << order - 1;
    }
    SetConsoleTextAttribute(hConsole, 7);
    cout << endl;
}

int partition(int arr[], int size, int start, int end) {
    int pivot = arr[end];
    int i = (start - 1);
    for (int j = start; j < end; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[end]);
    return (i + 1);
}

void quick_sort(int arr[], int size, int start, int end) {
    if (start < end) {
        int mid = partition(arr, size, start, end);
        quick_sort(arr, size, start, mid - 1);
        quick_sort(arr, size, mid + 1, end);
    }
}

void insert_sort(int arr[], int size) {
    int i, key, j;
    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void buble_sort(int arr[], int size){
    int temp;
    for(int i=0; i < size; i++){
        for (int j=0; j < size; j++){
            if (arr[i] < arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}   

void show_array(int arr[], int size) {
    cout << "Your array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int a_quantity(int arr[], int size, int a) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] >= a) {
            break;
        }
        count++;
    }
    return count;
}

int b_quantity(int arr[], int size, int b) {
    int count = 0;
    for (int i = size - 1; i >= 0; i--) {
        if (arr[i] <= b) {
            break;
        }
        count++;
    }
    return count;
}

int binary_search(int arr[], int start, int end, int value) {
    if (end >= start) {
        int mid = start + ((end - start) / 2);
        if (arr[mid] == value) {
            return mid;
        }
        if (arr[mid] > value) {
            return binary_search(arr, start, mid - 1, value);
        }
        return binary_search(arr, mid + 1, end, value);
    }
    return -1;
}

int avarage_value(int arr[], int size) {
    int max = -100, min = 100, avg;
    for (int i = 0; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i]; 
        }     
    }
    avg = (max + min) / 2;
    return avg;
}

void show_same_avarage(int arr[], int size, int avg, bool is_sorted) {
    int mid = size / 2;
    int count = 0;
    if (is_sorted) {
        int sample_size = 10;
        cout << "Indexes of same elements: ";
        for (int i = mid - sample_size; i < mid + sample_size + 1; i++) {
            if (arr[i] == avg) {
                cout << i << " ";
                count++;
            }
        }
        cout << endl;
        cout << "Count of same elements: " << count << endl;
    }
    else {
        cout << "Indexes of same elements: ";
        for (int i = 0; i < size; i++) {
            if (arr[i] == avg){
                cout << i << " ";
                count++;
            }
            
        }
        cout << endl;
        cout << "Count of same elements: " << count << endl;

    }
}

void make_sum_cur_next(int arr[], int size){
    for(int i=0; i< size; i++){
        if(i == size - 1){
            arr[i] = arr[i] + arr[0];
        }
        else{
            arr[i] = arr[i] + arr[i + 1];
        }
    }
}

void init_matrix(int *arr, int size){
	int startr = 0, endr = size * size - 1;
	int* end = arr + size * size - 1;
	for (int* ptr = arr; ptr <= end; ptr++) {
		*ptr = rand() % (endr - startr + 1) + startr;
	}
}

void sneake_init(int* arr, int size) {
	HANDLE hStdout;
	COORD destCoord;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	int tabl = 0;
	int* end = arr + size * size - 1;
	for (int* ptr = arr; ptr <= end; ptr++) {
		destCoord.X = (ptr - arr) / size + ((tabl / size) * 5);
		destCoord.Y = (ptr - arr) % size;
		SetConsoleCursorPosition(hStdout, destCoord);
		cout << *ptr;
		cout.flush();
		Sleep(300);
		tabl++;
	}
	destCoord.X = 0;
	destCoord.Y = size;
	SetConsoleCursorPosition(hStdout, destCoord);
}

void standart_init(int* arr, int size) {
	HANDLE hStdout;
	COORD destCoord;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	int tabl = 0;
	int* end = arr + size * size - 1;
	for (int* ptr = arr; ptr <= end; ptr++) {
		destCoord.X = (ptr - arr) % size + ((tabl % size) * 5);
		destCoord.Y = (ptr - arr) / size;
		SetConsoleCursorPosition(hStdout, destCoord);
		cout << *ptr;
		cout.flush();
		Sleep(300);
		tabl++;
	}
	destCoord.X = 0;
	destCoord.Y = size;
	SetConsoleCursorPosition(hStdout, destCoord);
}

void diagonal_transpon(int* arr, int size){
	int mid = (size * size / 2) - 1;
	int mid_row = size / 2;
	for (int i=0; i <= mid; i++) {
		if(i < mid_row){
			swap(*(arr + i), *(arr + (size / 2 * size) + i + size / 2));
			}
		if(i >= mid_row){
			swap(*(arr + i), *(arr + (size / 2 * size) + i - size / 2));
			}
		if ((i + 1) % size == 0){
			mid_row += size;
		}
	}
}

void vertical_transpon(int* arr, int size){
	int cur_col = 1;
	int start_pos = 0;
	while (cur_col <= int(size / 2))
	{
		for(int i=start_pos; i < size * size; i+=size){
			swap(*(arr + i), *(arr + (int(size / 2)) + i));
		}
		cur_col++;
		start_pos++;
	}	
}

void curcle_transpon(int* arr, int size){
	int mid_col = (size / 2), cur_row = 1;
	int start_pos = 0;
	while (cur_row <= int(size / 2))
	{
		for(int i=start_pos; i < (mid_col); i++){
			swap(*(arr + i), *(arr + (int(size / 2)) + i));
			swap(*(arr + i), *(arr + (size / 2 * size) + i + size / 2));
			swap(*(arr + i), *(arr + (size * size / 2) + i));
		}
		cur_row++;
		mid_col += size;
		start_pos += size;
	}	
}

void horizontal_transpon(int* arr, int size){
	int mid = (size * size / 2) - 1;
	for (int i=0; i <= mid; i++) {
		swap(*(arr + i), *(arr + (size * size / 2) + i));
	}
}

void operation_with_matrix(int* arr, int size, int num, char action) {
	int* end = arr + size * size - 1;
	for (int* ptr = arr; ptr <= end; ptr++) {
		switch(action){
			case '+':
			*ptr += num;
			break;
			case '*':
			*ptr *= num;
			break;
			case '-':
			*ptr += num;
			break;
			case '/':
			*ptr /= num;
			break;
			default:
			break;
		}
	}
}


void spiral_init(int* arr, int size) {
	HANDLE hStdout;
	COORD destCoord;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	int* ptr = arr;
	int cur_x = -1, cur_y = 0;
	int tabl = -1;
	int left = 0, right = size - 1;
    int top = 0, bottom = size - 1;
	while (left <= right && top <= bottom) {
        for (int i = left; i <= right; i++) {
			tabl++;
			cur_x++;
            destCoord.X = cur_x + ((tabl % size) * 5);
		    destCoord.Y = cur_y;
		    SetConsoleCursorPosition(hStdout, destCoord);
		    cout << *ptr;
		    cout.flush();
		    Sleep(300);
		    ptr++;
        }
		top++;

        for (int i = top; i <= bottom; i++) {
			destCoord.X = right + ((tabl % size) * 5);
		   	destCoord.Y = cur_y % size + 1;
			SetConsoleCursorPosition(hStdout, destCoord);
			cout << *ptr;
			cout.flush();
			Sleep(300);
			cur_y++;
		   	ptr++;
        }
        right--;

        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
				tabl--;
				cur_x--;
                destCoord.X = cur_x + ((tabl % size) * 5);
		   		destCoord.Y = bottom;
				SetConsoleCursorPosition(hStdout, destCoord);
				cout << *ptr;
				cout.flush();
				Sleep(300);
		   		ptr++;
            }
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
				cur_y--;
                destCoord.X = left + (tabl * 5);
		   		destCoord.Y = cur_y;
				SetConsoleCursorPosition(hStdout, destCoord);
				cout << *ptr;
				cout.flush();
				Sleep(300);
		   		ptr++;
            }
            left++;
        }
	}
	destCoord.X = 0;
	destCoord.Y = size;
	SetConsoleCursorPosition(hStdout, destCoord);
}
int partition(int* arr, int low, int high) {
    int pivot = *(arr + high);
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (*(arr + j) <= pivot) {
            i++; 
            swap(*(arr + i), *(arr + j));
        }
    }
    swap(*(arr + i + 1), *(arr + high)); 
    return i + 1; 
}

void determinant_of_matrix(int* arr, int size){
	int determn = 0; 
	for(int i = 0; i < size; i++){
		if (i == 0){
			determn += *(arr + i) * *(arr + i + size + 1) * *(arr + i + (size * 2)+ 2);
			determn -= *(arr + i) * *(arr + i + size + 2) * *(arr + i + (size * 2)+ 1);
		}
		if (i == 1){
			determn += *(arr + i) * *(arr + i + size + 1) * *(arr + i + (size * 2) - 1);
			determn -= *(arr + i) * *(arr + i + size - 1) * *(arr + i + (size * 2) + 1);
		}
		if (i == 2){
			determn += *(arr + i) * *(arr + i + size - 2) * *(arr + i + (size * 2) - 1);
			determn -= *(arr + i) * *(arr + i + size - 1) * *(arr + i + (size * 2) - 2);
		}
	}
	cout << "Determinant = " << determn << endl;
}

void quicksort(int* arr, int low, int high) {
    if (low < high) {

        int pi = partition(arr, low, high);

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

unsigned string_length(char *S)
{
     unsigned L = 0;
     while (S[L]) 
          ++L;
     return L;

}
void vertical_output(char *str, int cur_size){
    for(int i=0; i<=cur_size; i++){
        if (str[i] == ' '){
            cout << '\n';
        }
        else{
            cout << str[i];
        }
        
    }
    cout << endl;
}

void partition_output(char *str, int start_pos, int end_pos){
    for(int i=start_pos; i<= end_pos; i++){
        cout << str[i];
    }
    cout << " ";
}

void ordered_output(char *str, int cur_size){
    bool is_alph = true;
    int start_pos = 0;
    for (int i=0; i<=cur_size; i++){
        if (str[i] == ' ' or i == cur_size){
            if (is_alph){
                partition_output(str, start_pos, i-1);
            }
            is_alph = true;
            start_pos = i + 1;
        } 
        else{
            if (!isalpha(str[i])){
            is_alph = false;
        }
        }
    }
    bool is_num = true;
    for (int i=0; i<=cur_size; i++){
        if (str[i] == ' ' or i == cur_size){
            if (is_num){
                partition_output(str, start_pos, i-1);
            }
            is_num = true;
            start_pos = i + 1;
        } 
        else{
            if (!isdigit(str[i])){
            is_num = false;
        }
        }
    }
    bool is_all = true, char_init = false, int_init = false;
    for (int i=0; i<=cur_size; i++){
        if (str[i] == ' ' or i == cur_size){
            if (is_all && char_init && int_init){
                partition_output(str, start_pos, i-1);
            }
            is_all = true;
            int_init = false, char_init = false;
            start_pos = i + 1;
        } 
        else{
            if (!isalnum(str[i])){
            is_all = false;
            }
            if (isalpha(str[i])){
                char_init = true;
            }
            if (isdigit(str[i])){
                int_init = true;
            }
        }
    }
}

int linear_search(char *str, char *substr, int str_legth, int sub_length) {
    int sub_count = 0;
    for (int i = 0; i <= str_legth - sub_length; i++) {
        int j;
        for (j = 0; j < sub_length; j++) {
            if (str[i + j] != substr[j])
                break;
        }
        
        if (j == sub_length) 
           sub_count++;
    }

    return sub_count; 
}

void computeLps(char* pattern, int* &lps) {
    int n = string_length(pattern);
    int len = 0;
    int i = 1;

    while (i < n) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}
int kmp(char* text, char* pattern) {
    int count = 0;
    int lps[100];
    int n = string_length(text);
    int m = string_length(pattern);
    int i = 0;
    int j = 0;

    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }

        if (j == m) {
            count++;
            j = lps[j - 1];
        } else if (i < n && text[i] != pattern[j]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    return count;
}
void clear_string(char* str, int length){
    char cleaned_text[100]; 
    int j = 0;
    bool prev_space = false; 
    bool prev_punct = false; 
    for (int i = 0; i <= length; ++i) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
           cleaned_text[j++] = str[i] + ('a' - 'A'); 
        } else {
            cleaned_text[j++] = str[i];
        }

        
        if (cleaned_text[j - 1] == ' ') {
            if ( prev_space) {
                --j; 
            }
             prev_space = true;
        } else {
            prev_space = false; 
        }

        
        if (strchr(".,;:!?", cleaned_text[j - 1])) { 
            if (prev_punct) {
                --j; 
            }
            prev_punct = true;
        } else {
            prev_punct = false; 
        }
    }

    strcpy(str, cleaned_text);
}

void second_laba_menu(){
    srand(time(0));
    const int size = 100;
    char action = 's'; // начальное положение action
    int array[size]{};
    bool is_sorted = false, is_initialized = false;
    cout << "Second practice LETI" << endl;
    while (action != 'e') {
        cout << "MENU" << endl;
        cout << "1)Creates an array of size N = 100 and random elements in range from -99 to 99" << endl;
        cout << "2) Sort your array" << endl;
        cout << "3) Find max and min element in your array" << endl;
        cout << "4) Find avarage between max and min in sorted and unsorted array" << endl;
        cout << "5) Output quantity of elements less then a in sorted array(input a)" << endl;
        cout << "6) Output quantity of elements more then b in sorted array(input b)" << endl;
        cout << "7) Find if your element in sorted array(input your element)" << endl;
        cout << "8) Swaps array elements (input element indexes)" << endl;
        cout << "9) Make every element in arrays as a sum of current and next element" << endl;
        cout << "Enter action from 1 to 9 or e to exit: ";
        cin >> action;
        switch (action)
        {
        case '1':
        {
            int start = -size + 1, end = size - 1;
            for (int i = 0; i < size; i++) {
                array[i] = rand() % (end - start + 1) + start;
            }
        }
        is_initialized = true;
        is_sorted = false;
        show_array(array, size);
        _getch();
        break;
        case '2':
            if (is_initialized)
            {
                int array_2[size], array_3[size];
                copy(array, array + size, array_2);
                copy(array, array + size, array_3);
                auto start_time_buble = chrono::steady_clock::now();
                buble_sort(array_2, size);
                auto end_time_buble = chrono::steady_clock::now();
                auto run_time_buble = chrono::duration_cast<chrono::nanoseconds>(end_time_buble - start_time_buble);
                cout << "Buble sort runtime: " << run_time_buble.count() << "ns" << endl;


                auto start_time_insert = chrono::steady_clock::now();
                insert_sort(array_3, size);
                auto end_time_insert = chrono::steady_clock::now();
                auto run_time_insert = chrono::duration_cast<chrono::nanoseconds>(end_time_insert - start_time_insert);
                cout << "Insert sort runtime: " << run_time_insert.count() << "ns" << endl;

                auto start_time_quick = chrono::steady_clock::now();
                quick_sort(array, size, 0, size - 1);
                auto end_time_quick = chrono::steady_clock::now();
                auto run_time_quick = chrono::duration_cast<chrono::nanoseconds>(end_time_quick - start_time_quick);
                cout << "Quick sort runtime: " << run_time_quick.count() << "ns" << endl;

                show_array(array, size);
                is_sorted = true;
            }
            else {
                cout << "Your array is not initialized" << endl;
            }
            _getch();
            break;
        case '3':
            if (is_sorted) {
                auto start_time = chrono::steady_clock::now();
                cout << "Min element: " << array[0] << " Max element: " << array[99] << endl;
                auto end_time = chrono::steady_clock::now();
                auto run_time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time);
                cout << "runtime: " << run_time.count() << "ns" << endl;
            }
            else {
                cout << "Array is not sorted" << endl;
            }
            _getch();
            break;
        case '4':
            if (is_sorted) {
                auto start_time = chrono::steady_clock::now();
                int avg = (array[0] + array[99]) / 2;
                cout << "Avarage value: " << avg << endl;
                show_same_avarage(array, size, avg, is_sorted);
                auto end_time = chrono::steady_clock::now();
                auto run_time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time);
                cout << "runtime: " << run_time.count() << "ns" << endl;
            }
            else  if (is_initialized) {
                auto start_time = chrono::steady_clock::now();
                int avg = avarage_value(array, size);
                cout << "Avarage value: " << avg << endl;
                show_same_avarage(array, size, avg, is_sorted);
                auto end_time = chrono::steady_clock::now();
                auto run_time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time);
                cout << "runtime: " << run_time.count() << "ns" << endl;
            }
            else{
                cout << "Array is not initialazed" << endl;
            }
            _getch();
            break;
        case '5':
            if (is_sorted) {
                int a;
                cout << "Input number a: ";
                cin >> a;
                auto start_time = chrono::steady_clock::now();
                cout << "Quantity of element less then " << a << ": " << a_quantity(array, size, a) << endl;
                auto end_time = chrono::steady_clock::now();
                auto run_time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time);
                cout << "runtime: " << run_time.count() << "ns" << endl;
            }
            else {
                cout << "Array is not sorted" << endl;
            }
            _getch();
            break;
        case '6':
            if (is_sorted) {
                int b;
                cout << "Input number b: ";
                cin >> b;
                auto start_time = chrono::steady_clock::now();
                cout << "Quantity of element more then " << b << ": " << b_quantity(array, size, b) << endl;
                auto end_time = chrono::steady_clock::now();
                auto run_time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time);
                cout << "runtime: " << run_time.count() << "ns" << endl;

            }
            else {
                cout << "Array is not sorted" << endl;
            }
            _getch();
            break;
        case '7':
            if (is_sorted)
            {
                int value, ans;
                cout << "Enter the value of element you want to find: ";
                cin >> value;
                auto start_time = chrono::steady_clock::now();
                ans = binary_search(array, 0, size - 1, value);
                if (ans != -1) {
                    cout << "Your number was found in " << ans << " index" << endl;
                    auto end_time = chrono::steady_clock::now();
                    auto run_time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time);
                    cout << "runtime: " << run_time.count() << "ns" << endl;

                }
                else {
                    cout << "Your number is not in the array" << endl;
                }
            }
            else {
                cout << "Array is not sorted";
            }
            _getch();
            break;
        case '8':
            if (is_initialized)
            {
            int first_index, second_index;
            cout << "Input 2 indexes which you want to swap: ";
            cin >> first_index >> second_index;
            auto start_time = chrono::steady_clock::now();
            swap(array[first_index], array[second_index]);
            auto end_time = chrono::steady_clock::now();
            auto run_time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time);
            cout << "runtime: " << run_time.count() << "ns" << endl;
            show_array(array, size);
            }
            else {
                cout << "Array is not initialized";
            }
            _getch();
            break;
        case '9':
            if(is_initialized){
                make_sum_cur_next(array, size);
                show_array(array, size);
            }
            else{
                cout << "Array is not initialized" << endl;
            }
            _getch();
            break;
        }
        system("cls");
    }
    system("cls");
}

void third_laba_menu(){
    srand(time(0));
	int size;
	cout << "Enter the size of matrix(even number): ";
	cin >> size;
	int arr[size][size]{}; 
	init_matrix(*arr, size);
	char action = 's';
	while (action != 'e') {
		cout << "Menu\n----------------\n1) Fill matrix" << endl;
		cout << "2) Build new matrix from old\n3) Sort matrix" << endl;
		cout << "4)Operation with matrix\n5)IDZ" << endl;
		cout << "Choose action(e - quit): ";
		cin >> action;
		switch (action) {
			case '1':
			{
				char fill_act;
				cout << "1)Sneake fill\n2)Spiral fill\n3)Standart fill\nChoose action:";
				cin >> fill_act;
				switch (fill_act) {
				case '1':
					{
					system("cls");
					sneake_init(*arr, size);
					break;
					}
				case '2':
					{
					system("cls");
					spiral_init(*arr, size);
					break;
					}
				
				case '3':
					{
					system("cls");
					standart_init(*arr, size);
					break;
					}
				}
                _getch();
				break;
			}
			case '2':
			{
				char transp_act;
				cout << "1)Circle\n2)Diagonal\n3)Vertical\n4)Horizontal\nChoose action: ";
				cin>> transp_act;
				switch (transp_act)
				{
				case '1':
					curcle_transpon(*arr, size);
					break;
				case '2':
					diagonal_transpon(*arr, size);
					break;
				case '3':
					vertical_transpon(*arr, size);
					break;
				case '4':
					horizontal_transpon(*arr, size);
					break;
				default:
					break;
				}
				cout << "Done" << endl;
                _getch();
				break;
			}
			case '3':
			{
				quicksort(*arr, 0, size * size - 1);
				cout << "Array sorted" << endl;
                _getch();
				break;
			}
			case '4':
			{
				cout << "Enter number: ";
				int n;
				cin >> n;
				cout << "1)Multiply\n2)Add\n3)Subtract\n4)Divide\nChoose action: ";
				char operation;
				cin >> operation;
				switch (operation)
				{
				case '1':
					operation_with_matrix(*arr, size, n, '*');
					break;
				case '2':
					operation_with_matrix(*arr, size, n, '+');
					break;
				case '3':
					operation_with_matrix(*arr, size, n, '-');
					break;
				case '4':
					operation_with_matrix(*arr, size, n, '/');
					break;
				default:
					break;
				}
				cout << "Done" << endl;
                _getch();
				break;
			}
			case '5':{
				int idz_arr[3][3]{};
				init_matrix(*arr, 3);
				system("cls");
				standart_init(*arr, 3);
				determinant_of_matrix(*arr, 3);
                _getch();

			}
			default:
				break;	
        
		}
        system("cls");
	}
    system("cls");
}

void fourth_laba_menu(){
    char action = 's';
    int cur_str_size = 0;
    char char_arr[100];
    while (action != 'e')
    {
        cout << "Menu" << endl;
        cout << "1)Input string" << endl;
        cout << "2)Correct string" << endl;
        cout << "3)display first all words containing only letters, then words containing only numbers, and then words containing both letters and numbers" << endl;
        cout << "4)Display all words of the original sequence vertically on the screen." << endl;
        cout << "5) Find substring" << endl;
        cout << "Choose action: ";
        cin >> action;
        switch (action)
        {
        case '1':
        {
            char input_type;
            cout << "String or file (s/f): ";
            cin >> input_type;
            switch(input_type){
                case 'f':
                {
                    char file_name[50];
                    cout << "Input file name: ";
                    cin >> file_name;
                    ifstream file(file_name);
                    if(file.is_open()){
                        while(!file.eof()){
                            file.getline (char_arr, 100);
                        }
                    }
                    file.close();
                    cur_str_size = string_length(char_arr);
                    break;
                }
                case 's':
                    cout << "Input your string: " << endl;
                    cin.sync();
                    cin.getline(char_arr, 100);
                    cur_str_size = string_length(char_arr);
                    break;
            }
            break;
        }
        case '2':
        {
            clear_string(char_arr, cur_str_size);
            cout << char_arr;
            _getch();
            break;
        }
        case '3':
        ordered_output(char_arr, cur_str_size);
        _getch();
        break;
        case '4':
        {
            vertical_output(char_arr, cur_str_size);
            _getch();
            break;
        }
        case '5':
        {
            char algorithm_action;
            cout << "1)Linear algorithm \n2)KMP algorithm\n Choose your action: ";
            cin >> algorithm_action;
            int ans = 0;
            switch (algorithm_action)
            {
            case '1':
                {
                char substring[100];
                cout << "Input your substring: " << endl;
                cin.sync();
                cin.getline(substring, 100);
                int sub_ln = string_length(substring);
                ans = linear_search(char_arr, substring, cur_str_size, string_length(substring));
                break;
                }
            case '2':
            {
                char substring[100];
                cout << "Input your substring: " << endl;
                cin.sync();
                cin.getline(substring, 100);
                ans = kmp(char_arr, substring);
                break;
            }
            }
            cout << "Matches found: " << ans;
            _getch();
            break;
        }
        }
    system("cls");
    }
}
