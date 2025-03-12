#include <stdio.h>


int main() {
	
    int a; int *ptr;
    
    ptr = &a;
    
    printf("Donner une valeur de a:");
    scanf("%d",&a);
    
    printf("Acces par valeur, a = %d\n",a);
    printf("");    
    
    printf("Acces par adresse (pointeur), a = %d",(*ptr));
    

    return 0;
}