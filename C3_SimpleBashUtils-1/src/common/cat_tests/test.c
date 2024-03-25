#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "../utilities.c"
#define MAX_LINE_LENGTH 100000

// cat -n
void cat_test_1() {
  char command_cat[MAX_LINE_LENGTH];
  sprintf(command_cat, "cat %s %s > %s", "-n", "input/input_1",
          "output/output_cat_1");
  system(command_cat);

  char command_s21cat[MAX_LINE_LENGTH];
  sprintf(command_s21cat, "../../cat/s21_cat %s %s > %s", "-n", "input/input_1",
          "output/output_s21cat_1");
  system(command_s21cat);

  int result = compare_files("/output/output_s21cat_1", "/output/output_cat_1");
  if (result == 0)
    printf("Файлы идентичны.\n");
  else
    printf("Файлы различаются.\n");
}

// cat -b
void cat_test_2() {
  char command_cat[MAX_LINE_LENGTH];
  sprintf(command_cat, "cat %s %s > %s", "-b", "input/input_1",
          "output/output_cat_1");
  system(command_cat);

  char command_s21cat[MAX_LINE_LENGTH];
  sprintf(command_s21cat, "../../cat/s21_cat %s %s > %s", "-b", "input/input_1",
          "output/output_s21cat_1");
  system(command_s21cat);

  int result = compare_files("/output/output_s21cat_1", "/output/output_cat_1");
  if (result == 0)
    printf("Файлы идентичны.\n");
  else
    printf("Файлы различаются.\n");
}

// cat -e
void cat_test_3() {
  char command_cat[MAX_LINE_LENGTH];
  sprintf(command_cat, "cat %s %s > %s", "-e", "input/input_1",
          "output/output_cat_1");
  system(command_cat);

  char command_s21cat[MAX_LINE_LENGTH];
  sprintf(command_s21cat, "../../cat/s21_cat %s %s > %s", "-e", "input/input_1",
          "output/output_s21cat_1");
  system(command_s21cat);

  int result = compare_files("/output/output_s21cat_1", "/output/output_cat_1");
  if (result == 0)
    printf("Файлы идентичны.\n");
  else
    printf("Файлы различаются.\n");
}

// cat -e -n
void cat_test_4() {
  char command_cat[MAX_LINE_LENGTH];
  sprintf(command_cat, "cat %s %s %s > %s", "-e", "-n", "input/input_1",
          "output/output_cat_1");
  system(command_cat);

  char command_s21cat[MAX_LINE_LENGTH];
  sprintf(command_s21cat, "../../cat/s21_cat %s %s %s > %s", "-e", "-n",
          "input/input_1", "output/output_s21cat_1");
  system(command_s21cat);

  int result = compare_files("/output/output_s21cat_1", "/output/output_cat_1");
  if (result == 0)
    printf("Файлы идентичны.\n");
  else
    printf("Файлы различаются.\n");
}

// cat -e -b
void cat_test_5() {
  char command_cat[MAX_LINE_LENGTH];
  sprintf(command_cat, "cat %s %s %s > %s", "-e", "-b", "input/input_1",
          "output/output_cat_1");
  system(command_cat);

  char command_s21cat[MAX_LINE_LENGTH];
  sprintf(command_s21cat, "../../cat/s21_cat %s %s %s > %s", "-e", "-b",
          "input/input_1", "output/output_s21cat_1");
  system(command_s21cat);

  int result = compare_files("/output/output_s21cat_1", "/output/output_cat_1");
  if (result == 0)
    printf("Файлы идентичны.\n");
  else
    printf("Файлы различаются.\n");
}

// cat -v -E
void cat_test_6() {
  char command_cat[MAX_LINE_LENGTH];
  sprintf(command_cat, "cat %s %s %s > %s", "-v", "-e", "input/input_1",
          "output/output_cat_1");
  system(command_cat);

  char command_s21cat[MAX_LINE_LENGTH];
  sprintf(command_s21cat, "../../cat/s21_cat %s %s %s > %s", "-v", "-E",
          "input/input_1", "output/output_s21cat_1");
  system(command_s21cat);

  int result = compare_files("/output/output_s21cat_1", "/output/output_cat_1");
  if (result == 0)
    printf("Файлы идентичны.\n");
  else
    printf("Файлы различаются.\n");
}

// cat -v
void cat_test_7() {
  char command_cat[MAX_LINE_LENGTH];
  sprintf(command_cat, "cat %s %s > %s", "-v", "input/input_1",
          "output/output_cat_1");
  system(command_cat);

  char command_s21cat[MAX_LINE_LENGTH];
  sprintf(command_s21cat, "../../cat/s21_cat %s %s > %s", "-v", "input/input_1",
          "output/output_s21cat_1");
  system(command_s21cat);

  int result = compare_files("/output/output_s21cat_1", "/output/output_cat_1");
  if (result == 0)
    printf("Файлы идентичны.\n");
  else
    printf("Файлы различаются.\n");
}

// cat -t
void cat_test_8() {
  char command_cat[MAX_LINE_LENGTH];
  sprintf(command_cat, "cat %s %s > %s", "-t", "input/input_1",
          "output/output_cat_1");
  system(command_cat);

  char command_s21cat[MAX_LINE_LENGTH];
  sprintf(command_s21cat, "../../cat/s21_cat %s %s > %s", "-t", "input/input_1",
          "output/output_s21cat_1");
  system(command_s21cat);

  int result = compare_files("/output/output_s21cat_1", "/output/output_cat_1");
  if (result == 0)
    printf("Файлы идентичны.\n");
  else
    printf("Файлы различаются.\n");
}

// cat -s
void cat_test_9() {
  char command_cat[MAX_LINE_LENGTH];
  sprintf(command_cat, "cat %s %s > %s", "-s", "input/input_1",
          "output/output_cat_1");
  system(command_cat);

  char command_s21cat[MAX_LINE_LENGTH];
  sprintf(command_s21cat, "../../cat/s21_cat %s %s > %s", "-s", "input/input_1",
          "output/output_s21cat_1");
  system(command_s21cat);

  int result = compare_files("/output/output_s21cat_1", "/output/output_cat_1");
  if (result == 0)
    printf("Файлы идентичны.\n");
  else
    printf("Файлы различаются.\n");
}

// cat -T -v
void cat_test_10() {
  char command_cat[MAX_LINE_LENGTH];
  sprintf(command_cat, "cat %s %s %s > %s", "-t", "-v", "input/input_1",
          "output/output_cat_1");
  system(command_cat);

  char command_s21cat[MAX_LINE_LENGTH];
  sprintf(command_s21cat, "../../cat/s21_cat %s %s %s > %s", "-T", "-v",
          "input/input_1", "output/output_s21cat_1");
  system(command_s21cat);

  int result = compare_files("/output/output_s21cat_1", "/output/output_cat_1");
  if (result == 0)
    printf("Файлы идентичны.\n");
  else
    printf("Файлы различаются.\n");
}

// cat --number
void cat_test_11() {
  char command_cat[MAX_LINE_LENGTH];
  sprintf(command_cat, "cat %s %s > %s", "-n", "input/input_1",
          "output/output_cat_1");
  system(command_cat);

  char command_s21cat[MAX_LINE_LENGTH];
  sprintf(command_s21cat, "../../cat/s21_cat %s %s > %s", "--number",
          "input/input_1", "output/output_s21cat_1");
  system(command_s21cat);

  int result = compare_files("/output/output_s21cat_1", "/output/output_cat_1");
  if (result == 0)
    printf("Файлы идентичны.\n");
  else
    printf("Файлы различаются.\n");
}

// cat --number-nonblank
void cat_test_12() {
  char command_cat[MAX_LINE_LENGTH];
  sprintf(command_cat, "cat %s %s > %s", "-b", "input/input_1",
          "output/output_cat_1");
  system(command_cat);

  char command_s21cat[MAX_LINE_LENGTH];
  sprintf(command_s21cat, "../../cat/s21_cat %s %s > %s", "--number-nonblank",
          "input/input_1", "output/output_s21cat_1");
  system(command_s21cat);

  int result = compare_files("/output/output_s21cat_1", "/output/output_cat_1");
  if (result == 0)
    printf("Файлы идентичны.\n");
  else
    printf("Файлы различаются.\n");
}

// cat --squeeze_blank
void cat_test_13() {
  char command_cat[MAX_LINE_LENGTH];
  sprintf(command_cat, "cat %s %s > %s", "-s", "input/input_1",
          "output/output_cat_1");
  system(command_cat);

  char command_s21cat[MAX_LINE_LENGTH];
  sprintf(command_s21cat, "../../cat/s21_cat %s %s > %s", "--squeeze-blank",
          "input/input_1", "output/output_s21cat_1");
  system(command_s21cat);

  int result = compare_files("/output/output_s21cat_1", "/output/output_cat_1");
  if (result == 0)
    printf("Файлы идентичны.\n");
  else
    printf("Файлы различаются.\n");
}

// cat -v -e -n -t -s
void cat_test_14() {
  char command_cat[MAX_LINE_LENGTH];
  sprintf(command_cat, "cat %s %s %s %s %s %s > %s", "-v", "-e", "-n", "-t",
          "-s", "input/input_1", "output/output_cat_1");
  system(command_cat);

  char command_s21cat[MAX_LINE_LENGTH];
  sprintf(command_s21cat, "../../cat/s21_cat %s %s %s %s %s %s > %s", "-v",
          "-e", "-n", "-t", "-s", "input/input_1", "output/output_s21cat_1");
  system(command_s21cat);

  int result = compare_files("/output/output_s21cat_1", "/output/output_cat_1");
  if (result == 0)
    printf("Файлы идентичны.\n");
  else
    printf("Файлы различаются.\n");
}

// cat -v -e -b -t -s
void cat_test_15() {
  char command_cat[MAX_LINE_LENGTH];
  sprintf(command_cat, "cat %s %s %s %s %s %s > %s", "-v", "-e", "-b", "-t",
          "-s", "input/input_1", "output/output_cat_1");
  system(command_cat);

  char command_s21cat[MAX_LINE_LENGTH];
  sprintf(command_s21cat, "../../cat/s21_cat %s %s %s %s %s %s > %s", "-v",
          "-e", "-b", "-t", "-s", "input/input_1", "output/output_s21cat_1");
  system(command_s21cat);

  int result = compare_files("/output/output_s21cat_1", "/output/output_cat_1");
  if (result == 0)
    printf("Файлы идентичны.\n");
  else
    printf("Файлы различаются.\n");
}

// cat [file1] [file2] > [file3]
void cat_test_16() {
  char command_cat[MAX_LINE_LENGTH];
  sprintf(command_cat, "cat %s %s > %s", "input/input_1", "input/input_2",
          "output/output_cat_1");
  system(command_cat);

  char command_s21cat[MAX_LINE_LENGTH];
  sprintf(command_s21cat, "../../cat/s21_cat %s %s > %s", "input/input_1",
          "input/input_2", "output/output_s21cat_1");
  system(command_s21cat);

  int result = compare_files("/output/output_s21cat_1", "/output/output_cat_1");
  if (result == 0)
    printf("Файлы идентичны.\n");
  else
    printf("Файлы различаются.\n");
}

int main() {
  printf("1. cat -n\n");
  cat_test_1();

  printf("2. cat -b\n");
  cat_test_2();

  printf("3. cat -e\n");
  cat_test_3();

  printf("4. cat -e -n\n");
  cat_test_4();

  printf("5. cat -e -b\n");
  cat_test_5();

  printf("6. cat -v -E\n");
  cat_test_6();

  printf("7. cat -v\n");
  cat_test_7();

  printf("8. cat -t\n");
  cat_test_8();

  printf("9. cat -s\n");
  cat_test_9();

  printf("10. cat -T -v\n");
  cat_test_10();

  printf("11. cat --number\n");
  cat_test_11();

  printf("12. cat --number-nonblank\n");
  cat_test_12();

  printf("13. cat --squeeze-blank\n");
  cat_test_13();

  printf("14. cat -v -e -n -t -s \n");
  cat_test_14();

  printf("15. cat -v -e -b -t -s \n");
  cat_test_15();

  printf("16. cat [file1] [file2] > [file3]\n");
  cat_test_16();

  return 0;
}