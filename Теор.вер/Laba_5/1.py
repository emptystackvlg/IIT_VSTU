from colorama import Fore,Back,Style
from easygui import fileopenbox
from os import system
from math import sqrt
def input_var ():
    system("cls")
    path = fileopenbox (msg = "Выберите файл с данными")
    
    with open(path, "r") as file:
        line = file.readline()
        read_line = [float(x) for x in line.split()]
        return (read_line)


def sort_mass (main_mass):
    sorted_mass = []
    for i in main_mass:
        if (i not in sorted_mass):
            sorted_mass.append(i)
    return (sorted_mass)
def freq (main_list):
    mass_freq = []
    old_i = []
    for i in main_list:
            if (i not in old_i):
                mass_freq.append(main_list.count(i))
            old_i.append(i)
    return (mass_freq)

def relative_freq (sum_n,mass_freq):
    rel_freq = []
    x_freq = float (0)
    for i in mass_freq: 
        x_freq = 0 
        x_freq = i/sum_n
        rel_freq.append (x_freq)
    return rel_freq

def F_x (sort_mass,rel_freq):
    variables = []
    for i in range (len(sort_mass)):
        if (i!=0 ):
            summ = 0 
            for j in range (i):
                summ += rel_freq[j]
            variables.append(summ)
        else : 
            variables.append(0)
    variables.append(sum(rel_freq))
    strings = []
    for i in range (len(sort_mass)):
        if (i!=0):
            strings.append ("F_x = " + str(variables[i]) + "\t при \t\t" + str(sort_mass[i-1]) + " < " + " x <= " + str (sort_mass[i]))
        else : 
            print ("\n\n")
            strings.append ("F_x = " + str (variables[i]) + " \t при\t\t" + "x <= " + str (sort_mass[i]))
    strings.append("F_x = " + str (variables[len(sort_mass)]) + "\t при \t\t" + "x > " + str(sort_mass[len(sort_mass)-1]))
    for i in strings:
        print (i + "\n\n")


def params (mass,freq):
    n = len (mass)
    summ = 0
    X_v = (1/n) * sum(mass)
    for i in range (len(freq)):
        summ += ((freq[i] - X_v)**2*mass[i])
    D_v = (1/n) * summ
    Sigma_v = sqrt(D_v)


def show_table (main_mass,mass_freq):
    print (Fore.GREEN + "|x|",end = "")
    for i in main_mass:
        print (Fore.RED + "|" + str(i) + "|",end="")
    print (Style.RESET_ALL)
    print (Fore.LIGHTYELLOW_EX + "|n|",end = "")
    for i in mass_freq:
        print (Fore.BLUE + "| " + str(i) + " |",end="")




mass = input_var()
mass.sort()
#(F_x(sort_mass(mass),relative_freq(sum(freq(mass)),freq(mass))))
params (sort_mass(mass),freq(mass))

#show_table (sort_mass(mass),freq(mass))