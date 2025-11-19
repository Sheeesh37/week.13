#include <iostream>
using namespace std;

//pr1
void setToHundred(int** p) {
**p=100;
}

//pr2
void swapRef(int& a, int& b) {
int temp=a;
a=b;
b=temp;
}

//pr3
int countValid(int* arr[], int size) {
    int count=0;
    int** p=arr;
    for (int i=0;i<size;++i) {
        if (*p!=NULL) ++count;
        ++p;
    }
    return count;
}

//pr4
void fixNeg(int* arr, int size) {
    int*p =arr;
    for (int i =0;i<size;i++) {
        if (*p<0) {
            *p=0;
            p++;
        }
    }
}

//pr5
int sum2D(int** m, int r, int c) {
    int sum=0;
    for (int i=0;i<r;i++) {
        int*row=*(m+i);
        for (int j=0;j<c;j++) {
            sum+=*(row+j);
        }
    }
    return sum;
}

//pr6
void printIfValid(int*p) {
    if (p==NULL) {
        cout<<"null"<<endl;
    } else {
        cout<<*p<<endl;
    }
}

//pr7
int* findMax(int* arr, int size) {
    int*p=arr;
    int*maxp=arr;
    for (int i=0;i<size;i++) {
        p++;
        if (*p>*maxp) {
            maxp=p;
        }
    }
    return maxp;
}

//pr8
void reverseArr(int**arr,int size) {
    int*base=*arr;
    int*left=base;
    int*right=base+size-1;
    while (left<right) {
        int tmp=*left;
        *left=*right;
        *right=tmp;
        left++;
        right--;
    }
}

//pr9
void avg(const double* arr,int size,double*result) {
    double s=0;
    const double*p=arr;
    for (int i=0;i<size;i++) {
        s+=*p;
        p++;
    }
    *result=s/size;
}

//pr10
void mergeSorted(const int*a,int n,const int*b,int m,int*out) {
    const int*pa=a;
    const int*pb=b;
    int*po=out;
    int i=0,j=0;
    while (i<n && j<m) {
        if (*pa<=*pb) {
            *po=*pa;
            pa++;
            i++;
        } else {
            *po=*pb;
            pb++;
            j++;
        }
        po++;
    }
    while (i<n) {
        *po=*pa;
        pa++;
        po++;
        i++;
    }
    while (j<m) {
        *po=*pb;
        pb++;
        po++;
        i++;
    }
}









int main() {
    //pr1
    int x;
    cin>>x;
    int* p=&x;
    setToHundred(&p);
    cout<<x<<endl;

    //pr2
    int a,b;
    cin>>a>>b;
    swapRef(a,b);
    cout<<a<<' '<<b<<endl;

    //pr3
    int size;
    cin>>size;
    int*arr[size];
    for (int i=0;i<size;i++) {
        int v;
        cin>>v;
        if (v==-1) arr[i]=NULL;
        else {
            arr[i]=new int(v);
        }
    }
    cout<<countValid(arr,size);
    for (int i=0;i<size;i++) {
        if (arr[i]) {
            delete arr[i];
        }
    }

    //pr4
    int n;
    cin>>n;
    int d[n];
    for (int i=0;i<n;i++) {
        cin>>d[i];
        fixNeg(d,n);
    }
    for (int i=0;i<n;i++) {
        cout<<d[i]<<(i+1==n? "":" ");
    }

    //pr5
    int r,c;
    cin>>r>>c;
    int**mat=new int*[r];
    for (int i=0;i<r;i++) {
        mat[i]=new int[c];
        for (int j=0;j,c;j++) {
            cin>>mat[i][j];
        }
        cout<<sum2D(mat,r,c);
        for (int i=0;i<r;i++) delete[] mat[i];
        delete [] mat;
    }

    //pr6
    string s;
    cin>>s;
    if (s=="n") {
        printIfValid(NULL);
    } else {
        int val=stoi(s);
        printIfValid(&val);
    }

    //pr7
    int l;
    cin>>l;
    int e[l];
    for (int i=0;i<l;i++) cin>>e[l];
    int*mp=findMax(e,l);
    cout<<*mp;

    //pr8
    int h;
    cin>>h;
    int k[h];
    for (int i=0;i<h;i++) {
        cin>>k[h];
    }
    int*q=k;
    reverseArr(&q,h);
    for (int i=0;i<h;i++) {
        cout<<k[i]<<(i+1==n? "":" ");
    }

    //pr9
    int m;
    cin>>m;
    double f[m];
    for (int i=0;i<m;i++) cin>>f[i];
    double res;
    avg(f,m,&res);
    cout<<res;

    //pr10
    int g;
    cin>>g;
    int w[g];
    for (int i=0;i<g;i++) cin>>w[i];
    int y;
    cin>>y;
    int z[y];
    for (int i=0;i<y;i++) cin>>z[i];
    int out[g+y];
    mergeSorted(w,g,z,y,out);
    for (int i=0;i<g+y;i++) cout<<out[i]<<(i+1==g+y? "":" ");









    return 0;
}
