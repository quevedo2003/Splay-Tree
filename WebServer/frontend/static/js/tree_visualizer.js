
const treeWidth = document.body.clientWidth;
const treeHeight = window.innerHeight;
const horizontalMargins = 50;
const treeLayout = d3.tree().size([treeHeight, treeWidth - 100]);

const svg = d3.select('#tree-container').append('svg')
    .attr('width', treeWidth)
    .attr('height', treeHeight)
    .append('g')
    .attr('transform', `translate(50 , 0)`);



function getTreeData() {
    fetch('/get_tree')
    .then(response => response.json())
    .then(treeData => visualizeTree(treeData));
}


function visualizeTree(treeData){

    const root = d3.hierarchy(treeData);
    const treeNodes = treeLayout(root);

    svg.selectAll('.link')
        .data(treeNodes.links())
        .enter().append('path')
        .attr('class', 'link')
        .attr('d', d3.linkVertical()
            .x(d => d.x)
            .y(d => d.y))
        .style('stroke-width', 1)
        .style('stroke', 'blue');

    const nodes = svg.selectAll('.node')
        .data(treeNodes.descendants())
        .enter().append('g')
        .attr('class','node')
        .attr('transform', d => `translate(${d.y},${d.x})`);
    
    nodes.append('circle')
        .attr('r', 10);
        nodes.append('text')
            .attr('dy', -10)
            .style('text-anchor', 'middle')
            .text(d => d.data.name)
}

document.addEventListener('DOMContentLoaded', getTreeData);