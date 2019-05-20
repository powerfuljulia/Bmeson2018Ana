import math
sys0 = [0, 8, 15, 6.5, 4.4, 1.7, 3.4, 2.5, 0.78]
sys1 = [0, 8, 2.6, 2.3, 3.1, 1.8, 1.6, 0.69, 0.47]

sys01 = [0, 8, 2.6, 0.46, 3.3, 1.4, 1.6, 0.69, 0.76]
sys02 = [0, 8, 2.6, 0.9, 3.0, 1.7, 1.6, 0.69, 0.53]

sysAA0 = [0, 12, 19, 7.9, 5.1, 1.7, 8.7, 4.2, 4.9]
sysAA1 = [0, 12, 8.6, 3.8, 3.8, 1.7, 0.68, 3.5, 2.1]

for i in range (len(sys0)):
	sys0[0] += sys0[i]*sys0[i]
	sys1[0] += sys1[i]*sys1[i]
	sys01[0] += sys01[i]*sys01[i]
	sys02[0] += sys02[i]*sys02[i]
	sysAA0[0] += sysAA0[i]*sysAA0[i]
	sysAA1[0] += sysAA1[i]*sysAA1[i]
	print "bin1: ",math.sqrt(sys0[i]*sys0[i]+sysAA0[i]*sysAA0[i])
	print "bin2: ",math.sqrt(sys1[i]*sys1[i]+sysAA1[i]*sysAA1[i])
print "========="
print sys0[0], math.sqrt(sys0[0])
print sys1[0], math.sqrt(sys1[0])
print sys01[0], math.sqrt(sys01[0])
print sys02[0], math.sqrt(sys02[0])
print sysAA0[0], math.sqrt(sysAA0[0])
print sysAA1[0], math.sqrt(sysAA1[0])
tot0 = sys0[0] + sysAA0[0]
tot1 = sys1[0] + sysAA1[0]
print tot0, math.sqrt(tot0)
print tot1, math.sqrt(tot1)

