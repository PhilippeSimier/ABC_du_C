/****************************************************************
*	Conversion d'une date sous forme de chaine
*	en time-stamp
*
*       Compilation : g++ -Wall conversion.cpp -o conversion
*       Test : en ligne http://www.timestamp.fr/
*       Exemple : 2017-05-13 16:50:01   donne 1494683401
*****************************************************************/

#include <time.h>
#include <stdio.h>
#include <string>    // pour strptime
#include <string.h>  // pour memset

time_t dateToTimeStamp(std::string dateString){

    struct tm tm;
    memset(&tm, 0, sizeof(tm));

    strptime(dateString.c_str(), "%Y-%m-%d %T", &tm);
    printf("annee : %d\n",tm.tm_year + 1900);
    printf("mois  : %d\n",tm.tm_mon+1);
    printf("jour  : %d\n",tm.tm_mday);
    printf("heure : %d\n",tm.tm_hour);
    printf("min   : %d\n",tm.tm_min);
    printf("sec   : %d\n",tm.tm_sec);
    printf("décalage : %d\n",tm.tm_isdst);
    tm.tm_isdst = -1;    // Not set by strptime();

    return mktime(&tm);
}


int main(int argc, char **argv) {

    std::string date = "2017-05-22 10:55:01";
    time_t retour, maintenant, difference;

    retour = dateToTimeStamp(date);
    printf("TimeStamp : %d\n",(int)retour);
    time(&maintenant);
    difference = maintenant - retour;

    printf("%d s écoulées depuis le ",(int)difference); //unix time-stamp
    printf("%s \n", ctime(&retour)); //human readable date
}
