#include "fonctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int decoupe(char *s, arg_post  _post[] ){

    char *tab[25];
    int i=0;

    tab[i++] = strtok (s, "&");
    do
        tab[i] = strtok (NULL, "&");
    while (tab[i++] != NULL);
    i = 0;
    do {
	_post[i].nom = strtok (tab[i], "=");
        _post[i].valeur = strtok (NULL, "=");
    }
    while(_post[i++].nom != NULL);
    return i-1;
}

void debut_page(char *titre, char *css){
    printf("<html><head><title>%s</title>",titre);
    printf("<link rel=\"stylesheet\" type=\"text/css\" href=\"%s\"/>",css);
    printf("</head><body>");

}

void fin_page(){
    printf("</body></html>");
}

void environnement(){
    printf("<div class=\"env\" >");
    printf("<table>");
    printf("<tr> <td>Variable Nom</td> <td>Valeur</td> </tr>");
    printf("<tr><td>DOCUMENT_ROOT  </td> <td>%s</td></tr>",getenv("DOCUMENT_ROOT"));
    printf("<tr><td>CONTENT_LENGTH </td> <td>%s</td></tr>",getenv("CONTENT_LENGTH"));
    printf("<tr><td>SERVER_PROTOCOL</td> <td>%s</td></tr>",getenv("SERVER_PROTOCOL"));
    printf("<tr><td>SERVER_PORT    </td> <td>%s</td></tr>",getenv("SERVER_PORT"));
    printf("<tr><td>SERVER_SOFTWARE</td> <td>%s</td></tr>",getenv("SERVER_SOFTWARE"));
    printf("<tr><td>SCRIPT_NAME    </td> <td>%s</td></tr>",getenv("SCRIPT_NAME"));
    printf("<tr><td>SCRIPT_FILENAME</td> <td>%s</td></tr>",getenv("SCRIPT_FILENAME"));
    printf("<tr><td>REQUEST_METHOD </td> <td>%s</td></tr>",getenv("REQUEST_METHOD"));
    printf("<tr><td>REMOTE_HOST    </td> <td>%s</td></tr>",getenv("REMOTE_HOST"));
    printf("<tr><td>REMOTE_ADDR    </td> <td>%s</td></tr>",getenv("REMOTE_ADDR"));
    printf("<tr><td>REMOTE_PORT    </td> <td>%s</td></tr>",getenv("REMOTE_PORT"));
    printf("<tr><td>HTTP_HOST      </td> <td>%s</td></tr>",getenv("HTTP_HOST"));
    printf("<tr><td>HTTP_COOKIE    </td> <td>%s</td></tr>",getenv("HTTP_COOKIE"));
    printf("<tr><td>HTTP_REFERER   </td> <td>%s</td></tr>",getenv("HTTP_REFERER"));
    printf("<tr><td>HTTP_USER_AGENT</td> <td>%s</td></tr>",getenv("HTTP_USER_AGENT"));
    printf("<tr><td>HTTPS          </td> <td>%s</td></tr>",getenv("HTTPS"));
    printf("<tr><td>PATH           </td> <td>%s</td></tr>",getenv("PATH"));
    printf("<tr><td>QUERY_STRING   </td> <td>%s</td></tr>",getenv("QUERY_STRING"));
    printf("<tr><td>SERVER_SIGNATURE</td> <td>%s</td></tr>",getenv("SERVER_SIGNATURE"));
    printf("</table>");
    printf("</div>");

}

char *surligne(char *text){
    char *code;
    int len;
    len = strlen(text)+14;
    code = (char *)malloc(sizeof(char)*len);
    sprintf(code,"<mark>%s</mark>", text);
    return code;
}

void bouton_retour(){
    printf("<form action=\"%s\"> <input type=\"submit\" value=\"  Retour  \">  </form>",getenv("HTTP_REFERER"));

}
