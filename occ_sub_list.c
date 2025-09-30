#include <stdio.h>
#include <stdlib.h>


struct list{
	int val;
	struct list* next;

};

typedef struct list list;
typedef list*  List;

List sub_occ(List L,int x){
	List p=L;
	List tmp;
	while(p!=NULL && p->val==x){
		tmp=p;
		p=p->next;
		free(tmp);
	}
	p=L;

	while(p!=NULL && p->next!=NULL ){

		if(p->next->val==x){
			tmp=p->next;
			p->next=p->next->next;
			free(tmp);

		}else{
			p=p->next;
			
		}
		
	}
	


return L;


}

List insert_tete(List L,int x){

	List p=(List)malloc(sizeof(list));

	if(p==NULL){
		perror("->");
		exit(EXIT_FAILURE);
	}

	p->val=x;

	p->next=L;

	L=p;


	return p;

}

void afficherListe(List L){
	List p=L;

	if(L==NULL)
		printf("il y'a aucun element dans la liste\n");

	printf("Liste:");
	while(p!=NULL){
		printf("%d ->",p->val);
		p=p->next;
	}

	printf("NULL\n");

}


int main(){

int x,i=0,n;

printf("entrer le nombre d'element que vous voulez inserer:");
scanf("%d",&n);

List L=NULL;
	
for(int i=0;i<=n;i++){
printf("la valeur %d: ",i+1);
scanf("%d",&x);
L=insert_tete(L,x);

}

afficherListe(L);

L=sub_occ(L,3);

afficherListe(L);

}
