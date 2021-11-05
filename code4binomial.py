#All standard units are in Gev^(-2)

import math
from bigfloat import*

file = open("nbd.txt", "w+")

#Introduction of variables
cme = 900 #cme is centre of mass energy
s = math.pow(cme, 2)
Gamma = 0.85
C = 1.8
delta = 0.19
epsi = math.log(s) 
alph_P = 0.25
sigma_ND = 43.33
eta = 2.4
K = 1.4
#Calculation of parameters which include avg_k, Z
Z = 2*C*Gamma*(math.exp(delta*epsi))/(3.3+(alph_P*epsi))
sigma_P = 8*(math.pi)*Gamma*(math.exp(delta*epsi))
avg_k = sigma_P/(sigma_ND*2.56819)

avg_nc = 3*eta*avg_k/K



#code to find psi(z)
n = 1000

#Looping over number of clusters
for nc in range(1, 140):   	
   m = 0
   P_nc = 0   
   b = math.factorial(n)
   c = math.factorial(nc)
   d = math.factorial(n-nc)
   
   #Looping and summing over all the inelastic collisions 
   for k in range(1, 200):
   	
      m = m + pow(Z, (k-1))/(math.factorial(k-1)) 
      P_nc = P_nc + (sigma_P/(Z*sigma_ND*2.56819))*(1-(math.exp(-Z)*m))*(b/(c*d))*pow((k*3*eta/(K*n)), nc)*pow((1-(k*3*eta/(K*n))), n-nc)*(1/k)
    
   psi = (avg_nc)*P_nc
   z = (nc)/(avg_nc)
   file.write(str(z)+' '+str(psi)+'\n')  

file.close()

