
Program 
/*Server*/ 
#include<sys/types.h> 
#include<sys/socket.h> 
#include<netinet/in.h> 
#include<sys/stat.h> 
#include<unistd.h> 
#include<stdlib.h> 
#include<stdio.h> 
#include<fcntl.h> 

int main() 
{ 
int cont,create_socket,new_socket,addrlen,fd; 
int bufsize = 1024; 
char *buffer = malloc(bufsize); 
char fname[256]; 
struct sockaddr_in address; 
if ((create_socket = socket(AF_INET,SOCK_STREAM,0)) > 0) 
printf("The socket was created\n"); 
address.sin_family = AF_INET; 
address.sin_addr.s_addr = INADDR_ANY; 
address.sin_port = htons(15000); 
if (bind(create_socket,(struct sockaddr *)&address,sizeof(address)) == 0) printf("Binding Socket\n"); 
listen(create_socket,3); 
addrlen = sizeof(struct sockaddr_in); 
new_socket = accept(create_socket,(struct sockaddr *)&address,&addrlen); 
if (new_socket > 0) 
printf("The Client %s is Connected...\n", 
inet_ntoa(address.sin_addr)); 
recv(new_socket,fname, 255,0); 
printf("A request for filename %s Received..\n", fname); 
if ((fd=open(fname, O_RDONLY))<0) 
{perror("File Open Failed"); exit(0);} 
while((cont=read(fd, buffer, bufsize))>0) { 
send(new_socket,buffer,cont,0); 
} 
printf("Request Completed\n"); 
close(new_socket); 
return close(create_socket); 
}  
/*Client*/ 

#include<sys/socket.h> 
#include<sys/types.h> 
#include<netinet/in.h> 
#include<unistd.h> 
#include<stdlib.h> 
#include<stdio.h> 
int main(int argc,char *argv[]) 
{ 
int create_socket; 
int bufsize = 1024; 
char *buffer = malloc(bufsize); 
char fname[256]; 
struct sockaddr_in address; 
if ((create_socket = socket(AF_INET,SOCK_STREAM,0)) > 0) 
printf("The Socket was created\n"); 
address.sin_family = AF_INET; 
address.sin_port = htons(15000); 
inet_pton(AF_INET,argv[1],&address.sin_addr); 
if (connect(create_socket,(struct sockaddr *) &address, 
sizeof(address)) == 0) 
printf("The connection was accepted with the server %s...\n", 
argv[1]); 
printf("Enter The Filename to Request : "); scanf("%s",fname); 
send(create_socket, fname, sizeof(fname), 0); 
printf("Request Accepted... Receiving File...\n\n"); 
printf("The contents of file are...\n\n"); 
while((cont=recv(create_socket, buffer, bufsize, 0))>0) { 
write(1, buffer, cont);
} 
printf("\nEOF\n"); 
return close(create_socket); 
} 
 Output (Server) 
[root@localhost CN Lab] ./s.o 
Socket Created.. 
Binding Socket.. 
Now Listening for Request.. 
The Client 127.0.0.1 is trying to connect… 
A request for filename alpha received.. 
Requested completed.. 
[root@localhost CN Lab] 
Output (Client) 
[root@localhost CN Lab] ./c.o 127.0.0.1 
Socket Created.. 
Connetion is accepted by 127.0.0.1 .. 
Enter File Name to Request : alpha 
Requestion for file alpha.. Request accepted. Receiving file…

The contents of file are :- 
This a demo of client server using Sockets 
Just for trial. 
Now End of file
EOF
