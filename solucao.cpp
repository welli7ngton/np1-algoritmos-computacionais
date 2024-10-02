#include <iostream>

char reserva[10][6] = {
  {' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' '},
  {' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' '},
  {' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' '},
  {' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' '},
  {' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' '}};

void mostra_assentos(){
  printf("\n\t\t[A] [B] [C]\t[D] [E] [F]\n");
  for (int x = 0; x < 10; x++) {
    if (x != 9)
      printf("\n\t0%d\t", x + 1);
    else
      printf("\n\t%d\t", x + 1);

    for (int y = 0; y < 6; y++) {
      printf("[%c]", reserva[x][y]);
      if (y == 2) {
        printf("|\t|");
      }
    }
  }
}

bool faz_reserva(int categoria, int fileira, int assento){
  if (categoria == 1 && (assento == 0 || assento == 5)) {
    printf("\nNão é possível reservar poltrona Executiva na classe Economica.");
    return false;
  }else if (reserva[fileira - 1][assento] == 'x') {
    printf("\nNão é possivel resevar, poltrona ja reservada.");
    return false;
  }
  printf("\nPoltrona reservada.");
  reserva[fileira - 1][assento] = 'x';
  mostra_assentos();
  return true;
}

int seleciona_categoria(){
  int categoria = 0;
  while (true) {
    printf("\nEscolha uma categoria [1] Economico || [2] Executiva: ");
    scanf("%d", &categoria);

    if (categoria == 1 || categoria == 2) {
      return categoria;
    }
    printf("\nCategoria invalida, selecione novamente.");
  }
}

int seleciona_assento(){

  int fileira = -1, assento = -1;
  char _assento = ' ';

  while (assento == -1 || fileira == -1) {
    printf("\nDigite a fileira (1-10): ");
    scanf("%d", &fileira);
    printf("\nDigite a assento [A|a][B|b][C|c][D|d][E|e][F|f][(Q|q)uit]: ");
    scanf(" %c", &_assento);

    switch (_assento) {
    case 'A':
    case 'a':
      assento = 0;
      break;
    case 'B':
    case 'b':
      assento = 1;
      break;
    case 'C':
    case 'c':
      assento = 2;
      break;
    case 'D':
    case 'd':
      assento = 3;
      break;
    case 'E':
    case 'e':
      assento = 4;
      break;
    case 'F':
    case 'f':
      assento = 5;
      break;
    case 'Q':
    case 'q':
      return 0;
    default:
      fileira = -1, assento = -1;
      printf("\nAssento invalido.");
    }
    int categoria = seleciona_categoria();
    if (faz_reserva(categoria, fileira, assento)){
      return 0;
   }
  }
  return 0;
}



int main(){
  while (true) {
    printf("\n==================================================\n");
    mostra_assentos();
    seleciona_assento(); 
    printf("\n==================================================\n");
    char res = ' ';
    printf("\nDeseja continuar a reserva? (S/n): ");
    scanf(" %c", &res);
    if (res == 'N' || res == 'n') {
      printf("\nPrograma Encerrado.");
      break;
    }
    printf("\n==================================================\n");
  }
  return 0;
}
