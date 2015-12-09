#ifndef QUOTIENT_H
#define QUOTIENT_H

#ifdef __cplusplus
extern "C" {
#endif

void put_number_char_by_char_to_array_with_counter(char* array, int number, int *index);
void put_n_symbols_to_array_with_counter(char* array, int n, char symbol, int *index);
void put_result_to_array(char* array, int first_number, int second_number);
int numlen(int num);
int n_th_dig_of_num(int n, int num);
int power(int a, int b);

#ifdef __cplusplus
}
#endif

#endif // QUOTIENT_H
