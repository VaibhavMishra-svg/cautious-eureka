#include<stdio.h>
#define SIZE 50
#include<string.h>
char s[SIZE];
int top=-1; 
push(char elem)
{
    s[++top]=elem;
}
char pop()
{
    return(s[top--]);
}
int pr(char elem)
{
    switch(elem)
    {
    case ')': return 0;
    case '+':
    case '-': return 1;
    case '*':
    case '/': return 2;
    }
}
 main()
{
    char infx[50],prfx[50],ch,elem;
    int i=0,k=0;
    printf("\n\nRead the Infix Expression ? ");
    scanf("%s",infx);
    strrev(infx);
    while( (ch=infx[i++])!= '\0')
    {
        if( ch == ')') push(ch);
        else
            if(isalnum(ch)) prfx[k++]=ch;
            else
                if( ch == '(')
                {
                    while( s[top]!= ')')
                        prfx[k++]=pop();
                    elem=pop();
                }
                else
                {
                    while( pr(s[top]) > pr(ch) )
                        prfx[k++]=pop();
                    push(ch);
                }
    }
    while( s[top] != '\0')
        prfx[k++]=pop();
       strrev(prfx);
    strrev(infx);
    printf("\n\nGiven Infix Expn: %s  Prefix Expn: %s\n",infx,prfx);
}
