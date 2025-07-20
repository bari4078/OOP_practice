#include <iostream>
#include <cmath>
using namespace std;

class Fraction{
private:
    int numerator;
    int denominator;
public:
    void round(){
        //NULL_check
        if(denominator == 0){
            throw "Denominator is 0";
        }
        int a=abs(denominator),b=abs(numerator);
        while(b != 0){
            int temp = b;
            b = a%b;
            a = temp;
        }
        
        if(a!=0){
        this->numerator=numerator/a;
        this->denominator = denominator/a;
        }
        if(denominator < 0){
            numerator = -numerator;
            denominator = -denominator;
        }
    }
    
    //constructors
    Fraction(){
        numerator=0;
        denominator=1;
    }
    Fraction(int x){
        numerator=x;
        denominator=1;
    }
    Fraction(int x,int y){
        numerator=x;
        if(y==0){
            //NULL_check
            if(denominator == 0){
                throw "Denominator is 0";
            }
        }
        denominator=y;
        round();
    }
    Fraction(const Fraction &o){
        numerator=o.numerator;
        //NULL_check
        if(o.denominator == 0){
            throw "Denominator is 0";
        }
        denominator = o.denominator;
    }
    Fraction(float f){
        int err = 10e6;
        numerator = err*f;
        denominator = err;
        round();
    }
    //destructor
    ~Fraction(){}


    //getter
    int getNumerator(){
        return numerator;
    }
    int getDenominator(){
        return denominator;
    }

    //setters
    void setNumerator(int n){
        this->numerator = n;
    }
    void setDenominator(int n){
        this->denominator = n;
    }
    //show
    void show(){
        cout<<numerator<<"/"<<denominator<<endl;
    }

    //Addition
    //fraction + fraction
    Fraction operator+(const Fraction &o)const{
        Fraction result;
        result.numerator = denominator*o.numerator + this->numerator*o.denominator;
        result.denominator = denominator*o.denominator;
        result.round();
        return result;
    } 
    //fraction + float
    Fraction operator+(const float f) const{
        Fraction other(f);
        return *this + other;
    }
    //float + fraction
    friend Fraction operator+(float f,const Fraction &t){
        Fraction other(f);
        return other+t;
    }


    //subtraction
    //fraction - fraction
    Fraction operator-(const Fraction &f)const{
        Fraction result;
        result.numerator=numerator*f.denominator-f.numerator*this->denominator;
        result.denominator = denominator*f.denominator;
        result.round();
        return result;
    }
    //fraction - float
    Fraction operator-(const float f)const{
        Fraction other(f);
        return *this - other;
    }
    //float - fraction
    friend Fraction operator-(float f,const Fraction &t){
        Fraction other(f);
        return other-t;
    }

    //multiply
    //fraction*fraction
    Fraction operator*(const Fraction f)const{
        Fraction result;
        result.numerator=numerator*f.numerator;
        result.denominator=denominator*f.denominator;
        result.round();
        return result;
    }
    //fraction*float
    Fraction operator*(const float f)const{
        Fraction other(f);
        return *this*other;
    }
    //float * fraction
    friend Fraction operator*(float f, Fraction t){
        Fraction other(f);
        Fraction result = other*t;
        result.round();
        return result;
    }

    //division
    //fraction/fraction
    Fraction operator/(const Fraction &f)const{
        Fraction result;
        result.numerator=numerator*f.denominator;
        int n=f.numerator;

        if(n != 0)
            result.denominator=denominator*n;
        else{
            result.setDenominator(this->denominator);
            throw "Cannot divide by 0";
            
        }
        result.round();
        return result;
    }
    //fraction/float;
    Fraction operator/(float f)const{
        Fraction other(f);
        return *this/f;
    }
    //float/fraction
    friend Fraction operator/(float f,const Fraction &t){
        Fraction other(f);
        Fraction result = other/t;
        result.round();
        return result;
    }

    //+=
    //fraction += fraction
    Fraction operator+=(const Fraction &t)const{
        Fraction result;
        result = *this + t;
        result.round();
        return result;
    }
    //fraction += float
    Fraction operator +=(float f)const{
        Fraction other(f);
        Fraction result = *this + other;
        result.round();
        return result;
    }
    
    //-=
    //fraction -= fraction
    Fraction operator-=(const Fraction &t)const{
        Fraction result;
        result = *this - t;
        result.round();
        return result;
    }
    //fraction -=float
    Fraction operator-=(float f){
        Fraction other(f);
        Fraction result = *this - other;
        result.round();
        return result;
    }

    //*=
    //fractio *= fraction
    Fraction operator*=(const Fraction &t)const{
        Fraction result;
        result = *this * t;
        result.round();
        return result;
    }
    //fraction *= float
    Fraction operator*=(float f){
        Fraction other(f);
        Fraction result = *this * other;
        result.round();
        return result;
    }

    // /=
    //fraction /= fraction
    Fraction operator/=(const Fraction &t)const{
        Fraction result;
        result = *this / t;
        result.round();
        return result;
    }
    //fraction /= float
    Fraction operator/=(float f){
        Fraction other(f);
        Fraction result = *this / other;
        result.round();
        return result;
    }

    // << to show
    friend ostream& operator<<(ostream &out, const Fraction &f) {
        int n = f.numerator, d = f.denominator;
        if (d == 1){
            out << n;
        }
        else{
            if(n<0) out<<"-";
            out << n << '/' << d;
        }
        return out;
    }
};

class FractionVector{
private:
    Fraction *fractions;
    int max_size;
    int curr_size;
public:
    //constructors
    FractionVector(){
        max_size = 10;
        curr_size=0;
        fractions=new Fraction[max_size];
    }

    FractionVector(int size){
        max_size = size;
        curr_size=0;
        fractions = new Fraction[max_size];
    }
    //copy constructor
    FractionVector(const FractionVector &f){
        max_size = f.max_size;
        curr_size = f.curr_size;
        for(int i=0;i<curr_size;i++){
            this->fractions[i] = f.fractions[i];
        }
    }

    FractionVector operator = (const FractionVector &f){
        delete[] fractions;
        max_size = f.max_size;
        curr_size = f.curr_size;
        fractions = new Fraction[max_size];
        for(int i=0;i<curr_size;i++){
            this->fractions[i] = f.fractions[i];
        }
        return *this;
    }

    //destructor
    ~FractionVector() {}
    //set-get
    int getSize(){
        return curr_size;
    }
    
    //array sub 
    Fraction& operator[](int pos){
        if(pos >= curr_size){
            throw "Out of bound";
            //NULL_check
        }
        return fractions[pos];
    }

    const Fraction& operator[](int pos)const{
        if(pos >= curr_size){
            throw "Out of bound";
            //NULL_check
        }
        return fractions[pos];
    }
    //addition
    FractionVector operator+(const FractionVector &other)const{
        FractionVector result(max_size);
        if(this->curr_size != other.curr_size){
            throw "Invalid operation";
            //NULL_check
        }
        else{
            for(int i=0;i<curr_size;i++){
                result.fractions[result.curr_size++] = other.fractions[i] + fractions[i];
            }
        }
        return result;
    }
    //subtraction
    FractionVector operator-(const FractionVector &other)const{
        FractionVector result(max_size);
        if(this->curr_size != other.curr_size){
            throw "Invalid operation";
            //NULL_check
        }
        else{
            for(int i=0;i<curr_size;i++){
                result.fractions[result.curr_size++] = other.fractions[i] - fractions[i];
            }
        }
        return result;
    }

    //scalar multi
    //vector * fract
    FractionVector operator*(const Fraction k)const{
        FractionVector result(max_size);
        for(int i=0;i<curr_size;i++){
            result.fractions[result.curr_size++] = fractions[i]*k;
        }
        return result;
    }

    //fract * vect
    friend FractionVector operator*(const Fraction k, const FractionVector &t){
        return t*k;
    }

    //vector/ fract
    FractionVector operator/(const Fraction k)const{
        FractionVector result(max_size);
        for(int i=0;i<curr_size;i++){
            result.fractions[result.curr_size++] = fractions[i]/k;
        }
        return result;
        
    }

    //vector/float
    FractionVector operator/(const float f)const{
        Fraction k(f);
        return *this/k;
    }

    //dot product
    Fraction operator*(const FractionVector &other)const{
        Fraction result(0);
        if(curr_size != other.curr_size){
            throw "Invalid operation, order does not match";
            //NULL_check
            return result;
        }
        for(int i=0;i<curr_size;i++){
            result = result + (fractions[i] * other.fractions[i]);
        }
        return result;
    }

    float value(){
        float sum = 0;
        for(int i=0;i<curr_size;i++){
            float num = fractions[i].getNumerator();
            float den = fractions[i].getDenominator();
            sum += (num * num) / (den * den);
        }
        return sqrt(sum);
    }

    friend ostream& operator<<(ostream& out, const FractionVector &t){
        out<<"[";
        for(int i=0;i<t.curr_size;i++){
            out<<t.fractions[i]<<" ";
        }
        out<<"]";
        return out;
    }

    void push(Fraction item){
        if(curr_size >= max_size){
            throw "Vector already full";
        }
        else{
            fractions[curr_size++] = item;
        }
    }
};

class FractionMatrix{
private:
    FractionVector *rows;
    FractionVector *columns;
    int orderR,orderC;

public:
    FractionMatrix(int m, int n) {
        orderR = m;
        orderC = n;
        rows = new FractionVector[orderR];
        for (int i = 0; i < orderR; i++) {
            rows[i] = FractionVector(orderC);
            for (int j = 0; j < orderC; j++) {
                rows[i].push(Fraction(0));
            }
        }
    }
    
    FractionMatrix(){
        orderR=5;
        orderC=5;
        rows = new FractionVector[orderR];
        columns = new FractionVector[orderC];

        for (int i = 0; i < orderR; i++) {
            rows[i] = FractionVector(orderC);
        }
        for (int j = 0; j < orderC; j++) {
            columns[j] = FractionVector(orderR);
        }
    }
    //copy constructor
    FractionMatrix(const FractionMatrix &mat){
        orderR=mat.orderR;
        orderC=mat.orderC;

        rows = new FractionVector[orderR];
        columns = new FractionVector[orderC];
        for (int i = 0; i < orderR; i++) {
            rows[i] = FractionVector(orderR);
        }
        for(int i=0;i<orderR;i++){
            rows[i] = mat.rows[i];
        }

        for(int i=0;i<orderC;i++){
            columns[i] = mat.columns[i];
        }
    }

    //destructor
    ~FractionMatrix(){}

    void inputMat(){
        for(int i = 0; i < orderR; i++) {
            rows[i] = FractionVector(orderC);
        }
        for(int j = 0; j < orderC; j++) {
            columns[j] = FractionVector(orderR);
        }

        //filling up mat
        for(int i=0;i<orderR;i++){
            for(int j=0;j<orderC;j++){
                cout<<"Input numerator and denominator for position ("<<i<<","<<j<<"): ";
                int num, den;
                cin >> num >> den;
                if (den == 0) {
                    cout << "Denominator cannot be zero, input this again" << endl;
                    j--;
                    continue;
                }
                rows[i][j].setNumerator(num);
                rows[i][j].setDenominator(den);
            }
        }

        //copying everything into cols
        for(int j=0;j<orderC;j++){
            for(int i=0;i<orderR;i++){
                columns[j][i] = rows[i][j];
            }
        }
    }

    const FractionVector& operator[](int i)const{
        if (i >= orderR) {
            throw "Invalid index";
            //NULL_check
        }
        return rows[i];
    }

    FractionVector& operator[](int i){
        if (i >= orderR) {
            throw "Invalid index";
            //NULL_check
        }
        return rows[i];
    }

    FractionVector getColumn(int j)const{
        if(j >= orderC || j< 0){ 
            throw "Invalid order";
            //NULL_check
        }
        return columns[j];
    }

    //addition
    FractionMatrix operator+(const FractionMatrix &other)const{
        if(other.orderC != orderC || other.orderR != orderR){
            throw "Invalid order";
            //NULL_check
        }
        FractionMatrix result(orderR,orderC);

        for(int i=0;i<orderR;i++){
            for(int j=0;j<orderC;j++){
                result[i][j] = (*this)[i][j] + other[i][j];
            }
        }
        return result;
    }

    //subtraction
    FractionMatrix operator-(const FractionMatrix &other)const{
        if(other.orderC != orderC || other.orderR != orderR){
            throw "Invalid order";
            //NULL_check
        }
        FractionMatrix result(orderR,orderC);

        for(int i=0;i<orderR;i++){
            for(int j=0;j<orderC;j++){
                result[i][j] = rows[i][j] - other[i][j];
            }
        }
        return result;
    }

    //scalar multi
    FractionMatrix operator *(const Fraction f){
        FractionMatrix result(orderR,orderC);
        for(int i=0;i<orderR;i++){
            for(int j=0;j<orderC;j++){
                result[i][j] = (*this)[i][j] * f;
            }
        }
        return result;
    }

    const FractionMatrix operator *(const Fraction f)const{
        FractionMatrix result(orderR,orderC);
        for(int i=0;i<orderR;i++){
            for(int j=0;j<orderC;j++){
                result[i][j] = (*this)[i][j] * f;
            }
        }
        return result;
    }
    friend FractionMatrix operator *(const Fraction f,const FractionMatrix &mat){
        return mat * f;
    }

    //division
    FractionMatrix operator / (const Fraction f)const{
        FractionMatrix result(orderR,orderC);
        for(int i=0;i<orderR;i++){
            for(int j=0;j<orderC;j++){
                result[i][j] = (*this)[i][j]/f;
            }
        }
        return result;
    }

    FractionMatrix operator * (const FractionMatrix &other){
        if(orderC != other.orderR){
            throw "Invalid order";
            //NULL_check
        }
        FractionMatrix result(orderR,other.orderC);
        for(int i=0;i<orderR;i++){
            for(int j=0;j<other.orderC;j++){
                result[i][j]= Fraction(0);
                for(int k=0;k<orderC;k++){
                    result[i][j] = result[i][j] + ((*this)[i][k]*other[k][j]);
                }
            }
        }
        return result;
    }

    //hadamard
    FractionMatrix operator %(const FractionMatrix &other)const{
        if(other.orderC != orderC || other.orderR != orderR){
            throw "Invalid order";
            //NULL_check
        }
        FractionMatrix result(orderR,orderC);
        for(int i=0;i<orderR;i++){
            for(int j=0;j<orderC;j++){
                result[i][j] = (*this)[i][j]*other[i][j];
            }
        }
        return result;
    }


    FractionMatrix transpose(){
        FractionMatrix result(orderC,orderR);
        for(int i=0;i<orderR;i++){
            for(int j=0;j<orderC;j++){
                result[j][i] = (*this)[i][j];
            }
        }
        return result;
    }

    friend ostream& operator<<(ostream& out, const FractionMatrix &mat){
        
        for(int i=0;i<mat.orderR;i++){
            out<<mat[i]<<endl;
        }
        return out;
    }
};

//testing
int main() {
    //fraction test 
    cout << "\nFractions: " << endl;
    Fraction f1(3, 4);
    cout << "f1 = " << f1 << endl;
    Fraction f2(5, 6);
    cout << "f2 = " << f2 << endl;

    
    try {
        Fraction sumFract= f1 + f2;
        cout << "sum = f1 + f2 = " << sumFract << endl;
    }
    catch (const char* msg) {
        cout << "Error: " << msg << endl;
    }

    
    try {
        Fraction f4 = f2 - f1;
        cout << "Difference = f2 - f1 = " << f4 << endl;
    }
    catch (const char* msg) {
        cout << "Error: " << msg << endl;
    }
    
    try {
        Fraction f5 = f1 * f2;
        cout << "Product = f1 * f2 = " << f5 << endl;
    }
    catch (const char* msg) {
        cout << "Error: " << msg << endl;
    }

    
    try {
        Fraction f6 = f2 / f1;
        cout << "Division = f2 / f1 = " << f6 << endl;
    }
    catch (const char* msg) {
        cout << "Error: " << msg << endl;
    }  

    try {
        Fraction f7 = f1 + 2.5f;
        cout << "Sum_float = f1 + 2.5 = " << f7 << endl;
    }
    catch (const char* msg) {
        cout << "Error: " << msg << endl;
    }   

    try {
        Fraction f8 = 1.5f + f1;
        cout << "SumFloat = 1.5 + f1 = " << f8 << endl;
    }
    catch (const char* msg) {
        cout << "Error: " << msg << endl;
    }

    try {
        Fraction ProdFloat = 3.0f * f2;
        cout << "ProdFloat = 3.0 * f2 = " << ProdFloat << endl;
    }
    catch (const char* msg) {
        cout << "Error: " << msg << endl;
    }

    //fraction vector test
    cout << "\nFraction Vectors: " << endl;
    FractionVector v1(3), v2(3);
    
    try {
        v1.push(Fraction(1, 2));
    }
    catch (const char* msg) {
        cout << "Error: " << msg << endl;
    }
    
    try {
        v1.push(Fraction(2, 3));
    }
    catch (const char* msg) {
        cout << "Error: " << msg << endl;
    }
    
    try {
        v1.push(Fraction(3, 4));
    }
    catch (const char* msg) {
        cout << "Error: " << msg << endl;
    }
    cout << "v1 = " << v1 << endl;

    try {
    v2.push(Fraction(4, 5));    
    }
    catch (const char* msg) {
        cout << "Error: " << msg << endl;
    }
    
    try {
        v2.push(Fraction(5, 6));
    }
    catch (const char* msg) {
        cout << "Error: " << msg << endl;
    }
    
    try {
        v2.push(Fraction(6, 7));
    }
    catch (const char* msg) {
        cout << "Error: " << msg << endl;
    }
    cout << "v2 = " << v2 << endl;
    
    try {
        FractionVector v3 = v1 + v2;
        cout << "v3 = v1 + v2 = " << v3 << endl;
        
    }
    catch (const char* msg) {
        cout << "Error: " << msg << endl;
    }
    
    try {
        FractionVector v4 = v1 - v2;
        cout << "v4 = v1 - v2 = " << v4 << endl;
    }
    catch (const char* msg) {
        cout << "Error: " << msg << endl;
    }
    
    try {
        FractionVector v5 = v1 * Fraction(2);
        cout << "v5 = v1 * 2 = " << v5 << endl;
    }
    catch (const char* msg) {
        cout << "Error: " << msg << endl;
    }
    
    try {
        FractionVector v6 = Fraction(3) * v2;
        cout << "v6 = 3 * v2 = " << v6 << endl;
    }
    catch (const char* msg) {
        cout << "Error: " << msg << endl;
    }
    
    cout << "Dot = " << (v1 * v2) << endl;
    cout << "Mod, |V1| = " << v1.value() << endl;

    //fraction matrix test
    FractionMatrix m1(2, 2), m2(2, 2);
    
    m1[0][0] = Fraction(1, 2);
    m1[0][1] = Fraction(2, 3);
    m1[1][0] = Fraction(3, 4);
    m1[1][1] = Fraction(4, 5);

    m2[0][0] = Fraction(5, 6);
    m2[0][1] = Fraction(6, 7);
    m2[1][0] = Fraction(7, 8);
    m2[1][1] = Fraction(8, 9);

    FractionMatrix mat_sum = m1 + m2;
    FractionMatrix Subtracted = m2 - m1;
    FractionMatrix sum_with_fract = m1 * Fraction(2);
    FractionMatrix multiple = m1 * m2;
    FractionMatrix hamard = m1 % m2;
    FractionMatrix transposed = m1.transpose();

    cout << "\nFraction Matrices:" << endl;
    cout << "m1 =\n" << m1;
    cout << "m2 =\n" << m2;
    cout << "Matrix Sum = m1 + m2 =\n" << mat_sum;
    cout << "Subtraction = m2 - m1 =\n" << Subtracted;
    cout << "Sum with fraction = m1 * 2 =\n" << sum_with_fract;
    cout << "Multiple = m1 * m2 =\n" << multiple;
    cout << "Hadamard Product =\n" << hamard;
    cout << "Transposed M1 =\n" << transposed;

    return 0;
}
