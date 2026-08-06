a = input("Valor A:")
b = input("Valor B:")
c = input("Valor C:")

if a > 0
  printf("para cima\n")
else
  printf("Para baixo\n")
endif
%cometario

delta = b^2-(4*a*c);
if delta > 0;
  printf("Duas raises reias!\n");
elseif delta == 0;
  printf("Uma rais real!\n");
else
  printf("Nehnuma rais real\n");
endif
x1 = (-b + sqrt(delta))/(2*a);
x2 = (-b - sqrt(delta))/(2*a);
printf("raises x1=%f x2=%f!\n",x1,x2);
