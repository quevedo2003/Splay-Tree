from flask import Flask, render_template, jsonify, request
import requests

app = Flask(__name__)

@app.route('/')  #defines homepage route when accessed html file is rendered
def index():
    return render_template('index.html')

@app.route('/get_tree')  #route to fetch tree data from backend server
def get_tree():
    response = requests.get('http://localhost:8080/get_tree') 
    tree_data = response.json() #parse the JSON response from the backend server
    return jsonify(tree_data) #returns the json response to 

# @app.route('/search_tree')
# def search_tree():
#     query = request.args.get('query')
#     response = requests.get(f'http://localhost:8080/search_tree?query={query}')
#     tree_data = response.json()
#     return jsonify(tree_data)
    

#Run flask if script is executed
if __name__ == '__main__':
    app.run(host="localhost",port=8000,debug=True) #frontend server running on localhost:8000