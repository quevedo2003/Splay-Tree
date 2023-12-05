# Splay-Tree
`212 Final Project`
All code for final project

The project is divided into Class and WebServer. The Class files dealing with the splay tree creation, implementation, and testing, while the WebServer deals with the front end and back end development of the website.

# Class
To see the implemntation of the tree go to the testcases directory and compile the cpp file to see the outputs on the command line.

# WebServer
To run the webserver follow these steps below:
1) Install Flask:
    On mac: brew install python
            pip install Flask
            pip install requests
    On linux: dnf install python3
              pip3 install Flask
              pip3 install requests
2) Compile backend-server:
   cd into the backend directory
   g++ -std=c++11 splay_tree.cpp backend_server.cpp -o <name of executable>
3) Run backend-server: 
    ./<name of executable>
4) Run frontend-server
   cd into the frontend directory
   python3 frontend-server.py

Based on current configuration, website will be accessible at "localhost:8000"
