#All standard units are in Gev^(-2)

import math
from bigfloat import*
file = open("27the24.txt", "w+")

#Introduction of variables
cme = 27000 #cme is centre of mass energy
s = math.pow(cme, 2)
Gamma = 0.85
C = 1.8
delta = 0.19
epsi = math.log(s) 
alph_P = 0.25
sigma_ND = 78.671
eta = 2.4
K = 1.4
sigma_P = 8*(math.pi)*Gamma*(math.exp(delta*epsi))
#Calculation of parameters which include avg_k, Z
Z = 2*C*Gamma*(math.exp(delta*epsi))/(3.3+(alph_P*epsi))
avg_k = 8*(math.pi)*Gamma*(math.exp(delta*epsi))/(sigma_ND*2.56819)
avg_nc = 3*eta*avg_k/K

#code to find psi(z)

#Looping over number of clusters
for nc in range(1, 180):
   m = 0
   P_nc = 0
   
   #Looping and summing over all inelastic collisions
   for k in range(1, 100):
      f = math.factorial(nc)
      g = math.factorial(k-1)
      x = math.exp(-Z)
      y = math.exp(-k*3*eta/K)
      m = m + pow(Z, (k-1))/g
      P_nc = P_nc + (sigma_P/(Z*sigma_ND*2.56819))*(1-(x)*m)*y*pow(k*3*eta/K, nc)*(1/k)/(f) 
      
   psi = (avg_nc)*P_nc
   z = (nc)/(avg_nc)
   file.write(str(z)+' '+str(psi)+'\n')    

file.close()   


           
