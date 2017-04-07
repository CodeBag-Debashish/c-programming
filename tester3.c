#include <stdio.h>
#include <stdlib.h>
#define NAME_SIZE 30

struct person {
   int age;
   float weight;
   char *name;
};

int main() {

    struct person *ptr;
    int i, num;

    printf("Enter number of persons: ");
    scanf("%d", &num);
    
    struct person * db[num];

    printf("Enter name, age and weight of the person respectively:\n");

    i = 0;
    while(i < num) {
      db[i] = malloc(sizeof(struct person));
      db[i]->name = malloc(NAME_SIZE*sizeof(char));
      scanf("%s%d%f",db[i]->name, &(db[i]->age), &(db[i]->weight));
      i++;
    }

    printf("Displaying Infromation:\n");
    
    for(i = 0; i < num; ++i)
        printf("%s\t%d\t%.2f\n", db[i]->name, db[i]->age, db[i]->weight);

    // add this piece of code
    for(i=0;i<num;i++) {
      free(db[i]->name);
      free(db[i]);
    }

   return 0;
}
 