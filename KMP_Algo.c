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
    int len = 0; 
  
    lps[0] = 0;
    int i = 1; 
    while (i < M) { 
        if (pat[i] == pat[len]) { 
            len++; 
            lps[i] = len; 
            i++; 
        } 
        else
        {
            if (len != 0) { 
                len = lps[len - 1];
            } 
            else 
            { 
                lps[i] = 0; 
                i++; 
            } 
        } 
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

