#include<iostream>
#include<math.h>
using namespace std;

struct term {
    int expo;
    int coeff;
};

class poly {
public:
    int last;
    struct term t[20];

    poly() {     //constructor
        last = 0;
    }

    void insert(int c, int e) {   // to insert terms of poly in an array
        struct term t1;
        t1.coeff = c;
        t1.expo = e;
        t[last] = t1;
        last++;
    }

    void showpoly() {
        for (int i = 0; i < last; i++) {
            int coef = t[i].coeff;
            int expo = t[i].expo;

            if (i == 0) {
                cout<<coef;
            } else {
                if (coef < 0) {
                    cout << " - " << abs(coef);
                } else {
                    cout << " + " << coef;
                }
            }

            if (expo != 0) {
                cout << "x^" << expo;
            }
        }
        cout << endl;


    }

    poly add(poly p2) {
        poly p3;
        int c, e;
        int x = 0, y = 0;

        while (x < last && y < p2.last) {
            if (t[x].expo == p2.t[y].expo) {
                c = t[x].coeff + p2.t[y].coeff;
                e = t[x].expo;
                p3.insert(c, e);
                x++;
                y++;
            } else if (t[x].expo > p2.t[y].expo) {
                c = t[x].coeff;
                e = t[x].expo;
                p3.insert(c, e);
                x++;
            } else {
                c = p2.t[y].coeff;
                e = p2.t[y].expo;
                p3.insert(c, e);
                y++;
            }
        }

        while (x < last) {
            c = t[x].coeff;
            e = t[x].expo;
            p3.insert(c, e);
            x++;
        }

        while (y < p2.last) {
            c = p2.t[y].coeff;
            e = p2.t[y].expo;
            p3.insert(c, e);
            y++;
        }

        return p3;
    }

    poly subtract(poly p2){
        int c, e;
        poly p3;
        int x=0, y=0;

        while(x < last && y < p2.last){
            if(t[x].expo == p2.t[y].expo){
                c = t[x].coeff - p2.t[y].coeff;
                e = t[x].expo;
                p3.insert(c,e);
                x++;
                y++;
            }
            else if(t[x].expo > p2.t[y].expo){
                c = t[x].coeff;
                e = t[x].expo;
                p3.insert(c,e);
                x++;
            }
            else{
                c = p2.t[y].coeff;
                e = p2.t[y].expo;
                p3.insert(c,e);
                y++;
            }
        }
        while(x < last){
            c = t[x].coeff;
            e = t[x].expo;
            p3.insert(c,e);
            x++; 
        }
        while(y < p2.last){
            c = p2.t[y].coeff;
            e = p2.t[y].expo;
            p3.insert(c,e);
            y++;
        }
        return p3;
    }

    int eval(poly p4){
        int a;
            cout<<"Enter the value of x: ";
            cin>>a;
            int evaluation =0;
            for(int i=0; i< p4.last; i++ ){
                if(p4.t[i].coeff != 0){
                    evaluation = (evaluation+ (p4.t[i].coeff * pow(a, p4.t[i].expo)));
                }
            }
            return evaluation;
    }
};

int main() {
    poly p1, p2, p3, p4;
    int c, e;
    int tot_elem;
    char uc;
    int n;
    do
    {
        cout<<"Press 1 to add two polynomails"<<endl;
        cout<<"Press 2 to subtract two polynomials"<<endl;
        cout<<"press 3 for Evaluation of a polynomial"<<endl;
        cin>>n;
        switch(n){
            case 1:
            cout << "Enter the total number of terms for poly1: ";
            cin >> tot_elem;
            for (int i = 0; i < tot_elem; i++) {
                cout << "Enter the coefficient and exponent for term " << i + 1 << ": ";
                cin >> c >> e;
                p1.insert(c, e);
            }
            cout<<"First polynomial look like: ";
            p1.showpoly();
            cout << "Enter the total number of terms for poly2: ";
            cin >> tot_elem;
            for (int i = 0; i < tot_elem; i++) {
                cout << "Enter the coefficient and exponent for term " << i + 1 << ": ";
                cin >> c >> e;
                p2.insert(c, e);
            }
            cout<<"Second polynomial look like: ";
            p2.showpoly();

            p3 = p1.add(p2);

            cout <<"\nResultant polynomial after addition: ";
            p3.showpoly();
            break;

            case 2:
            cout << "Enter the total number of terms for poly1: ";
            cin >> tot_elem;
            for (int i = 0; i < tot_elem; i++) {
                cout << "Enter the coefficient and exponent for term " << i + 1 << ": ";
                cin >> c >> e;
                p1.insert(c, e);
            }
            cout<<"First polynomial look like: ";
            p1.showpoly();
            cout <<"Enter the total number of terms for poly2: ";
            cin >> tot_elem;
            for (int i = 0; i < tot_elem; i++) {
                cout << "Enter the coefficient and exponent for term " << i + 1 << ": ";
                cin >> c >> e;
                p2.insert(c, e);
            }
            cout<<"Second polynomial look like: ";
            p2.showpoly();

            p3 = p1.subtract(p2);
            cout <<"\nResultant polynomial after subtraction : ";
            p3.showpoly();
            break;

            case 3:
            int a,res;
            cout << "Enter the total number of terms for poly to be evaluated: ";
            cin >> tot_elem;
            for (int i = 0; i < tot_elem; i++) {
                cout << "Enter the coefficient and exponent for term  "<< i + 1 << " : ";
                cin >> c >> e;
                p4.insert(c, e);
            }
            cout<<"\nPolynomial is : ";
            p4.showpoly();
            res =p4.eval(p4);
            cout<<"\nResult after evaluation : "<<res;
            break;

            default: 
                cout<<"Invalid choice";
                exit(0);
        }
        cout<<"\nDo you want to continue..?('y' for Yes/ 'n' for No)\n";
        cin>>uc;

    }while(uc == 'y');
    return 0;
}

    

















