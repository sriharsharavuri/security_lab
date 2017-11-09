import socket

clientsocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
host = socket.gethostname()
port = 19988
clientsocket.connect((host, port))
msg = clientsocket.recv(1024)

print("Message from server %s " % str(msg))