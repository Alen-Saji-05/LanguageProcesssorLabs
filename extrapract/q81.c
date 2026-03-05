#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define MAX 100
char expr[MAX][50], opt[MAX][50];
int n, dead[MAX];
int isnum(char s[]) {
    for(int i=0;s[i];i++) if(!isdigit(s[i])) return 0;
    return 1;
}
// Copy Propagation: replace variable with its copied value
void propagate(char cp[][2][10], int nc, char *s) {
    for(int i=0;i<nc;i++)
        if(strcmp(s, cp[i][0])==0) { strcpy(s, cp[i][1]); return; }
}
int main() {
    char lhs[10], or1[10], or2[10], op;
    char cp[MAX][2][10]; // copy table: cp[i][0] = var, cp[i][1] = value
    int nc=0;

    printf("Enter number of expressions: ");
    scanf("%d", &n);
    for(int i=0;i<n;i++) { printf("Expr %d: ", i+1); scanf("%s", expr[i]); }

    printf("\n--- Original ---\n");
    for(int i=0;i<n;i++) printf("%s\n", expr[i]);

    // === Constant Folding + Copy Propagation ===
    for(int i=0;i<n;i++) {
        if(sscanf(expr[i], "%[^=]=%[^+-*/]%c%s", lhs, or1, &op, or2)==4) {
            // Expression with operator: a=b+c
            propagate(cp, nc, or1);  // replace b with its value if copy exists
            propagate(cp, nc, or2);  // replace c with its value if copy exists
            if(isnum(or1) && isnum(or2)) {
                // Constant Folding: both operands are numbers
                int res, v1=atoi(or1), v2=atoi(or2);
                switch(op) {
                    case '+':res=v1+v2;break; case '-':res=v1-v2;break;
                    case '*':res=v1*v2;break; case '/':res=v1/v2;break;
                }
                sprintf(opt[i], "%s=%d", lhs, res);
                // Add folded result to copy table so later uses get replaced
                strcpy(cp[nc][0], lhs);
                sprintf(cp[nc][1], "%d", res);
                nc++;
            } else {
                sprintf(opt[i], "%s=%s%c%s", lhs, or1, op, or2);
            }
        } else if(sscanf(expr[i], "%[^=]=%s", lhs, or1)==2) {
            // Simple copy: a=b
            propagate(cp, nc, or1);
            strcpy(cp[nc][0], lhs);
            strcpy(cp[nc][1], or1);
            nc++;
            sprintf(opt[i], "%s=%s", lhs, or1);
        }
    }

    printf("\n--- After Constant Folding & Copy Propagation ---\n");
    for(int i=0;i<n;i++) printf("%s\n", opt[i]);

    // === Dead Code Elimination ===
    // If a variable is assigned but never used in any later RHS, it's dead
    for(int i=0;i<n;i++) {
        char v[10]; sscanf(opt[i], "%[^=]", v);
        int used=0;
        for(int j=i+1;j<n;j++) {
            char *rhs = strchr(opt[j], '=');
            if(rhs && strstr(rhs+1, v)) { used=1; break; }
        }
        dead[i] = !used;
    }
    dead[n-1] = 0; // keep last expression (final result)

    printf("\n--- After Dead Code Elimination ---\n");
    for(int i=0;i<n;i++)
        if(!dead[i]) printf("%s\n", opt[i]);

    return 0;
}