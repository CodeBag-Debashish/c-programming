#include <stdio.h>
#include <stdlib.h>
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
    
    ptr = (struct person*) malloc(num * sizeof(struct person));
   
    //ptr->name=(char*)malloc(num*sizeof(char));
    for(i=0;i<num;i++) {
        ptr[i].name = malloc(30*sizeof(char));
    }

    for(i = 0; i < num; ++i) {
        printf("Enter name, age and weight of the person respectively:\n");
        scanf("%s%d%f",ptr[i].name, &(ptr[i].age), &(ptr[i].weight));
    }

    printf("Displaying Infromation:\n");
    for(i = 0; i < num; ++i)
        printf("%s\t%d\t%.2f\n", ptr[i].name, ptr[i].age, ptr[i].weight);

   return 0;
}
 