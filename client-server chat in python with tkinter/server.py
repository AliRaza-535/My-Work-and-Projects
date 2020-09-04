import sys
import socket
from tkinter import *

window = Tk()
window.geometry('500x500+200+10')
window.title('SERVER')

var = IntVar()

def show(who,msg2):
    if who=="server":
        msg1 = instring.get()
        my_label03 = Label(window,text=msg1, fg='blue', font=('Arial',14))
        my_label03.pack(side=TOP, anchor=E)
        var.set(1)
    elif who=="client":
        my_label02 = Label(window,text=msg2, fg='black', font=('Arial',14))
        my_label02.pack(side=TOP, anchor=W)
    return

def Exit():
    window.destroy()
    exit()

################ server code ################
def server_program():
    host = socket.gethostname() # get the hostname
    port = 8888  # initiate port no above 1024

    server_socket = socket.socket()  # get instance
    # look closely. The bind() function takes tuple as argument
    server_socket.bind((host, port))  # bind host address and port together

    # configure how many client the server can listen simultaneously
    server_socket.listen(2)
    conn, address = server_socket.accept()  # accept new connection
    print("Connection from: " + str(address))
    sb.destroy()
    
    while True:
        # receive data stream. it won't accept data packet greater than 1024 bytes
        data = conn.recv(1024)#.decode()
        if not data:
            # if data is not received break
            break
        show("client", data)    # from connected user
        
        # take input from server
        global instring
        instring = StringVar()
        label = Label(window,text='Write Message Here', font=('Arial',10,'bold'))
        entry = Entry(window, text=instring, width=40)
        button = Button(window, text='send', command=lambda: show("server", ""), fg='white', bg='black', width=6, font=('Arial',10,'bold'))
        button.pack(side=BOTTOM)
        entry.pack(side=BOTTOM)
        label.pack(side=BOTTOM)
        
        button.wait_variable(var)  # waite until button is pressed
        button.destroy()
        entry.destroy()
        label.destroy()
        message = instring.get()
        var.set(0)
        conn.send(message.encode())  # send data to the client
        
    conn.close()  # close the connection
    return


b0=Button(window,text='X',command=Exit, fg='white',bg='red',width=6,font=('Arial',10,'bold'))
b0.place(x=315, y=473)
global sb
sb = Button(window, text='Server', command= server_program, fg='white', bg='black', width=6, font=('Arial',20,'bold'))
sb.place(x=200, y=150)

window.mainloop()













