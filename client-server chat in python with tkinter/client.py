#**********MESSENGER**********#

import sys
import socket
from tkinter import *

window = Tk()
window.geometry('500x500+450+10')
window.title('CLIENT')

var = IntVar()
t1 = StringVar()
t2 = StringVar()
t3 = StringVar()
t4 = StringVar()
frame = Frame(window).pack()

def login_signup():
    cb.destroy()
    global l0
    l0 = Label(frame,text='messenger', fg='blue', font=('Viner Hand ITC',30,'bold'))
    # login code
    global l1
    l1 = Label(frame,text='User Name')
    global l2
    l2 = Label(frame,text='Password')
    global l3
    l3 = Label(frame,text='Existing Account?', fg='red', font=('italic',8,'bold'))
    global e1
    e1= Entry(frame, text=t1)
    global e2
    e2= Entry(frame, text=t2, show="*")
    global b1
    b1=Button(frame,text='Log In',command=verification,fg='white',bg='dark blue',width=6,font=('Arial',10,'bold'))
    
    l0.place(x=150, y=10)
    l3.place(x=70, y=110)
    l1.place(x=70, y=150)
    e1.place(x=70, y=170)
    l2.place(x=70, y=200)
    e2.place(x=70, y=220)
    b1.place(x=135, y=250)
    
    # signup code
    global l4
    l4 = Label(frame,text='Create New Account?', fg='red', font=('italic',8,'bold'))
    global l5
    l5 = Label(frame,text='New User Name')
    global l6
    l6 = Label(frame,text='New Password')
    global e3
    e3 = Entry(frame, text=t3)
    global e4
    e4 = Entry(frame, text=t4, show="*")
    global b2
    b2 = Button(frame,text='Sign Up',command=createAccount,fg='white',bg='dark blue',width=6,font=('Arial',10,'bold'))

    l4.place(x=300, y=110)
    l5.place(x=300, y=150)
    e3.place(x=300, y=170)
    l6.place(x=300, y=200)
    e4.place(x=300, y=220)
    b2.place(x=365, y=250)
    return

def createAccount():
    l0.destroy()
    l1.destroy()
    l2.destroy()
    l3.destroy()
    l4.destroy()
    l5.destroy()
    l6.destroy()
    e1.destroy()
    e2.destroy()
    e3.destroy()
    e4.destroy()
    b1.destroy()
    b2.destroy()
    
    name = t3.get()
    password = t4.get()
    
    # accounts file opens in append mode
    accounts = open('accounts.txt','a')
    accounts.write(name)
    accounts.write('\n')
    accounts.write(password)
    accounts.write('\n')
    accounts.close()
    
    print ('Account created')
    client_program()
    return

def verification():
    l0.destroy()
    l1.destroy()
    l2.destroy()
    l3.destroy()
    l4.destroy()
    l5.destroy()
    l6.destroy()
    e1.destroy()
    e2.destroy()
    e3.destroy()
    e4.destroy()
    b1.destroy()
    b2.destroy()
    
    name = t1.get()
    password = t2.get()

    # accounts file opens in read mode
    accounts = open('accounts.txt','r')
    accountslist = accounts.read().splitlines()
    for i in range(len(accountslist)):
        if accountslist[i]==name:
            if accountslist[i+1]==password:
                print ('Account Verified')
                accounts.close()
                client_program()
                return
    print ('Account Does Not Exists.')
    accounts.close()
    login_signup()
    return

def show(who, msg2):
    if who=="client":
        msg1 = instring.get()
        my_label02 = Label(window,text=msg1, fg='blue', font=('Arial',14))
        my_label02.pack(side=TOP, anchor=E)
        var.set(1)
    elif who=="server":
        my_label03 = Label(window,text=msg2, fg='black', font=('Arial',14))
        my_label03.pack(side=TOP, anchor=W)
    return

def Exit():
    window.destroy()
    exit()

################ client code ################

def client_program():
    host = socket.gethostname()  # as both code is running on same pc
    port = 8888  # socket server port number
    
    client_socket = socket.socket()  # instantiate
    client_socket.connect((host, port))  # connect to the server
    
    while True: #message.lower().strip() != 'bye':
        # take input from client
        global instring
        instring = StringVar()
        label = Label(window,text='Write Message Here', font=('Arial',10,'bold'))
        entry = Entry(window, text=instring, width=40)
        button = Button(window, text='send', command=lambda: show("client", ""), fg='white', bg='black', width=6, font=('Arial',10,'bold'))
        button.pack(side=BOTTOM)
        entry.pack(side=BOTTOM)
        label.pack(side=BOTTOM)
        
        button.wait_variable(var)  # waite until button is pressed
        button.destroy()
        entry.destroy()
        label.destroy()
        message = instring.get()
        var.set(0)
        
        client_socket.send(message.encode())  # send message
        data = client_socket.recv(1024) #.decode()  # receive response
        show("server", data)    # show in GUI window
        
    client_socket.close()  # close the connection
    return


b0=Button(window,text='X',command=Exit, fg='white',bg='red',width=6,font=('Arial',10,'bold'))
b0.place(x=315, y=473)
global cb
cb = Button(window, text='Client', command= login_signup, fg='black', bg='green', width=6, font=('Arial',20,'bold'))
cb.place(x=200, y=100)

window.mainloop()




















