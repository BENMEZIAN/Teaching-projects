#include <stdio.h>

int main() {
	
    int tab[5] = {1, 2, 3, 4, 5};
    int *p;

    p = &tab[0]; // équivalent à p = tab

    for(int i = 0; i < 5; i++) {
        printf("tab[%d] = %d\n", i, *(p + i));
    }

    return 0;
}