#ifndef GENARR_H
#define GENARR_H

#define INT_ARR_MAX_LENGTH 10

#define CHAR_ARR_MAX_LENGTH 10

#define INR_ARR_COLS_LENGTH 4
#define INR_ARR_ROWS_LENGTH 5



void generIntArr(int *);

void generCharArr_1(char (* result)[10]);
void generCharArr_2(char **result);


void generTwoIntAtt(int (*ptr)[INR_ARR_COLS_LENGTH]);


#endif // GENARR_H
