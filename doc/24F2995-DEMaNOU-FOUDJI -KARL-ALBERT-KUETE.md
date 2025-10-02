Cahier de suivi – DEMANOU FOUDJI (Matricule 24F2995)
Informations générales

    Nom:DEMANOU FOUDJI
    prenom : KARL ALBERT KUETE
    Matricule : 24F2995
    Fichier principal : deleteOccurence.c,simplementcirculaire,ajoutLIsteTRiee.cc au total j'ai fait trois sur les cinq

Objectif du programme deleteOccurence.c:supprimer tous les Occurence

    
    pour deleteOccurence j'ai considere deux List tmp et p si la liste est vide je fais tous simplement NULL 
    mais il est aussi possible que le premier element de ma liste soit l'element a supprimer et meme le suivant meme toute ma liste donc j'ai utilisé:
    tantque(while) et les condition suivant dans la boucle while L!=NULL ou L->next==x faire ma variable tmp ici va me permettre de stocker p
    et puis je fais avancé p avec a p=p->next et je dessaloue tmp
    
    
    variable utilisé dans ma fonction deleteOccurence:tmp,p 
    type de ma fonction est:List
    boucle utilisé: tantque
    
    structure:
    list:enregistrement
        val:T
        next:^list
        
    List=^list
    
simplementcirculaire:créé une liste simplement chainé circulaire
    
    
    pour cela j'ai considere les cas ou si ma liste est vide dans ce cas je et le cas ou ma liste n'est pas vide
    j'ai alloue(p) if la liste est different de null on fait p->next=p et on return p si non je cree une variable tmp de type List
    
    maintenant je parcourt grace tmp tous la liste jusqu'a je tmp->next est egale a ma liste tantque(tm->next!=NULL) tmp=tmp->next
    
    puis tmp->next j'affecte p mon premier element et a p->next=l return l si ces l'ajout en queur et p si ces l'ajout en tete
    
    variable utilise dans ma fonction simplementcirculaire:tmp,l,p;
    

    et la structure est la meme pour deleteOccurence
    
ajoutLIsteTRiee:ici il s'agit d'ajout d'un element de telle sorte que la liste reste vide

    les cas de born sont ici ces si le l'element ajouter est plus petit que le premier l'element de la liste
    ou si la liste est vide  et si le dernier element est plus petit que l'element a ajouter j'alloue(pd) qui est la variable a inserer 
    
    p<-l
    pd->val=x et pd->next=NULL pour le cas ou l'element p doit ce trouvé a la dernier position 
     je verifie si l==NULL ou si x<L->val si ces le ca je fais pd->next=l et je retourne pd
        
    
     si ce n'est pas le cas j'utilise while(p->next!=NULL && p->next->val<x)faire
		p=p->next
    fintantque
    
    pd->next = p->next pour ne pas perdre ma liste ici pd->next pointe sur la suivant de la ou est situe p 
    puis p->next=pd pour que p pointe sur son nouveau suivant qui est pd
     et je return ma liste
     
    variable utilisé:p,pd,l
    boucle:tantque
    
    
    
    
    
Compilation

Dans le terminal, placez-vous dans le dossier contenant le fichier InsertListeDoubleTrie.c et tapez :

gcc -Wall -o InsertListeDoubleTrie InsertListeDoubleTrie.c
gcc -wall -o ajoutLIsteTRiee ajoutLIsteTRiee.c
gcc -wall -o deleteOccurence deleteOccurence.c
 
    -Wall pour activer les avertissements du compilateur.
    -o InsertListeDoubleTrie pour nommer l’exécutable obtenu.

Exécution

Pour lancer le programme compilé, entrez simplement :

./InsertListeDoubleTrie
./ajoutLIsteTRiee
./deleteOccurence

Collaboration

Ma contribution collaborative s’est également traduite par l’appréciation et la validation commune des différents programmes uploadés par l’équipe. Chaque programme a été discuté et validé collectivement pour assurer la cohérence et la qualité du travail réalisé.
Historique des actions

    Rédaction, test et mise en ligne du fichier InsertListeDoubleTrie.c
    Participation à la validation collective des travaux sur le dépôt.


