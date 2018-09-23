#include <stdio.h>
#include <string.h>

void findIndexesOfPat(char *text, char *pat, int *lps) {
    
    int len1, len2, j, i;
    
    i = 0;
    j = 1;
    len1 = strlen(text);
    len2 = strlen(pat);
    
    while(i < len1) {
        
        j = lps[j-1];
        while(j < len2 && i < len1) {
            
            if(text[i] == pat[j]) {
                i++;
                j++;
            }
            else if(j > 0)
                j = lps[j-1];
            else 
				i++;
        }
        
        if(j == len2)
            printf("Pattern found at %d\n", (i-j));
    }
}

void preprocess(int *lps, char *pat) {
    
    int len = strlen(pat);
    lps[0] = 0;
    
    for(int i=1;i<len;i++) {
        
        if(pat[lps[i-1]] == pat[i])
            lps[i] = lps[i-1] + 1;
        else
            lps[i] = 0;
    }
}

int main(void) {
	
	char text[] = "ABCABCDEFGH";
	char pat[] = "ABCDEF";
	int lps[strlen(pat)];
	
	preprocess(lps, pat);
	findIndexesOfPat(text, pat, lps);
	
	return 0;
}

