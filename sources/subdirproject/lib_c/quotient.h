#ifndef QUOTIENT_H
#define QUOTIENT_H

#ifdef __cplusplus
extern "C" {
#endif

void print_n_symbols(FILE *stream, int n, char symbol);
void quotient_out(FILE *stream, int first_number, int second_number);
int numlen(int num);
int n_th_dig_of_num(int n, int num);
int power(int a, int b);

#ifdef __cplusplus
}
#endif

#endif // QUOTIENT_H
