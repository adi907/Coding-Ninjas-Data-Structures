Implement a polynomial class, with following properties and functions.
Properties :
1. An integer (lets say A) which holds the coefficient and degrees. Use array indices as degree and A[i] as coefficient of ith degree.
2. An integer holding total size of array A.
Functions :
1. Default constructor
2. Copy constructor
3. setCoefficient -
This function sets coefficient for a particular degree value. If the given degree is greater than the current capacity of polynomial, increase the capacity accordingly and add then set the required coefficient. If the degree is within limits, then previous coefficient value is replaced by given coefficient value
4. Overload "+" operator (P3 = P1 + P2) :
Adds two polynomials and returns a new polynomial which has result.
5. Overload "-" operator (P3 = p1 - p2) :
Subtracts two polynomials and returns a new polynomial which has result
6. Overload * operator (P3 = P1 * P2) :
Multiplies two polynomials and returns a new polynomial which has result
7. Overload "=" operator (Copy assignment operator) -
Assigns all values of one polynomial to other.
8. print() -
Prints all the terms (only terms with non zero coefficients are to be printed) in increasing order of degree.
Print pattern for a single term : <coefficient>"x"<degree>
And multiple terms should be printed separated by space. And after printing one polynomial, print new line. For more clarity, refer sample test cases
Input Format :
Line 1 : N, total number of terms in polynomial P1
Line 2 : N integers representing degree of P1 (separated by space)
Line 3 : N integers representing coefficients of P1 (separated by space)
Line 4 : M, total number of terms in polynomial P2
Line 5 : M integers representing degree of P2 (separated by space)
Line 6 : M integers representing coefficients of P2 (separated by space)
Line 7 : Integer C, choice representing the function to be called (See main for more details)
Sample Input 1 :
3
1 3 5
1 2 -4
4
0 1 2 3
4 2 -3 1
1
Sample Output 1 :
4x0 3x1 -3x2 3x3 -4x5

```cpp
 #include<bits/stdc++.h>
 using namespace std;

#define MAX 5

class Polynomial {
	public:
        int *degCoeff;
        int capacity;
        Polynomial(){
            degCoeff=new int[MAX];
            capacity=MAX;
            for(int i=0;i<capacity;i++){
                degCoeff[i]=0;
            }
        }

        Polynomial(Polynomial const &P){
            this->degCoeff=new int[P.capacity];
            for(int i=0;i<P.capacity;i++){
                this->degCoeff[i]=P.degCoeff[i];
            }
            this->capacity=P.capacity;
        }

        void operator=(Polynomial const &P){
            this->degCoeff=new int[P.capacity];
            for(int i=0;i<P.capacity;i++){
                this->degCoeff[i]=P.degCoeff[i];
            }
            this->capacity=P.capacity;
        }

        void setCoefficient(int degree,int coeff){
            if(this->capacity<=degree){
                int* newdegCoeff=new int[degree+1];
                for(int i=0;i<degree+1;i++){
                    newdegCoeff[i]=0;
                }
                for(int i=0;i<capacity;i++){
                    newdegCoeff[i]=degCoeff[i];
                }
                delete[] degCoeff;
                degCoeff=newdegCoeff;
                capacity=degree+1;
            }
            degCoeff[degree]=coeff;
        }

        void print() const{
            for(int i=0;i<(this->capacity);i++){
                if(this->degCoeff[i]!=0){
                    cout<<this->degCoeff[i]<<"x"<<i<<" ";
                }
            }cout<<endl;
        }

        Polynomial operator+(Polynomial const &P){
            Polynomial Pnew;
            int limits=max(this->capacity,P.capacity);
            for(int i=0;i<limits;i++){
                Pnew.setCoefficient(i,this->degCoeff[i]+P.degCoeff[i]);
            }
            return Pnew;
        }

        Polynomial operator-(Polynomial const &P){
            Polynomial Pnew;
            int limits=max(this->capacity,P.capacity);
            for(int i=0;i<limits;i++){
                Pnew.setCoefficient(i,this->degCoeff[i]-P.degCoeff[i]);
            }
            return Pnew;
        }

        Polynomial operator*(Polynomial const &P){
            int degMax=this->capacity+P.capacity;
            int* newdegCoeff=new int[degMax+1];
            for(int i=0;i<=degMax;i++){
                newdegCoeff[i]=0;
            }
            Polynomial Pnew;
            delete[] Pnew.degCoeff;
            Pnew.degCoeff=newdegCoeff;
            for(int i=0;i<(this->capacity);i++){
                for(int j=0;j<(P.capacity);j++){
                    Pnew.degCoeff[i+j]+=(this->degCoeff[i])*(P.degCoeff[j]);
                }
            }
            return Pnew;
        }
};

 
int main(){
    int count1,count2,choice;
    cin >> count1;
    
    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];
    
    for(int i=0;i < count1; i++) {
        cin >> degree1[i];
    }
    
    for(int i=0;i < count1; i++) {
        cin >> coeff1[i];
    }
    
    Polynomial first;
    for(int i = 0; i < count1; i++){
        first.setCoefficient(degree1[i],coeff1[i]);
    }
    
    cin >> count2;
    
    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];
    
    for(int i=0;i < count2; i++) {
        cin >> degree2[i];
    }
    
    for(int i=0;i < count2; i++) {
        cin >> coeff2[i];
    }
    
    Polynomial second;
    for(int i = 0; i < count2; i++){
        second.setCoefficient(degree2[i],coeff2[i]);
    }
    
    cin >> choice;
    
    Polynomial result;
    switch(choice){
            // Add
        case 1:
            result = first + second;
            result.print();
            break;
            // Subtract
        case 2 :
            result = first - second;
            result.print();
            break;
            // Multiply
        case 3 :
            result = first * second;
            result.print();
            break;
            
        case 4 : // Copy constructor
        {
            Polynomial third(first);
            if(third.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
        case 5 : // Copy assignment operator
        {
            Polynomial fourth(first);
            if(fourth.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
    }
    
    return 0;
}
```
