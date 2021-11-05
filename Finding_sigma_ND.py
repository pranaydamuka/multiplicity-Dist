import math
from bigfloat import*
cme = 27000 #cme is centre of mass energy
s = math.pow(cme, 2)
Gamma = 0.85
C = 1.8
delta = 0.19
epsi = math.log(s) 
alph_P = 0.25
K = 1.4
sigma_P = 8*(math.pi)*Gamma*(math.exp(delta*epsi))
Z = 2*C*Gamma*(math.exp(delta*epsi))/(3.3+(alph_P*epsi))

m = 0
n = 0
for k in range(1, 50):
   y = math.factorial(k-1)
   x = math.exp(-Z)
   m = m + pow(Z, (k-1))/y
   n = n + ((1-(x*m))/k)	
   sigma_ND = (sigma_P/Z)*n/2.56819
print(sigma_ND)


	
	
	
	
