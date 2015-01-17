#include <stdio.h>
#include <string.h>
#define NMAX 100001
#define MMAX 10001

/*  Searching all occurences of a needle in a haystack.

    Haystack: AABAACAADAABAAABAA
    Needle: AABA

    Indexes: 0, 9, 13 */

char W[MMAX], S[NMAX], T[MMAX];
int m, found;

void kmp_search(char W[], char S[]) {
    int i = 0;

    while((S[m+i] != 0) && (W[i] != 0 ))
        if(S[m+i] == W[i]) i++;
        else {
            m += i - T[i];
            if(i > 0) i = T[i];
        }

    if(W[i] == 0) {
        printf("%d\n", m);
        if(found == 0) found = 1;
        m++;
        kmp_search(W, S);
    }

    /*  For just one occurence, change by:
        if(W[i] == 0) return m;
        else return m + i;
    */
}

void kmp_table(char W[]) {
  int i = 2;
  int j = 0;

  T[0] = -1;
  T[1] =  0;

  while(W[i] != 0)
      if(W[i-1] == W[j]) T[i++] = ++j;
      else if(j > 0) j = T[j];
      else T[i++] = j = 0;

  return;
}

void getIndex() {
    m = 0, found = 0;
    kmp_table(W);
    kmp_search(W, S);

    if(!found) printf("Not found\n");
}

int main() {
    printf("Haystack: ");
    gets(S);

    printf("Needle: ");
    gets(W);

    getIndex();

    return 0;
}
