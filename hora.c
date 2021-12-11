//Esse arquivo é apenas um teste e contém anotações sobre as funções de tempo.
//https://www.tutorialspoint.com/c_standard_library/time_h.htm

#include <time.h>
#include <stdio.h>

int main(void)
{
    time_t now;
    struct tm *now_tm;
    int hour;

    now = time(NULL);
    now_tm = localtime(&now);
    hour = now_tm->tm_hour;
}