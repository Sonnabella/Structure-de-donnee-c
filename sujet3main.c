#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sujet3.c"
#include "sujet3.h"

int main(){
File *mafile;
mafile=(File*)malloc(sizeof(File));
init(mafile);
printf("%d\n\n", filePleine(mafile));
printf("%d\n\n", fileVide(mafile));
segment seg1 = {{1,2},{4,7}};
segment seg2 = {{2,2},{-2,-2}};
enfiler(mafile,seg1);
enfiler(mafile,seg2);
printf("Réussi\n\n");
afficher(mafile);
point m =defiler(mafile); 
printf("Le milieu est : p(%2f , %2f)\n\n" , m.x , m.y);
m=defiler(mafile);
printf("Le milieu est : p(%2f , %2f)\n\n" , m.x , m.y);

afficher(mafile);

enfiler(mafile,seg1);

supprimer(mafile);

afficher(mafile);

defiler(mafile);


free(mafile);

return 0;

}

