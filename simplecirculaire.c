#include <stdio.h>
#include <stdlib.h>



struct list{
	int val;
	struct list*  next;
};

typedef struct list list;
typedef list* List;


List createNoeud(int x){
	
	List p=(List)malloc(sizeof(list));

	if(p==NULL){
		perror("->");
		exit(EXIT_FAILURE);
	}

	p->val=x;
	p->next=NULL;

return p;
}


List insertQueue(List l,int v){
	List p=createNoeud(v);
	if(l==NULL){
		p->next=p;
		return p;
	}else{

		List tmp=l;

		while(tmp->next!=l)tmp=tmp->next;

		tmp->next=p;

		p->next=l;


		return l;

	}





}


List insertHead(List l, int v){
    List p = createNoeud(v);

    if(l == NULL){
        p->next = p;
        return p;
    } else {
        List tmp = l;
        while(tmp->next != l){   
            tmp = tmp->next;
        }
        tmp->next = p;
        p->next = l;
        return p;   
    }
}


void afficher(List l){
    if(l == NULL){
        printf("Liste vide\n");
        return;
    }
    List p = l;
    do {
        printf("%d ", p->val);
        p = p->next;
    } while(p != l);
    printf("\n");
}



int main(){
    List l = NULL;

    l = insertHead(l, 10);
    l = insertHead(l, 20);
    l = insertQueue(l, 30);
    l = insertHead(l, 40);
    l = insertQueue(l, 50);

    afficher(l);  // résultat attendu : 40 20 10 30 50

    return 0;
}




