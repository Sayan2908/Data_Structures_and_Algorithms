Sets
    i proposals /1*10/
    j reviewers /1*5/;


Parameters
    N  no. of proposals /10/
    M  no. of reviewers /5/
    K  no. of reviews for each proposal /4/
    alpha contrains 2-22 /1000/
    epsilon small value /0.000001/;
    
    
Table w(i,j) preference (j) for each proposal (i)
        1   2   3   4   5   
     1  3   5   18  3   0   
     2  6   6   8   2   1   
     3  6   2   6   1   4   
     4  0   2   5   8   6    
     5  1   4   6   9   2   
     6  10  6   5   3   3 
     7  8   9   7   4   5   
     8  6   8   1   5   0   
     9  10  9   5   8   7   
     10 3   10  8   4   10;

alias(j,jj);

Binary Variables y(i,j), L(i,j), S(i,j), R1(i,j), R2(i,j), x(i,j,jj);
Positive Variables sl(i,j,jj),temp(j,jj);
Variable Obj;

Equations Eq1(j),Eq2(j),Eq3(j),Eq4(j),Eq5(j),Eq6(j),Eq7(j),Eq8(j),E3(i),Ea3(i),Eb3(i),Ec3(i),E4(i,j),
Ea5(i,j),Eb5(i,j),Ec5(i,j),Ea6(i,j,jj),Eb6(i,j,jj),Ea7(i,j,jj),E8,E9(j,jj),Eb7(i,j,jj), Ee1(j), Ee2(j),Ed3(i),Ed5(i,j),Ec6(i,j,jj);

Eq1(j).. sum(i,y(i,j)) =l= ceil(N*K/M);
Eq2(j).. sum(i,y(i,j)) =g= floor(N*K/M);

Eq3(j).. sum(i,L(i,j)) =l= ceil(N/M);
Eq4(j).. sum(i,L(i,j)) =g= floor(N/M);

Eq5(j).. sum(i,S(i,j)) =l= ceil(N/M);
Eq6(j).. sum(i,S(i,j)) =g= floor(N/M);

Eq7(j).. sum(i,R1(i,j)) =l= ceil(N/M);
Eq8(j).. sum(i,R1(i,j)) =g= floor(N/M);

Ee1(j).. sum(i,R2(i,j)) =l= ceil(N/M);
Ee2(j).. sum(i,R2(i,j)) =g= floor(N/M);

E3(i).. sum(j,y(i,j)) =e= K;
Ea3(i).. sum(j,L(i,j)) =e= 1;
Eb3(i).. sum(j,S(i,j)) =e= 1;
Ec3(i).. sum(j,R1(i,j)) =e= 1;
Ed3(i).. sum(j,R2(i,j)) =e= 1;

E4(i,j).. L(i,j) + S(i,j) +  R1(i,j) + R2(i,j)=e= y(i,j);

Ea5(i,j).. L(i,j) =l= y(i,j);
Eb5(i,j).. S(i,j) =l= y(i,j);
Ec5(i,j).. R1(i,j) =l= y(i,j);
Ed5(i,j).. R2(i,j) =l= y(i,j);

Ea6(i,j,jj)$(ord(j) <> ord(jj)).. L(i,j) + S(i,jj) - x(i,j,jj) =l= 1;
Eb6(i,j,jj)$(ord(j) <> ord(jj)).. S(i,j) + R1(i,jj) - x(i,j,jj) =l= 1;
Ec6(i,j,jj)$(ord(j) <> ord(jj)).. R1(i,j) + R2(i,jj) - x(i,j,jj) =l= 1;

Ea7(i,j,jj)$(ord(j) <> ord(jj)).. -N*(1-x(i,j,jj)) =l= w(i,jj) - w(i,j) + sl(i,j,jj);
Eb7(i,j,jj)$(ord(j) <> ord(jj)).. w(i,jj) - w(i,j) + sl(i,j,jj) =l= N*x(i,j,jj) - epsilon;
 
E8.. Obj =e= sum(i,sum(j,w(i,j)*y(i,j))) + alpha*sum(j,sum(jj,temp(j,jj)));
E9(j,jj)$(ord(j) <> ord(jj)).. temp(j,jj) =e= sum(i,sl(i,j,jj));


model NSF /all/;

solve NSF using mip minimizing Obj;