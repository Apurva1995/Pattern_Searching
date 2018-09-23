#include <stdio.h>
#include <string.h>

void findIndexesOfPat(char *text, char *pat) {
    
    int len1, len2, j;
    
    len1 = strlen(text);
    len2 = strlen(pat);
    
    for(int i=0;i<=(len1-len2);i++) {
        
        for(j=0;j<len2;j++) {
            
            if(text[i+j] != pat[j])
                break;
        }
        
        if(j == len2)
            printf("Pattern found at %d\n", i);
    }
}

int main(void) {
	
	char text[] = "AABAACAADAABAAABAA";
	char pat[] = "AABA";
	
	findIndexesOfPat(text, pat);
	
	return 0;
}

