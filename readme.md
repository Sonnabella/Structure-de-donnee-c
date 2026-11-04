# File de segments en C

TP de structures de données : implémentation d'une file (FIFO) de segments du plan cartésien, avec calcul du milieu à chaque défilement.

![Énoncé du sujet 3](images/sujet3.png)

## Contexte

Un segment du plan cartésien est défini par deux points, eux-mêmes caractérisés par leur abscisse `x` et leur ordonnée `y`. Le but de ce TP est de constituer une file de segments dans laquelle on enfile un nouveau segment à la queue et où l'on défile toujours en tête, la file ne pouvant contenir plus de 50 éléments.

À chaque défilement, le programme ne restitue pas le segment lui-même mais le **point milieu** de ce segment. Le sujet demande un fichier en-tête regroupant les constantes et structures, les fonctions de gestion de la file (pleine, vide, enfiler, défiler, supprimer) et un `main` qui les teste toutes.

## Structure du projet

```
sujet3/
├── sujet3.h        # constantes, structures et prototypes
├── sujet3.c        # implémentation des fonctions de la file
├── sujet3main.c    # programme principal de démonstration
└── images/
    └── sujet3.png  # énoncé du sujet
```

## Choix d'implémentation

La file est une **liste simplement chaînée** avec un pointeur sur la tête et un pointeur sur la queue, ce qui rend l'enfilage et le défilage en temps constant. La limite de 50 segments est vérifiée à chaque ajout grâce à un compteur `nb_el`.

| Élément | Rôle |
|---|---|
| `point` | Un point `(x, y)` en coordonnées réelles (`double`) |
| `segment` | Deux points `a` et `b` |
| `Noeud` | Un segment et un pointeur vers le nœud suivant |
| `File` | Nombre d'éléments, pointeur de tête, pointeur de queue |
| `FULL` / `EMPTY` | Capacité maximale (50) et valeur d'une file vide (0) |

## Fonctions

| Fonction | Description |
|---|---|
| `init` | Initialise une file vide |
| `filePleine` | Retourne `vrai` si la file contient 50 segments |
| `fileVide` | Retourne `vrai` si la file ne contient aucun segment |
| `enfiler` | Ajoute un segment à la queue, retourne `faux` si la file est pleine |
| `defiler` | Retire le segment de tête et retourne son point milieu |
| `afficher` | Affiche tous les segments de la file |
| `supprimer` | Libère tous les nœuds et vide la file |

Le milieu d'un segment `[A, B]` est calculé ainsi :

```
M = ((A.x + B.x) / 2 , (A.y + B.y) / 2)
```

## Compilation et exécution

Le fichier `sujet3main.c` inclut directement `sujet3.c`, il suffit donc de compiler le `main` seul :

```bash
gcc sujet3main.c -o sujet3main -lm
./sujet3main
```

## Exemple d'exécution

Le `main` crée une file, teste `filePleine` et `fileVide`, enfile deux segments (`(1,2)-(4,7)` et `(2,2)-(-2,-2)`), les affiche, puis les défile un par un. Il termine par un test sur file vide.

```
0

1

Réussi

segment: point1 = (1.000000,2.000000), point2 = (4.000000,7.000000)

segment: point1 = (2.000000,2.000000), point2 = (-2.000000,-2.000000)

Le milieu est : p(2.500000 , 4.500000)

Le milieu est : p(0.000000 , 0.000000)

File videFile vide
On ne peut défiler une file vide
```

## Ce que j'ai appris

- Définir et combiner des structures imbriquées (`point`, `segment`, `Noeud`, `File`) et les regrouper dans un fichier en-tête.
- Implémenter une file avec une liste chaînée et gérer correctement la tête, la queue et le compteur d'éléments.
- Allouer et libérer la mémoire dynamiquement (`malloc` / `free`) sans laisser de fuite.
- Séparer le code en trois fichiers (déclarations, implémentation, programme principal).

## Mes difficultés

- **Le cas du dernier élément** : lorsqu'on défile le dernier nœud, il faut aussi remettre le pointeur de queue à `NULL`, sinon il pointe vers une zone libérée.
- **L'ordre des opérations dans `defiler`** : sauvegarder le segment avant de libérer le nœud, sinon on perd la donnée à restituer.
- **La libération complète de la file** : parcourir la liste en gardant un pointeur temporaire pour ne pas perdre le nœud suivant avant le `free`.

## Ce que ça m'apporte

Une meilleure maîtrise des pointeurs et de la gestion mémoire en C, et une base solide pour aborder d'autres structures de données (piles, listes, arbres). C'est aussi mon premier projet publié sur GitHub, le début d'un portfolio que je compte enrichir au fil de mes TP.

## Auteur

**Ton nom ou pseudo**
[github.com/ton-pseudo](https://github.com/Sonnabella)