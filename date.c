#include "date.h"
char *date(){  char *resultado;  time_t t;  struct tm *tm;  char dateTime[1000];  t = time(NULL);  tm = localtime(&t);  strftime(dateTime, 100, "%d/%m/%Y", tm);  resultado = dateTime;  return resultado;}
