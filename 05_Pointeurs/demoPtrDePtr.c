/*****************************************************************
*    Programme demonstration sur les pointeurs de pointeurs
*    compilation: gcc -Wall demoPtrDePtr.c -o demoPtrDePtr
*
*****************************************************************/

#include <stdio.h>

void miseAZero(short ** t){
    t[0][0] = 2; 	//a[0] avec 2 index
    *(t[0]) = 1; 	//a[0] avec 1 index
    *(*t) = 0; 		//a[0] sans index
    t[0][1] = 2; 	//a[1] avec 2 indexs
    * (t[0] + 1) = 1; 	//a[1] avec 1 index
    * ((*t) + 1) = 0; 	//a[1] sans index
    t[0][2] = 2; 	//a[2] avec 2 indexs
    * (t[0] + 2) = 1; 	//a[2] avec 1 index
    * ((*t) + 2) = 0; 	//a[2] sans index
    t[1][1] = 0; 	//b[1] avec 2 indexs
    * (t[1] + 1) = 1; 	//b[1] avec 1 index
    * (*(t + 1) + 1)=0; //b[1] sans index
    t[1][0] = 2; 	//b[0] avec 2 indexs
    * (t[1]) = 1; 	//b[0] avec 1 index
    * (*(t+1)) = 0; 	//b[0] sans index
}
int main(){

    short a[3] = {1245, 1924, 234};
    short b[2] = {24, 256};
    short * t[2] = {a,b};
    miseAZero(t);
  return 0;
}
