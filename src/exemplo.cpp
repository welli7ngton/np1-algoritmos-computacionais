#include <iostream>

/* run this program using the console pauser or add your own getch,
 * system("pause") or input loop */

int main(int argc, char **argv) {
  char reserva[10][6] = {
      {' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' '},
      {' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' '},
      {' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' '},
      {' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' '},
      {' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' '}};
  int fileira = -1, acento = -1;
  char poltrona = ' ';

  while (true) {
    printf("\nDigite a fileira (1-10): ");
    scanf("%d", &fileira);
    printf("\nDigite a poltrona [A][B][C][D][E][F]: ");
    scanf(" %c", &poltrona);

    switch (poltrona) {
    case 'A':
      acento = 0;
      break;
    case 'B':
      acento = 1;
      break;
    case 'C':
      acento = 2;
      break;
    case 'D':
      acento = 3;
      break;
    case 'E':
      acento = 4;
      break;
    case 'F':
      acento = 5;
      break;
    default:
      printf("\nPoltrona invalida");
    }

    reserva[fileira - 1][acento] = 'x';
    printf("\n\t\t[A] [B] [C]\t[D] [E] [F]\n");
    for (int x = 0; x < 10; x++) {
      if (x != 9)
        printf("\n\t0%d\t", x + 1);
      else
        printf("\n\t%d\t", x + 1);

      for (int y = 0; y < 6; y++) {
        printf("[%c] ", reserva[x][y]);
        if (y == 2) {
          printf("\t");
        }
      }
    }
    printf("\n");
  }
  return 0;
}
