#include <stdio.h>
#include <stdlib.h>
char *x[5] = {"abcdrtiu","defsdsd","ghasi","jwrkl","mqwerno"};
char *y[5] = {"123as","456we","7wew89","145301","102ew"};
struct hcode {
	char *word;
}hcodes[5];
struct key {
	int id;
	char *word;
	struct hcode *password;
}keytab[5];
void display_content(int,char *,struct key *,struct key *);
int main () { 
	
	for(int i=0;i<5;i++) 
	printf("&x[%d] = %u and x[%d] = %u string = %8s\n",i,((unsigned int)(&x[i]))%10000,i,((unsigned int)(x[i]))%10000,x[i]);
	printf("\n");
	for(int i=0;i<5;i++) 
	printf("&y[%d] = %u and y[%d] = %u string = %8s\n",i,((unsigned int)(&y[i]))%10000,i,((unsigned int)(y[i]))%10000,y[i]);	
	printf("\n");

	for(int i = 0 ; i < 5 ; i++) {
		keytab[i].word = y[i];
		keytab[i].id = i+1;
		keytab[i].password = hcodes+i;
		keytab[i].password->word = x[i];
	}
	
	struct key * ptr = keytab;

	printf("before modification : \n\n");
	printf("size of key struct = %d\n",sizeof(struct key));
	display_content(0,NULL,keytab,ptr);

	printf("\t1st output :: %s,",++ptr->word);
	display_content(1,"++ptr++->word",keytab,ptr); 
	
	printf("\t2nd output:: %s,",++ptr++->password++->word);
	display_content(1,"++ptr++->password->word",keytab,ptr);
	
	printf("\t3rd output:: %s,",++ptr++->password++->word);
	display_content(1,"++ptr++->password++->word",keytab,ptr);

	printf("\t4th output:: %s,",++ptr[-1].password++->word);
	display_content(1,"++ptr[-1].password++->word",keytab,ptr);

	return 0;
}
void display_content(int change,char *str,struct key tab[],struct key *ptr) {
	// mod used for short address view
	if(str != NULL) printf("    when executed : %s\n\n",str);
	if(change) printf("changes occured : \n");
	if(ptr != NULL) printf("ptr = %u\n",((unsigned int)(ptr))%10000);
	for(int i=0;i<5;i++) {
		printf("keytab[%d] addrs = %5u | [id = %d] ",i,((unsigned int)(keytab+i))%10000,keytab[i].id );
		printf("[word = %8s] ",keytab[i].word );
		printf("[word ptr = %5u] ",((unsigned int)(keytab[i].word))%10000);
		printf("[pass ptr = %5u] ",((unsigned int)(keytab[i].password))%10000);
		printf("[pass word ptr = %5u] \n",((unsigned int)(keytab[i].password->word))%10000);

	}
	printf("----------------------------------------------\n");
}

