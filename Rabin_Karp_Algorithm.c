#include <stdio.h>
#include <string.h>
#define d 256       //We have taken the value of 'd' as 256 becuase there are 256 characters in ASCII set. If our text and pat contained only digits(0-9), we would have taken 'd' as 10.
#define q 101       //For modulo operation


void searchPattern(char *text, char *pat) {
    
    int n = strlen(text);
    int m = strlen(pat);
    
    int h, i, j;
    int p, t;       //'p' and 't' contains hash values for pat and text respectively
    
    h = 1;
    p = t = 0;
    
    //Calculating hash for pat and the first window
    /*
    *     This algorithm uses rolling hash function to calculate hash values.
    */
    for(i=m-1;i>=0;i--) {
        
        p = (p + pat[i] * h) % q;
        t = (t + text[i] * h) % q;
        if(i != 0)
            h = (h * d) % q;
    }
    
    //Looking for pattern
    for(i=0;i<=(n-m);i++) {
        
        if(p == t) {
            
            for(j=0;j<m;j++) {
                
                if(text[i+j] != pat[j])
                    break;
            }
            
            if(j == m)
                printf("Pattern found at %dth position\n", i);
        }
        
        //recalculating hash for next window
        t = (d * (t - text[i] * h) + text[i+m]) % q;
        //t = ((d%q) * (t - text[i] * h) + text[i+m]) % q;
        if(t < 0)
            t += q;
    }
}

int main(void) {
	
	char text[] = "AAAAAAAAAAAAAAA";
	char pat[] = "AAA";
	
	searchPattern(text, pat);
	return 0;
}

