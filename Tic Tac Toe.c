#include <stdio.h>

#define SIZE 3

void print_board(char board[SIZE][SIZE]) {
	printf("\n");
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			printf(" %c ", board[i][j]);
			if (j < SIZE - 1) printf("|");
		}
		printf("\n");
		if (i < SIZE - 1) printf("---+---+---\n");
	}
	printf("\n");
}

int check_winner(char board[SIZE][SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
			return board[i][0];
		if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i])
			return board[0][i];
	}
	if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
		return board[0][0];
	if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
		return board[0][2];
	return 0;
}

int is_draw(char board[SIZE][SIZE]) {
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			if (board[i][j] == ' ')
				return 0;
	return 1;
}

int main() {
	char board[SIZE][SIZE];
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			board[i][j] = ' ';
	int player = 0; // 0 for X, 1 for O
	int row, col;
	char winner = 0;
	printf("\n--- Tic Tac Toe (2-player) ---\n");
	while (1) {
		print_board(board);
		printf("Player %d (%c), enter row and column (1-3 1-3): ", player + 1, player == 0 ? 'X' : 'O');
		scanf("%d %d", &row, &col);
		row--; col--;
		if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col] != ' ') {
			printf("Invalid move. Try again.\n");
			continue;
		}
		board[row][col] = player == 0 ? 'X' : 'O';
		winner = check_winner(board);
		if (winner) {
			print_board(board);
			printf("Player %d (%c) wins!\n", player + 1, winner);
			break;
		}
		if (is_draw(board)) {
			print_board(board);
			printf("It's a draw!\n");
			break;
		}
		player = 1 - player;
	}
	return 0;
}
