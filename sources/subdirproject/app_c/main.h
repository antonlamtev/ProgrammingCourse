#ifndef MAIN
#define MAIN

#define put_error puts("Неправильный ввод параметров!!!");

void exchange(void);
void exchange_parameters(int argc, char** argv);

void help_exchange(void);
void help_queens(void);
void help_matrix(void);
void help_quotient(void);
void help_lines_symmetrization(void);
void help(void);
void help_parameters(int argc, char** argv);

void queens(void);
void input_with_check(int* x, int* y, int number);
void display_result(int result);
void queens_parameters(int argc, char** argv);

void lines_symmetrization(char* input_file_name, char* output_file_name);
void lines_symmetrization_parameters(int argc, char** argv);

void matrix(char* input_file_name, char* output_file_name);
void matrix_parameters(int argc, char** argv);

void main_menu(void);
void menu_no_parameters(void);

void quotient(void);
void quotient_parameters(int argc, char** argv);

#endif // MAIN

