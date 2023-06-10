n = [6,5,8,31,24,11,15]

npi = [30.5,6.19,6.56,6.35,6.76,6.19,37.4]

fi = []

for i in range (len(n)):
    var = (n[i]-npi[i])**2/npi[i]
    fi.append(var)

print (fi)
print (sum(fi))