#include <stdio.h>
#include <stdlib.h>

typedef struct nodolista {    int key;    struct nodolista *next;  } NODOLISTA;

void aggiungi_in_testa( int KEY, NODOLISTA* *proot        )
{
NODOLISTA *ptr;
ptr=(NODOLISTA*)malloc(sizeof(NODOLISTA));
ptr->next=*proot;
ptr->key=KEY;
*proot=ptr;
}

void stampa(NODOLISTA *ptr)
{
	printf("\n");
	while(ptr)
	{
		printf("%d ", ptr->key);
		ptr=ptr->next;
	}
	printf("\n");
}

/* FUNZIONE DA IMPLEMENTARE !!!!!! */
int  elimina( int KEY, NODOLISTA* *proot  )
{
	while ((*proot) != NULL ){
		if((*proot)->key = KEY){
			NODOLISTA *next = (*proot)->next;
			free(*proot);
			*proot=next;
			return(1);
		}
		else {
			proot = &((*proot)->next);
		}
	}
	return(0);
}


int main()
{
	NODOLISTA *root;
	root=NULL;

	/* codice aggiunto per fare la prova */
	aggiungi_in_testa( 111, &root );
	aggiungi_in_testa( 4,   &root );
	aggiungi_in_testa( 111, &root );
	aggiungi_in_testa( 71,  &root );
	stampa(root);

	elimina(   4 , &root );
	stampa(root);
	elimina( 111 , &root );
	stampa(root);
	elimina(  53 , &root );
	stampa(root);
	elimina(  71 , &root );
	stampa(root);
	elimina( 111 , &root );
	stampa(root);
	/* cerco di eliminare un elemento che non esiste */
	elimina(  10 , &root );
	stampa(root);

	return(0);
}

