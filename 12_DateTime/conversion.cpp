/****************************************************************
*	Conversion d'une date sous forme de chaine
*	en time-stamp
*
*       Compilation : g++ -Wall conversion.c -o conversion
*****************************************************************/

#include <time.h>
#include <stdio.h>
#include <string>    // pour strptime
#include <string.h>  // pour memset

int main(int argc, char **argv) {

    struct tm tm;
    time_t ts = 0;
    memset(&tm, 0, sizeof(tm));

    std::string dateString = "2017-05-13 15:50:01";

    strptime(dateString.c_str(), "%Y-%m-%d %T", &tm);
    ts = mktime(&tm);

    printf("%d \n", (int)ts); //unix time-stamp
    printf("%s \n", ctime(&ts)); //human readable date
}
