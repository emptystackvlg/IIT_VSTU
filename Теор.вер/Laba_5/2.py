from colorama import Fore,Back,Style
from easygui import fileopenbox
import matplotlib.pyplot as plt
from os import system
from math import sqrt,fabs,log10,floor

def input_var () -> list:
    system("cls")
    path = fileopenbox (msg = "Выберите файл с данными")
    temp_mass = []
    main_mass = []
    with open(path, "r") as file:
        lines = file.readlines()
        for line in lines: 
            read_line = [float(x) for x in line.split()]
            temp_mass.append(read_line)
        for i in range (len(temp_mass)):
            for j in temp_mass[i] :
                main_mass.append(j)
    return (main_mass)

def make_intervals (main_mass) -> dict:
    intervals = {}
    x_min = min(main_mass)
    x_max = max(main_mass)
    k = 1 + 3.322 * log10(len(main_mass))
    k = floor(k)
    print ("Оптимальное количество интервалов : " + str(k) + "\n")
    num_of_intervals = float (input("Введите количество интервалов\n> "))
    global h
    h = (x_max - x_min)/num_of_intervals
    if (h >= 0.5):  
        dh = fabs(float ((round(h) - h)))
        dh *= num_of_intervals
        dh = (float("{0:.4f}".format(dh)))
        dh /= 2
        h = round (h)
        if (dh == 0):
            h += 0.001
    else :
        h = round(h,4)
        h += 0.001   
        dh = 0 
    current_x = float ("{0:.4f}".format (x_min - dh))
    for i in range (int (num_of_intervals)):
        intervals [i] = [float ("{0:.4f}".format(current_x)) + float("{0:.4f}".format(h*i)),float ("{0:.4f}".format(current_x)) + float("{0:.4f}".format(h*(i+1)))]
    return intervals

def intervals_freq (main_mass,intervals) -> list:
    freq_intervals = []
    for key in intervals.keys():
        ni = 0 
        for var in main_mass:
            if (intervals[key][0]<= var <intervals[key][1]):
                ni += 1
        freq_intervals.append (ni) 
    if (sum (freq_intervals) == len (main_mass)):
        return freq_intervals            
    else :
        print ("Ошибка, сумма ni != n")
        exit(0)
def relative_freq (mass_of_ni, count_n) -> list:
    rel_freq = []
    for ni in mass_of_ni:
        ni /= count_n
        rel_freq.append (float("{0:.4f}".format(ni)))
    return rel_freq

def mid_of_intervals (intervals) -> list:
    mid = []
    for key in intervals.keys():
        ci = sum(intervals[key]) / 2
        mid.append (ci)
    return mid

def params (mass_of_ni,mid,n) -> list:
    x_v = 1 
    summ = 0
    for i in range (len(mass_of_ni)):
        summ += mass_of_ni [i] * mid[i]
    x_v = float("{0:.3f}".format(summ/n))
    summ = 0
    for i in range (len(mass_of_ni)):
        summ += mass_of_ni[i] * ((mid[i] - x_v)**2)
    d_v = float("{0:.3f}".format(summ/len (mass_of_ni)))
    Sigma_v = float("{0:.3f}".format(sqrt (d_v)))
    parametrs = [x_v, d_v,Sigma_v]
    return parametrs

def F_x (intervals,rel_freq) -> list:
    variables = []
    interval = []
    for value in intervals.values():
        for i in range (2):
            interval.append (value[i])
    sorted_intervals = []
    for i in interval:
        if (i not in sorted_intervals):
            sorted_intervals.append(i)

    for i in range (len(rel_freq)):
            summ = 0 
            for j in range (i+1):
                summ += rel_freq[j]
            variables.append(float("{0:.4f}".format(summ)))

    for i in range (len(rel_freq)):
        print (" Номер интервала : " + str(i+1) + "\n Интервал : [ " + str (sorted_intervals[i]) + " ; " + str (sorted_intervals[i+1]) + " )")
        print (" Относительная частота : " + str (rel_freq[i]) + "\n Накопленная относительная частота : " + str(variables[i]))
        print ("\n")
    return (sorted_intervals,variables)

def F_x_group (mids,rel_freq) -> list:
    variables = []
    for i in range (len(rel_freq)):
            
            summ = 0 
            for j in range (i+1):
                summ += rel_freq[j]
            variables.append (summ)

    for i in range (len(rel_freq)):
        print (" Номер интервала : " + str(i+1) + "\n Середина интервала : " + str (mids[i]))
        print (" Относительная частота : " + str (rel_freq[i]) + "\n Накопленная относительная частота : " + str(variables[i]))
        print ("\n")
    return variables

def plot_of_fx (sorted_intervals,variables):
    variables.insert (0,0)
    plt.grid()
    plt.xticks(sorted_intervals,rotation = 'vertical')
    plt.yticks(variables)
    plt.xlabel (r'$x$')
    plt.ylabel(r'$F*(x)$')
    plt.title ("График эмпирической функции распределения\nдля интервального ряда")
    plt.ylim(0,1.05)
    plt.plot (sorted_intervals,variables,'-bo')
    plt.show()


def plot_of_fx_group (mids,variables):
    plt.grid()
    plt.xticks(mids,rotation = 'vertical')
    plt.yticks(variables)
    plt.xlabel (r'$x$')
    plt.ylabel(r'$F*(x)$')
    plt.title ("График эмпирической функции распределения\nдля группированного ряда")
    plt.ylim(0,1.05)
    plt.plot (mids,variables,'-ro')
    plt.show()



def hyst_of_freq (x,intervals):
    interval = []
    for value in intervals.values():
        for i in range (2):
            interval.append (value[i])
    sorted_intervals = []
    for i in interval:
        if (i not in sorted_intervals):
            sorted_intervals.append(i)
    if (min(sorted_intervals) >= 0):
        plt.xlim (min(sorted_intervals) - 1,max(sorted_intervals) + 1)
    else :
        plt.xlim (min(sorted_intervals) - 1,max(sorted_intervals) + 1)
    nh = []
    for n in x:
        nh.append(float("{0:.3f}".format(n/h)))
    mass_x = []
    for x in sorted_intervals:
        if (x == sorted_intervals[0]) :
            for j in range (2):
                mass_x.append(x)
        else:
            for j in range (3):
                mass_x.append(x)
    mass_x.pop()
    mass_y = []
    mass_y.append(0)
    for y in nh:
        for i in range (2):
            mass_y.append(y)
        mass_y.append(0)
    if (min(sorted_intervals) >= 0):
        plt.xlim (min(sorted_intervals) - 0.5,max(sorted_intervals) + 0.5)
    else :
        plt.xlim (min(sorted_intervals) -0.5,max(sorted_intervals) + 0.5)
    plt.grid(axis='y')
    plt.title ("Гистограмма частот")
    plt.xticks(sorted_intervals,rotation = 'vertical')
    plt.yticks(nh)
    plt.xlabel(r'$x$')
    plt.ylabel(r'$ni/h$')
    plt.ylim (0,max(nh) + 5)
    plt.plot (mass_x,mass_y,'r')
    plt.show()

def hyst_of_rel_freq (freq_y,intervals):
    interval = []
    for value in intervals.values():
        for i in range (2):
            interval.append (value[i])
    sorted_intervals = []
    for i in interval:
        if (i not in sorted_intervals):
            sorted_intervals.append(i)
    mass_x = []
    for x in sorted_intervals:
        if (x == sorted_intervals[0]) :
            for j in range (2):
                mass_x.append(x)
        else:
            for j in range (3):
                mass_x.append(x)
    mass_x.pop()
    mass_y = []
    mass_y.append(0)
    for y in freq_y:
        for i in range (2):
            mass_y.append(float("{0:.3f}".format(y/h)))
        mass_y.append(0)
    y_to_plot = []
    for yp in freq_y:
        y_to_plot.append(float("{0:.3f}".format(yp/h)))
    if (min(sorted_intervals) >= 0):
        plt.xlim (min(sorted_intervals) - 1,max(sorted_intervals) + 1)
    else :
        plt.xlim (min(sorted_intervals) -1,max(sorted_intervals) + 1)
    plt.grid(axis='y')
    plt.title ("Гистограмма относительных частот")
    plt.xlabel(r'$x$')
    plt.ylabel(r'$wi/h$')
    plt.xticks(sorted_intervals,rotation = 'vertical')
    plt.yticks(y_to_plot)
    plt.ylim (0,max(mass_y)+ 0.1)
    plt.plot (mass_x,mass_y)
    plt.show()


def polygon_of_freq(mids,freq):
    plt.grid()
    plt.title ("Полигон распределения частот")
    plt.xlabel(r'$xc$')
    plt.ylabel(r'$ni$')
    plt.xticks(mids,rotation = 'vertical')
    plt.yticks(freq)
    plt.ylim (0,max(freq)+ 1)
    plt.xlim (min(mids) - 1,max(mids) + 1)
    plt.plot (mids,freq,'-ro')
    plt.show()

def polygon_of_rel_freq (mids,rel_freq):
    plt.grid()
    plt.title ("Полигон распределения относительных частот")
    plt.xlabel(r'$xc$')
    plt.ylabel(r'$wi$')
    plt.xticks(mids,rotation = 'vertical')
    plt.yticks(rel_freq)
    plt.ylim (0,max(rel_freq)+ 0.1)
    plt.xlim (min(mids) - 1,max(mids) + 1)
    plt.plot (mids,rel_freq,'-ro')
    plt.show()




main_mass = input_var()
main_mass.sort()
intervals = make_intervals(main_mass)

def menu():
    system("cls")
    print ("Выберите нужный пункт : \n")
    print ("\t1. Вывод введенной информации на экран\n\n"+"\t2. Составление и вывод на экран интервального ряда частот и относительных частот, построение гистограмм\n\n" + 
           "\t3. Составление и вывод на экран группированного ряда частот и относительных частот, построение полигонов\n\n"+"\t4. Нахождение эмпирической функции распределения F*(x) для интервального ряда вывод ее на экран и построение графика\n\n"
           +"\t5. Нахождение эмпирической функции распределения F*(x) для группированного ряда вывод ее на экран и построение графика\n\n"+"\t6. Вычисление числовых характеристик и вывод на экран полученных результатов\n\n"+"\tВведите 0 для выхода\n\n")
    mode = int(input("> "))
    interval = []
    for value in intervals.values():
        for i in range (2):
            interval.append (value[i])
    sorted_intervals = []
    for i in interval:
        if (i not in sorted_intervals):
            sorted_intervals.append(i)

    mass_freq = intervals_freq (main_mass,intervals)
    mass_rel_freq = relative_freq(mass_freq,len(main_mass))
    mids = mid_of_intervals(intervals)
    if (mode == 0):
        system("cls")
        exit(0)
    elif (mode == 1):
        system ("cls")
        print (" Вариационный ряд: \n\n\t" + str (main_mass))
        print ("\n")
        print (" Интервалы: \n")
        for i in range (len(intervals.values())):
            print (" Номер интервала : " + str(i+1) + "\n Интервал : [ " + str (sorted_intervals[i]) + " ; " + str (sorted_intervals[i+1]) + " )\n")
        system("pause")
        menu()
    elif (mode == 2):
        system ("cls")
        print (" Интервальный ряд частот : \n")
        for i in range (len(intervals.values())):
            print (" Номер интервала : " + str(i+1) + "\n Интервал : [ " + str (sorted_intervals[i]) + " ; " + str (sorted_intervals[i+1]) + " )\n")
            print (" Частота : " + str (mass_freq[i]) + "\n")
        hyst_of_freq(mass_freq,intervals)
        system("pause")
        system("cls")
        print (" Интервальный ряд относительных частот : \n")
        for i in range (len(intervals.values())):
            print (" Номер интервала : " + str(i+1) + "\n Интервал : [ " + str (sorted_intervals[i]) + " ; " + str (sorted_intervals[i+1]) + " )\n")
            print (" Относительная частота : " + str (mass_rel_freq[i]) + "\n")
        hyst_of_rel_freq(mass_rel_freq,intervals)
        system ("pause")
        menu()
    elif (mode == 3):
        system ("cls")
        print (" Группированный ряд распределения частот : \n")
        for i in range (len(intervals.values())):
            print (" Номер интервала : " + str(i+1) + "\n Середина интервала : " + str (mids[i] )+ "\n")
            print (" Частота : " + str (mass_freq[i]) + "\n")
        polygon_of_freq(mids,mass_freq)
        system("pause")
        system("cls")
        print (" Группированный ряд распределения относительных частот : \n")
        for i in range (len(intervals.values())):
            print (" Номер интервала : " + str(i+1) + "\n Середина интервала : " + str (mids[i] )+ "\n")
            print (" Относительная частота : " + str (mass_freq[i]) + "\n")
        polygon_of_rel_freq(mids,mass_rel_freq)
        system ("pause")
        menu()
    elif (mode == 4):
        system ("cls")
        print (" Эмпирическая функция распределения для интервального ряда : \n")
        data_to_plot = F_x (intervals,mass_rel_freq)
        plot_of_fx(data_to_plot[0],data_to_plot[1])
        print ("\n")
        system("pause")
        menu()
    elif (mode == 5) :
        system ("cls")
        print (" Эмпирическая функция распределения для группированного ряда : \n")
        vars = F_x_group(mids,mass_rel_freq)
        plot_of_fx_group (mids,vars)
        print ("\n")
        system("pause")
        menu ()
    elif (mode == 6):
        system("cls")
        parameters = params(mass_freq,mids,len(main_mass))
        print (" Числовые параметры выборки : \n")
        print ("\tX_v = " + str(parameters[0]) + "\n")
        print ("\tD_v = " + str(parameters[1]) + "\n")
        print ("\tSigma_v = " + str(parameters[2]) + "\n")
        print ("\n")
        system ("pause")
        menu ()
menu()  