/*Nome: Rafael da Silva de Freitas
  Matrícula: 20201917*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STRING_LENGTH 20000

int x = 0, y = 0;

char right(char current_position) {
  switch (current_position) {
    case 'N':
      current_position = 'L';
      break;
    case 'L':
      current_position = 'S';
      break;
    case 'S':
      current_position = 'O';
      break;
    case 'O':
      current_position = 'N';
      break;
  }
  return current_position;
}

char left(char current_position) {
  switch (current_position) {
    case 'N':
      current_position = 'O';
      break;
    case 'L':
      current_position = 'N';
      break;
    case 'S':
      current_position = 'L';
      break;
    case 'O':
      current_position = 'S';
      break;
  }
  return current_position;
}

void front(char current_position, int *positions) {
  if (current_position == 'N') {
    y++;
    positions[1] = y;
  } else if (current_position == 'S') {
    y--;
    positions[1] = y;
  } else if (current_position == 'L') {
    x++;
    positions[0] = x;
  } else if (current_position == 'O') {
    x--;
    positions[0] = x;
  }
}

void back(char current_position, int *positions) {
  if (current_position == 'N') {
    y--;
    positions[1] = y;
  } else if (current_position == 'S') {
    y++;
    positions[1] = y;
  } else if (current_position == 'L') {
    x--;
    positions[0] = x;
  } else if (current_position == 'O') {
    x++;
    positions[0] = x;
  }
}

bool judgeCircle(int *positions) {
  return (positions[0] == 0) && (positions[1] == 0);
}

int main() {
  int positions[2] = {x, y};
  char *moves = (char *)malloc(sizeof(char) * MAX_STRING_LENGTH);
  char current_position = 'N';

  if (moves == NULL) {
    printf("Erro: não foi possível alocar memória para a string.\n");
    exit(1);
  }

  printf("Digite os movimentos: ");
  gets(moves);

  for (size_t i = 0; i < strlen(moves); i++) {
    switch (moves[i]) {
      case 'R':
        current_position = right(current_position);
        break;
      case 'L':
        current_position = left(current_position);
        break;
      case 'F':
        front(current_position, positions);
        break;
      case 'B':
        back(current_position, positions);
        break;
      default:
        printf("Letra incorreta!");
        exit(1);
        break;
    }
  }

  printf("(%d, %d)\n", positions[0], positions[1]);

  if (judgeCircle(positions)) {
    printf("true\n");
  } else {
    printf("false\n");
  }

  free(moves);
  return 0;
}
