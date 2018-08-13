#include <stdio.h>

#define MAXLINE 1000 /*maximuminputlinelength*/

int _getline(char s[], int lim);
void copy(char to[], char from[]);
void reverse(char to[], char from[]);
/* print the longest input line */

main()
{
    int len; /* current line length */
    int max; /* maximum length seen so far */
    char line[MAXLINE]; /* current input line */
    char longest[MAXLINE]; /* longest line saved here */
    max = 0;
    
    while ((len = _getline(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    
    if(max>0) /*therewasaline*/
    {
        printf("%s", longest);
        char re[MAXLINE];
        reverse(re, longest);
        printf("%s", re);
        printf("%c", re[0]);
    }
    
    return 0;
}

/* getline: read a line into s, return length */
int _getline(char s[],int lim)
{
    int c, i;
    for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    
    s[i] = '\0';
    return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}

void reverse(char to[], char from[])
{
    int i, c;
    int len;
    
    for (i = 0; (c = from[i]) != '\0'; i++) {
        to[i] = c;
    }
    to[len] = '\0';
}