#include <stdio.h>
#include <stdlib.h>


struct list{
	int val;
	struct list* next;
};
typedef struct list list;
typedef list* List;

List insert_trie(List L,int x){
	List p=L;
	List pd=(List)malloc(sizeof(list));
	if(pd==NULL){
		perror("->");
		exit(1);
	}
	pd->val=x;
	pd->next=NULL;

	if(L==NULL ||  x<L->val){
		pd->next=L;
		return pd;
	}
	while(p->next!=NULL && p->next->val<x){
		p=p->next;
	}

	
		pd->next=p->next;
		p->next=pd;

	
	
return L;

}





void afficherListe(List L){
	List p=L;

	if(p==NULL)
		printf("il y'a aucun element dans la liste\n");

	printf("Liste:");
	while(p!=NULL){
		printf("%d ->",p->val);
		p=p->next;
	}



}

int main(){
	List L=NULL;
	int n,x;
	printf("entrer le nombre d'element a inserer:\n");
	scanf("%d",&n);
	printf("entrer le nombre d'element pas ordre croissant\n");
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		L=insert_trie(L,x);
	}

	afficherListe(L);

	L=insert_trie(L,3);

	afficherListe(L);



		free(L);
	
	

	return 0;
}


