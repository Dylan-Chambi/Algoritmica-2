#include <bits/stdc++.h>
#define input freopen("in.txt" "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;


void print(int sudoku[9][9])
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++){
			cout << "[" <<sudoku[i][j] << "] ";
            if((j+1)%3 == 0 && j+1 != 9){
                cout << "| ";
            }
        }
		cout << endl;
        if((i+1)%3 == 0 && i+1 != 9){
            cout << "---------------------------------------" << endl;
        }
	}
}

bool verificarSudoku(int sudoku[9][9], int fila, int columna, int numero)
{
    // Verifica si encontramos el numero en la misma fila
	for (int x = 0; x <= 8; x++){
		if (sudoku[fila][x] == numero){
			return false;
        }
    }

	// Verifica si encontramos el numero en la misma columna
	for (int x = 0; x <= 8; x++)
		if (sudoku[x][columna] == numero)
			return false;

	// Verifica si encontramos el mismo numero en el cuadrado del sudoku
	int filaInicio = fila - fila % 3;
    int	columnaInicio = columna - columna % 3;
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			if (sudoku[i + filaInicio][j + columnaInicio] == numero){
				return false;
            }
        }
    }
	return true;
}
bool solveSuduko(int sudoku[9][9], int fila, int columna)
{
	if (fila == 9 - 1 && columna == 9){
		return true;
    }
	if (columna == 9) {
		fila++;
		columna = 0;
	}
	if (sudoku[fila][columna] > 0)
		return solveSuduko(sudoku, fila, columna + 1);

	for (int num = 1; num <= 9; num++)
	{
		if (verificarSudoku(sudoku, fila, columna, num))
		{
			sudoku[fila][columna] = num;
			if (solveSuduko(sudoku, fila, columna + 1))
				return true;
		}
		sudoku[fila][columna] = 0;
	}
	return false;
}

int main()
{
	int sudoku[9][9];
    for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			cin >> sudoku[i][j];
	}
    cout << endl;
	if (solveSuduko(sudoku, 0, 0))
		print(sudoku);
	else
		cout << "no solution exists " << endl;

	return 0;
}
/*

3 0 6 5 0 8 4 0 0
5 2 0 0 0 0 0 0 0
0 8 7 0 0 0 0 3 1
0 0 3 0 1 0 0 8 0
9 0 0 8 6 3 0 0 5
0 5 0 0 9 0 6 0 0
1 3 0 0 0 0 2 5 0
0 0 0 0 0 0 0 7 4
0 0 5 2 0 6 3 0 0

*/
