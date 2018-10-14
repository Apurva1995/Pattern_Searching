\*
*Time complexity : O((m^3) * NO_OF_CHARACTERS) For computing state table, 
                  where 
                  'm' is the length of pattern to search 
                  NO_OF_CHARACTERS is the character set in text
                  
                 : O(n) For searching the pattern
                 where
                 'n' is the length of text
*/


#include <stdio.h>
#include <string.h>
#define NO_OF_CHARACTERS 256

int getNextState(int m, int state, char *pat, int x) {
    
    if(state < m && pat[state] == x)
        return state + 1;
    
    int i;
    
    for(int ns=state; ns>0; ns--) {
        
        if(pat[ns-1] == x) {
            
            for(i=0;i<ns-1;i++) {
                
                if(pat[i] != pat[state-ns+1+i])
                    break;
            }
            if(i == ns-1)
                return ns;
        }
    }
    return 0;
}

void computeTable(int m, int tableForAutomata[][NO_OF_CHARACTERS], char *pat) {
    
    for(int state=0;state<=m;state++) {
        
        for(int x=0;x<NO_OF_CHARACTERS;x++) {
            
            tableForAutomata[state][x] = getNextState(m, state, pat, x);
        }
    }
}

void search(char *pat, char *txt) {
    
    int m = strlen(pat);
    int n = strlen(txt);
    
    int tableForAutomata[m+1][NO_OF_CHARACTERS];
    
    computeTable(m,tableForAutomata, pat);
    
    int state = 0;
    
    for(int i=0;i<n;i++) {
        
        state = tableForAutomata[state][txt[i]];
        
        if(state == m)
            printf("Pattern found at %d index\n", i-m+1);
    }
}

int main(void) {
    char *txt = "AABAACAADAABAAABAA"; 
    char *pat = "AAABAA"; 
    search(pat, txt); 
    return 0; 
}
