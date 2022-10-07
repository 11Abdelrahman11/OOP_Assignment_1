#include <iostream>
#include <bits/c++io.h>
/*
    Algorithm:
    for loop looping over the statement character by character
    if finds any character like 'h or s' it might be our words
    so we check the next characters if they are 'e, h or i'
    if the word is one of our words we replace it by replace function
*/
using namespace std;

int main()
{
    string sentience;
    getline(cin,sentience);
    for (int chrctr = 0, adder = 1; chrctr < sentience.length(); chrctr += adder){ //looping on every character in the string
        if (sentience[chrctr] == ' ' || chrctr == 0){
            if (chrctr == 0){
                if (sentience[chrctr] == 'h' || sentience[chrctr] == 'H'){ //he check
                    if (sentience[chrctr+1] == 'e'){
                        if (sentience[chrctr+2] == ' ' || sentience.length() == 2){
                            sentience.replace(chrctr, 2, "he or she");
                        }
                        else if (sentience[chrctr+2] == 'r'){ //her check
                            if (sentience[chrctr+3] == ' ' || sentience.length() == 3){
                                sentience.replace(chrctr, 3, "him or her");
                            }
                        }
                    }
                    else if (sentience[chrctr+1] == 'i'){ //him check
                        if (sentience[chrctr+2] == 'm'){
                            if (sentience[chrctr+3] == ' ' || sentience.length() == 3){
                                sentience.replace(chrctr, 3, "him or her");
                            }
                        }
                    }
                }
                else if (sentience[chrctr] == 's' || sentience[chrctr] == 'S'){ //she check
                    if (sentience[chrctr+1] == 'h'){
                        if (sentience[chrctr+2] == 'e'){
                            if (sentience[chrctr+3] == ' ' || sentience.length() == 3){
                                sentience.replace(chrctr, 3, "he or she");
                            }
                        }
                    }
                }
            }
            if (sentience[chrctr] == ' '){
                if ((sentience[chrctr+1] == 'h' || sentience[chrctr+1] == 'H') && sentience[chrctr-1] != 'r'){ //he check
                    if (sentience[chrctr+2] == 'e'){
                        if (sentience[chrctr+3] == ' '){
                            sentience.replace(chrctr+1, 2, "he or she");
                        }
                        else if (sentience[chrctr+3] == 'r'){ //her check
                            if (sentience[chrctr+4] == ' ' || sentience[chrctr+4] == '.'){
                                sentience.replace(chrctr+1, 3, "him or her");
                            }
                        }
                    }
                    else if (sentience[chrctr+2] == 'i'){ //him check
                        if (sentience[chrctr+3] == 'm'){
                            if (sentience[chrctr+4] == ' ' || sentience[chrctr+4] == '.'){
                                sentience.replace(chrctr+1, 3, "him or her");
                            }
                        }
                    }
                }
                else if ((sentience[chrctr+1] == 's' || sentience[chrctr+1] == 'S') && sentience[chrctr-1] != 'r'){ //she check
                    if (sentience[chrctr+2] == 'h'){
                        if (sentience[chrctr+3] == 'e'){
                            if (sentience[chrctr+4] == ' ' || sentience[chrctr+4] == '.'){
                                sentience.replace(chrctr+1, 3, "he or she");
                            }
                        }
                    }
                }
            }
        }
    }
    cout << sentience << endl;
    return 0;
}
