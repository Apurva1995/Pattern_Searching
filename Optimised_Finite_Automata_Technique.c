#include <stdio.h>
#include <string.h>
#define NO_OF_CHARS 256

void computeTF(char *text, char* pat) {
    
    int m = strlen(pat);
    
    int TF[m+1][NO_OF_CHARS];
    //Initializing lps for 0th row as 0 because lps of a single character is 0
    int lps = 0;     
    
    //Filling 0th row as 0 for all the characters except the character at pat[0]
    for(int i=0;i<NO_OF_CHARS;i++)
        TF[0][i] = 0;
        
    TF[0][pat[0]] = 1;
    
    for(int i=1;i<=m;i++) {
        
        /*Initializing the current row with previous values, because in case of mismatch, we jump to LPS of
         *the current string
        */
        for(int j=0;j<NO_OF_CHARS;j++)
            TF[i][j] = TF[lps][j];
            
        //Change the value for current character in pattern
        TF[i][pat[i]] = i+1;
        
        //Updating lps to latest lps value for the currently formed String
        if(i<m)
            lps = TF[lps][pat[i]];
    }
    
    findPattern(TF, text, pat, m);
}

void findPattern(int TF[][NO_OF_CHARS], char *text, char *pat, int m) {
    
    int n = strlen(text);
    int state = 0;
    for(int i=0;i<n;i++) {
        
        state = TF[state][text[i]];
        if(state == m) {
            
            printf("Pattern found at %d index \n", (i-m+1));
        }
    }
}

int main(void) {
	
	char *text =  "GEEKS FOR GEEKS";
	char *pat  =  "GEEKS";
	
	computeTF(text, pat);
	return 0;
}

//Explanation of computeTF() method (Refer geeksForgeeks "KMP" algorithm for visualization)
/*
* We are initializing every row with lps row, because in case of mismatch, we will move to a state that lps of that 
* character represents.
*
* In KMP algorithm, in case of mismatch, we used to check with pat[lps[j-1]] till we found a match or j=0.
* Using this logic, suppose we are filling lps for "ACACAA". For the last 'A', we will match with 'C' at 3. It won't match, 
* so will match with pat[lps[j-1]], i.e, 'C' at 1. Again mismatch, so with pat[lps[j-1]], i.e, 'A' at '0'. It matches, so ;sp 
* is 1.
* So, the sequence of checked indexes is 3->1->0, in case of mismatch. In case of match, we just increase lps by 1.
*
* Now, in this Efficient construction of FA, on a state if we find current character, i.e, pat[i], we move to next state, i.e,
* currentState + 1. So, when we are checking for TF[i][pat[j]], if at state 'i', pat[j] was available, we would have incresed the state 
* by 1. So the lps will be increased by 1, because state is getting increased by 1. In case of match, we are just increasing the lps by 1.
*
* Now, in case of mismatch, notice how TF table is filled. For the same example "ACACAA"
* Values filled at index 1, is with TF[lps][pat[j]]. Value of lps is 0 here.
* Values filled at index 2, is with TF[lps][pat[j]]. Value of lps is 0 here.
* Values filled at index 3, is with TF[lps][pat[j]]. Value of lps was 0 here. After execution, lps = 1.
* Values filled at index 4, is with TF[lps][pat[j]]. Value of lps was 1 here. After execution, lps = 2.
* Values filled at index 5, is with TF[lps][pat[j]]. Value of lps was 2 here. After execution, lps = 3.
* Now while checking for last 'A', we are matching with 'C' at 3(current value of lps). But it won't match, so it takes directly
* TF[lps]['A']. Why? How does it know that TF[lps]['A'] contains correct value of lps?
* Notice how TF is filled. What all are the indexes that are used. 0->0->1.
* So, when we didn't find 'A' ath index 3, we would have moved to index 1, according to KMP algo. But here at index 3, the value present
* is from index 1 only. Now, after not finding 'A' at 1, we would have moved to 0, but we already have value of index 0 present at index
* 1. So using previous computed values only, we are filling TF table. So, we don't need to go step by step.
*/
