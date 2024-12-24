#include<stdio.h>
#include<string.h>

char STR[100], PAT[100], REP[100], ans[100];
int i, j, c, m, k, flag = 0;

void read() {
    printf("Enter the MAIN string: \n");
    fgets(STR, sizeof(STR), stdin);
    STR[strcspn(STR, "\n")] = '\0';
    printf("Enter a PATTERN string: \n");
    fgets(PAT, sizeof(PAT), stdin);
    PAT[strcspn(PAT, "\n")] = '\0';
    printf("Enter a REPLACE string: \n");
    fgets(REP, sizeof(REP), stdin);
    REP[strcspn(REP, "\n")] = '\0';
}

void replace() {
    i = m = c = j = 0;
    while (STR[c] != '\0') {
        if (STR[m] == PAT[i]) {
            i++;
            m++;
            if (PAT[i] == '\0') {
                for (k = 0; REP[k] != '\0'; k++, j++) {
                    ans[j] = REP[k];
                }
                flag = 1;
                i = 0;
                c = m;
            }
        } else {
            ans[j++] = STR[c++];
            m = c;
            i = 0;
        }
    }
    ans[j] = '\0';
}

void print() {
    if (flag == 0)
        printf("Pattern not found!!!\n");
    else
        printf("\nThe RESULTANT string is:\n%s\n", ans);
}

int main() {
    read();
    replace();
    print();
    return 0;
}
