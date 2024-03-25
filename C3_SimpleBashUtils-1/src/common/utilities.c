#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define MAX_LINE_LENGTH 100000

int compare_files(const char *file_name1, const char *file_name2) {
  char cwd[MAX_LINE_LENGTH];
  getcwd(cwd, sizeof(cwd));

  char file1[MAX_LINE_LENGTH] = "";
  strcat(file1, cwd);
  strcat(file1, file_name1);

  char file2[MAX_LINE_LENGTH] = "";
  strcat(file2, cwd);
  strcat(file2, file_name2);

  // printf("%s\n", file1);
  // printf("%s\n", file2);

  FILE *fp1, *fp2;
  char line1[MAX_LINE_LENGTH], line2[MAX_LINE_LENGTH];
  fp1 = fopen(file1, "r");
  fp2 = fopen(file2, "r");
  if (fp1 == NULL || fp2 == NULL) {
    printf("Ошибка открытия файлов.\n");
    return -1;
  }

  int ch1, ch2;
  while (1) {
    ch1 = getc(fp1);
    ch2 = getc(fp2);
    if (ch1 != ch2) {
      printf("%d, %d\n", ch1, ch2);
      return 1;
    }
    if (ch1 == EOF || ch2 == EOF) {
      break;
    }
  }

  fclose(fp1);
  fclose(fp2);
  return 0;
}