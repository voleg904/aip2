#include <iostream>
#include <new>

void output(const int *const *mtx, int r, int c){
  for (size_t i = 0; i < r; ++i){
    for (size_t j = 0; j < c; ++j){
      std::cout << mtx[i][j] << ' ';
    }
    std::cout << '\n';
  }
}
void input(int *arr, int l){
  for (size_t i = 0; i < l; ++i){
    std::cin >> arr[i];
  }
}
int ** convert(const int * t, size_t n, const size_t * lns, size_t rows);


int main(){
  int n = 0,rows = 0;
  int **result = nullptr;
  std::cin >> n >> rows;
  if (std::cin.fail()){
    return 1;
  }
  int *rowl = nullptr;
  int *arr = nullptr;
  try{
    rowl = new int[n];
    arr = new int[rows]; 
  }
  catch (const std::bad_alloc &){
    delete rowl;
    delete arr;
    return 2;
  }
  input(rowl,n);
  input(arr,rows);
  if (std::cin.fail()){
    delete rowl;
    delete arr;
    return 1;
  }
}


