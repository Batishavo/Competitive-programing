def run():
    f = open('entrada.txt', 'r')
    file_data = f.read()
    f.close()
    #print(file_data)
    cad=""
    flag=False
    mylist=[]
    for i in file_data:
        #print(i,"\n")
        if i == '\"':
            #print("entra \n",i)
            if flag == True :
                mylist.append(cad)
            #print(cad,"\n")  
            cad=""
            flag = not flag
        else: 
            if flag == True :
                # if i == '':
                #     i = '8'
                # if i == '0':
                #     i='1'
                cad = cad+i
    num=766
    w = open("salida.txt", "w")
    for i in mylist:
        w.write("          echo \"{}) {}\"\n".format(num, i) )
        num = num + 1
    w.close()

if __name__ == '__main__':
    run()