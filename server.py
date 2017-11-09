# Server
import socket
import time

serversocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
host = socket.gethostname()
port = 19988
serversocket.setsockopt(socket.SOL_SOCKET,socket.SO_REUSEADDR, 1)
serversocket.bind((host, port))
serversocket.listen(5)
while True:
	clientsocket, addr = serversocket.accept()
	print("Got a connection from %s " % str(addr))
	clientsocket.send(b"Thank you for connecting \n")
	clientsocket.close()