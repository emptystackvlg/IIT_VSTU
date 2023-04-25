from os import system
def main ():
    system ("cls")
    path = str(input ("Укажите путь к файлу\n> "))
    mass = []
    try:
        with open(path,"r") as file:
            lines = file.readlines()
            for line in lines: 
                read_line = [float(x) for x in line.split()]
                mass.append(read_line)
            for i in range (len(mass)):
                print ("i = " + str(i))
                for j in mass[i] :
                    print (j,sep=" ")
    except FileNotFoundError:
        print ("Файл не найден")
        system("pause")
        main()

main ()