#include <stdio.h>
#include <string.h>
#define NO_OF_CHARS 256

void createBadArray(int m, int badArray[], char *pat) {
    
    for(int i=0;i<NO_OF_CHARS;i++)
        badArray[i] = -1;
        
    for(int i=0;i<m;i++)
        badArray[(int)pat[i]] = i;
}

int max(int x, int y) {
    
    return (x>y)?x:y;
}

void search(char *text, char *pat) {
    
    int m = strlen(pat);
    int n = strlen(text);
    
    int badArray[NO_OF_CHARS];
    
    createBadArray(m, badArray, pat);
        
    int s, j;
    s = 0;
    
    while(s <= (n-m)) {
        
        j = m-1;
        while(j >=0 && pat[j] == text[s+j])
            j--;
        
        if(j < 0) {
            
            printf("Pattern found at %d position\n", s);
            
            s += (s+m) < n ? (m-badArray[text[s+m]]):1;
        }
        else {
            
            s += max(1, j-badArray[text[s+j]]);
        }
    }
}

int main(void) {
	
	char *text = "AABAACAADAABAABA";
	char *pat = "AABA";
	
	search(text, pat);
	return 0;
}


/*
* Time Complexity : Omega(n/m),
*                              Best case happens when we have to compare only one character of pattern every time.
*                 : O(mn),
*                             Worst case happens when all the characters of text and pattern are same.
*
*                              Where n is the length of the text, and
*                              m is the length of pattern.
*
*/
