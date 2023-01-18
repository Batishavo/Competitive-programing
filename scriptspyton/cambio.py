
def run():
    f = open('entrada.txt', 'r')
    file_data = f.read()
    f.close()
    #print(file_data)
    cad=""
    mylist=[]
    # print(file_data)
    for i in file_data:
        # print(i,"---")
        if i == '0':
            i='1'
        elif i == '4':
            i='5'
        cad=cad+i
    w = open("salida.txt", "w")
    w.write(cad)
    w.close()

if __name__ == '__main__':
    run()