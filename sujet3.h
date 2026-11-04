#ifndef SUJET3_H
#define SUJET3_H
#define EMPTY 0
#define FULL 50

struct point{
    double x,y;
};
typedef struct point point;

struct segment{
    point a,b;
};
typedef struct segment segment;

struct Noeud{
    segment seg;
    struct Noeud *next;
};
typedef struct Noeud Noeud;

struct File{
    int nb_el;
    Noeud *head;
    Noeud *queue;
};
typedef struct File File;

typedef enum{faux,vrai}boolean;

void init(File *mafile);
boolean filePleine(File *mafile);
boolean fileVide(File *mafile);
boolean enfiler(File *mafile , segment seg);
point defiler(File *mafile);
void afficher(File *mafile);
void supprimer(File *mafile);

#endif