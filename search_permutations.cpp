#include <stdio.h>
#include <cstring>
#define MAX 256

/*  Prints all occurrences and its permutations.

    Input:  txt[] = "BACDGABCDA"  pat[] = "ABCD"
    Output: Found at Index 0
            Found at Index 5
            Found at Index 6 */

/*  Function returns true if contents of arr1[] and arr2[] are same, otherwise false. */
bool compare(char arr1[], char arr2[]) {
    for(int i = 0; i < MAX; i++)
        if(arr1[i] != arr2[i]) return false;
    return true;
}

/*  Function search for all permutations of pat[] in txt[] */
void search(char *pat, char *txt) {
    int M = strlen(pat), N = strlen(txt);

    /*  countP[]:  Store count of all characters of pattern */
    /*  countTW[]: Store count of current window of text */
    char countP[MAX] = {0}, countTW[MAX] = {0};

    for(int i = 0; i < M; i++) {
        (countP[pat[i]])++;
        (countTW[txt[i]])++;
    }

    /*  Traverse through remaining characters of pattern */
    for(int i = M; i < N; i++) {
        /*  Compare counts of current window of text with counts of pattern[] */
        if(compare(countP, countTW)) printf("%d\n", i-M);

        /*  Add current character to current window */
        (countTW[txt[i]])++;

        /*  Remove the first character of previous window */
        countTW[txt[i-M]]--;
    }

    /*  Check for the last window in text */
    if(compare(countP, countTW)) printf("%d\n", N-M);
}

int main() {
    char txt[] = "AAABABAA";
    char pat[] = "AABA";

    search(pat, txt);
    return 0;
}
