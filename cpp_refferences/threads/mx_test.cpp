#include "matrix.h"


int main(){
    auto err = [](auto str){ std::cout << "Matrix.h error in: " << str << "\n"; std::exit(-1); };

    int n = 3;
    std::vector<double> v = {5.0,3.0,1.0,-1.0,-9.0,-11.0,-13.0,15.0,19.0};
    std::vector<double> u = {0.3,0.3,0.9,-0.11,-0.9,0.1,0.3,0.15,0.17};
    std::vector<double> v_1 = {3.0,5.0,7.0,9.0,11.0,12.0};
    std::vector<double> u_1 = {-1.0,5.0,0.0,0.7,9.0,1.0,-1.0,3.1,4.0,0.0,2.0,1.0};


    Matrix<double>  M(n,n,v);
    std::vector<double> zero ={0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};
    Matrix<double> N(n,n,zero);
    M=M*M;
    for(int i= 0; i<M.size();i++)
    {
        if(std::abs(N[i]-M[i])>0.00001){ std::cout<<"problem found"<<std::endl;exit(-1);}
        else{std::cout<<"the resoult is good"<<std::endl;}
    }



{
    Matrix<double>  M;
    if(M.size() != 0) {err("initializer list constructor test [size]");}
    if(M.begin() != M.end() )  { err("default contructor test [begin == end]");}
    if(M.cbegin() != M.cend()){ err("default contructor test [cbegin == cend]");}
}

{
    Matrix<double>  M(n,n,v);
    if(M.size() != 9) {err("initializer list constructor test [size]");}
    if(
        M(0,0) != 5.0 ||M(0,1)!=3.0||(M(0,2)!=1.0)
        ||(M(1,0)!=-1.0) ||M(1,1)!=-9.0||M(1,2)!=-11.0
        ||M(2,0)!=-13.0 ||M(2,1)!=15.0||M(2,2)!=19.0)
    { err("initializer list constructor test indexing");}
}


{
    Matrix<double>  M(n,n,v);
    Matrix<double>  N{M};
    if(N.size() != 9){ err("Coppy constructor test [size]");}
    if(
        N(0,0) != 5.0 ||N(0,1)!=3.0||N(0,2)!=1.0
        ||N(1,0)!=-1.0 ||N(1,1)!=-9.0||N(1,2)!=-11.0
        ||N(2,0)!=-13.0 ||N(2,1)!=15.0||N(2,2)!=19.0)
    { err("coppy constructor test indexing");}

    if(M.size() != 9) {err("Coppy constructor test [size]");}
    if(
        M(0,0) != 5.0 ||M(0,1)!=3.0||(M(0,2)!=1.0)
        ||(M(1,0)!=-1.0) ||M(1,1)!=-9.0||M(1,2)!=-11.0
        ||M(2,0)!=-13.0 ||M(2,1)!=15.0||M(2,2)!=19.0)
    { err("coppy constructor test indexing");}
}

{
    Matrix<double>  M(n,n,v);
    Matrix<double>  N{std::move(M)};
    if(M.size() !=0) { err("move constructor test [src size]");}
    if(M.begin() != M.end()){ err("move constructor test [src begin == src end]"); }
	if(N.size() != 9){ err("move constructor test [size]");}
    if(
        N(0,0) != 5.0 ||N(0,1)!=3.0||N(0,2)!=1.0
        ||N(1,0)!=-1.0 ||N(1,1)!=-9.0||N(1,2)!=-11.0
        ||N(2,0)!=-13.0 ||N(2,1)!=15.0||N(2,2)!=19.0)
        { err("move constructor test [elements]");}
}

{
    Matrix<double>  M(n,n,v);
    Matrix<double>  N;
    N = M;
    if(N.size() != 9){ err("assignment test  [size]");}
    if(
        N(0,0) != 5.0 ||N(0,1)!=3.0||N(0,2)!=1.0
        ||N(1,0)!=-1.0 ||N(1,1)!=-9.0||N(1,2)!=-11.0
        ||N(2,0)!=-13.0 ||N(2,1)!=15.0||N(2,2)!=19.0)
        { err("assignment test [elements]");}
      if(M.size() != 9) {err("assignment test [scr size]");}
        if(
        M(0,0) != 5.0 ||M(0,1)!=3.0||(M(0,2)!=1.0)
        ||(M(1,0)!=-1.0) ||M(1,1)!=-9.0||M(1,2)!=-11.0
        ||M(2,0)!=-13.0 ||M(2,1)!=15.0||M(2,2)!=19.0)
        { err("assignment test [scr elements]");}
}

{
    Matrix<double>  M(n,n,v);
    M=M;
    if(M.size() != 9) {err("self assignment test [ size]");}
        if(
        M(0,0) != 5.0 ||M(0,1)!=3.0||(M(0,2)!=1.0)
        ||(M(1,0)!=-1.0) ||M(1,1)!=-9.0||M(1,2)!=-11.0
        ||M(2,0)!=-13.0 ||M(2,1)!=15.0||M(2,2)!=19.0)
        { err("self assignment test [elements]");}
}

{
    Matrix<double>  M(n,n,v);
    Matrix<double>  N;
    N= std::move(M);
    if(M.size() !=0) { err("assignment test [src size]");}
    if(M.begin() != M.end()){ err("assignment test [src begin == src end]"); }
    if(N.size() != 9){ err("assignment test  [size]");}
    if(
        N(0,0) != 5.0 ||N(0,1)!=3.0||N(0,2)!=1.0
        ||N(1,0)!=-1.0 ||N(1,1)!=-9.0||N(1,2)!=-11.0
        ||N(2,0)!=-13.0 ||N(2,1)!=15.0||N(2,2)!=19.0)
        { err("assignment test [elements]");}
}

{
    Matrix<double>  M(n,n,v);
    M = std::move(M);
    if(M.size() != 0) 
    {
        if(M.size() != 9){
            err("self assignment test [ size]");
        }
    }
    if(M.size() != 0){
        if(
            M(0,0) != 5.0 ||M(0,1)!=3.0||(M(0,2)!=1.0)
            ||(M(1,0)!=-1.0) ||M(1,1)!=-9.0||M(1,2)!=-11.0
            ||M(2,0)!=-13.0 ||M(2,1)!=15.0||M(2,2)!=19.0)
            {
                err("self assignment test [elements]");
            }
    }
}

{
    Matrix<double>  M(n,n,v);
    Matrix<double>  N(n,n,u);
    std::vector<double> ref_1 = {5.3,3.3,1.9,-1.11,-9.9,-10.9,-12.7,15.15,19.17};
    Matrix<double> ref(n,n,ref_1);
    Matrix<double> res = M+N;
    if(M.size() != 9) {err("operator + (l-value, l-value) test [ size]");}
    if(
        M(0,0) != 5.0 ||M(0,1)!=3.0||(M(0,2)!=1.0)
        ||(M(1,0)!=-1.0) ||M(1,1)!=-9.0||M(1,2)!=-11.0
        ||M(2,0)!=-13.0 ||M(2,1)!=15.0||M(2,2)!=19.0)
        { err("operator + (l-value, l-value) test [elements]");}
    if(N.size() != 9) {err("operator + (l-value, l-value) test [ size]");}
    if(
        N(0,0) != 0.3 ||N(0,1)!=0.3||(N(0,2)!=0.9)
        ||(N(1,0)!=-0.11) ||N(1,1)!=-0.9||N(1,2)!=0.1
        ||N(2,0)!=0.3 ||N(2,1)!=0.15||N(2,2)!=0.17)
        { err("operator + (l-value, l-value) test [elements]");}
    if(res.size() != 9) {err("operator + (l-value, l-value) test [ size]");}
    if
    (
        std::abs(res(0,0)-ref(0,0)) >1e-15||std::abs(res(0,1)-ref(0,1)) >1e-15||std::abs(res(0,2)-ref(0,2)) >1e-15
        ||std::abs(res(1,0)-ref(1,0)) >1e-15||std::abs(res(1,1)-ref(1,1)) >1e-15||std::abs(res(1,2)-ref(1,2)) >1e-15
        ||std::abs(res(2,0)-ref(2,0)) >1e-15||std::abs(res(2,1)-ref(2,1)) >1e-15||std::abs(res(2,2)-ref(2,2)) >1e-15
    )   {err("operator + (l-value, l-value) test [ res]");}

}


{
    Matrix<double>  M(n,n,v);
    Matrix<double>  N(n,n,u);
    std::vector<double> ref_1 = {5.3,3.3,1.9,-1.11,-9.9,-10.9,-12.7,15.15,19.17};
    Matrix<double> ref(n,n,ref_1);
    Matrix<double> res = std::move(M)+N;
    if(M.size() !=0) { err("operator +(r-value, l-value)  test [move]");}
    if(N.size() != 9) {err("operator + (r-value, l-value) test [ size]");}
    if(
        N(0,0) != 0.3 ||N(0,1)!=0.3||(N(0,2)!=0.9)
        ||(N(1,0)!=-0.11) ||N(1,1)!=-0.9||N(1,2)!=0.1
        ||N(2,0)!=0.3 ||N(2,1)!=0.15||N(2,2)!=0.17)
        { err("operator + (r-value, l-value) test [elements N]");}
    if(res.size() != 9) {err("operator + (r-value, l-value) test [ size]");}
    if
    (
        std::abs(res(0,0)-ref(0,0)) >1e-15||std::abs(res(0,1)-ref(0,1)) >1e-15||std::abs(res(0,2)-ref(0,2)) >1e-15
        ||std::abs(res(1,0)-ref(1,0)) >1e-15||std::abs(res(1,1)-ref(1,1)) >1e-15||std::abs(res(1,2)-ref(1,2)) >1e-15
        ||std::abs(res(2,0)-ref(2,0)) >1e-15||std::abs(res(2,1)-ref(2,1)) >1e-15||std::abs(res(2,2)-ref(2,2)) >1e-15
    )   {err("operator + (r-value, l-value) test [ res]");}
}

{
    Matrix<double>  M(n,n,v);
    Matrix<double>  N(n,n,u);
    std::vector<double> ref_1 = {5.3,3.3,1.9,-1.11,-9.9,-10.9,-12.7,15.15,19.17};
    Matrix<double> ref(n,n,ref_1);
    Matrix<double> res = M + std::move(N);
    if(N.size() !=0) { err("operator +(l-value, r-value)  test [move]");}
    if(M.size() != 9) {err("operator + (l-value, r-value) test [ size]");}
    if(res.size() != 9) {err("operator + (l-value, r-value) test [ size]");}
    if
    (
        std::abs(res(0,0)-ref(0,0)) >1e-15||std::abs(res(0,1)-ref(0,1)) >1e-15||std::abs(res(0,2)-ref(0,2)) >1e-15
        ||std::abs(res(1,0)-ref(1,0)) >1e-15||std::abs(res(1,1)-ref(1,1)) >1e-15||std::abs(res(1,2)-ref(1,2)) >1e-15
        ||std::abs(res(2,0)-ref(2,0)) >1e-15||std::abs(res(2,1)-ref(2,1)) >1e-15||std::abs(res(2,2)-ref(2,2)) >1e-15
    )   {err("operator + (l-value, r-value) test [ res]");}
}

{
    Matrix<double>  M(n,n,v);
    Matrix<double>  N(n,n,u);
    std::vector<double> ref_1 = {5.3,3.3,1.9,-1.11,-9.9,-10.9,-12.7,15.15,19.17};
    Matrix<double> ref(n,n,ref_1);
    Matrix<double> res = std::move(M) + std::move(N);
    if(M.size() !=9) { err("operator +(r-value, r-value)  test [move]");}
    if(N.size() !=0) { err("operator +(r-value, r-value)  test [move]");}
    if(res.size() != 9) {err("operator + (r-value, r-value) test [ size]");}
    if
    (
        std::abs(res(0,0)-ref(0,0)) >1e-15||std::abs(res(0,1)-ref(0,1)) >1e-15||std::abs(res(0,2)-ref(0,2)) >1e-15
        ||std::abs(res(1,0)-ref(1,0)) >1e-15||std::abs(res(1,1)-ref(1,1)) >1e-15||std::abs(res(0,2)-ref(0,2)) >1e-15
        ||std::abs(res(2,0)-ref(2,0)) >1e-15||std::abs(res(2,1)-ref(2,1)) >1e-15||std::abs(res(2,2)-ref(2,2)) >1e-15
    )   {err("operator + (r-value, r-value) test [ res]");}
}

{
    Matrix<double>  M(n,n,v);
    Matrix<double>  N(n,n,u);
    std::vector<double> ref_1 = {4.7,2.7,0.1,-0.89,-8.1,-11.1,-13.3,14.85,18.83};
    Matrix<double> ref(n,n,ref_1);
    Matrix<double> res = M-N;
    if(M.size() != 9) {err("operator - (l-value, l-value) test [ size]");}
    if(
        M(0,0) != 5.0 ||M(0,1)!=3.0||(M(0,2)!=1.0)
        ||(M(1,0)!=-1.0) ||M(1,1)!=-9.0||M(1,2)!=-11.0
        ||M(2,0)!=-13.0 ||M(2,1)!=15.0||M(2,2)!=19.0)
        { err("operator - (l-value, l-value) test [elements]");}
    if(N.size() != 9) {err("operator - (l-value, l-value) test [ size]");}
    if(
        N(0,0) != 0.3 ||N(0,1)!=0.3||(N(0,2)!=0.9)
        ||(N(1,0)!=-0.11) ||N(1,1)!=-0.9||N(1,2)!=0.1
        ||N(2,0)!=0.3 ||N(2,1)!=0.15||N(2,2)!=0.17)
        { err("operator - (l-value, l-value) test [elements]");}
    if(res.size() != 9) {err("operator - (l-value, l-value) test [ size]");}
    if
    (
        std::abs(res(0,0)-ref(0,0)) >1e-15||std::abs(res(0,1)-ref(0,1)) >1e-15||std::abs(res(0,2)-ref(0,2)) >1e-15
        ||std::abs(res(1,0)-ref(1,0)) >1e-15||std::abs(res(1,1)-ref(1,1)) >1e-15||std::abs(res(1,2)-ref(1,2)) >1e-15
        ||std::abs(res(2,0)-ref(2,0)) >1e-15||std::abs(res(2,1)-ref(2,1)) >1e-15||std::abs(res(2,2)-ref(2,2)) >1e-15
    )   {err("operator - (l-value, l-value) test [ res]");}
}

{
    Matrix<double>  M(n,n,v);
    Matrix<double>  N(n,n,u);
    std::vector<double> ref_1 = {4.7,2.7,0.1,-0.89,-8.1,-11.1,-13.3,14.85,18.83};
    Matrix<double> ref(n,n,ref_1);
    Matrix<double> res = std::move(M)-N;
    if(M.size() !=0) { err("operator -(r-value, l-value)  test [move]");}
    if(N.size() != 9) {err("operator - (r-value, l-value) test [ size]");}
    if(
        N(0,0) != 0.3 ||N(0,1)!=0.3||(N(0,2)!=0.9)
        ||(N(1,0)!=-0.11) ||N(1,1)!=-0.9||N(1,2)!=0.1
        ||N(2,0)!=0.3 ||N(2,1)!=0.15||N(2,2)!=0.17)
        { err("operator - (r-value, l-value) test [elements N]");}
    if(res.size() != 9) {err("operator - (r-value, l-value) test [ size]");}
    if
    (
        std::abs(res(0,0)-ref(0,0)) >1e-15||std::abs(res(0,1)-ref(0,1)) >1e-15||std::abs(res(0,2)-ref(0,2)) >1e-15
        ||std::abs(res(1,0)-ref(1,0)) >1e-15||std::abs(res(1,1)-ref(1,1)) >1e-15||std::abs(res(1,2)-ref(1,2)) >1e-15
        ||std::abs(res(2,0)-ref(2,0)) >1e-15||std::abs(res(2,1)-ref(2,1)) >1e-15||std::abs(res(2,2)-ref(2,2)) >1e-15
    )   {err("operator - (r-value, l-value) test [ res]");}
}

{
    Matrix<double>  M(n,n,v);
    Matrix<double>  N(n,n,u);
    std::vector<double> ref_1 = {4.7,2.7,0.1,-0.89,-8.1,-11.1,-13.3,14.85,18.83};
    Matrix<double> ref(n,n,ref_1);
    Matrix<double> res = M - std::move(N);
    if(N.size() !=0) { err("operator -(l-value, r-value)  test [move]");}
    if(M.size() != 9) {err("operator - (l-value, r-value) test [ size]");}
    if(res.size() != 9) {err("operator - (l-value, r-value) test [ size]");}
    if
    (
        std::abs(res(0,0)-ref(0,0)) >1e-15||std::abs(res(0,1)-ref(0,1)) >1e-15||std::abs(res(0,2)-ref(0,2)) >1e-15
        ||std::abs(res(1,0)-ref(1,0)) >1e-15||std::abs(res(1,1)-ref(1,1)) >1e-15||std::abs(res(1,2)-ref(1,2)) >1e-15
        ||std::abs(res(2,0)-ref(2,0)) >1e-15||std::abs(res(2,1)-ref(2,1)) >1e-15||std::abs(res(2,2)-ref(2,2)) >1e-15
    )   {err("operator - (l-value, r-value) test [ res]");}

}

{
    Matrix<double>  M(n,n,v);
    Matrix<double>  N(n,n,u);
    std::vector<double> ref_1 = {4.7,2.7,0.1,-0.89,-8.1,-11.1,-13.3,14.85,18.83};
    Matrix<double> ref(n,n,ref_1);
    Matrix<double> res = std::move(M)-std::move(N);
    if(N.size() !=0) { err("operator -(r-value, r-value)  test [move]");}
    if(M.size() !=9) { err("operator -(r-value, r-value)  test [move]");}
    if(res.size() != 9) {err("operator - (r-value, r-value) test [ size]");}
    if
    (
        std::abs(res(0,0)-ref(0,0)) >1e-15||std::abs(res(0,1)-ref(0,1)) >1e-15||std::abs(res(0,2)-ref(0,2)) >1e-15
        ||std::abs(res(1,0)-ref(1,0)) >1e-15||std::abs(res(1,1)-ref(1,1)) >1e-15||std::abs(res(1,2)-ref(1,2)) >1e-15
        ||std::abs(res(2,0)-ref(2,0)) >1e-15||std::abs(res(2,1)-ref(2,1)) >1e-15||std::abs(res(2,2)-ref(2,2)) >1e-15
    )   {err("operator - (r-value, r-value) test [ res]");}
}

{
    Matrix<double>  M(n,n,v);
    Matrix<double>  N(n,n,u);
    std::vector<double> ref_1 = {5.3,3.3,1.9,-1.11,-9.9,-10.9,-12.7,15.15,19.17};
    Matrix<double> ref(n,n,ref_1);
    M += N;
    if(M.size() != 9) {err("operator += (l-value, l-value) test [ size]");}
    if(N.size() != 9) {err("operator += (l-value, l-value) test [ size]");}
    if(
        N(0,0) != 0.3 ||N(0,1)!=0.3||(N(0,2)!=0.9)
        ||(N(1,0)!=-0.11) ||N(1,1)!=-0.9||N(1,2)!=0.1
        ||N(2,0)!=0.3 ||N(2,1)!=0.15||N(2,2)!=0.17)
        { err("operator += test [elements]");}
    if
    (
        M(0,0)-ref(0,0) >1e-15||M(0,1)-ref(0,1) >1e-15||M(0,2)-ref(0,2) >1e-15
        ||M(1,0)-ref(1,0) >1e-15||M(1,1)-ref(1,1) >1e-15||M(1,2)-ref(1,2) >1e-15
        ||M(2,0)-ref(2,0) >1e-15||M(2,1)-ref(2,1) >1e-15||M(2,2)-ref(2,2) >1e-15
    )   {err("operator +=  test [ res]");}
}

{
    Matrix<double>  M(n,n,v);
    Matrix<double>  N(n,n,u);
    std::vector<double> ref_1 = {4.7,2.7,0.1,-0.89,-8.1,-11.1,-13.3,14.85,18.83};
    Matrix<double> ref(n,n,ref_1);
    M -=N;
    if(M.size() != 9) {err("operator -=  test [ size]");}
    if(N.size() != 9) {err("operator -=  test [ size]");}
    if
    (
        (M(0,0)-ref(0,0)) >1e-15||M(0,1)-ref(0,1) >1e-15||M(0,2)-ref(0,2) >1e-15
        ||M(1,0)-ref(1,0) >1e-15||M(1,1)-ref(1,1) >1e-15||M(1,2)-ref(1,2) >1e-15
        ||M(2,0)-ref(2,0) >1e-15||M(2,1)-ref(2,1) >1e-15||M(2,2)-ref(2,2) >1e-15
    )
   {err("operator -=  test [ res]");}
}

{
    Matrix<double>  M(n,n,v);
    std::vector<double> ref_1 = {10.0,6.0,2.0,-2.0,-18.0,-22.0,-26.0,30.0,38.0};
    Matrix<double> ref(n,n,ref_1);
    M *=2;
    if(M.size() != 9) {err("operator *=  test [ size]");}
    if
    (
        (M(0,0)-ref(0,0)) >1e-15||M(0,1)-ref(0,1) >1e-15||M(0,2)-ref(0,2) >1e-15
        ||M(1,0)-ref(1,0) >1e-15||M(1,1)-ref(1,1) >1e-15||M(1,2)-ref(1,2) >1e-15
        ||M(2,0)-ref(2,0) >1e-15||M(2,1)-ref(2,1) >1e-15||M(2,2)-ref(2,2) >1e-15
    )
   {err("operator *=  test [ res]");}
}

{
    Matrix<double>  M(n,n,v);
    std::vector<double> ref_1 = {2.5,1.5,0.5,-0.5,-4.5,-5.5,-6.5,7.5,9.5};
    Matrix<double> ref(n,n,ref_1);
    M /=2;
    if(M.size() != 9) {err("operator /=  test [ size]");}
    if
    (
        (M(0,0)-ref(0,0)) >1e-15||M(0,1)-ref(0,1) >1e-15||M(0,2)-ref(0,2) >1e-15
        ||M(1,0)-ref(1,0) >1e-15||M(1,1)-ref(1,1) >1e-15||M(1,2)-ref(1,2) >1e-15
        ||M(2,0)-ref(2,0) >1e-15||M(2,1)-ref(2,1) >1e-15||M(2,2)-ref(2,2) >1e-15
    )
   {err("operator /=  test [ res]");}
}


{
    Matrix<double>  N(n,n,v);
    std::vector<double> ref_1 = {10.0,6.0,2.0,-2.0,-18.0,-22.0,-26.0,30.0,38.0};
    Matrix<double> ref(n,n,ref_1);
    Matrix<double>  M = N*2.0;
    if(M.size() != 9) {err("operator *  test(l-value, scalar) [ size]");}
    if
    (
        (M(0,0)-ref(0,0)) >1e-15||M(0,1)-ref(0,1) >1e-15||M(0,2)-ref(0,2) >1e-15
        ||M(1,0)-ref(1,0) >1e-15||M(1,1)-ref(1,1) >1e-15||M(1,2)-ref(1,2) >1e-15
        ||M(2,0)-ref(2,0) >1e-15||M(2,1)-ref(2,1) >1e-15||M(2,2)-ref(2,2) >1e-15
    )
   {err("operator *  test(l-value ,scalar) [ res]");}
}

{
    Matrix<double>  N(n,n,v);
    std::vector<double> ref_1 = {10.0,6.0,2.0,-2.0,-18.0,-22.0,-26.0,30.0,38.0};
    Matrix<double> ref(n,n,ref_1);
    Matrix<double>  M = std::move(N)*2.0;
    if(M.size() != 9) {err("operator *  test(r-value, scalar) [ size]");}
    if(N.size() != 0) {err("operator *  test(r-value, scalar) [ move]");}
    if
    (
        (M(0,0)-ref(0,0)) >1e-15||M(0,1)-ref(0,1) >1e-15||M(0,2)-ref(0,2) >1e-15
        ||M(1,0)-ref(1,0) >1e-15||M(1,1)-ref(1,1) >1e-15||M(1,2)-ref(1,2) >1e-15
        ||M(2,0)-ref(2,0) >1e-15||M(2,1)-ref(2,1) >1e-15||M(2,2)-ref(2,2) >1e-15
    )
   {err("operator *  test(r-value ,scalar) [ res]");}
}

{
    Matrix<double>  N(n,n,v);
    std::vector<double> ref_1 = {10.0,6.0,2.0,-2.0,-18.0,-22.0,-26.0,30.0,38.0};
    Matrix<double> ref(n,n,ref_1);
    Matrix<double>  M = 2.0*N;
    if(M.size() != 9) {err("operator *  test( scalar,l-value) [ size]");}
    if
    (
        (M(0,0)-ref(0,0)) >1e-15||M(0,1)-ref(0,1) >1e-15||M(0,2)-ref(0,2) >1e-15
        ||M(1,0)-ref(1,0) >1e-15||M(1,1)-ref(1,1) >1e-15||M(1,2)-ref(1,2) >1e-15
        ||M(2,0)-ref(2,0) >1e-15||M(2,1)-ref(2,1) >1e-15||M(2,2)-ref(2,2) >1e-15
    )
   {err("operator *  test(l-value ,scalar) [ res]");}
}

{
    Matrix<double>  N(n,n,v);
    std::vector<double> ref_1 = {10.0,6.0,2.0,-2.0,-18.0,-22.0,-26.0,30.0,38.0};
    Matrix<double> ref(n,n,ref_1);
    Matrix<double>  M =2.0* std::move(N);
    if(M.size() != 9) {err("operator *  test(scalar,r-value) [ size]");}
    if(N.size() != 0) {err("operator *  test(scalar,r-value) [ move]");}
    if
    (
        (M(0,0)-ref(0,0)) >1e-15||M(0,1)-ref(0,1) >1e-15||M(0,2)-ref(0,2) >1e-15
        ||M(1,0)-ref(1,0) >1e-15||M(1,1)-ref(1,1) >1e-15||M(1,2)-ref(1,2) >1e-15
        ||M(2,0)-ref(2,0) >1e-15||M(2,1)-ref(2,1) >1e-15||M(2,2)-ref(2,2) >1e-15
    )
   {err("operator *  test(scalar,r-value) [ res]");}
}

{
    Matrix<double>  N(n,n,v);
    std::vector<double> ref_1 = {2.5,1.5,0.5,-0.5,-4.5,-5.5,-6.5,7.5,9.5};
    Matrix<double> ref(n,n,ref_1);
    Matrix<double>  M= N/2.0;
    if(M.size() != 9) {err("operator /  test (l-value,scalar) [ size]");}
    if
    (
        (M(0,0)-ref(0,0)) >1e-15||M(0,1)-ref(0,1) >1e-15||M(0,2)-ref(0,2) >1e-15
        ||M(1,0)-ref(1,0) >1e-15||M(1,1)-ref(1,1) >1e-15||M(1,2)-ref(1,2) >1e-15
        ||M(2,0)-ref(2,0) >1e-15||M(2,1)-ref(2,1) >1e-15||M(2,2)-ref(2,2) >1e-15
    )
   {err("operator /  test (l-value,scalar) [ res]");}
}

{
    Matrix<double>  N(n,n,u);
    Matrix<double>  M(n,n,v);
    std::vector<double> ref_1 = {1.470,-1.05,4.97,-2.61,6.15,-3.67,0.15,-14.55,-6.97};
    Matrix<double> ref(n,n,ref_1);
    Matrix<double>  res = M*N;
    if(M.size() != 9) {err("operator *[matrix] (l-value, l-value) test [ size]");}
    if(N.size() != 9) {err("operator *[matrix] (l-value, l-value) test [ size]");}
    if(
        N(0,0) != 0.3 ||N(0,1)!=0.3||(N(0,2)!=0.9)
        ||(N(1,0)!=-0.11) ||N(1,1)!=-0.9||N(1,2)!=0.1
        ||N(2,0)!=0.3 ||N(2,1)!=0.15||N(2,2)!=0.17)
        { err("operator *[matrix] test [elements]");}
    if(
        M(0,0) != 5.0 ||M(0,1)!=3.0||(M(0,2)!=1.0)
        ||(M(1,0)!=-1.0) ||M(1,1)!=-9.0||M(1,2)!=-11.0
        ||M(2,0)!=-13.0 ||M(2,1)!=15.0||M(2,2)!=19.0)
        { err("operator *[matrix] test [elements]");}
    if(res.size() != 9) {err("operator *[matrix] (l-value, l-value) test [ size]");}
    if
    (
        std::abs(res(0,0)-ref(0,0)) >1e-10||std::abs(res(0,1)-ref(0,1)) >1e-10||std::abs(res(0,2)-ref(0,2)) >1e-10
        ||std::abs(res(1,0)-ref(1,0)) >1e-10||std::abs(res(1,1)-ref(1,1)) >1e-10||std::abs(res(1,2)-ref(1,2)) >1e-10
        ||std::abs(res(2,0)-ref(2,0)) >1e-10||std::abs(res(2,1)-ref(2,1)) >1e-10||std::abs(res(2,2)-ref(2,2)) >1e-10
    )   {err("operator * [matrix] (l-value, l-value) test [ res]");}
}

{
    Matrix<double>  N(n,n,u);
    Matrix<double>  M(n,n,v);
    std::vector<double> ref_1 = {1.470,-1.05,4.97,-2.61,6.15,-3.67,0.15,-14.55,-6.97};
    Matrix<double> ref(n,n,ref_1);
    Matrix<double> res = std::move(M)*N;
    if(N.size() != 9) {err("operator *[matrix] (r-value, l-value) test [ size]");}
    if(M.size() != 0) {err("operator *[matrix] (r-value, l-value) test [ size]");}
    if(
        N(0,0) != 0.3 ||N(0,1)!=0.3||(N(0,2)!=0.9)
        ||(N(1,0)!=-0.11) ||N(1,1)!=-0.9||N(1,2)!=0.1
        ||N(2,0)!=0.3 ||N(2,1)!=0.15||N(2,2)!=0.17)
        { err("operator *[matrix] test [elements]");}
    if(res.size() != 9) {err("operator *[matrix] (r-value, l-value) test [ size]");}
    if
    (
        std::abs(res(0,0)-ref(0,0)) >1e-10||std::abs(res(0,1)-ref(0,1)) >1e-10||std::abs(res(0,2)-ref(0,2)) >1e-10
        ||std::abs(res(1,0)-ref(1,0)) >1e-10||std::abs(res(1,1)-ref(1,1)) >1e-10||std::abs(res(1,2)-ref(1,2)) >1e-10
        ||std::abs(res(2,0)-ref(2,0)) >1e-10||std::abs(res(2,1)-ref(2,1)) >1e-10||std::abs(res(2,2)-ref(2,2)) >1e-10
    )   {err("operator * [matrix] (r-value, l-value) test [ res]");}
}

{
    Matrix<double>  N(n,n,u);
    Matrix<double>  M(n,n,v);
    std::vector<double> ref_1 = {1.470,-1.05,4.97,-2.61,6.15,-3.67,0.15,-14.55,-6.97};
    Matrix<double> ref(n,n,ref_1);
    Matrix<double> res = M*std::move(N);
    if(M.size() != 9) {err("operator *[matrix] (l-value, r-value) test [ size]");}
    if(N.size() != 0) {err("operator *[matrix] (l-value, r-value) test [ size]");}
    if(
        M(0,0) != 5.0 ||M(0,1)!=3.0||(M(0,2)!=1.0)
        ||(M(1,0)!=-1.0) ||M(1,1)!=-9.0||M(1,2)!=-11.0
        ||M(2,0)!=-13.0 ||M(2,1)!=15.0||M(2,2)!=19.0)
        { err("operator *[matrix] test [elements]");}
    if(res.size() != 9) {err("operator *[matrix] (l-value, r-value) test [ size]");}
    if
    (
        std::abs(res(0,0)-ref(0,0)) >1e-10||std::abs(res(0,1)-ref(0,1)) >1e-10||std::abs(res(0,2)-ref(0,2)) >1e-10
        ||std::abs(res(1,0)-ref(1,0)) >1e-10||std::abs(res(1,1)-ref(1,1)) >1e-10||std::abs(res(1,2)-ref(1,2)) >1e-10
        ||std::abs(res(2,0)-ref(2,0)) >1e-10||std::abs(res(2,1)-ref(2,1)) >1e-10||std::abs(res(2,2)-ref(2,2)) >1e-10
    )   {err("operator * [matrix] (l-value, r-value) test [ res]");}
}

{    Matrix<double>  N(n,n,u);
    Matrix<double>  M(n,n,v);
    std::vector<double> ref_1 = {1.470,-1.05,4.97,-2.61,6.15,-3.67,0.15,-14.55,-6.97};
    Matrix<double> ref(n,n,ref_1);
    Matrix<double> res = std::move(M)*std::move(N);
    if(N.size() != 0) {err("operator *[matrix] (r-value, r-value) test [ size]");}
    if(M.size() != 9) {err("operator *[matrix] (r-value, r-value) test [ size]");}
    if(res.size() != 9) {err("operator *[matrix] (r-value, r-value) test [ size]");}
    if
    (
        std::abs(res(0,0)-ref(0,0)) >1e-10||std::abs(res(0,1)-ref(0,1)) >1e-10||std::abs(res(0,2)-ref(0,2)) >1e-10
        ||std::abs(res(1,0)-ref(1,0)) >1e-10||std::abs(res(1,1)-ref(1,1)) >1e-10||std::abs(res(1,2)-ref(1,2)) >1e-10
        ||std::abs(res(2,0)-ref(2,0)) >1e-10||std::abs(res(2,1)-ref(2,1)) >1e-10||std::abs(res(2,2)-ref(2,2)) >1e-10
    )   {err("operator * [matrix] (r-value, r-value) test [ res]");}
}


{ 
    std::vector<double> ref_1 {70.0,20.0,9.0,24.6,138.0,56.0,13.0,52.4};
    Matrix<double> M(3,2,v_1);
    Matrix<double> N(4,3,u_1);
    Matrix<double> ref(4,2,ref_1);
    Matrix<double> res = M*N;

    if(M.size() != 6) {err("operator *[matrix] (l-value, l-value) test [ size]");}
    if(N.size() != 12) {err("operator *[matrix] (l-value, l-value) test [ size]");}
    if(
        N(0,0) != -1.0 ||N(0,1)!=5.0||(N(0,2)!=0.0)||N(0,3)!=0.7
        ||(N(1,0)!=9.0) ||N(1,1)!=1.0||N(1,2)!=-1.0||N(1,3)!=3.1
        ||N(2,0)!=4.0 ||N(2,1)!=0.0||N(2,2)!=2.0|| N(2,3)!=1.0)
        { err("operator *[matrix] test [elements]");}
    if(
        M(0,0) != 3.0 ||M(0,1)!=5.0||(M(0,2)!=7.0)
        ||(M(1,0)!=9.0) ||M(1,1)!=11.0||M(1,2)!=12.0)
        { err("operator *[matrix] test [elements]");}
   if(res.size() != 8) {err("operator *[matrix] (l-value, l-value) test [ size]");}
    if
    (
        std::abs(res(0,0)-ref(0,0)) >1e-10||std::abs(res(0,1)-ref(0,1)) >1e-10||std::abs(res(0,2)-ref(0,2)) >1e-10||std::abs(res(0,3)-ref(0,3)) >1e-10
        ||std::abs(res(1,0)-ref(1,0)) >1e-10||std::abs(res(1,1)-ref(1,1)) >1e-10||std::abs(res(1,2)-ref(1,2)) >1e-10||std::abs(res(1,3)-ref(1,3)) >1e-10
    )   {err("operator * [matrix] (l-value, l-value) test [ res]");}
}

{

    std::vector<double> ref_1 {70.0,20.0,9.0,24.6,138.0,56.0,13.0,52.4};
    Matrix<double> M(3,2,v_1);
    Matrix<double> N(4,3,u_1);
    Matrix<double> ref(4,2,ref_1);
    Matrix<double> res = std::move(M)*N;

    if(M.size() != 0) {err("operator *[matrix] (r-value, l-value) test [ size]");}
    if(N.size() != 12) {err("operator *[matrix] (r-value, l-value) test [ size]");}
    if(
        N(0,0) != -1.0 ||N(0,1)!=5.0||(N(0,2)!=0.0)||N(0,3)!=0.7
        ||(N(1,0)!=9.0) ||N(1,1)!=1.0||N(1,2)!=-1.0||N(1,3)!=3.1
        ||N(2,0)!=4.0 ||N(2,1)!=0.0||N(2,2)!=2.0|| N(2,3)!=1.0)
        { err("operator *[matrix] test [elements]");}
    if(res.size() != 8) {err("operator *[matrix] (r-value, l-value) test [ size]");}
    if
    (
        std::abs(res(0,0)-ref(0,0)) >1e-10||std::abs(res(0,1)-ref(0,1)) >1e-10||std::abs(res(0,2)-ref(0,2)) >1e-10||std::abs(res(0,3)-ref(0,3)) >1e-10
        ||std::abs(res(1,0)-ref(1,0)) >1e-10||std::abs(res(1,1)-ref(1,1)) >1e-10||std::abs(res(1,2)-ref(1,2)) >1e-10||std::abs(res(1,3)-ref(1,3)) >1e-10
    )   {err("operator * [matrix] (r-value, l-value) test [ res]");}
}

{
    std::vector<double> ref_1 {70.0,20.0,9.0,24.6,138.0,56.0,13.0,52.4};
    Matrix<double> M(3,2,v_1);
    Matrix<double> N(4,3,u_1);
    Matrix<double> ref(4,2,ref_1);
    Matrix<double> res = M*std::move(N);

    if(M.size() != 6) {err("operator *[matrix] (l-value, r-value) test [ size]");}
    if(N.size() != 0) {err("operator *[matrix] (l-value, r-value) test [ size]");}
    if(
        M(0,0) != 3.0 ||M(0,1)!=5.0||(M(0,2)!=7.0)
        ||(M(1,0)!=9.0) ||M(1,1)!=11.0||M(1,2)!=12.0)
        { err("operator *[matrix] test [elements]");}
   if(res.size() != 8) {err("operator *[matrix] (l-value, r-value) test [ size]");}
    if
    (
        std::abs(res(0,0)-ref(0,0)) >1e-10||std::abs(res(0,1)-ref(0,1)) >1e-10||std::abs(res(0,2)-ref(0,2)) >1e-10||std::abs(res(0,3)-ref(0,3)) >1e-10
        ||std::abs(res(1,0)-ref(1,0)) >1e-10||std::abs(res(1,1)-ref(1,1)) >1e-10||std::abs(res(1,2)-ref(1,2)) >1e-10||std::abs(res(1,3)-ref(1,3)) >1e-10
    )   {err("operator * [matrix] (l-value, r-value) test [ res]");}
}

{

    
    std::vector<double> ref_1 {70.0,20.0,9.0,24.6,138.0,56.0,13.0,52.4};
    Matrix<double> M(3,2,v_1);
    Matrix<double> N(4,3,u_1);
    Matrix<double> ref(4,2,ref_1);
    Matrix<double> res = std::move(M)*std::move(N);

    if(M.size() != 6) {err("operator *[matrix] (r-value, r-value) test [ size]");}
    if(N.size() != 0) {err("operator *[matrix] (r-value, r-value) test [ size]");}
   if(res.size() != 8) {err("operator *[matrix] (r-value, r-value) test [ size]");}
    if
    (
        std::abs(res(0,0)-ref(0,0)) >1e-10||std::abs(res(0,1)-ref(0,1)) >1e-10||std::abs(res(0,2)-ref(0,2)) >1e-10||std::abs(res(0,3)-ref(0,3)) >1e-10
        ||std::abs(res(1,0)-ref(1,0)) >1e-10||std::abs(res(1,1)-ref(1,1)) >1e-10||std::abs(res(1,2)-ref(1,2)) >1e-10||std::abs(res(1,3)-ref(1,3)) >1e-10
    )   {err("operator * [matrix] (r-value, r-value) test [ res]");}
}

{
    Matrix<double>  M(n,n,v);
    std::cout<< M << std::endl;
}
   std::cout<<"so far so good"<<std::endl;
}