
const treeWidth = 500;
const treeHeight = 500;
const treeLayout = d3.tree().size([treeWidth,treeHeight]);

const svg = d3.select('#tree-container').append('svg')
    .attr('width', treeWidth)
    .attr('height', treeHeight)
    .append('g')



function getTreeData() {
    let response = fetch('/get_tree');
    let treeData = response.json();
    visualizeTree(treeData);
}

function visualizeTree(treeData){
    
    const root = d3.hierarchy(treeData);
    const treeNodes = treeLayout(root);

    svg.selectAll('.link')
        .data(treeNodes.links())
        .enter().append('path')
        .attr('class', 'link')
        .attr('d', d3.linkVertical()
            .x(d => d.y)
            .y(d => d,x));

    svg.selectAll('.node')
        .data(treeNodes.descendants())
        .enter().append('circle')
        .attr('class', 'node')
        .attr('cx', d => d.y)
        .attr('cy', d => d.x)
        .attr('r', 5);
}


getTreeData();