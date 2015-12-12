/* 数独完全求解程序 Ver 3.0 */
/* coolypf */
/* 2008-11-24 22:11 */
#include <iostream>
using namespace std;
int matrix[9][9];  /*数独矩阵*/
int count = 0;     /*解的个数*/
int check(int x, int y, bool mark[10]) /*检测matrix[x][y]的取值范围*/
{
  int i, j, c = 0;
  for(i = 1; i <= 9; ++i)
  {
    mark[i] = true;
  }
  for(i = 0; i < 9; ++i)
  {
    mark[matrix[x][i]] = false;
  }
  for(i = 0; i < 9; ++i)
  {
    mark[matrix[i][y]] = false;
  }
  x = x / 3 * 3;
  y = y / 3 * 3;
  for(i = 0; i < 3; ++i)
  {
    for(j = 0; j < 3; ++j)
    {
      mark[matrix[x + i][y + j]] = false;
    }
  }
  for(i = 1; i <= 9; ++i)
  {
    if(mark[i]) ++c;
  }
  return c;
}
void display()  /*输出解*/
{
  int x, y;
  cout << "Solution " << count << ":\n";
  for(x = 0; x < 9; ++x)
  {
    for(y = 0; y < 9; ++y)
    {
      cout << matrix[x][y] <<' ';
    }
    cout << endl;
  }
}
void sudoku()  /*求解数独*/
{
  bool mark[10];  /*matrix中元素的取值范围*/
  int x, y, xm=-1, ym, min=10, c;
  for(x = 0 ; x < 9; ++x)  /*检测取值范围最小的空格*/
  {
    for(y = 0; y < 9; ++y)
    {
      if(matrix[x][y]) continue;  /*非空格则跳过*/
      c = check(x, y, mark);
      if(c == 0) return;  /*不可解*/
      if(c < min)
      {
        min = c;
        xm = x;
        ym = y;
      }
    }
  }
  if(xm == -1)  /*matrix填完*/
  {
    ++count;
    display();
    return;
  }
  check(xm, ym, mark);
  for(x=1; x <= 9; ++x)
  {
    if(mark[x])
    {
      matrix[xm][ym] = x;  /*尝试*/
      sudoku();  /*递归*/
    }
  }
  matrix[xm][ym]=0;  /*回溯*/
}
int main()
{
  int x, y;
  for(x=0;x <9; ++x)  /*输入数独*/
  {
    for(y=0; y<9; ++y)
    {
      cin >> matrix[x][y];
    }
  }
  sudoku();  /*求解数独*/
  cout << endl << count << " solution(s) in total.\n";
  return 0;
}
