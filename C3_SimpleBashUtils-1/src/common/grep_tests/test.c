#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "../utilities.c"
#define MAX_LINE_LENGTH 100000

// grep [pattern] [file]
void grep_test_1() {
  char command_grep[MAX_LINE_LENGTH];
  sprintf(command_grep, "grep %s %s > %s", "apple", "input/input_1",
          "output/output_grep_1");
  system(command_grep);

  char command_s21grep[MAX_LINE_LENGTH];
  sprintf(command_s21grep, "../../grep/s21_grep %s %s > %s", "apple",
          "input/input_1", "output/output_s21grep_1");
  system(command_s21grep);

  int result =
      compare_files("/output/output_s21grep_1", "/output/output_grep_1");
  if (result == 0)
    printf("Файлы идентичны.\n");
  else
    printf("Файлы различаются.\n");
}

// grep -e [pattern] -e [pattern] [file]
void grep_test_2() {
  char command_grep[MAX_LINE_LENGTH];
  sprintf(command_grep, "grep %s %s %s %s %s > %s", "-e", "apple", "-e",
          "orange", "input/input_1", "output/output_grep_1");
  system(command_grep);

  char command_s21grep[MAX_LINE_LENGTH];
  sprintf(command_s21grep, "../../grep/s21_grep %s %s %s %s %s > %s", "-e",
          "apple", "-e", "orange", "input/input_1", "output/output_s21grep_1");
  system(command_s21grep);

  int result =
      compare_files("/output/output_s21grep_1", "/output/output_grep_1");
  if (result == 0)
    printf("Файлы идентичны.\n");
  else
    printf("Файлы различаются.\n");
}

// grep -e [pattern] -i [file]
void grep_test_3() {
  char command_grep[MAX_LINE_LENGTH];
  sprintf(command_grep, "grep %s %s %s %s > %s", "-e", "apple", "-i",
          "input/input_1", "output/output_grep_1");
  system(command_grep);

  char command_s21grep[MAX_LINE_LENGTH];
  sprintf(command_s21grep, "../../grep/s21_grep %s %s %s %s > %s", "-e",
          "apple", "-i", "input/input_1", "output/output_s21grep_1");
  system(command_s21grep);

  int result =
      compare_files("/output/output_s21grep_1", "/output/output_grep_1");
  if (result == 0)
    printf("Файлы идентичны.\n");
  else
    printf("Файлы различаются.\n");
}

// grep -e [pattern] -v [file]
void grep_test_4() {
  char command_grep[MAX_LINE_LENGTH];
  sprintf(command_grep, "grep %s %s %s %s > %s", "-e", "apple", "-v",
          "input/input_1", "output/output_grep_1");
  system(command_grep);

  char command_s21grep[MAX_LINE_LENGTH];
  sprintf(command_s21grep, "../../grep/s21_grep %s %s %s %s > %s", "-e",
          "apple", "-v", "input/input_1", "output/output_s21grep_1");
  system(command_s21grep);

  int result =
      compare_files("/output/output_s21grep_1", "/output/output_grep_1");
  if (result == 0)
    printf("Файлы идентичны.\n");
  else
    printf("Файлы различаются.\n");
}

// grep -e [pattern] -c [file]
void grep_test_5() {
  char command_grep[MAX_LINE_LENGTH];
  sprintf(command_grep, "grep %s %s %s %s > %s", "-e", "apple", "-c",
          "input/input_1", "output/output_grep_1");
  system(command_grep);

  char command_s21grep[MAX_LINE_LENGTH];
  sprintf(command_s21grep, "../../grep/s21_grep %s %s %s %s > %s", "-e",
          "apple", "-c", "input/input_1", "output/output_s21grep_1");
  system(command_s21grep);

  int result =
      compare_files("/output/output_s21grep_1", "/output/output_grep_1");
  if (result == 0)
    printf("Файлы идентичны.\n");
  else
    printf("Файлы различаются.\n");
}

// grep -e [pattern] -l [file1] [file2]
void grep_test_6() {
  char command_grep[MAX_LINE_LENGTH];
  sprintf(command_grep, "grep %s %s %s %s %s > %s", "-e", "apple", "-l",
          "input/input_1", "input/input_2", "output/output_grep_1");
  system(command_grep);

  char command_s21grep[MAX_LINE_LENGTH];
  sprintf(command_s21grep, "../../grep/s21_grep %s %s %s %s %s > %s", "-e",
          "apple", "-l", "input/input_1", "input/input_2",
          "output/output_s21grep_1");
  system(command_s21grep);

  int result =
      compare_files("/output/output_s21grep_1", "/output/output_grep_1");
  if (result == 0)
    printf("Файлы идентичны.\n");
  else
    printf("Файлы различаются.\n");
}

// grep -e [pattern] -h [file1] [file2]
void grep_test_7() {
  char command_grep[MAX_LINE_LENGTH];
  sprintf(command_grep, "grep %s %s %s %s %s > %s", "-e", "apple", "-h",
          "input/input_1", "input/input_2", "output/output_grep_1");
  system(command_grep);

  char command_s21grep[MAX_LINE_LENGTH];
  sprintf(command_s21grep, "../../grep/s21_grep %s %s %s %s %s > %s", "-e",
          "apple", "-h", "input/input_1", "input/input_2",
          "output/output_s21grep_1");
  system(command_s21grep);

  int result =
      compare_files("/output/output_s21grep_1", "/output/output_grep_1");
  if (result == 0)
    printf("Файлы идентичны.\n");
  else
    printf("Файлы различаются.\n");
}

// grep -e [pattern] -n [file]
void grep_test_8() {
  char command_grep[MAX_LINE_LENGTH];
  sprintf(command_grep, "grep %s %s %s %s > %s", "-e", "apple", "-n",
          "input/input_1", "output/output_grep_1");
  system(command_grep);

  char command_s21grep[MAX_LINE_LENGTH];
  sprintf(command_s21grep, "../../grep/s21_grep %s %s %s %s > %s", "-e",
          "apple", "-n", "input/input_1", "output/output_s21grep_1");
  system(command_s21grep);

  int result =
      compare_files("/output/output_s21grep_1", "/output/output_grep_1");
  if (result == 0)
    printf("Файлы идентичны.\n");
  else
    printf("Файлы различаются.\n");
}

// grep -e [pattern] -s [file1] [non-exixtent file]
void grep_test_9() {
  char command_grep[MAX_LINE_LENGTH];
  sprintf(command_grep, "grep %s %s %s %s %s > %s", "-e", "apple", "-s",
          "input/input_1", "lol", "output/output_grep_1");
  system(command_grep);

  char command_s21grep[MAX_LINE_LENGTH];
  sprintf(command_s21grep, "../../grep/s21_grep %s %s %s %s %s> %s", "-e",
          "apple", "-s", "input/input_1", "lol", "output/output_s21grep_1");
  system(command_s21grep);

  int result =
      compare_files("/output/output_s21grep_1", "/output/output_grep_1");
  if (result == 0)
    printf("Файлы идентичны.\n");
  else
    printf("Файлы различаются.\n");
}

// grep -f [file1] [file2]
void grep_test_10() {
  char command_grep[MAX_LINE_LENGTH];
  sprintf(command_grep, "grep %s %s %s > %s", "-f", "input/input_1",
          "input/input_2", "output/output_grep_1");
  system(command_grep);

  char command_s21grep[MAX_LINE_LENGTH];
  sprintf(command_s21grep, "../../grep/s21_grep %s %s %s > %s", "-f",
          "input/input_1", "input/input_2", "output/output_s21grep_1");
  system(command_s21grep);

  int result =
      compare_files("/output/output_s21grep_1", "/output/output_grep_1");
  if (result == 0)
    printf("Файлы идентичны.\n");
  else
    printf("Файлы различаются.\n");
}

// grep -n -o [pattern] [file]
void grep_test_11() {
  char command_grep[MAX_LINE_LENGTH];
  sprintf(command_grep, "grep %s %s %s %s > %s", "-n", "-o", "app",
          "input/input_1", "output/output_grep_1");
  system(command_grep);

  char command_s21grep[MAX_LINE_LENGTH];
  sprintf(command_s21grep, "../../grep/s21_grep %s %s %s %s > %s", "-n", "-o",
          "app", "input/input_1", "output/output_s21grep_1");
  system(command_s21grep);

  int result =
      compare_files("/output/output_s21grep_1", "/output/output_grep_1");
  if (result == 0)
    printf("Файлы идентичны.\n");
  else
    printf("Файлы различаются.\n");
}
// grep -iv [pattern] [file]
void grep_test_12() {
  char command_grep[MAX_LINE_LENGTH];
  sprintf(command_grep, "grep %s %s %s > %s", "-iv", "apple", "input/input_1",
          "output/output_grep_1");
  system(command_grep);

  char command_s21grep[MAX_LINE_LENGTH];
  sprintf(command_s21grep, "../../grep/s21_grep %s %s %s > %s", "-iv", "apple",
          "input/input_1", "output/output_s21grep_1");
  system(command_s21grep);

  int result =
      compare_files("/output/output_s21grep_1", "/output/output_grep_1");
  if (result == 0)
    printf("Файлы идентичны.\n");
  else
    printf("Файлы различаются.\n");
}

// grep -i -n -c -v -e [pattern] -e [pattern] [file1] [file2]
void grep_test_13() {
  char command_grep[MAX_LINE_LENGTH];
  sprintf(command_grep, "grep %s %s %s %s %s %s %s %s %s %s> %s", "-i", "-n",
          "-c", "-v", "-e", "apple", "-e", "orange", "input/input_1",
          "input/input_2", "output/output_grep_1");
  system(command_grep);

  char command_s21grep[MAX_LINE_LENGTH];
  sprintf(command_s21grep,
          "../../grep/s21_grep %s %s %s %s %s %s %s %s %s %s> %s", "-i", "-n",
          "-c", "-v", "-e", "apple", "-e", "orange", "input/input_1",
          "input/input_2", "output/output_s21grep_1");
  system(command_s21grep);

  int result =
      compare_files("/output/output_s21grep_1", "/output/output_grep_1");
  if (result == 0)
    printf("Файлы идентичны.\n");
  else
    printf("Файлы различаются.\n");
}

int main() {
  printf("1. grep [pattern] [file]\n");
  grep_test_1();

  printf("2. grep -e [pattern] -e [pattern] [file]\n");
  grep_test_2();

  printf("3. grep -e [pattern] -i [file]\n");
  grep_test_3();

  printf("4. grep -e [pattern] -v [file]\n");
  grep_test_4();

  printf("5. grep -e [pattern] -c [file]\n");
  grep_test_5();

  printf("6. grep -e [pattern] -l [file1] [file2]\n");
  grep_test_6();

  printf("7. grep -e [pattern] -h [file1] [file2]\n");
  grep_test_7();

  printf("8. grep -e [pattern] -n [file]\n");
  grep_test_8();

  printf("9. grep -e [pattern] -s [file1] [non-exixtent file]\n");
  grep_test_9();

  printf("10. grep -f [file1] [file2]\n");
  grep_test_10();

  printf("11. grep -n -o [pattern] [file]\n");
  grep_test_11();

  printf("12. grep -iv [pattern] [file]\n");
  grep_test_12();

  printf("13. grep -i -n -c -v -e [pattern] -e [pattern] [file1] [file2]\n");
  grep_test_13();
}