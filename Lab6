#include <stdio.h>
#include <stdlib.h>
#define MAX_ip 50
#pragma region interface
void ORIGINAL_INTERFACE() {
  printf(" ______________________________________\n");
  printf("|  ---Page Replacement Algorithm---   |\n");
  printf("|    1. Default referenced sequence   |\n");
  printf("|    2. Manual input sequence         |\n");
  printf("|_____________________________________|\n");
}

void FRAME_INSERT_INTERFACE() {
  printf(" _________________________________________\n");
  printf("|  -----Page Replacement Algorithm-----   |\n");
  printf("|  Input page frames:                     |\n");
  printf("|_________________________________________|\n");
}

void ALGORITHM_OPTIONS_INTERFACE() {
  printf(" _________________________________________\n");
  printf("|  -----Page Replacement Algorithm-----   |\n");
  printf("|          1.  FIFO algorithm             |\n");
  printf("|          2.  OPT algorithm              |\n");
  printf("|          3.  LRU algorithm              |\n");
  printf("|_________________________________________|\n");
}
#pragma endregion
void Copy_ARR(int defA[], int A[]) {
  int i;
  for (i = 0; i < 11; i++) A[i] = defA[i];
  A[i + 1] = '\0';
}

void INSERT_ARR(int A[], int n) {
  int i;
  for (i = 0; i < n; i++) {
    scanf("%d", &A[i]);
  }
  A[i] = '\0';
}

void FIFO(int A[], int NumOf_frames, int n) {
  printf(" _______________________________________________\n");
  printf("|     ---FIFO Page Replacement Algorithm---     |\n");
  printf("|                                               |\n");
  int i, j = 0, k, available = 0, count = 0, Arr_2[7][50];
  ///////////////////////////////////
  for (i = 0; i < n; i++) Arr_2[0][i] = A[i];
  for (i = 1; i <= NumOf_frames + 1; i++) {
    for (k = 0; k < n; k++) Arr_2[i][k] = -1;
  }
  Arr_2[1][0] = Arr_2[0][0];
  Arr_2[NumOf_frames + 1][0] = -2;
  ////////////////////////////////
  int ck = 0;
  for (i = 1; i < n; i++) {
    for (k = 1; k <= NumOf_frames; k++)
      if (Arr_2[k][i - 1] == Arr_2[0][i]) available = 1;
    for (k = 1; k <= NumOf_frames; k++) {
      Arr_2[k][i] = Arr_2[k][i - 1];
      if (Arr_2[k][i - 1] == -1 && available == 0) {
        Arr_2[k][i] = Arr_2[0][i];
        Arr_2[NumOf_frames + 1][i] = -2;
        count++;
        ck = 1;
        break;
      }
    }
    if (ck == 1) {
      ck = 0;
      continue;
    }
    if (available == 0) {
      count = count + 1;
      Arr_2[j + 1][i] = Arr_2[0][i];
      j = (j + 1) % NumOf_frames;
      Arr_2[NumOf_frames + 1][i] = -2;
    }
    available = 0;
  }
  ////////////////////////////////////
  for (i = 0; i <= NumOf_frames + 1; i++) {
    printf("|     ");
    for (k = 0; k < n; k++) {
      if (Arr_2[i][k] == -1)
        printf("   ");
      else if (Arr_2[i][k] == -2)
        printf("*  ");
      else
        printf("%d  ", Arr_2[i][k]);
    }
    printf("\n");
  }
  printf("|     Number of Page Fault: %d\n", count + 1);
  printf("|                                               |\n");
  printf("|_______________________________________________|\n");
}

void LRU(int A[], int NumOf_frames, int n) {
  printf(" _______________________________________________\n");
  printf("|     ---LRU Page Replacement Algorithm---     |\n");
  int i, k, available = 0, Arr_2[7][50];
  int a;
  int count = 0;
  ////////////////////////////////////
  for (i = 0; i < n; i++) Arr_2[0][i] = A[i];
  for (i = 1; i <= NumOf_frames + 1; i++) {
    for (k = 0; k < n; k++) Arr_2[i][k] = -1;
  }
  Arr_2[1][0] = Arr_2[0][0];
  Arr_2[NumOf_frames + 1][0] = -2;
  //////////////////////////////////
  int ck = 0;
  for (i = 1; i < n; i++) {
    for (k = 1; k <= NumOf_frames; k++)
      if (Arr_2[k][i - 1] == Arr_2[0][i]) available = 1;
    for (k = 1; k <= NumOf_frames; k++) {
      Arr_2[k][i] = Arr_2[k][i - 1];
      if (Arr_2[k][i - 1] == -1 && available == 0) {
        Arr_2[k][i] = Arr_2[0][i];
        Arr_2[NumOf_frames + 1][i] = -2;
        count++;
        ck = 1;
        break;
      }
    }
    if (ck == 1) {
      ck = 0;
      continue;
    }
    if (available == 0) {
      int imin1 = 100;
      int imin2 = 100;
      int _min1 = 100, _min2 = 100;
      for (k = 1; k <= NumOf_frames; k++) {
        for (a = i - 1; a >= 0; a--) {
          if (Arr_2[k][i - 1] == Arr_2[0][a]) {
            _min1 = a;
            imin1 = k;
            break;
          }
        }
        if (_min1 < _min2) {
          _min2 = _min1;
          imin2 = imin1;
        }
      }
      Arr_2[imin2][i] = Arr_2[0][i];
      Arr_2[NumOf_frames + 1][i] = -2;
      count++;
    }
    available = 0;
  }
  ////////////////////////////////////
  for (i = 0; i <= NumOf_frames + 1; i++) {
    printf("|     ");
    for (k = 0; k < n; k++) {
      if (Arr_2[i][k] == -1)
        printf("   ");
      else if (Arr_2[i][k] == -2)
        printf("*  ");
      else
        printf("%d  ", Arr_2[i][k]);
    }
    printf("\n");
  }
  printf("|     Number of Page Fault: %d\n", count + 1);
  printf("|________________________________________________\n");
}

void OPT(int A[], int NumOf_frames, int n) {
  printf(" _______________________________________________\n");
  printf("|     ---OPT Page Replacement Algorithm---     |\n");
  int i, k, available = 0, Arr_2[7][50];
  int a;
  int count = 0;
  ////////////////////////////////////
  for (i = 0; i < n; i++) Arr_2[0][i] = A[i];
  for (i = 1; i <= NumOf_frames + 1; i++) {
    for (k = 0; k < n; k++) Arr_2[i][k] = -1;
  }
  Arr_2[1][0] = Arr_2[0][0];
  Arr_2[NumOf_frames + 1][0] = -2;
  //////////////////////////////////
  int ck = 0;
  for (i = 1; i < n; i++) {
    for (k = 1; k <= NumOf_frames; k++)
      if (Arr_2[k][i - 1] == Arr_2[0][i]) available = 1;
    for (k = 1; k <= NumOf_frames; k++) {
      Arr_2[k][i] = Arr_2[k][i - 1];
      if (Arr_2[k][i - 1] == -1 && available == 0) {
        Arr_2[k][i] = Arr_2[0][i];
        Arr_2[NumOf_frames + 1][i] = -2;
        count++;
        ck = 1;
        break;
      }
    }
    if (ck == 1) {
      ck = 0;
      continue;
    }
    if (available == 0) {
      int imax1 = -1;
      int imax2 = -1;
      int _max1 = -1, _max2 = -1;
      for (k = 1; k <= NumOf_frames; k++) {
        for (a = i + 1; a < n; a++) {
          if (Arr_2[k][i - 1] == Arr_2[0][a]) {
            _max1 = a;
            imax1 = k;
            break;
          }
        }
        if (a == n) {
          _max1 = n;
          imax1 = k;
        }
        if (_max1 > _max2) {
          _max2 = _max1;
          imax2 = imax1;
        }
      }
      Arr_2[imax2][i] = Arr_2[0][i];
      Arr_2[NumOf_frames + 1][i] = -2;
      count++;
    }
    available = 0;
  }
  ////////////////////////////////////
  for (i = 0; i <= NumOf_frames + 1; i++) {
    printf("|     ");
    for (k = 0; k < n; k++) {
      if (Arr_2[i][k] == -1)
        printf("   ");
      else if (Arr_2[i][k] == -2)
        printf("*  ");
      else
        printf("%d  ", Arr_2[i][k]);
    }
    printf("\n");
  }
  printf("|     Number of Page Fault: %d\n", count + 1);
  printf("|________________________________________________\n");
}

int main() {
  int default_A[] = {1, 9, 5, 2, 2, 3, 7, 1, 0, 0, 7};
  int A[MAX_ip];
  int NumOf_frames;
  int n;
  int choice;
  ////////////////////////////////
  ORIGINAL_INTERFACE();
  do {
    printf("Menu: ");
    scanf("%d", &choice);
  } while (choice != 1 && choice != 2);
  //////////////////////////////////
  if (choice == 2) {
    printf("  ---Manual input sequence---   \n");
    printf("Enter element number: ");
    scanf("%d", &n);
    printf("Enter string: ");
    INSERT_ARR(A, n);
  } else {
    Copy_ARR(default_A, A);
    n = 11;
  }
  //////////////////////////////
  FRAME_INSERT_INTERFACE();
  printf("Input page frames: ");
  scanf("%d", &NumOf_frames);
  system("cls");
  //////////////////////////////
  ALGORITHM_OPTIONS_INTERFACE();
  int choice2;
  do {
    printf("Ban chon: ");
    scanf("%d", &choice2);
  } while (choice2 < 1 && choice2 > 3);

  switch (choice2) {
    case 1:
      FIFO(A, NumOf_frames, n);
      break;
    case 2:
      OPT(A, NumOf_frames, n);
      break;
    case 3:
      LRU(A, NumOf_frames, n);
      break;
  }
  ////////////////////////////////
  return 0;
}
