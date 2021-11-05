import numpy as np
import pandas as pd
import math

file = open("7exp24.txt", "w+")

data = pd.read_csv('7000_24.csv')


data1 = data['n'].values
data2 = data['P_n'].values
data3 = data['xp'].values
data4 = data['xm'].values
data5 = data['yp'].values
data6 = data['ym'].values

x = 0
y = 0
z = 0
for i, j in zip(data1, data2):
	x = x + i*j
	y =  y + j
	z = z + i*i*j
		
avg_n = x/y
avg_nsqr = z/y
sigma = np.sqrt(avg_nsqr-(avg_n*avg_n))
N = 442000

deltavg_n = sigma/np.sqrt(N)	

print(avg_n)
print(deltavg_n/avg_n)

for i, j, k, l, m, n in zip(data1, data2, data3, data4, data5, data6):

	a = i/avg_n
	b = j*avg_n
	c = (deltavg_n/avg_n)*a 
	d = (deltavg_n/avg_n)*a  
	e = ((deltavg_n/avg_n)+(m/j))*b 
	f = ((deltavg_n/avg_n)+(n/j))*b
	file.write(str(a)+4*'\t'+str(b)+ 4*'\t'+str(c) +4*'\t'+str(d) + 4*'\t'+str(e) + 4*'\t'+str(f)+'\n') 



	


	
