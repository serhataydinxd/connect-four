#include <stdio.h>
#include <stdlib.h>

void init(void);         // initialize the table
void yaz(void);          // print the connect four table
void say(void);          // calculate the round number
void turn(char xo);      // execute the turns
void koy(int a, char c); // read the coloumn and place the tile there
void kont(char c);       // check the board for winners and change the turns
void bitir(char c);      // print the final board and winner
void draw(void);         // declares it a draw

char c4[7][7];
int tur, colo, last;
char sira, kaz;
int kazandi = 0;

int main(void) {
  init();
  sira = 'X';
  while (1 == 1) {
    say();
    if (sira == 'X') {
      turn('X');
      kont('X');
    } else if (sira == 'O') {
      turn('O');
      kont('O');
    } else if (sira == 'B') {
      bitir(kaz);
      break;
    } else {
      draw();
      break;
    }
  }
  return 0;
}

void init(void) {
  for (int i = 0; i <= 5; i++) {
    for (int b = 0; b <= 6; b++) {
      c4[i][b] = '*';
    }
    for (int d = 1; d <= 7; d++) {
      c4[6][d - 1] = d + '0';
    }
  }
}

void yaz(void) {
  for (int i = 0; i <= 6; i++) {
    for (int b = 0; b <= 6; b++) {
      printf("%2c", c4[i][b]);
    }
    printf("\n");
  }
}

void say(void) {
  int sayi = 0;
  for (int i = 0; i <= 5; i++) {
    for (int b = 0; b <= 6; b++) {
      if (c4[i][b] == '*') {
        sayi++;
      }
    }
  }
  tur = 43 - sayi;
}

void turn(char xo) {
  system("clear");
  say();
  printf(" move number %d\n", tur);
  yaz();
  printf("Player %c’s turn, enter a column number:", xo);
  scanf("%d", &colo);
  koy(colo, xo);
}

void koy(int a, char c) {
  int b = a - 1; /*since arrays start counting from 0 we need to take one off of
                    user input*/
  if (c4[5][b] == '*') {
    c4[5][b] = c;
    last = 50 + b;
  } else if (c4[4][b] == '*') {
    c4[4][b] = c;
    last = 40 + b;
  } else if (c4[3][b] == '*') {
    c4[3][b] = c;
    last = 30 + b;
  } else if (c4[2][b] == '*') {
    c4[2][b] = c;
    last = 20 + b;
  } else if (c4[1][b] == '*') {
    c4[1][b] = c;
    last = 10 + b;
  } else if (c4[0][b] == '*') {
    c4[0][b] = c;
    last = b;
  } else {
    printf("Coloumn is full, ");
    turn(c);
  }
}

void kont(char c) {
  int yan = 0, dik = 0, casa = 0, caso = 0;
  if (tur == 42) {
    sira = 'D';
  } else if (tur >= 7) {
    // horizontal checking
    for (int i = 0; i < 7; i++) {
      if (c4[last / 10][i] == c) {
        yan++;
      } else {
        yan = 0;
      }
      if (yan >= 4) {
        kazandi = 1;
      }
    }
    // vertical checking
    for (int i = 0; i < 6; i++) {
      if (c4[i][last % 10] == c) {
        dik++;
      } else {
        dik = 0;
      }
      if (dik >= 4) {
        kazandi = 1;
      }
    }
    // right cross checking
    for (int a = last / 10, b = last % 10; a >= 0 && b < 7; a--, b++) {
      if (c4[a][b] == c) {
        casa++;
      } else {
        break;
      }
    }
    for (int a = last / 10 + 1, b = last % 10 - 1; a < 6 && b >= 0; a++, b--) {
      if (c4[a][b] == c) {
        casa++;
      } else {
        break;
      }
    }
    if (casa >= 4) {
      kazandi = 1;
    }
    // left cross checking
    for (int a = last / 10, b = last % 10; a >= 0 && b >= 0; a--, b--) {
      if (c4[a][b] == c) {
        caso++;
      } else {
        break;
      }
    }
    for (int a = last / 10 + 1, b = last % 10 + 1; a < 6 && b < 7; a++, b++) {
      if (c4[a][b] == c) {
        caso++;
      } else {
        break;
      }
    }
    if (caso >= 4) {
      kazandi = 1;
    }
  }
  if (kazandi == 1) {
    kaz = c;
    sira = 'B';
  }
  if (sira == 'X') {
    sira = 'O';
  } else if (sira == 'O') {
    sira = 'X';
  }
}

void bitir(char c) {
  system("clear");
  say();
  printf(" moves made= %d\n", tur - 1);
  yaz();
  printf("\n  %c won!", c);
}

void draw(void) {
  system("clear");
  printf("\n");
  yaz();
  printf("\n It's a draw!");
}