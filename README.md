#How to build Server/Client 

1.) Open 2 seperate terminal windows. 
	- 1 for Server, cd to ServerSide folder
	- 1 for Clients, cd to Clientside Folder
2.) Run Server first:
	- $./server <port> <ip Address>
	- ie:  $./server 9999 localhost
3.) Run Client(s) following it:
	- For the amount of clients you want to run, do:
		- $./client <txtfile name> <port> <ip Address>
		- ie for 1 client: 	$./client varTxt.txt 9999 localhost
		- ie for multiple clients: 
			-$./client varTxt.txt 9999 localhost; ./client varTxt2.txt 9999 localhost; ./client varTxt3.txt 9999 localhost
4.) To exit Server, do Cntrl+ C to exit.

