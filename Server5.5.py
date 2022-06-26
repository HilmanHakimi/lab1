import socket
import os
from _thread import *

ServerSocket = socket.socket()
host = ''
port = 8889
ThreadCount = 0
try:
        ServerSocket.bind((host, port))

except socket.error as e:
        print(str(e))

print('Waiting for a Connection..')
ServerSocket.listen(5)

def threaded_client(connection):
        connection.send(str.encode('Welcome to the Server\n'))

        while True:
                file_name = input(str("Please enter the file name of the file:"))
                file = open(file_name , 'rb')
                file_data = file.read(1024)
                connection.send(file_data)
                print("Data has been transmitted successfully...")
                if not data:
                        break
                connection.sendall(str.encode(reply))
        connection.close()

while True:
    Client, address = ServerSocket.accept()
    print('Connected to: ' + address[0] + ':' + str(address[1]))
    start_new_thread(threaded_client, (Client, ))
    ThreadCount += 1
    print('Thread Number: ' + str(ThreadCount))

ServerSocket.close()
