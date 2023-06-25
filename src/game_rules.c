void print_score(short int player_score1, short int player_score2) {
    for (short int i = 0; i < 80; i++) { putchar('-');}

    printf("\n%25d%30d\n", player_score1, player_score2);
}

short int check_score(short int player_score1, short int player_score2) {
    if (player_score1 == max_count || player_score2 == max_count) {
            printf("%45s", "Game over!\n");
            player_score1 > player_score2 ? printf("%47s", "Player 1 wins!\n") : printf("%47s", "Player 2 wins!\n");
            return 1;
    }
    return 0;
}


