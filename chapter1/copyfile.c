#include <stdio.h>
#define IN 1
#define OUT 0

/* copy input to output; 1st version */
main()
{
    int c, state;
    long nc, nl, nw;
    
    nc = nl = nw = 0;
    state = OUT;
    
    while ((c = getchar()) != EOF) {
        putchar(c);
        printf("%d", c);
        
        ++nc;
        
        if (c == '\n') {
            ++nl;
        }
        
        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
        }
        else if(state == OUT){
            state = IN;
            ++nw;
        }
    }
    
    printf("%ld %ld %ld\n", nl, nw, nc);
}