#include <stdio.h>
#include <stdlib.h>

// Définition de la structure du noeud
typedef struct Liste
{
    int val;
    struct Liste *prec;
    struct Liste *suiv;
} Liste;

Liste *insertionTrie(Liste *l, int val)
{
    Liste *nv = (Liste *)malloc(sizeof(Liste));
    nv->val = val;
    nv->prec = NULL;
    nv->suiv = NULL;

    if (l == NULL)
    {
        return nv;
    }

    Liste *p = l;
    if (val < l->val)
    {
        nv->suiv = l;
        l->prec = nv;
        return nv;
    }

    while (p->suiv != NULL && p->suiv->val < val)
    {
        p = p->suiv;
    }

    nv->suiv = p->suiv;
    nv->prec = p;
    if (p->suiv != NULL)
    {
        p->suiv->prec = nv;
    }
    p->suiv = nv;

    return l;
}

void afficheListe(Liste *l)
{
    Liste *p = l;
    while (p != NULL)
    {
        printf("%d -> ", p->val);
        p = p->suiv;
    }
    printf("NULL\n");
}

int main()
{
    Liste *l = NULL;
    int n, val;

    while (n <= 0)
    {
        printf("Entrez un nombre correct d'éléments a insérer dans la liste : ");
        scanf("%d", &n);
    }

    for (int i = 0; i < n; i++)
    {
        printf("Entrez l'élément %d: ", i + 1);
        scanf("%d", &val);
        l = insertionTrie(l, val);
    }
    printf("La liste ordonnée est : ");
    afficheListe(l);
    printf("\n");

    printf("Veuillez inserer un element dans la liste : ");
    scanf("%d", &val);
    insertionTrie(l, val);

    printf("La nouvelle liste ordonnee est : ");
    afficheListe(l);
    printf("\n");

    Liste *p;
    while (l)
    {
        p = l;
        l = l->suiv;
        free(p);
    }
    return 0;
}
