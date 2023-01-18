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
                if i == '0':
                    i = '1'
                # if i == '0':
                #     i='1'
                cad = cad+i
    w = open("salida.txt", "w")
    for i in mylist:
        w.write("          if [ $nombre_servicio == \"{}\" ] \n          then\n          /root/dockers/{}/levanta_{}.sh\n          fi\n".format(i,i,i[4:-3]))
    w.close()

if __name__ == '__main__':
    run()