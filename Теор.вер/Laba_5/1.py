from easygui import fileopenbox
import matplotlib.pyplot as plt
from os import system,path
from math import sqrt
def input_var ():
    system("cls")
    path_f = fileopenbox (msg = "Выберите файл с данными")
    temp_mass = []
    main_mass = []
    with open(path_f, "r") as file:
        lines = file.readlines()
        for line in lines: 
            read_line = [int(x) for x in line.split()]
            temp_mass.append(read_line)
        for i in range (len(temp_mass)):
            for j in temp_mass[i] :
                main_mass.append(j)
    return (main_mass)


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
                mass_freq.append(int(main_list.count(i)))
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
    variables_to_show = []
    for var in variables:
        var = float("{0:.3f}".format(var))
        variables_to_show.append(var)
    for i in range (len(sort_mass)):
        if (i == 0):
            strings.append ("F*(x) = " + str (variables_to_show[i]) + " \t при\t\t" + "x  <=  " + str (sort_mass[i]))
        else : 
            strings.append ("F*(x) = " + str(variables_to_show[i]) + "\t при \t\t" + str(sort_mass[i-1]) + " < " + " x  <=  " + str (sort_mass[i]))
            
    strings.append("F*(x) = " + str (variables_to_show[len(sort_mass)]) + "\t при \t\t" + "x  >  " + str(sort_mass[len(sort_mass)-1]))
    for i in strings:
        print (i + "\n\n")
    return variables_to_show


def params (mass,freq):
    n = len (mass)
    summ = 0
    X_v = float("{0:.4f}".format((1/n) * sum(mass)))
    for i in range (len(freq)):
        summ += ((freq[i] - X_v)**2*mass[i])
    D_v = float("{0:.4f}".format((1/n) * summ))
    Sigma_v = float("{0:.4f}".format(sqrt(D_v)))
    return (X_v,D_v,Sigma_v)

def make_plot_fx (sorted_mass,variables):
    plt.grid(axis='y',drawstyle = 'steps-post')
    plt.xlim (min(sorted_mass) -1 ,max(sorted_mass)+1)
    plt.ylim (0,1.05)
    plt.xlabel (r'$x$')
    plt.ylabel(r'$F*(x)$')
    plt.title ("График эмпирической функции распределения")
    x_mass = []
    y_mass = []
    for x in sorted_mass:
        if (x == max(sorted_mass)):
            for i in range (2):
                x_mass.append(x)
            x_mass.append(x+1)
        else:
            for i in range (2):
                x_mass.append(x)    
    for y in variables:
        if (y == 0):
            y_mass.append(y)
        else:
            for i in range(2):
                y_mass.append(y)
    plt.xticks(x_mass,rotation = 'vertical')
    plt.yticks(y_mass)
    plt.plot (x_mass,y_mass)
    plt.savefig('f_x_plot.png')
    print ("\nГрафик сохранён в директории " + str(path.abspath('f_x_plot.png')))
    plt.show ()

def make_plot_of_freq (mass_x,mass_y):
    plt.grid()
    plt.xlim (min(mass_x) -1 ,max(mass_x)+1)
    plt.ylim (0,max (mass_y)+1)
    plt.xlabel (r'$xi$')
    plt.ylabel(r'$ni$')
    plt.title ("Полигон частот")
    plt.xticks(mass_x)
    plt.yticks(mass_y)
    plt.plot (mass_x,mass_y, '-ro',markersize = 5)
    plt.savefig('freq_pol.png')
    print ("\nПолигон сохранён в директории " + str(path.abspath('freq_pol.png')))
    plt.show()  

def make_plot_of_rel_freq (mass_x,mass_y):
    plt.grid()
    plt.xlim (min(mass_x) -1 ,max(mass_x)+1)
    plt.ylim (0,max(mass_y) + 0.05)
    plt.xlabel (r'$xi$')
    plt.ylabel(r'$ni/n (wi)$')
    plt.title ("Полигон относительных частот")
    plt.plot (mass_x,mass_y, '-ro',markersize = 5)
    plt.xticks(mass_x)
    plt.yticks(mass_y)
    plt.savefig('rel_freq_pol.png')
    print ("\nПолигон сохранён в директории " + str(path.abspath('rel_freq_pol.png')))
    plt.show()  
def menu ():
    system("cls")
    print ("Выберите нужный пункт : \n")
    print ("\t1. Составление вариационного ряда и вывод его на экран\n\n"+"\t2. Составление и вывод на экран статистического ряда частот и построение полигона\n\n" + 
           "\t3. Составление и вывод на экран статистического ряда относительных частот и построение полигона\n\n"+"\t4. Нахождение эмпирической функции распределения F*(x) вывод ее на экран и построение графика\n\n"
           +"\t5. Вычисление числовых характеристик и вывод на экран полученных результатов\n\n"+"\tВведите 0 для выхода\n\n")
    mode = int(input("> "))
    sorted_mass = sort_mass(mass)
    freq_mass = freq (mass)
    rel_freq_mass = relative_freq(len(mass),freq_mass)
    if (mode == 0):
        system("cls")
        exit(0)
    elif (mode == 1):
        system ("cls")
        print ("Вариационный ряд: \n\n" + str (mass))
        print ("\n")
        system("pause")
        menu()
    elif (mode == 2):
        system("cls")
        print ("Статистический ряд частот: \n")
        print ("x  :  " + str (sorted_mass))
        print ("-------" * len(sorted_mass))
        print ("ni :  " + str (freq_mass))
        make_plot_of_freq (sorted_mass,freq_mass)
        print ("\n")
        system ("pause")
        menu ()
    elif (mode == 3):
        system("cls")
        print ("Статистический ряд относительных частот: \n")
        print ("x  :  " + str (sorted_mass))
        print ("---------" * len(sorted_mass))
        rel_freq_to_show = []
        for i in rel_freq_mass:
            i = float("{0:.4f}".format(i))
            rel_freq_to_show.append(i)
        print ("wi :  " + str (rel_freq_to_show))
        make_plot_of_rel_freq(sorted_mass,rel_freq_to_show)
        print ("\n")
        system ("pause")
        menu ()
    elif (mode == 4):
        system("cls")
        print ("Эмпирическая функция распределения F*(x) :\n")
        variables_show = F_x(sorted_mass,rel_freq_mass)
        make_plot_fx(sorted_mass,variables_show)
        print ("\n")
        system ("pause")
        menu ()
    elif (mode == 5):
        system ("cls")
        print ("Числовые характеристики : \n")
        parameters = params(mass,freq_mass)
        print ("\tX_v = " + str(parameters[0]) + "\n")
        print ("\tD_v = " + str(parameters[1]) + "\n")
        print ("\tSigma_v = " + str(parameters[2]) + "\n")
        print ("\n")
        system ("pause")
        menu ()


mass = input_var()
mass.sort()
menu()













