#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sujet3.h"

void init(File *mafile){
    mafile->nb_el=0;
    mafile->head=NULL;
    mafile->queue=NULL;
}

boolean filePleine(File *mafile){
    return mafile->nb_el==FULL;
}

boolean fileVide(File *mafile){
    return mafile->nb_el==EMPTY;
}

boolean enfiler(File *mafile, segment seg){
    if(!filePleine(mafile)){
        Noeud *nouveau;
        nouveau=(Noeud*)malloc(sizeof(Noeud));
        nouveau->seg=seg;
        nouveau->next=NULL;
        if(fileVide(mafile)){
            mafile->head=nouveau;
            mafile->queue=nouveau;
        }
        else{
            mafile->queue->next=nouveau;
            mafile->queue=nouveau;
        }
        mafile->nb_el++;
        return vrai;
    }
    return faux;
}

point defiler(File *mafile){
    point milieu;
    milieu.x=0;
    milieu.y=0;
    if(!fileVide(mafile)){
        Noeud *tmp;
        tmp=mafile->head;
        segment tmp_seg;
        tmp_seg = mafile->head->seg;
        if(mafile->nb_el==1){
            mafile->head=NULL;
            mafile->queue=NULL;
        }
        else
            mafile->head=tmp->next;
        mafile->nb_el--;
        free(tmp);
        milieu.x=(tmp_seg.a.x + tmp_seg.b.x)/2;
        milieu.y=(tmp_seg.a.y + tmp_seg.b.y)/2;
    }
    else
        printf("\nOn ne peut défiler une file vide\n");
    return milieu;

}

void afficher(File *mafile){
    if(!fileVide(mafile)){
        Noeud *tmp;
        tmp = mafile->head;
        for(int i=0;i<mafile->nb_el;i++){
            
            printf("segment: point1 = (%lf,%lf), point2 = (%lf,%lf)\n\n", tmp->seg.a.x, tmp->seg.a.y, tmp->seg.b.x, tmp->seg.b.y);
            tmp=tmp->next;
        }

    }
    else
        printf("File vide");

}

void supprimer(File *mafile){
    while(!fileVide(mafile)){
        Noeud *tmp = mafile->head;
        mafile->head=tmp->next;
        free(tmp);
        mafile->nb_el--;
    }
    mafile->head=NULL;
    mafile->queue=NULL;
}

