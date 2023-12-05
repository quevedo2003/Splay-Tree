from flask import Flask, render_template, jsonify, request
from flask_cors import CORS
import requests

app = Flask(__name__)
CORS(app)

@app.route('/')  #defines homepage route when accessed html file is rendered
def index():
    return render_template('index.html')

@app.route('/get_tree')  #route to fetch tree data from backend server
def get_tree():
    response = requests.get('http://localhost:8080/get_tree') 
    tree_data = response.json() #parse the JSON response from the backend server
    return jsonify(tree_data) #returns the json response to 

@app.route('/search_tree')
def search_tree():
    try:
        query = request.args.get('query')
        response = requests.get(f'http://localhost:8080/search_tree?query={query}')
        response.raise_for_status()  # Check for HTTP errors
        tree_data = response.json()
        return jsonify(tree_data)
    except requests.exceptions.RequestException as e:
        print(f"Error in search_tree endpoint: {e}")
        return jsonify(error=str(e)), 500  # Internal Server Error
    

#Run flask if script is executed
if __name__ == '__main__':
    app.run(host="localhost",port=8000,debug=True) #frontend server running on localhost:8000