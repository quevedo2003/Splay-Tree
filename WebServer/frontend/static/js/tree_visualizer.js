// Get the width and height of the tree container
const treeWidth = document.body.clientWidth;
const treeHeight = window.innerHeight;

// Set margins and create a tree layout
const horizontalMargins = 50;
// Create a tree layout using D3.js with specified size
const treeLayout = d3.tree().size([treeHeight, treeWidth - 100]);

// Create an SVG container for the tree
const svg = d3.select('#tree-container').append('svg')
    .attr('width', treeWidth)
    .attr('height', treeHeight)
    .append('g')
    // Translate the entire tree to the right by 50 pixels
    .attr('transform', `translate(50, 0)`);

// Function to fetch and visualize tree data
function getTreeData() {
    // Fetch tree data from the server
    fetch('/get_tree')
    .then(response => response.json())
    // Once data is retrieved, visualize the tree
    .then(treeData => visualizeTree(treeData));
}

// Function to show a popup menu when clicking on a tree node
let currentPopupMenu = null;
function showPopupMenu(event, d) {
    event.preventDefault(); // Prevent default behavior

    if(currentPopupMenu) {
        currentPopupMenu.remove();
        currentPopupMenu = null;
    }

    const navBar = document.querySelector('nav');
    const navBarRect = navBar.getBoundingClientRect();

    // Create a popup menu
    const popUpMenu = d3.select(navBar).append('div')
        .attr('class', 'popup-div')
        .style('position', 'absolute')
        // Position the popup just below the navbar
        .style('left', `${navBarRect.bottom}px`)
        .style('top', '10%');

    // Add a button to the popup menu
    popUpMenu.append('button')
        .text('Go to URL')
        .on('click', () => {
            // Handle button click (to be implemented)
        });

    currentPopupMenu = popUpMenu;
}

// Function to visualize the tree
function visualizeTree(treeData){
    // Create a hierarchy and layout for the tree nodes
    const root = d3.hierarchy(treeData);
    // Generate node and link positions based on the tree layout
    const treeNodes = treeLayout(root);

    // Draw links between tree nodes
    svg.selectAll('.link')
        .data(treeNodes.links())
        .enter().append('path')
        .attr('class', 'link')
        .attr('d', d3.linkHorizontal()
            .x(d => d.y) // x-coordinate is based on y
            .y(d => d.x)) // y-coordinate is based on x
        .style('stroke-width', 1)
        .style('stroke', 'blue');

    // Draw circles and labels for tree nodes
    const nodes = svg.selectAll('.node')
        .data(treeNodes.descendants())
        .enter().append('g')
        .attr('class','node')
        .attr('transform', d => `translate(${d.y},${d.x})`)
        .on('click', (event, d) => showPopupMenu(event, d));
    
    // Draw circles representing each tree node
    nodes.append('circle')
        .attr('r', 10);
    // Add text labels to each tree node
    nodes.append('text')
        .attr('dy', -10)
        .style('text-anchor', 'middle')
        .text(d => d.data.name);
}

// Event listener to trigger fetching and visualizing tree data on page load
document.addEventListener('DOMContentLoaded', getTreeData);
