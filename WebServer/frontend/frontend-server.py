from flask import Flask, render_template, jsonify
import requests

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/get_tree')
def get_tree():
    response = requests.get('http://localhost:8080/get_tree')
    tree_data = response.json()
    return jsonify(tree_data)

if __name__ == '__main__':
    app.run(host="localhost",port=8000,debug=True)