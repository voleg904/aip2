#include <iostream>
#include <new>

void output(const size_t *const *mtx, size_t n, const size_t * rows){
  for (size_t i = 0; i < n; ++i){
    for (size_t j = 0; j < rows[i]; ++j){
      std::cout << mtx[i][j] << ' ';
    }
    std::cout << '\n';
  }
}
void input(size_t *arr, size_t l){
  for (size_t i = 0; i < l; ++i){
    std::cin >> arr[i];
  }
}

size_t **make(size_t r,const size_t *lns){
  size_t **mtx = new size_t *[r];
  for (size_t i = 0; i<r; ++i){
    try{
      mtx[i] = new size_t[lns[i]];
    }
    catch (const std::bad_alloc &){
      for (size_t j = 0; j<i; ++j){
        delete[] mtx[j];
      }
      delete[] mtx;
    }
  }
  return mtx;
}

size_t ** convert(const size_t * t, size_t n, const size_t * lns, size_t rows){
  size_t **result = make(rows,t);
  int flag = 0;
  for (size_t i = 0;i<n;++i){
    for (size_t j = 0; j<t[i]; ++j){
      result[i][j] = lns[flag];
      flag++;
    }
  }
  return result;
}


int main(){
  int n = 0,rows = 0;
  size_t **result = nullptr;
  std::cin >> n >> rows;
  if (std::cin.fail()){
    return 1;
  }
  size_t *rowl = nullptr;
  size_t *arr = nullptr;
  try{
    rowl = new size_t[n];
    arr = new size_t[rows]; 
  }
  catch (const std::bad_alloc &){
    delete[] rowl;
    delete[] arr;
    return 2;
  }
  input(rowl,n);
  input(arr,rows);
  if (std::cin.fail()){
    delete[] rowl;
    delete[] arr;
    return 1;
  }
  result = convert(rowl,n,arr,rows);
  output(result,n,rowl);
}


