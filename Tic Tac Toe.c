#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

char check_board(char[10],char[10]);
int print_board(char[10]);
int check_tied(char[10]);

// 0|1|2
// - - -
// 3|4|5
// - - -
// 6|7|8

//TODO: Add timer of 2 second?
//TODO: Add more stuff to do than TTT

int main(void){
    char board[10] = "         ";
    char vis_board[10] = "123456789";
    int x_turn = 1;
    int o_turn = 0;
    int block;
    char gg[10];
    char *ptr;

    //main game loop
    while (1){

        while (1){
            print_board(vis_board);
            if (x_turn){
                printf("x's turn");
            } else {
                printf("o's turn");
            }
            printf("\nWhich block? ");
            //------------Input validation
            scanf("%s",gg);
            block = strtol(gg,&ptr,10);
            //printf("-%u-\n",*ptr);
            if (*ptr != 0){
                printf("Please enter a interger(1-9)\n");
                continue;
            }
                if (board[block-1] == 'x' || board[block-1] == 'o' || block == 0){
                    printf("%d already taken\n",block);
                } else {
                    if (x_turn){
                        board[block-1] = 'x';
                        vis_board[block-1] = 'x';
                    } else if (o_turn){
                        board[block-1] = 'o';
                        vis_board[block-1] = 'o';
                    }
                    break;
                }

        }


        //checks if win condition met or tie
        if (check_board(vis_board,board) == 1){
            if (x_turn){
                print_board(vis_board);
                printf("\ncongratz %c wins!\n",'x');
            }
            if (o_turn){
                print_board(vis_board);
                printf("\ncongratz %c wins!\n",'x');
            }
            break;
        } else if (check_board(vis_board,board) == 2){
            print_board(vis_board);
            printf("\nGame tied\n");
            break;
        }

        x_turn = !x_turn;
        o_turn = !o_turn;


    }
    printf("Press Enter to Continue");
    while (getchar()!='\n');
    system("clear");

    return(0);
}

int print_board(char board[10]){
    printf("\n");
    for (int i = 0; i < strlen(board); ++i){
        printf("%c",board[i]);
        if (i != 2 && i != 5 && i != 8){
            printf("|");
        } else if (i != 8){
            printf("\n- - -\n");
        }
    }
    printf("\n");
    return(0);
}

char check_board(char board[10],char board2[10]){
    //return 1 when win condition 0 otherwise 2 if game tied
    //horizontal
    system("clear");
    if (board[0] == board[1] && board[0] == board[2]){
        return (1);
    } else if (board[3] == board[4] && board[3] == board[5]){
        return board[3];
    } else if (board[6] == board[7] && board[6] == board[8]){
        return (1);
    //vertical
    } else if (board[0] == board[3] && board[0] == board[6]){
        return (1);
    } else if (board[1] == board[4] && board[1] == board[7]){
        return (1);
    } else if (board[2] == board[5] && board[2] == board[8]){
        return (1);
    //diagonal
    } else if (board[0] == board[4] && board[0] == board[8]){
        return (1);
    } else if (board[2] == board[4] && board[2] == board[6]){
        return (1);
    //check if tied game
    } else if (check_tied(board2)){
        return(2);
    }else {
        return(0);
    }
}


int check_tied(char board[10]){
    //run through board if ' ' is found return 0 else return 1
    for (int i = 0; i < 9; ++i){
        if (board[i] == ' '){
            return(0);
        }
    }
    return(1);
}
