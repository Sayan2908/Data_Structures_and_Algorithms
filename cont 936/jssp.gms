Sets i orders /1*3/, m machines /1*3/;
Alias(i,ii);
Alias(m,mm);

Table C(i,m) cost of ith job on machine m
     1   2   3
1    10  11  12
2    9   18  19
3    6   9   15;

Table p(i,m) duration of each job in machine m
     1   2   3
1    9   12  15
2    7   16  19
3    21  8   14;

Parameter r(i)/1 1,2 5,3 4/;
Parameter d(i)/1 13,2 21,3 32/;

Variables ts(i),obj,x(i,m),y(i,ii);
Free Variable obj;
Binary Variables x(i,m),y(i,ii);
Positive Variable ts(i);


Scalar U/55/;

Equations sol,eq1(i,m),eq2(i),eq3(i),eq4(i),eq5(m),eq6(i),eq7(i),eq8(i),eq9(i);
eq1(i,m).. obj =e= sum((i,m),(C(i,m)*x(i,m)));
eq2(i).. ts(i) =g= r(i);
eq3(i).. ts(i) =l= d(i)- sum(m,(p(i,m)*x(i,m)));
eq4(i).. sum(m,x(i,m)) =l= 1;
eq5(m).. sum(m,(x(i,m)*p(i,m))) =l= smax(i,d(i)) - smin(i,r(i));
eq6(i)$(ord(i)<>ord(ii)).. y(i,ii) + y(ii,i) =g= x(i,m) + x(ii,m) -1;
eq7(i)$(ord(i)<>ord(ii)).. ts(ii) =g= ts(i) + sum(m,p(i,m)*x(i,m)) - U*(1-y(ii));
eq8(i)$(ord(i)<>ord(ii)).. y(ii) + y(i) =l= 1;
eq9(i)$(ord(i)<>ord(ii)).. y(ii) + y(i) + x(i,m) + x(ii,mm) =l= 2;

Model jssp /all/;
solve jssp using mip minimizing obj;