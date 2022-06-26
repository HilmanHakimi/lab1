import socket

ClientSocket = socket.socket()
host = '192.168.56.102'
port = 8889

print('Waiting for connection..')
try:
    ClientSocket.connect((host, port))
except socket.error as e:
    print(str(e))

Response = ClientSocket.recv(1024)
print(Response)

while True:
        file_name = input(str("Please enter a file name for the incoming file:"))
        file = open(file_name , 'wb')
        file_data = ClientSocket.recv(1024)
        file.write(file_data)
        file.close()
        print("File has been received successfully...")

ClientSocket.close()
