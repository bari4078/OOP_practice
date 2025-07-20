#include <bits/stdc++.h>
using namespace std;

class Matrix{
private:
    int row,cols;
    int **mat;
public:
    Matrix(){
        row=0;cols=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<cols;j++){
                mat[i] = new int[cols];
            }
        }
    }
    Matrix(int r,int c){
        row=r;cols=c;
        mat = new int*[row];
        for(int i=0;i<row;i++){
            for(int j=0;j<cols;j++){
                mat[i] = new int[cols];
            }
        }
    }
    ~Matrix(){
        for(int i=0;i<row;i++){
            delete[] mat[i];
        }
        delete[] mat;
    }

    void set(int r,int c,int val){
        mat[r][c] = val;
    }
    int get(int r,int c){
        return mat[r][c];
    }
    void add(int n){
        for(int i=0;i<row;i++){
            for(int j=0;j<cols;j++){
                mat[i][j] += n;
            }
        }
    }
    int add(){
        int out=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<cols;j++){
                out += mat[i][j];
            }
        }
        return out;
    }
    void print(){
        for(int i=0;i<row;i++){
            for(int j=0;j<cols;j++){
                cout<< mat[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};

int main()
{
    srand(time(NULL));
cout<<"Hello World"<<'\n';
Matrix m(3,3);
for(int i=0; i<3; i++)
for(int j=0; j<3; j++)
m.set(i,j,i+j);
m.print();
cout<<m.get(0,0)<<'\n';
m.set(0,0,100);
cout<<m.get(0,0)<<'\n';
m.add(100);
m.print();
cout<<m.add()<<'\n';
int i=rand()%1000+1;
cout<<"random num: "<<i<<endl;
return 0;
}