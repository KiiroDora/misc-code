#include <cstdlib>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

int main()
{
    
    srand(time(0));

    int randnum, chances, range, lrange, input, diff, num_hscore, let_hscore;
    char randlet, guesslet;
    string lpool;
    
    char *p;
    char vowel[5] = {'a', 'e', 'i', 'o', 'u'}; 
    char consont[21] = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'};
    char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    
    while(true){
        cout<<"\n----MAIN MENU----\n1-Guess The Number\n2-Guess The Letter\n3-High Score\n4-Credits\n5-Exit\n\nEnter your choice:\n";
        cin>>input;
        
        switch(input) {
            case 1:
                while(true) {
                    cout<<"\n----GUESS THE NUMBER----\n1-Easy\n2-Medium\n3-Hard\n4-Return to Main Menu\n\nEnter your choice:\n";
                    cin>>diff;
                    
                    switch(diff) {
                        case 1:
                            chances = 5;
                            range = 15;
                            break;
                        case 2:
                            chances = 4;
                            range = 20;
                            break;
                        case 3:
                            chances = 3;
                            range = 40;
                            break;
                        default:
                            goto exit_loop;
                            break;
                    }
                    
                    cout<<"\n\nInstructions:\n1. Guess the number on the given range.\n2. You are only allowed to make one guess at a time.\n3. Each game has a number of chances to guess the correct number.\n4. If you spend all of your chances, you lose the game.\n\nTime to guess the number! The range is 1-"<<range<<".\nYou have "<<chances<<" chances to find the number.\n";
                    randnum = rand() % range + 1;
                    while(chances) {
                        cin>>input;
                        if (input == randnum) { 
                            cout<<"Correct! You have won the game with "<<chances<<" chances left.\n"; 
                            num_hscore = chances;
                            break;
                        } 
                        else if (input > randnum) { cout<<"Your guess is higher than the correct number.\n"; }
                        else { cout<<"Your guess is lower than the correct number.\n"; }
                        chances--;
                        cout<<"You have "<<chances<<" chances left.\n";
                    }
                    
                    if (chances == 0) { cout<<"You have lost the game. The number was "<<randnum<<".\n"; }
                    
                    cout<<"Do you want to try again? (1 -> retry, 2 -> main menu)\n";
                    cin>>input;
                    if (input == 1) { continue; }
                    break;
                }
                
                exit_loop:
                    break;

            case 2:
                while(true) {
                    cout<<"\n----GUESS THE LETTER----\n1-Easy\n2-Medium\n3-Hard\n4-Return to Main Menu\n\nEnter your choice:\n";
                    cin>>diff;
                    
                    switch(diff) {
                        case 1:
                            chances = 2;
                            p = vowel;
                            lpool = " vowels";
                            lrange = 5;
                            break;
                        case 2:
                            chances = 4;
                            p = consont;
                            lpool = " consonants";
                            lrange = 21;
                            break;
                        case 3:
                            chances = 5;
                            p = alphabet;
                            lpool = " the alphabet";
                            lrange = 26;
                            break;
                        default:
                            goto exit_loop2;
                            break;
                    }
                    
                    cout<<"\n\nInstructions:\n1. Guess the letter on the given range.\n2. You are only allowed to make one guess at a time.\n3. Each game has a number of chances to guess the correct number.\n4. If you spend all of your chances, you lose the game.\n\nTime to guess the letter! Guess from"<<lpool<<".\nYou have "<<chances<<" chances to find the letter.\n";
                    randnum = rand() % lrange;
                    randlet = *(p+randnum);
                    while(chances) {
                        cin>>guesslet;
                        if (guesslet == randlet) { 
                            cout<<"Correct! You have won the game with "<<chances<<" chances left.\n"; 
                            let_hscore = chances;
                            break;
                        } 
                        else if (guesslet > randlet) { cout<<"Your guess is alphabetically higher than the correct letter.\n"; }
                        else { cout<<"Your guess is alphabetically lower than the correct number.\n"; }
                        chances--;
                        cout<<"You have "<<chances<<" chances left.\n";
                    }
                    
                    if (chances == 0) { cout<<"You have lost the game. The letter was "<<randlet<<".\n"; }
                    
                    cout<<"Do you want to try again? (1 -> retry, 2 -> main menu)\n";
                    cin>>input;
                    if (input == 1) { continue; }
                    break;
                }
                
                exit_loop2:
                    break;

            case 3:
                cout<<"\n----HIGH SCORE----\n\nGuess The Number: "<<num_hscore<<" chances left\nGuess the Letter: "<<let_hscore<<" chances left\n";
                break;
            case 4:
                cout<<"\n----CREDITS----\n\nCode written by Yusuf Selman Abaci aka KiiroDora\n\n";
                break;
            case 5:
                cout<<"Thank you for playing! See you next time.";
                return 0;
                break;
            default:
                cout<<"Invalid output. Please try again.";
                break;
        }
        
        
    }
    return EXIT_SUCCESS;
}
