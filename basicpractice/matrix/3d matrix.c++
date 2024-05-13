#include <iostream>
using namespace std;
const int rows = 3;
const int cols = 3;
void input(int mat1[rows][cols]) {
 cout << "Enter elements of the matrix:" 
<< endl;
 for (int i = 0; i < rows; ++i) {
 for (int j = 0; j < cols; ++j) {
 cout << "Enter element at (" << i 
<< ", " << j << "): ";
 cin >> mat1[i][j];
 } }}
void display(int mat[rows][cols]) {
 cout << "Matrix:" << endl;
 for (int i = 0; i < rows; ++i) {
 for (int j = 0; j < cols; ++j) {
 cout << mat[i][j] << " ";
 }
 cout << endl;
 }}
void add(int matA[rows][cols], int matB[rows][cols], int 
res[rows][cols]) {
 for (int i = 0; i < rows; ++i) {
 for (int j = 0; j < cols; ++j) {
 res[i][j] = matA[i][j] + matB[i][j];
 } }}
void multiply(int matA[rows][cols], int matB[rows][cols], int 
res[rows][cols]) {
 for (int i = 0; i < rows; ++i) {
 for (int j = 0; j < cols; ++j) {
 res[i][j] = 0;
 for (int k = 0; k < cols; ++k) {
 res[i][j] += matA[i][k] * matB[k][j];
 } } }}
void transpose(int mat[rows][cols], int trans[rows][cols]) {
 for (int i = 0; i < rows; ++i) {
 for (int j = 0; j < cols; ++j) {
 trans[j][i] = mat[i][j];
 } }}
int main() {
cout<<"suraj singh\n";
cout<<"23pcs5219\n";
 int matrix1[rows][cols];
 int matrix2[rows][cols];
 int result[rows][cols];
 cout << "Matrix 1:" << endl;
 input(matrix1);
 cout << "Matrix 2:" << endl;
 input(matrix2);
 add(matrix1, matrix2, result);
 cout << "\nAddition Result:" << endl;
 display(result);
 multiply(matrix1, matrix2, result);
 cout << "\nMultiplication Result:" << endl;
 display(result);
 int transposeResult[rows][cols];
 transpose(matrix1, transposeResult);
 cout << "\nTranspose of Matrix 1:" << endl;
 display(transposeResult);
 return 0;}