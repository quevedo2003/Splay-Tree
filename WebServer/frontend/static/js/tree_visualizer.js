
const treeWidth = 500;
const treeHeight = 500;

const svg = d3.select('#tree-container').append('svg')
    .attr('width', treeWidth)
    .attr('height', treeHeight)
    .append('g')



function getTreeData() {
    let response = fetch('/get_tree');
    let treeData = response.json();
    visualizeTree(treeData);
}

const root = d3.hierarchy(treeData);



function visualizeTree(treedata){



}















getTreeData();