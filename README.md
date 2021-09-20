# Advanced Programming 1 - 3th assignment
![Alt Text](https://github.com/ashkan-nasirzadeh/simpleShell/blob/master/README%20assets/shell-gif.gif)
![Alt Text](https:/media/giphy.com/embed/U16eJ5dFcfiolA5u85)
![Alt Text](https://giphy.com/gifs/dsO8D6Qf1brrO)

![Alt Text](https://media.giphy.com/media/vFKqnCdLPNOKc/giphy.gif)
## Overview
In this exercise we implemented a more realistic server and client than we did in Milestone 2, among other things we used parallelism. That is, we allowed receipt of more than one customer.
When a client logs in,
A text menu that the server sent will appear and through which the interaction between the server and the client will take place:
Classification, updating parameters of the algorithm and more ...
The server can handle multiple clients simultaneously.
## <a href="https://he.wikipedia.org/wiki/%D7%A4%D7%95%D7%A8%D7%98_(%D7%AA%D7%A7%D7%A9%D7%95%D7%A8%D7%AA)">Ports</a>, buffer and <a href="https://he.wikipedia.org/wiki/Internet_Protocol">IP's</a>
TCP server port: 50000
Clients port: Provided randomly by computer
Clients IP: 127.0.0.1
Buffer size: 4096 byte's 
## UML
![image](https://user-images.githubusercontent.com/88191199/134019688-994adeb0-a895-41ab-8221-8f1340802a4f.png)
![image](https://user-images.githubusercontent.com/88191199/134021475-f7fb878d-cea7-4709-b943-a2a361f0c53c.png)
![image](https://user-images.githubusercontent.com/88191199/134023445-0b1d636f-7944-4bc6-997e-3a1fd68d000d.png)
## Assingment's Requirements
The client will receive a menu from the server and will have to choose which task he wants the server to perform,
by pressing one of the following keys on the keyboard:
```diff
- 1 = upload an unclassified csv data file.
- 2 = algorithm settings.
- 3 = classify data.
- 4 = display results.
- 5 = download results.
- 6 = display algorithmconfusion matrix.
- 7 = exit.
```
![image](https://user-images.githubusercontent.com/88191199/134007506-0300f4c0-9685-4da1-b439-97c863107bd4.png)
> note that there are tasks that require interaction with the server.
 

## General Instructions
You can find all the required files under `Develop branch`.
In order to run the project you need to use the `CMakeLists.txt` - which we provided to you and exsists under Develop branch. <br/>
After building the project using the CMake file, you will have to run the project in 2 or more <ins>differents</ins> terminals (server before the clients) using these commands:
```ruby
    ./runServer
```
```ruby
    ./runClient
```
