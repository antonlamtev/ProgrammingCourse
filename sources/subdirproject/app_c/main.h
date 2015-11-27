#ifndef MAIN
#define MAIN

#define put_error puts("Неправильный ввод параметров!!!");

void exchange(void);

void help_exchange(void);
void help_queens(void);
void help_matrix(void);
void help_quotient(void);
void help_lines_symmetrization(void);
void help(void);

void lines_symmetrization(char* input_file_name, char* output_file_name);

void matrix(char* input_file_name, char* output_file_name);

void main_menu(void);
void menu_no_parameters(void);

void queens(void);
void input_with_check(int* x, int* y, int number);
void display_result(int result);

void quotient(void);

#endif // MAIN

