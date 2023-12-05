#include "httplib.h"
#include "splay_tree.h"

int main(int argc, char *argv[]) {
    
    // Create an HTTP server instance using httplib
    httplib::Server backend;

    // Create an instance of the Splay Tree for storing browsing history
    STree history;

    // Check if command line arguments are provided
    if (argc == 1){
        // TODO: Add logic for handling command line arguments if needed
    }

    // Define an endpoint to handle GET requests for retrieving the tree data
    backend.Get("/get_tree", [&](const httplib::Request& /*req*/, httplib::Response &res) {
        try {
            // Respond with the JSON representation of the splay tree
            res.set_content(history.toJson(), "application/json");
        } catch (const std::exception& e) {
            // Handle exceptions and respond with an error
            res.status = 500;
            res.set_content("{\"error\": \"" + std::string(e.what()) + "\"}", "application/json");
        }
    });



    // Define the /search_tree endpoint
    backend.Get("/search_tree", [&](const httplib::Request& req, httplib::Response &res) {
        // Extract the search query from the request parameters
        std::string query = req.get_param_value("query");

        // Perform a splay search on the tree with the given query
        history.splaySearch(query);

        // Get the root URL from the tree
        std::string root_url = history.get_root();

        // Insert the query into the tree if it's not the root URL
        if (root_url != query) {
            history.insert(query);
        }

        // Respond with the updated JSON representation of the splay tree
        res.set_content(history.toJson(), "application/json");
    });


    // Start the backend server and listen on localhost:8080
    backend.listen("localhost", 8080);
}
