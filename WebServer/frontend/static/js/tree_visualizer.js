
const treeWidth = document.body.clientWidth;
const treeHeight = window.innerHeight;
const treeLayout = d3.tree().size([treeWidth,treeHeight]);

const svg = d3.select('#tree-container').append('svg')
    .attr('width', treeWidth)
    .attr('height', treeHeight)
    .append('g')



function getTreeData() {
    fetch('/get_tree')
    .then(response => {
        return response.json();
    })
    .then(treeData => {
        console.log(treeData);
        visualizeTree(treeData);
    })
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
        .style('stroke-width', 1);

    svg.selectAll('.node')
        .data(treeNodes.descendants())
        .enter().append('circle')
        .attr('class', 'node')
        .attr('cx', d => d.x)
        .attr('cy', d => d.y)
        .attr('r', 5);
}

document.addEventListener('DOMContentLoaded', getTreeData);