/***********************************************************************************
*    Programme pour connaitre le version du client mysql
*    Installation du client :
*	apt-get install libmysqlclient-dev
*    Compilation :
*	gcc -Wall clientVersion.c -o clientVersion  `mysql_config --cflags --libs`
*    Exécution :
*	./clientVersion
*    Affichage :
*       MySQL client version: 5.5.44
************************************************************************************/
#include <my_global.h>
#include <mysql.h>

int main(int argc, char **argv)
{
  printf("MySQL client version: %s\n", mysql_get_client_info());

  exit(0);
}
